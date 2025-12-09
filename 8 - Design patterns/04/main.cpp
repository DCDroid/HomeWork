#include <fstream>
#include <string>
#include <memory>

// Разделяем большой интерфейс на специализированные интерфейсы
class Printable
{
public:
    virtual ~Printable() = default;
};

class HTMLPrintable : public Printable
{
public:
    virtual ~HTMLPrintable() = default;
    virtual std::string printAsHTML() const = 0;
};

class TextPrintable : public Printable
{
public:
    virtual ~TextPrintable() = default;
    virtual std::string printAsText() const = 0;
};

class JSONPrintable : public Printable
{
public:
    virtual ~JSONPrintable() = default;
    virtual std::string printAsJSON() const = 0;
};

// Класс для HTML формата
class HTMLData : public HTMLPrintable
{
public:
    explicit HTMLData(std::string data) : data_(std::move(data)) {}

    std::string printAsHTML() const override
    {
        return "<html>" + data_ + "</html>";
    }

private:
    std::string data_;
};

// Класс для текстового формата
class TextData : public TextPrintable
{
public:
    explicit TextData(std::string data) : data_(std::move(data)) {}

    std::string printAsText() const override
    {
        return data_;
    }

private:
    std::string data_;
};

// Класс для JSON формата
class JSONData : public JSONPrintable
{
public:
    explicit JSONData(std::string data) : data_(std::move(data)) {}

    std::string printAsJSON() const override
    {
        return "{ \"data\": \"" + data_ + "\"}";
    }

private:
    std::string data_;
};

// Функции сохранения больше не зависят от формата
void saveToAsHTML(std::ofstream& file, const HTMLPrintable& printable)
{
    file << printable.printAsHTML();
}

void saveToAsJSON(std::ofstream& file, const JSONPrintable& printable)
{
    file << printable.printAsJSON();
}

void saveToAsText(std::ofstream& file, const TextPrintable& printable)
{
    file << printable.printAsText();
}