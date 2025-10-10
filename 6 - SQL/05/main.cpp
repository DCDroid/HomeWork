#include <iostream>
#include "Users.h"
#include <pqxx/pqxx>

int main()
{   
    Users users;

    users.connect_to_db();
    users.create_db();

    

    users.add_user();

    return 0;
}