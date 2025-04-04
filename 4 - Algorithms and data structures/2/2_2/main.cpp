#include <iostream>

int *pointer;

int fibo(int number) {

    if(number > 1) { // не учитывается выход за границы массива
        if(pointer[number] != 0)  return pointer[number];
    }

    if(number == 2) return 1;
    if(number == 1) return 1;
    if(number == 0) return 0;

    pointer[number] = fibo(number - 1) + fibo(number - 2);

    return pointer[number];
}



int main()
{
    // сложность по времени - О(n) 
    // сложность по памяти - О(n) 

    pointer = new int[10];
    for(int i = 0; i < 10; i ++) pointer[i] = 0;

    for(int i = 0; i < 10; i++)
        std::cout << fibo(i) << '\n';
    return 0;

    delete[] pointer;
}