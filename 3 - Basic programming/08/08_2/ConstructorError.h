#pragma once
#include <string>

class ConstructorError : public std::exception
{

private:
    std::string m_exception_text;
public:
    ConstructorError(std::string exception_text);
    const char* what() const noexcept override;
};

