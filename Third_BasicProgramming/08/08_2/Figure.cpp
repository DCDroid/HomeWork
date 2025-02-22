#include "Figure.h"

Figure::Figure() 
{
    check();
}
std::string Figure::get_name()
{
    return this->name;
}
void Figure::print() {
    std::cout << this->name << std::endl;
    if (correct) std::cout << "Good" << std::endl; else std::cout << "Bad" << std::endl;
    std::cout << "Side count: " << this->side_count << "\n\n";
}
void Figure::check() {
    if(side_count == 0) correct = true;
    else correct = false;
}