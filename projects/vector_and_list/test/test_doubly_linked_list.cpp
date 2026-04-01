#include <gtest/gtest.h>
#include "doubly_linked_list.hpp"
#include "doubly_linked_list.cpp"

using al::DoublyLinkedList;

TEST(DoublyLinkedListTest, ConstructorInitializesEmptyList) {
    DoublyLinkedList<int> list;
    EXPECT_EQ(list.get_size(), 0);
    EXPECT_FALSE(list.has_item(10));
}

TEST(DoublyLinkedListTest, PushBackSingleElement) {
    DoublyLinkedList<int> list;
    list.push_back(5);

    EXPECT_EQ(list.get_size(), 1);
    EXPECT_TRUE(list.has_item(5));
}

TEST(DoublyLinkedListTest, PushBackMultipleElements) {
    DoublyLinkedList<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    EXPECT_EQ(list.get_size(), 3);
    EXPECT_TRUE(list.has_item(1));
    EXPECT_TRUE(list.has_item(2));
    EXPECT_TRUE(list.has_item(3));
}

TEST(DoublyLinkedListTest, HasItemOnEmptyList) {
    DoublyLinkedList<int> list;
    EXPECT_FALSE(list.has_item(100));
}

TEST(DoublyLinkedListTest, HasItemReturnsCorrectValue) {
    DoublyLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);

    EXPECT_TRUE(list.has_item(10));
    EXPECT_TRUE(list.has_item(20));
    EXPECT_FALSE(list.has_item(5));
}

TEST(DoublyLinkedListTest, RemoveFirstFromEmptyList) {
    DoublyLinkedList<int> list;
    EXPECT_FALSE(list.remove_first(1));
}

TEST(DoublyLinkedListTest, RemoveFirstSingleElementList) {
    DoublyLinkedList<int> list;

    list.push_back(42);
    EXPECT_TRUE(list.remove_first(42));
    EXPECT_EQ(list.get_size(), 0);
    EXPECT_FALSE(list.has_item(42));
}

TEST(DoublyLinkedListTest, RemoveFirstHead) {
    DoublyLinkedList<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    EXPECT_TRUE(list.remove_first(1));
    EXPECT_EQ(list.get_size(), 2);
    EXPECT_FALSE(list.has_item(1));
    EXPECT_TRUE(list.has_item(2));
    EXPECT_TRUE(list.has_item(3));
}

TEST(DoublyLinkedListTest, RemoveFirstTail) {
    DoublyLinkedList<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    EXPECT_TRUE(list.remove_first(30));
    EXPECT_EQ(list.get_size(), 2);
    EXPECT_FALSE(list.has_item(30));
}

TEST(DoublyLinkedListTest, RemoveFirstMiddleElement) {
    DoublyLinkedList<int> list;

    list.push_back(5);
    list.push_back(10);
    list.push_back(15);

    EXPECT_TRUE(list.remove_first(10));
    EXPECT_EQ(list.get_size(), 2);
    EXPECT_TRUE(list.has_item(5));
    EXPECT_TRUE(list.has_item(15));
}

TEST(DoublyLinkedListTest, RemoveFirstNonexistent) {
    DoublyLinkedList<int> list;

    list.push_back(1);
    list.push_back(2);

    EXPECT_FALSE(list.remove_first(3));
    EXPECT_EQ(list.get_size(), 2);
}


TEST(DoublyLinkedListTest, RemoveFirstRepeatedValues) {
    DoublyLinkedList<int> list;

    list.push_back(5);
    list.push_back(5);
    list.push_back(5);

    EXPECT_TRUE(list.remove_first(5));
    EXPECT_EQ(list.get_size(), 2);
    EXPECT_TRUE(list.has_item(5));
}

TEST(DoublyLinkedListFloatTest, ConstructorInitializesEmptyList) {
    DoublyLinkedList<float> list;
    EXPECT_EQ(list.get_size(), 0);
    EXPECT_FALSE(list.has_item(1.5f));
}

TEST(DoublyLinkedListFloatTest, PushBackElements) {
    DoublyLinkedList<float> list;

    list.push_back(1.1f);
    list.push_back(2.2f);
    list.push_back(3.3f);

    EXPECT_EQ(list.get_size(), 3);
    EXPECT_TRUE(list.has_item(1.1f));
    EXPECT_TRUE(list.has_item(2.2f));
    EXPECT_TRUE(list.has_item(3.3f));
}

TEST(DoublyLinkedListFloatTest, RemoveFirstMiddleElement) {
    DoublyLinkedList<float> list;

    list.push_back(0.5f);
    list.push_back(1.5f);
    list.push_back(2.5f);

    EXPECT_TRUE(list.remove_first(1.5f));
    EXPECT_EQ(list.get_size(), 2);

    EXPECT_FALSE(list.has_item(1.5f));
    EXPECT_TRUE(list.has_item(0.5f));
    EXPECT_TRUE(list.has_item(2.5f));
}

TEST(DoublyLinkedListFloatTest, RemoveNonexisting) {
    DoublyLinkedList<float> list;

    list.push_back(4.4f);
    list.push_back(5.5f);

    EXPECT_FALSE(list.remove_first(9.9f));
    EXPECT_EQ(list.get_size(), 2);
}

TEST(DoublyLinkedListCharTest, ConstructorInitializesEmptyList) {
    DoublyLinkedList<char> list;
    EXPECT_EQ(list.get_size(), 0);
    EXPECT_FALSE(list.has_item('a'));
}

TEST(DoublyLinkedListCharTest, PushBackCharacters) {
    DoublyLinkedList<char> list;

    list.push_back('a');
    list.push_back('b');
    list.push_back('c');

    EXPECT_EQ(list.get_size(), 3);
    EXPECT_TRUE(list.has_item('a'));
    EXPECT_TRUE(list.has_item('b'));
    EXPECT_TRUE(list.has_item('c'));
}

TEST(DoublyLinkedListCharTest, RemoveFirstHead) {
    DoublyLinkedList<char> list;

    list.push_back('x');
    list.push_back('y');
    list.push_back('z');

    EXPECT_TRUE(list.remove_first('x'));
    EXPECT_EQ(list.get_size(), 2);

    EXPECT_FALSE(list.has_item('x'));
    EXPECT_TRUE(list.has_item('y'));
    EXPECT_TRUE(list.has_item('z'));
}

TEST(DoublyLinkedListCharTest, RemoveNonexisting) {
    DoublyLinkedList<char> list;

    list.push_back('p');
    list.push_back('q');

    EXPECT_FALSE(list.remove_first('w'));
    EXPECT_EQ(list.get_size(), 2);
}

TEST(ListPrintTest, PrintNonEmptyIntList)
{
    DoublyLinkedList<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    testing::internal::CaptureStdout();
    list.print();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "1 2 3 \n");
}

TEST(ListPrintTest, PrintNonEmptyFloatList)
{
    DoublyLinkedList<float> list;

    list.push_back(1.1f);
    list.push_back(2.2f);
    list.push_back(3.3f);

    testing::internal::CaptureStdout();
    list.print();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "1.1 2.2 3.3 \n");
}

TEST(ListPrintTest, PrintNonEmptyCharList)
{
    DoublyLinkedList<char> list;

    list.push_back('a');
    list.push_back('b');
    list.push_back('c');


    testing::internal::CaptureStdout();
    list.print();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "a b c \n");
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
