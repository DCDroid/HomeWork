#include "iostream"

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
    std::cout << "Dynamic array: ";
    for (int i = 0; i < actual_size; i++)
    {
        if(i < logical_size)
            std::cout << arr[i] << " ";
        else
            std::cout << "_ ";
    }
}

int main()
{
    int logical_size = 0;
    int actual_size = 0;
    int* arr = nullptr;

    std::cout << "Enter the actual size of the array: ";
    std::cin >> actual_size;
    std::cout << "Enter the logical size of the array: ";
    std::cin >> logical_size;

    if (logical_size > actual_size)
    {
        std::cout << "Logical size cannot be greater than actual size!" << std::endl;
        return -1;
    }

    arr = new int[actual_size];

    for (int i = 0; i < logical_size; i++)
    {
        std::cout << "Введите arr[" << i << "]: ";
        std::cin >> arr[i];
    }

    print_dynamic_array(arr, logical_size, actual_size);

    delete[] arr;
    return 0;
}