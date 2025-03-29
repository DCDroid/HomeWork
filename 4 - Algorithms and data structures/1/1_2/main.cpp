#include <iostream>

int NumberOfLarge(int* array, int array_len, int number)
{
    int left = 0, middle = 0, right = array_len - 1;
    while (true)
    {
        middle = (left + right) / 2;

        if(array[middle] > number) {
            right = middle - 1;
        }
        else if(array[middle] <= number) {
            left = middle + 1;
            if(array[middle + 1] > number) {
                break;
            }
        }
        
    }
    
    return array_len - left;
}

int main() 
{
    int array[] = {14, 16, 19, 32, 32, 32, 56, 69, 72};

    int number{};
    
    std::cout << "Enter a starting point: ";
    std::cin >> number; 

    std::cout << "The number of elements in the array is greater than " << number << ": " << NumberOfLarge(array, 9, number) << std::endl;

    return 0;
}