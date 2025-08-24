#include "catch2/catch_all.hpp"

#include "List.cpp"

TEST_CASE( "Test list", "[list]" ) {
    SECTION("Test List.Empty()") {
        List list;
        CHECK(list.Empty() == true);
        list.PushBack(1);
        CHECK(list.Empty() == false);
    }
    SECTION("Test List.Size()") {
        List list;
        CHECK(list.Size() == 0);
        list.PushBack(1);
        list.PushBack(1);
        CHECK(list.Size() == 2);
    }
    SECTION("Test List.Clear()") {
        List list;
        list.PushBack(1);
        CHECK(list.Size() == 1);
        list.Clear();
        CHECK(list.Size() == 0);
    }
}

int main()
{
    return Catch::Session().run();
}