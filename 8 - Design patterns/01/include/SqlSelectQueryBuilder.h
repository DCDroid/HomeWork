#pragma once

#include "SqlSelectQuery.h"

class SqlSelectQueryBuilder {

private:
    SqlSelectQuery query_;

public:
    SqlSelectQueryBuilder& AddFrom(const std::string& from) noexcept;
    SqlSelectQueryBuilder& AddColumn(const std::string& from) noexcept;

    SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv);
    SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns);
    SqlSelectQueryBuilder& AddWhere(const std::string& column, const std::string& value) noexcept;

    std::string BuildQuery() noexcept;
};