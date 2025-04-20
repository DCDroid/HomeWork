#include <iostream>

void go_on_piramid(int *arr, int size)
{
    std::cout << "Array: ";
    for(int i = 0; i < size; i++) std::cout << arr[i] << " ";

    int position = 0, level = 0;
    bool l_or_r = true; // true - left, false - right
    std::cout << "\nYou are here: " << 0 << " root " << arr[0] << std::endl;

    while(true)
    {
        std::cout << "Enter command (l/r/q/u): ";
        char command;
        std::cin >> command;
        if(command == 'l') 
        {
            if (2 * position + 1 >= size) 
            {
                std::cout << "No left child\n";
                continue;
            }
            l_or_r = true;
            level++;
            position = 2 * position + 1;
            std::cout << "You are here: " << level << " left(" << arr[(position - 1)/2] << ") " << arr[position] << std::endl;
        } 
        else if(command == 'r') 
        {
            if (2 * position + 2 >= size) 
            {
                std::cout << "No right child\n";
                continue;
            }
            l_or_r = true;
            level++;
            position = 2 * position + 2;
            std::cout << "You are here: " << level << " right(" << arr[(position - 2)/2] << ") " << arr[position] << std::endl;
        } 
        else if(command == 'u') 
        {
            if (level == 0) 
            {
                std::cout << "You are at the root\n";
                continue;
            }

            level--;
            if(l_or_r) 
            {
                position = (position - 1) / 2;
                if(position > 0) {
                    std::cout << "You are here: " << level << " left(" << arr[(position - 1)/2] << ") " << arr[position] << std::endl;
                }
                else {
                    std::cout << "You are here: " << level << " root " << arr[position] << std::endl;
                }
                
            }
            else
            {
                position = (position - 2) / 2;
                if(position > 0) {
                    std::cout << "You are here: " << level << " right(" << arr[(position - 2)/2] << ") " << arr[position] << std::endl;
                }
                else {
                    std::cout << "You are here: " << level << " root " << arr[position] << std::endl;
                }
            }
            
            
        } 
        else if(command == 'q') 
        {
            break;
        } 
        else {
            std::cout << "Invalid command\n";
            continue;
        }
    }
}

int main() 
{
    int arr_1[] = {1, 3, 6, 5, 9, 8};
    int arr_2[] = {94, 67, 18, 44, 55, 12, 6, 42};
    int arr_3[] = {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};

    go_on_piramid(arr_1, sizeof(arr_1) / sizeof(arr_1[0]));
}