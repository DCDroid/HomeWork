#include <iostream>

int main()
{
    int month_number{};
    enum month { January, February, March, April, May, June, July, August, September, October, November, December };

    month my_month;

    while (true)
    {
        

        std::cout << "Enter month number: ";
        std::cin >> month_number;

        if (month_number > 12 || month_number < 0) {
            std::cout << "Incorrect number!\n";
            continue;
        }

        else if (month_number == 0) {
            std::cout << "Goodbye\n";
            break;
        }

        my_month = static_cast<month>(month_number - 1);
        switch (my_month)
        {
        case January: 
            std::cout << "January\n";
            break;
        case February: 
            std::cout << "February\n";
            break;
        case March: 
            std::cout << "March\n";
            break;
        case April: 
            std::cout << "April\n";
            break;
        case May: 
            std::cout << "May\n";
            break;
        case June: 
            std::cout << "June\n";
            break;
        case August: 
            std::cout << "August\n";
            break;
        case September: 
            std::cout << "September\n";
            break;
        case October: 
            std::cout << "October\n";
            break;
        case November: 
            std::cout << "November\n";
            break;
        case December: 
            std::cout << "December\n";
            break;

        default:
            break;
        }
    }

    return 0;
}