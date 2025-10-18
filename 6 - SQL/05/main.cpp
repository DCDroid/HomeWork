#include <iostream>
#include "Users.h"
#include <pqxx/pqxx>

int main()
{   
    Users users;

    try
    {
        users.connect_to_db();
        users.create_db();
    }
    catch(const pqxx::sql_error& e)
    {
        std::cerr << e.what() << '\n';  
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }

    
    try
    {
        UserInfo user;
        user.email = "jimhalpert@dunder-mifflin.com";
        user.name = "Jim";
        user.second_name = "Halpert";
        user.phone_numbers.push_back("(502) 942-6422");

        users.add_user(user);
    }
    catch(const pqxx::sql_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';  
    }

    try
    {
        UserInfo user;
        user.email = "jimhalpert@dunder-mifflin.com";
        user.phone_numbers.push_back("(502) 942-9867");
        user.phone_numbers.push_back("(502) 142-9867");
        users.add_phone_number(user);
    }
    catch(const pqxx::sql_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';  
    }
    
    try
    {
        UserInfo user;
        user.email = "jimhalpert@dunder-mifflin.com";
        user.name = "JimNew";
        user.second_name = "HalpertNew";
        user.phone_numbers.push_back("(502) 111-2222");
        users.change_user(user);
    }
    catch(const pqxx::sql_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';  
    }
    
    try 
    {
        UserInfo user;
        user.email = "jimhalpert@dunder-mifflin.com";
        user.phone_numbers.push_back("(502) 111-2222"); // номер, который нужно удалить
        users.delete_phone_number(user);
    }
    catch(const pqxx::sql_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';  
    }    
    
    /*
    try
    {   
        users.delete_user("jimhalpert@dunder-mifflin.com");
    }   
    catch(const pqxx::sql_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';  
    }    
    */
    
    try
    {
        auto user = users.find_user("jimhalpert@dunder-mifflin.com");
        std::cout << "Name: " << user.name << "\nSecond Name: " << user.second_name << "\nEmail: " << user.email << "\nPhone Numbers:\n";
        for(const auto& phone : user.phone_numbers)
        {
            std::cout << phone << std::endl;
        }
    }   
    catch(const pqxx::sql_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';  
    }

    return 0;
}