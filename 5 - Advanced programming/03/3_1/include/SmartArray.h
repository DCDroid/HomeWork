#include <stdexcept>

class SmartArray {

public:
    SmartArray(int size);
    ~SmartArray();
    int get_element(int value);
    void add_element(int value);
private:
    int* m_array;
    int m_size;
    int m_current_index = 0;
};

// Custom exception class
class MyException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Something went wrong!";
    }
};