#include <iostream>

int pivoting(int* arr, int size, int pi_index) // pi_index должен быть меньше size !!!
{
    int pi = arr[pi_index], l_pointer{0}, r_pointer{size - 1};
    // if(size > 1) {
        while(true) 
        {
            while(arr[l_pointer] < pi) 
            {
                l_pointer++;
            }
            while(arr[r_pointer] > pi) 
            {
                r_pointer--;
            }
            if(l_pointer >= r_pointer) 
            {
                return l_pointer;
                break;
            }

            std::swap(arr[r_pointer], arr[l_pointer]);
            l_pointer++;
            r_pointer--;
        }
    // }
}


void quick_sort(int* arr, int size)
{
    if(size > 1) {
        int pi = size / 2;
        int border = pivoting(arr, size, pi);
        quick_sort(arr, border);
        quick_sort(arr + border, size - border);
    }
}


void print_arr(int* arr, int arr_size)
{
    for(int i = 0; i < arr_size; i++) std::cout << arr[i] << " ";
    std::cout << '\n';
}

int main()
{
    int arr_size{10};
    int arr_1_size{15};
    int arr_2_size{18};

    int arr[] = {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
    int arr_1[] = {88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
    int arr_2[] = {24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62};

    quick_sort(arr, arr_size);
    quick_sort(arr_1, arr_1_size);
    quick_sort(arr_2, arr_2_size);

    print_arr(arr, arr_size);
    print_arr(arr_1, arr_1_size);
    print_arr(arr_2, arr_2_size);
    

    return 0;
}