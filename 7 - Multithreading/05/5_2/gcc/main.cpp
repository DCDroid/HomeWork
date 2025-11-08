#include <iostream>
#include <future>
#include <list>
#include <thread>

// Функция поиска минимума, будет выполняться асинхронно
void find_min(std::promise<std::list<int>::iterator>&& prom, 
              std::list<int>::iterator start,
              std::list<int>::iterator end)
{
    auto min_it = start;
    for(auto it = start; it != end; ++it)
    {
        if(*it < *min_it)
        {
            min_it = it;
        }
    }
    prom.set_value(min_it);
}

void my_sort(std::list<int>& lst)
{
    for(auto it = lst.begin(); it != lst.end(); ++it)
    {
        // Создаем promise и future для получения результата
        std::promise<std::list<int>::iterator> prom;
        std::future<std::list<int>::iterator> fut = prom.get_future();

        // Запускаем асинхронный поиск минимума
        std::thread t(find_min, 
                     std::move(prom),
                     it,
                     lst.end());

        // Ждем результат и выполняем обмен
        auto min_it = fut.get();
        if (min_it != it)
        {
            std::swap(*it, *min_it);
        }

        // Дожидаемся завершения потока
        t.join();
    }
}

int main()
{   
    std::list<int> lst = {5, 3, 8, 1, 4};
    
    std::cout << "Исходный список: ";
    for(const auto& val : lst)
    {
        std::cout << val << " ";
    }
    std::cout << '\n';

    my_sort(lst);

    std::cout << "Отсортированный список: ";
    for(const auto& val : lst)
    {
        std::cout << val << " ";
    }
    std::cout << '\n';
}