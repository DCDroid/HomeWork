#include "Users.h"

Users::Users()
{
    std::cout << "a" << std::endl;
}

Users::~Users()
{
    std::cout << "~a" << std::endl;
}

void Users::connect_to_db()
{
    _db_connection = std::make_unique<pqxx::connection>(
        "host=localhost user=this_is_my_user password=this_is_my_password dbname=users port=5432"
    );

    // Проверка, было ли соединение успешно установлено
    if (!_db_connection || !_db_connection->is_open())
    {
        throw std::runtime_error("DB connection is not open.");
    }

    
    _db_connection->prepare("insert_user", "INSERT INTO Users (email, name, second_name) VALUES ($1, $2, $3)");

    _db_connection->prepare("insert_phone_number", "INSERT INTO PhoneNumbers (email, phone_number) VALUES ($1, $2)");

    _db_connection->prepare("update_user_name", "UPDATE Users SET name = $1 WHERE email = $2");

    _db_connection->prepare("update_user_second_name", "UPDATE Users SET second_name = $1 WHERE email = $2");

    _db_connection->prepare("delete_user_phones", "DELETE FROM PhoneNumbers WHERE email = $1");

    _db_connection->prepare("delete_user", "DELETE FROM Users WHERE email = $1");


    std::cout << _db_connection->is_open() << std::endl;
}

void Users::create_db()
{
    if(!_db_connection || !_db_connection->is_open())
    {
        throw std::runtime_error("DB connection is not open.");
    }
    pqxx::work tx( *_db_connection );
    tx.exec(
        "CREATE TABLE if not exists Users ("
        "    email VARCHAR(255) NOT NULL,"
        "    name VARCHAR(255) NOT NULL,"
        "    second_name VARCHAR(255) NOT NULL,"
        "    PRIMARY KEY (email)"
        ");"

        "CREATE TABLE if not exists PhoneNumbers ("
        "    email VARCHAR(255) NOT NULL,"
        "    phone_number VARCHAR(255) NOT NULL,"
        "    FOREIGN KEY (email) REFERENCES Users (email),"
        "    PRIMARY KEY (phone_number, email)"
        ");"
    );
    tx.commit();
}

void Users::add_user(UserInfo& user_info)
{
    if (!_db_connection || !_db_connection->is_open())
    {
        throw std::runtime_error("DB connection is not open.");
    }
    pqxx::work tx( *_db_connection );
    tx.exec_prepared("insert_user", user_info.email, user_info.name, user_info.second_name);
    for(auto i : user_info.phone_numbers)
        tx.exec_prepared("insert_phone_number", user_info.email, i);
    tx.commit();
}

void Users::add_phone_number(UserInfo& user_info)
{
    if (!_db_connection || !_db_connection->is_open())
    {
        throw std::runtime_error("DB connection is not open.");
    }
    pqxx::work tx( *_db_connection );
    for(auto i : user_info.phone_numbers)
        tx.exec_prepared("insert_phone_number", user_info.email, i);
    tx.commit();
}   

// Удаляет ВСЕ старые номера телефонов пользователя, если предлагается хотя бы 1 новый номер телефона
void Users::change_user(UserInfo& info)
{
    if (!_db_connection || !_db_connection->is_open())
    {
        throw std::runtime_error("DB connection is not open.");
    }
    pqxx::work tx( *_db_connection );
    if(info.name.empty() == false)
    {
        tx.exec_prepared("update_user_name", info.name, info.email);
    }
    
    if(info.second_name.empty() == false)
    {
        tx.exec_prepared("update_user_second_name", info.second_name, info.email);
    }
    if(info.phone_numbers.empty() == false)
    {
        // Удаляем ВСЕ старые номера
        tx.exec_prepared("delete_user_phones", info.email);
        
        // Добавляем новые
        for(const auto& phone : info.phone_numbers)
        {
            tx.exec_prepared("insert_phone_number", info.email, phone);
        }
    }
    
    tx.commit();
}

void Users::delete_phone_number(UserInfo& info)
{
    if (!_db_connection || !_db_connection->is_open())
    {
        throw std::runtime_error("DB connection is not open.");
    }
    pqxx::work tx( *_db_connection );
    for(const auto& phone : info.phone_numbers)
    {
        tx.exec_params("DELETE FROM PhoneNumbers WHERE email = $1 AND phone_number = $2", info.email, phone);
    }
    tx.commit();
}

void Users::delete_user(std::string email)
{
    if (!_db_connection || !_db_connection->is_open())
    {
        throw std::runtime_error("DB connection is not open."); 
    }
    pqxx::work tx( *_db_connection );
    // Сначала удаляем связанные номера телефонов из-за FOREIGN KEY
    tx.exec_prepared("delete_user_phones", email);
    // Затем удаляем самого пользователя
    tx.exec_prepared("delete_user", email);
    tx.commit();
}

UserInfo Users::find_user(std::string email)
{
    UserInfo user;
    if (!_db_connection || !_db_connection->is_open())
    {
        throw std::runtime_error("DB connection is not open.");
    }
    pqxx::nontransaction ntx( *_db_connection );
    
    // Поиск информации о пользователе
    pqxx::result user_res = ntx.exec_params("SELECT name, second_name FROM Users WHERE email = $1", email);
    if (!user_res.empty())
    {
        user.email = email;
        user.name = user_res[0][0].as<std::string>();
        user.second_name = user_res[0][1].as<std::string>();
        // Поиск номеров телефонов
        pqxx::result phones_res = ntx.exec_params("SELECT phone_number FROM PhoneNumbers WHERE email = $1", email);
        for (const auto& row : phones_res)
        {
            user.phone_numbers.push_back(row[0].as<std::string>());
        }
    }
    
    return user;
}

