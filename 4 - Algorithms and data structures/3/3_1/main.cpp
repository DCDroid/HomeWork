#include <iostream> 

void merge_sort(int* arr, int size)
{
    if(size == 2) 
    {
        if(arr[0] > arr[1]) 
        {
            std::swap(arr[0], arr[1]);
        }
    }
    else if (size != 1) 
    {
        int middle = size / 2;
        merge_sort(arr, middle);
        merge_sort(arr + middle, size - middle);
        
        int left_pointer{0}, right_pointer{middle}, arr_pointer{0};
        int tmp_arr[size];
        

        while(true)
        {
            if(arr_pointer == size) break;
            if(left_pointer == middle && right_pointer < size)
            {
                tmp_arr[arr_pointer] = arr[right_pointer];
                arr_pointer++;
                right_pointer++;
            }
            else if(right_pointer == size && left_pointer < middle) 
            {
                tmp_arr[arr_pointer] = arr[left_pointer];
                arr_pointer++;
                left_pointer++;
            }
            else 
            {
                if(arr[right_pointer] < arr[left_pointer]) 
                {
                    tmp_arr[arr_pointer] = arr[right_pointer];
                    arr_pointer++;
                    right_pointer++;
                }
                else{
                    tmp_arr[arr_pointer] = arr[left_pointer];
                    arr_pointer++;
                    left_pointer++;
                }
            }
        }
        

        for(int i = 0; i < size; i++)
        {
            arr[i] = tmp_arr[i];
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
    int arr_size{10};
    int arr_1_size{15};
    int arr_2_size{18};

    int arr[] = {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
    int arr_1[] = {88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
    int arr_2[] = {24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62};

    merge_sort(arr, arr_size);
    merge_sort(arr_1, arr_1_size);
    merge_sort(arr_2, arr_2_size);

    print_arr(arr, arr_size);
    print_arr(arr_1, arr_1_size);
    print_arr(arr_2, arr_2_size);
    

    return 0;
}