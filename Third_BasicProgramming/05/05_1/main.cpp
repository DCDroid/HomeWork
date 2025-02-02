#include <iostream>

class Figure
{
private:
    uint16_t m_sides_count{0};
    std::string m_name{"Figure"};
public:
    Figure() = default;
    Figure(uint16_t sides_count, std::string name)
    {
        m_sides_count = sides_count;
        m_name = name;
    }
    uint16_t get_sides_count()
    {
        return m_sides_count;
    }
    std::string get_name()
    {
        return m_name;
    }

};

class Triangle: public Figure { 
public:
    Triangle(std::string name) : Figure(3, name) {}

};

class Quadrangle: public Figure {
public:
    Quadrangle(std::string name) : Figure(4, name)  {}
};

int main()
{
    Figure my_figure;
    Quadrangle my_quadrangle("Quadrangle");
    Triangle my_triangle("Triangle");
     
    std::cout << "Side quantity: " << '\n';
    std::cout << my_figure.get_name() << ": " <<  my_figure.get_sides_count() << '\n';
    std::cout << my_triangle.get_name() << ": " <<  my_triangle.get_sides_count() << '\n';
    std::cout << my_quadrangle.get_name() << ": " <<  my_quadrangle.get_sides_count() << '\n';
}