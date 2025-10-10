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
    try
    {
        _db_connection = std::make_unique<pqxx::connection>(
            "host=localhost user=postgres password=1q2w3e4r dbname=users port=5432"
        );
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(pqxx::sql_error e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << _db_connection->is_open() << std::endl;
}

void Users::create_db()
{
    if(_db_connection->is_open())
    {
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
}

void Users::add_phone_number(std::string phone_number, std::string email)
{

}

void Users::change_user(UserInfo& info)
{
      
}

void Users::delete_phone_number(std::string phone_number, std::string email)
{

}

void Users::delete_user(std::string email)
{

}

UserInfo Users::find_user(std::string email)
{
    UserInfo user;
    return user;
}

