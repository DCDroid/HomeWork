#include <iostream>

template <class T>
class Table {
    int rows, cols;
    T* data;
public:
    Table(int r, int c) : rows(r), cols(c) {
        data = new int[rows * cols]{};
    }

    ~Table() {
        delete[] data;
    }

    int* operator[](int row) {
        return data + row * cols;
    }
};

int main()
{
    auto test = Table<int>(2, 2);
    test[0][0] = 1;
    test[0][1] = 2;
    test[1][0] = 3;
    test[1][1] = 4;
    std::cout << test[0][0]; 
    std::cout << test[0][1]; 
    std::cout << test[1][0]; 
    std::cout << test[1][1]; 
}