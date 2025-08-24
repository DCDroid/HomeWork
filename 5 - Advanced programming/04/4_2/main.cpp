#include "catch2/catch_all.hpp"

#include "List.cpp"

TEST_CASE( "Test list", "[list]" ) {
    SECTION("Test List.PushBack()") {
        List list;
        list.PushBack(1);
        list.PushBack(2);
        CHECK(list.Empty() == false);
        CHECK(list.Size() == 2);
        CHECK(list.PopBack() == 2);
    }
    SECTION("Test List.PushFront()") {
        List list;
        list.PushFront(2);
        list.PushFront(1);
        CHECK(list.Empty() == false);
        CHECK(list.Size() == 2);
        CHECK(list.PopFront() == 1);
    }
    SECTION("Test List.PopFront()") {
        List list;
        CHECK_THROWS_AS(list.PopFront(), std::runtime_error);
        CHECK_THROWS_WITH(list.PopFront(), "list is empty");
        list.PushFront(2);
        list.PushFront(1);
        CHECK(list.PopFront() == 1);
        CHECK(list.Size() == 1);
    }
    SECTION("Test List.PopBack()") {
        List list;
        CHECK_THROWS_AS(list.PopBack(), std::runtime_error);
        CHECK_THROWS_WITH(list.PopBack(), "list is empty");
        list.PushBack(2);
        list.PushBack(1);
        CHECK(list.PopBack() == 1);
        CHECK(list.Size() == 1);
    }
}

int main()
{
    return Catch::Session().run();
}