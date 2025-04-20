#include "iostream"

void print_pyramid(int *arr, int size) 
{
    std::cout << "Array: ";
    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    
    std::cout << "\nPyramid:\n" << 0 << " root " << arr[0] << std::endl;
    for(int i = 0; ; i++)
    {
        if (2 * i + 1 >= size)
            break;
        std::cout << i + 1 << " left(" << arr[i] << ") " << arr[2 * i + 1] << std::endl;
        if (2 * i + 2 >= size)
            break;
        std::cout << i + 1 << " right(" << arr[i] << ") " << arr[2 * i + 2] << std::endl;
        
        
    }
}

int main()
{
    int arr_1[] = {1, 3, 6, 5, 9, 8};
    int arr_2[] = {94, 67, 18, 44, 55, 12, 6, 42};
    int arr_3[] = {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};

    print_pyramid(arr_1, sizeof(arr_1) / sizeof(arr_1[0]));
    std::cout << '\n';
    print_pyramid(arr_2, sizeof(arr_2) / sizeof(arr_2[0]));
    std::cout << '\n';
    print_pyramid(arr_3, sizeof(arr_3) / sizeof(arr_3[0]));
}