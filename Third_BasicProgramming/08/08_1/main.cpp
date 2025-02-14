#include <iostream>
#include <exception>

class BadLength : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "You entered forbidden lenght word! Goodbye";
    }
};

int function(std::string str, int forbidden_length)
{
    if(str.length() == forbidden_length) throw BadLength();
    return str.length();
}

int main()
{
    int forbidden_length{}, tmp_lenght;
    std::cout << "Enter forbidden length: ";
    std::cin >> forbidden_length;
    std::string word_tmp;

    while(true)
    {
        std::cout << "Enter word: ";
        std::cin >> word_tmp;
        try
        {
            tmp_lenght = function(word_tmp, forbidden_length);
            std::cout << "Lenght of the word " << word_tmp << " is " << tmp_lenght << std::endl; 
        }
        catch (const BadLength& ex) 
        {
            std::cout << ex.what() << std::endl; 
            break;
        }
    }

    return 0;
}