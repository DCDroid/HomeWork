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

    Table& operator=(const Table &some) = delete;
    Table(const Table &some) = delete;
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
    std::cout << test[1][1] << '\n'; 

    /*    
    Tеперь такое не компилируется
    Table<int> t1(2, 2);
    Table<int> t2 = t1;

    Table<int> t1(2, 2);
    Table<int> t2(3, 3);
    t2 = t1; // ОПАНЬКИ! Утечка памяти и двойное удаление!
    */

}