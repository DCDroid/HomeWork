#include <iostream>

int fibo(int number) {
    if(number == 2) return 1;
    if(number == 1) return 1;
    if(number == 0) return 0;
    return fibo(number - 1) + fibo(number - 2);
}

int main()
{
    // сложность по времени - О(2^n) 
    // сложность по памяти - О(1) 

    for(int i = 0; i < 10; i++)
        std::cout << fibo(i) << '\n';
    return 0;
}