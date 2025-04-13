#include "iostream"

int actual_size = 1;
int logical_size = 1;

void print_dynamic_array(int* arr, int logical_size_, int actual_size_)
{
    std::cout << "Dynamic array: " << actual_size_ << "\n";
    for (int i = 0; i < actual_size; i++)
    {
        if(i < logical_size)
            std::cout << arr[i] << " ";
        else
            std::cout << "_ ";
    }
}

int* append_to_dynamic_array(int* arr, int new_value)
{
    if(logical_size < actual_size)
    {
        arr[logical_size] = new_value;
        logical_size++;
    }
    else if(logical_size == actual_size)
    {
        int* new_arr = new int[actual_size * 2];
        for (int i = 0; i < actual_size * 2; i++)
        {
            if (i < actual_size)
                new_arr[i] = arr[i];
            else
                new_arr[i] = 0; // Initialize new elements to zero
        }
        delete[] arr;
        arr = new_arr;
        arr[logical_size] = new_value;
        logical_size++;
        actual_size = actual_size * 2;
        std::cout << "Array size increased to: " << actual_size << std::endl;
    }

    return arr;
}

int main()
{
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

    while(true) {
        std::cout << "\nEnter a new value to append to the array (or -1 to exit): ";
        int new_value;
        std::cin >> new_value;
        if (new_value == -1) {
            break;
        }
        arr = append_to_dynamic_array(arr, new_value);

        std::cout << "New logical size: " << logical_size << ", new actual size: " << actual_size << std::endl;

        print_dynamic_array(arr, logical_size, actual_size);
    }

    delete[] arr;
    return 0;
}