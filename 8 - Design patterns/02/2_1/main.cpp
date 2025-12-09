#include <string>
#include <iostream>
#include <algorithm>

class Text {
public:
    virtual void render(const std::string& data) const {
        std::cout << data;
    }
    virtual ~Text() = default;
};


class DecoratedText : public Text {
public:
    explicit DecoratedText(Text* text) : text_(text) {}
    virtual ~DecoratedText() = default;
    Text* text_;
};

class ItalicText : public DecoratedText {
public:
    explicit ItalicText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const override {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText {
public:
    explicit BoldText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const override {
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};

class ParagraphText : public DecoratedText {
public:
    explicit ParagraphText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const override {
        std::cout << "<p>";
        text_->render(data);
        std::cout << "</p>";
    }
};

class ReversedText : public DecoratedText {
public:
    explicit ReversedText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const override {
        std::string reversed_data = data;
        std::reverse(reversed_data.begin(), reversed_data.end());
        text_->render(reversed_data);
    }
};

class LinkText : public DecoratedText {
public:
    explicit LinkText(Text* text) : DecoratedText(text) {}
    void render(const std::string& href, const std::string& data) const {
        std::cout << "<a href=" << href << ">";
        text_->render(data);
        std::cout << "</a>";
    }
};

int main() {
    auto text_block = new ItalicText(new BoldText(new Text()));
    text_block->render("Hello world");
    std::cout << std::endl;

    auto paragraph = new ParagraphText(new Text());
    paragraph->render("Hello world");
    std::cout << std::endl;

    auto reversed = new ReversedText(new Text());
    reversed->render("Hello world");
    std::cout << std::endl;

    auto link = new LinkText(new Text());
    link->render("netology.ru", "Hello world");
    std::cout << std::endl;

    delete text_block;
    delete paragraph;
    delete reversed;
    delete link;

    return 0;
}