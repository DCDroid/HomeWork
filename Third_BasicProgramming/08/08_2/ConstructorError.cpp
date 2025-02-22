#include "ConstructorError.h"

ConstructorError::ConstructorError(std::string exception_text)
{
    m_exception_text = exception_text;
}

const char* ConstructorError::what() const noexcept
{
    return m_exception_text.c_str();
}