class Counter
{
private:
    int m_counter = 0;
public:
    Counter() = default;
    Counter(const int init_value);
    void increment();
    void decrement();
    int get_counter();
};