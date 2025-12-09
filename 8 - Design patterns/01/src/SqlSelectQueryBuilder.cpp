#include "SqlSelectQueryBuilder.h"
#include <sstream>
#include <algorithm>

#include <iterator>

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(const std::string& from) noexcept
{
    query_.from_ = from;
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(const std::string& column) noexcept
{
    query_.columns_.push_back(column);
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumns(const std::vector<std::string>& columns)
{
    query_.columns_.insert(query_.columns_.end(), columns.begin(), columns.end());
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::string& column, const std::string& value) noexcept
{
    query_.where_.insert({column, value});
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::map<std::string, std::string>& kv)
{
    for (const auto& p : kv) {
        query_.where_.insert(p);
    }
    return *this;
}

std::string SqlSelectQueryBuilder::BuildQuery() noexcept
{
    std::ostringstream oss;
    // Columns
    if (query_.columns_.empty()) {
        oss << "SELECT *";
    } else {
        oss << "SELECT ";
        for (size_t i = 0; i < query_.columns_.size(); ++i) {
            if (i) oss << ", ";
            oss << query_.columns_[i];
        }
    }
    // FROM
    if (!query_.from_.empty()) {
        oss << " FROM " << query_.from_;
    }

    // WHERE
    if (!query_.where_.empty()) {
        oss << " WHERE ";
        size_t idx = 0;
        for (auto it = query_.where_.begin(); it != query_.where_.end(); ++it) {
            if (idx) oss << " AND ";
            oss << it->first << "=" << it->second;
            ++idx;
        }
    }
    oss << ";";
    return oss.str();
}

