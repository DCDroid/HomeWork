// Live.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;


class Live
{
private:
    int** m_table;
    int** m_table_new;
    int m_rows_l{}, m_colums_l{};
    int m_live_iteration_c{1};
    bool m_stagnation{};
    bool m_out_stagnation{};
    int m_alive_cells_c{};
    bool m_is_dead{};

public:
    int initialization(std::string live_cfg_path)
    {
        std::string s;
        std::ifstream cfg(live_cfg_path);

        int init_alive{};

        int tmp_colum{}, tmp_row{}, number{};

        if(!cfg.is_open()) {
            std::cout << "Open error" << std::endl;
            return -1;
        }

        for (int i{}; cfg >> s; i++) {
            if (i == 0)
                m_rows_l = atoi(s.c_str());
            else if (i == 1) {
                m_colums_l = atoi(s.c_str());
                m_table = new int*[m_rows_l + 2];
                m_table_new = new int* [m_rows_l + 2];
                for (int j{}; j < m_rows_l + 2; j++) {
                    m_table[j] = new int[m_colums_l + 2];
                    m_table_new[j] = new int[m_colums_l + 2];
                }
                for (int p{}; p < m_rows_l + 2; p++) {
                    for (int j{}; j < m_colums_l + 2; j++) {
                        m_table[p][j] = 0;
                        m_table_new[p][j] = 0;
                    }
                }
            }
            else
            {
                number = atoi(s.c_str());
                if ((i % 2 != 0) && (number < m_colums_l)) {
                    tmp_colum = number;
                    m_table[tmp_row + 1][tmp_colum + 1] = 1;
                    init_alive++;
                }
                if (number < m_rows_l)
                {
                    tmp_row = number;
                }
            }
        }
        // init_done = true;
        cfg.close();
        m_alive_cells_c = init_alive;
        return 0;
    }

    void show_table() {
        std::system("cls");
        if (m_colums_l != 0 && m_rows_l != 0) {
            for (int i{1}; i <= m_rows_l; i++) {
                for (int j{1}; j <= m_colums_l; j++) {
                    if (m_table[i][j]) std::cout << " * ";
                    else std::cout << " - ";
                }
                std::cout << "\n";
            }

            std::cout << "Generation: " << m_live_iteration_c << ". Alive cells: " << m_alive_cells_c << "\n";
            
            if (m_alive_cells_c == 0) {
                std::cout << "All cells are dead. Game over" << std::endl;
                m_is_dead = true;
            }

            if (m_stagnation) {
                std::cout << "The world has stagnated. Game over" << std::endl;
                m_out_stagnation = true;
            }
        }
        else
        {
            std::cout << "Пусто" << std::endl;
        }
    }

    void execute() {
        int is_similar{};
        m_live_iteration_c++;
        for (int i{1}, mate_counter{0}; i <= m_rows_l; i++) {
            for (int j{1}; j <= m_colums_l; j++) {
                
                mate_counter += m_table[i + 1][j - 1] + m_table[i + 1][j] + m_table[i + 1][j + 1];
                mate_counter += m_table[i][j - 1] + m_table[i][j + 1];
                mate_counter += m_table[i - 1][j - 1] + m_table[i - 1][j] + m_table[i - 1][j + 1];

                

                if (m_table[i][j] == false) {
                    if(mate_counter == 3) m_table_new[i][j] = 1;
                }
                else if (mate_counter == 3 || mate_counter == 2)
                {
                    m_table_new[i][j] = 1;
                }
                else 
                {
                    m_table_new[i][j] = 0;
                }                
                if (mate_counter > 3)
                {
                    m_table_new[i][j] = 0;
                }

                mate_counter = 0;
            }
        }

        m_alive_cells_c = 0;
        for (int i{ 1 }; i <= m_rows_l; i++) {
            for (int j{ 1 }; j <= m_colums_l; j++) {
                if (m_table_new[i][j] == m_table[i][j]) is_similar++;
                if (m_table_new[i][j] == true) m_alive_cells_c++;
            }
        }
        
        if (is_similar == m_rows_l * m_colums_l) m_stagnation = true;
        

        for (int i{}; i < m_rows_l + 2; i++) {
            std::copy(m_table_new[i], m_table_new[i] + m_colums_l + 2, m_table[i]); 
        }

        for (int i{}; i < m_rows_l + 2; i++) {
            for (int j{}; j < m_colums_l + 2; j++) {
                m_table_new[i][j] = 0;
            }
        }
    }

    bool is_end() {
        return m_out_stagnation || m_is_dead;
    }

    ~Live()
    {
        for (int i{}; i < m_rows_l + 2; i++) {
            delete[] m_table[i];
            delete[] m_table_new[i];
        }
        delete[] m_table;
        delete[] m_table_new;
    }
    
};

int main()
{
    std::string live_cfg_path{"live_cfg.txt"};

    Live my_live;
    my_live.initialization(live_cfg_path);


    while (true) {
        
        my_live.show_table();
        my_live.execute();

        if (my_live.is_end()) 
            break;

        std::this_thread::sleep_for(0.5s);
    }

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
