#include <pqxx/pqxx>
#include <iostream>

struct UserInfo
{
    std::string name;
    std::string second_name;
    std::string email;
    std::list<std::string> phone_numbers;
};

class Users
{
private:
    std::unique_ptr<pqxx::connection> _db_connection;

public:
    Users();
    ~Users();
    void connect_to_db();
    void create_db();
    void add_user(UserInfo& info);                 
    void add_phone_number(std::string phone_number, std::string email);
    void change_user(UserInfo& info);
    void delete_phone_number(std::string phone_number, std::string email);
    void delete_user(std::string email);
    UserInfo find_user(std::string email);
};