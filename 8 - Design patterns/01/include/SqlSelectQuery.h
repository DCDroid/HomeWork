#pragma once

#include <string>
#include <vector>
#include <map>

class SqlSelectQuery
{
public:    
    std::vector<std::string> columns_;
    std::map<std::string, std::string> where_;
    std::string from_;
};