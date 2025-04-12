#include <iostream>

#define MIN_NUMBER (int)10
#define MAX_NUMBER (int)24

void count_sort(int* arr, int size)
{
    const int count_array_size = MAX_NUMBER - MIN_NUMBER + 1;
    int count_arr[count_array_size] = {0};
    
    for(int i = 0; i < size; i++) 
    {
        if(arr[i] >= MIN_NUMBER && arr[i] <= MAX_NUMBER) 
        {
            count_arr[arr[i] - MIN_NUMBER]++;
        }
    }

    for(int i = 0; i < count_array_size; i++)
    {
        std::cout << count_arr[i] << " ";
    }
    std::cout << '\n';

    int orig_arr_pointer{0};
    for(int i = 0; i < count_array_size; i++)
    {
        while(count_arr[i] != 0)
        {
            arr[orig_arr_pointer] = i + MIN_NUMBER;
            orig_arr_pointer++;
            count_arr[i]--;
        }
    }
}

void print_arr(int* arr, int arr_size)
{
    for(int i = 0; i < arr_size; i++) std::cout << arr[i] << " ";
    std::cout << '\n';
}

int main()
{
    int arr[] = {19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17};
    int arr_1[] = {16, 17, 14, 20, 22, 20, 17, 22, 16, 19, 23, 24, 20, 22, 21, 18, 14, 16, 17, 21, 10, 11, 19, 23, 11, 11, 17, 17, 11, 21, 17, 11, 17, 16, 12, 11, 16, 22, 23, 16};
    int arr_2[] = {21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21, 18, 19, 20, 12, 16, 20, 14, 17, 13, 10, 23, 19, 14, 10, 22, 19, 12, 24, 23, 22, 15, 13, 22, 18, 18, 11, 23, 24, 17, 10};

    count_sort(arr, sizeof(arr) / sizeof(int));
    count_sort(arr_1, sizeof(arr_1) / sizeof(int));
    count_sort(arr_2, sizeof(arr_2) / sizeof(int));

    print_arr(arr, sizeof(arr) / sizeof(int));
    print_arr(arr_1, sizeof(arr_1) / sizeof(int));
    print_arr(arr_2, sizeof(arr_2) / sizeof(int));
    

    return 0;
}