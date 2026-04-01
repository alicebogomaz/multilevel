#include <gtest/gtest.h>
#include "vector.hpp"
#include "vector.cpp"

using al::Vector;

TEST(VectorTest, DefaultSizeIsZero)
{
    Vector<int> v;
    EXPECT_EQ(v.get_size(), 0);
}

TEST(VectorTest, PushBackIncreasesSize)
{
    Vector<int> v;

    v.push_back(10);
    EXPECT_EQ(v.get_size(), 1);

    v.push_back(20);
    EXPECT_EQ(v.get_size(), 2);
}

TEST(VectorTest, HasItemReturnsFalseOnEmptyVector)
{
    Vector<int> v;
    EXPECT_FALSE(v.has_item(5));
}

TEST(VectorTest, HasItemReturnsTrueIfExists)
{
    Vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    EXPECT_TRUE(v.has_item(2));
    EXPECT_FALSE(v.has_item(99));
}

TEST(VectorTest, InsertAtBeginning)
{
    Vector<int> v;

    v.push_back(2);
    v.push_back(3);

    EXPECT_TRUE(v.insert(0, 1));

    EXPECT_EQ(v.get_size(), 3);
    EXPECT_TRUE(v.has_item(1));
}

TEST(VectorTest, InsertAtEndWorksLikePushBack)
{
    Vector<int> v;

    v.push_back(1);
    v.push_back(2);

    EXPECT_TRUE(v.insert(2, 3));

    EXPECT_EQ(v.get_size(), 3);
    EXPECT_TRUE(v.has_item(3));
}

TEST(VectorTest, InsertInMiddleShiftsElements)
{
    Vector<int> v;

    v.push_back(1);
    v.push_back(3);

    EXPECT_TRUE(v.insert(1, 2));

    EXPECT_EQ(v.get_size(), 3);

    EXPECT_TRUE(v.has_item(1));
    EXPECT_TRUE(v.has_item(2));
    EXPECT_TRUE(v.has_item(3));
}

TEST(VectorTest, InsertWrongPositionReturnsFalse)
{
    Vector<int> v;

    v.push_back(1);
    v.push_back(2);

    EXPECT_FALSE(v.insert(5, 100));
    EXPECT_EQ(v.get_size(), 2);
}

TEST(VectorTest, RemoveFirstReturnsFalseIfNotFound)
{
    Vector<int> v;

    v.push_back(1);
    v.push_back(2);

    EXPECT_FALSE(v.remove_first(999));
    EXPECT_EQ(v.get_size(), 2);
}

TEST(VectorTest, RemoveFirstDeletesElement)
{
    Vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    EXPECT_TRUE(v.remove_first(20));
    EXPECT_EQ(v.get_size(), 2);

    EXPECT_FALSE(v.has_item(20));
    EXPECT_TRUE(v.has_item(10));
    EXPECT_TRUE(v.has_item(30));
}

TEST(VectorTest, RemoveFirstRemovesOnlyFirstOccurrence)
{
    Vector<int> v;

    v.push_back(5);
    v.push_back(7);
    v.push_back(5);
    v.push_back(5);

    EXPECT_TRUE(v.remove_first(5));
    EXPECT_EQ(v.get_size(), 3);

    EXPECT_TRUE(v.has_item(5));
}

TEST(VectorTest, RemoveFirstFromEmptyVectorReturnsFalse)
{
    Vector<int> v;
    EXPECT_FALSE(v.remove_first(1));
    EXPECT_EQ(v.get_size(), 0);
}

TEST(VectorPrintTest, PrintEmptyVector)
{
    Vector<int> v;

    testing::internal::CaptureStdout();
    v.print();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "the list is empty :c \n");
}

TEST(VectorPrintTest, PrintNonEmptyIntVector)
{
    Vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    testing::internal::CaptureStdout();
    v.print();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "1 2 3 \n");
}


TEST(VectorFloatTest, ConstructorCreatesEmptyVector) {
    Vector<float> v;
    EXPECT_EQ(v.get_size(), 0);
}

TEST(VectorFloatTest, PushBackWorks) {
    Vector<float> v;

    v.push_back(1.1f);
    v.push_back(2.2f);

    EXPECT_EQ(v.get_size(), 2);
    EXPECT_TRUE(v.has_item(1.1f));
    EXPECT_TRUE(v.has_item(2.2f));
}

TEST(VectorFloatTest, InsertAtBeginning) {
    Vector<float> v;

    v.push_back(2.2f);
    v.push_back(3.3f);

    EXPECT_TRUE(v.insert(0, 1.1f));

    EXPECT_EQ(v.get_size(), 3);
    EXPECT_TRUE(v.has_item(1.1f));
}

TEST(VectorFloatTest, InsertInMiddle) {
    Vector<float> v;

    v.push_back(1.1f);
    v.push_back(3.3f);

    EXPECT_TRUE(v.insert(1, 2.2f));

    EXPECT_EQ(v.get_size(), 3);
    EXPECT_TRUE(v.has_item(2.2f));
}

TEST(VectorFloatTest, InsertInvalidPosition) {
    Vector<float> v;
    v.push_back(1.1f);

    EXPECT_FALSE(v.insert(5, 2.2f));
}

TEST(VectorFloatTest, RemoveFirstWorks) {
    Vector<float> v;

    v.push_back(1.1f);
    v.push_back(2.2f);
    v.push_back(3.3f);

    EXPECT_TRUE(v.remove_first(2.2f));
    EXPECT_FALSE(v.has_item(2.2f));
    EXPECT_EQ(v.get_size(), 2);
}

TEST(VectorFloatTest, RemoveFirstNonexistent) {
    Vector<float> v;

    v.push_back(1.1f);
    v.push_back(2.2f);

    EXPECT_FALSE(v.remove_first(9.9f));
    EXPECT_EQ(v.get_size(), 2);
}

TEST(VectorPrintTest, PrintNonEmptyFloatVector)
{
    Vector<float> v;

    v.push_back(1.1f);
    v.push_back(2.2f);
    v.push_back(3.3f);

    testing::internal::CaptureStdout();
    v.print();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "1.1 2.2 3.3 \n");
}

TEST(VectorCharTest, ConstructorCreatesEmptyVector) {
    Vector<char> v;
    EXPECT_EQ(v.get_size(), 0);
}

TEST(VectorCharTest, PushBackAddsCharacters) {
    Vector<char> v;

    v.push_back('a');
    v.push_back('b');
    v.push_back('c');

    EXPECT_EQ(v.get_size(), 3);
    EXPECT_TRUE(v.has_item('a'));
    EXPECT_TRUE(v.has_item('b'));
    EXPECT_TRUE(v.has_item('c'));
}

TEST(VectorCharTest, InsertAtPosition) {
    Vector<char> v;

    v.push_back('x');
    v.push_back('z');

    EXPECT_TRUE(v.insert(1, 'y'));

    EXPECT_EQ(v.get_size(), 3);
    EXPECT_TRUE(v.has_item('y'));
}

TEST(VectorCharTest, InsertAtInvalidPosition) {
    Vector<char> v;

    v.push_back('a');

    EXPECT_FALSE(v.insert(10, 'b'));
}

TEST(VectorCharTest, RemoveFirstExisting) {
    Vector<char> v;

    v.push_back('a');
    v.push_back('b');
    v.push_back('c');

    EXPECT_TRUE(v.remove_first('b'));
    EXPECT_EQ(v.get_size(), 2);
    EXPECT_FALSE(v.has_item('b'));
}

TEST(VectorCharTest, RemoveFirstNonexistent) {
    Vector<char> v;

    v.push_back('a');
    v.push_back('b');

    EXPECT_FALSE(v.remove_first('z'));
    EXPECT_EQ(v.get_size(), 2);
}

TEST(VectorPrintTest, PrintNonEmptyCharVector)
{
    Vector<char> v;

    v.push_back('a');
    v.push_back('b');
    v.push_back('c');

    testing::internal::CaptureStdout();
    v.print();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "a b c \n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
