#include <gtest/gtest.h>

#include "long_num.hpp"

using namespace al;

TEST(LongNumberTest, NoArguments) {

    LongNumber num;

    std::stringstream ss;
    ss << num;

    EXPECT_EQ(ss.str(), "0");
}

TEST(LongNumberTest, StringPos) {
    LongNumber num("13032008");
    std::stringstream ss;
    ss << num;
    EXPECT_EQ(ss.str(), "13032008");
}

TEST(LongNumberTest, StringNeg) {
    LongNumber num("-13032008");
    std::stringstream ss;
    ss << num;
    EXPECT_EQ(ss.str(), "-13032008");
}

TEST(LongNumberTest, StringZero) {
    LongNumber num("0");
    std::stringstream ss;
    ss << num;
    EXPECT_EQ(ss.str(), "0");
}

TEST(LongNumberTest, Copy) {
    LongNumber original("13032008");
    LongNumber copy(original);

    std::stringstream ss1, ss2;
    ss1 << original;
    ss2 << copy;

    EXPECT_EQ(ss1.str(), ss2.str());
}

TEST(LongNumberTest, Equality) {
    LongNumber num1("13032008");
    LongNumber num2("13032008");
    LongNumber num3("13032007");

    EXPECT_TRUE(num1 == num2);
    EXPECT_FALSE(num1 == num3);
}

TEST(LongNumberTest, Inequality) {
    LongNumber num1("13032008");
    LongNumber num2("13032008");
    LongNumber num3("13032007");

    EXPECT_FALSE(num1 != num2);
    EXPECT_TRUE(num1 != num3);
}

TEST(LongNumberTest, GreaterThan) {
    LongNumber num1("1303200");
    LongNumber num2("1303");
    LongNumber num3("13032009");
    LongNumber num4("-13032008");

    EXPECT_TRUE(num1 > num2);
    EXPECT_FALSE(num1 > num3);
    EXPECT_TRUE(num1 > num4);
}

TEST(LongNumberTest, LessThan) {
    LongNumber num1("1303200");
    LongNumber num2("13032009");
    LongNumber num3("-13032008");

    EXPECT_TRUE(num1 < num2);
    EXPECT_FALSE(num2 < num1);
    EXPECT_TRUE(num3 < num1);
}

TEST(LongNumberTest, IsNegative) {
    LongNumber pos("13032008");
    LongNumber neg("-13032008");
    LongNumber zero("0");

    EXPECT_FALSE(pos.is_negative());
    EXPECT_TRUE(neg.is_negative());
    EXPECT_FALSE(zero.is_negative());
}

TEST(StringCompareTestSum, CheckEquality) {
    std::string str1 = "500";
    LongNumber ln1("200");
    LongNumber ln2("300");
    LongNumber ln3 = ln1 + ln2;
    std::string str2 = getNumberString(ln3);
    EXPECT_EQ(str1, str2) << "Неверный результат сложения";
}

TEST(StringCompareTestSubtraction, CheckEquality) {
    std::string str1 = "100";
    LongNumber ln1("200");
    LongNumber ln2("300");
    LongNumber ln3 = ln2 - ln1;
    std::string str2 = getNumberString(ln3);
    EXPECT_EQ(str1, str2) << "Неверный результат вычитания";
}

TEST(StringCompareTestMultiple, CheckEquality) {
    std::string str1 = "60000";
    LongNumber ln1("200");
    LongNumber ln2("300");
    LongNumber ln3 = ln1 * ln2;
    std::string str2 = getNumberString(ln3);
    EXPECT_EQ(str1, str2) << "Неверный результат умножения";
}

TEST(StringCompareTestDivision, CheckEquality) {
    std::string str1 = "200";
    LongNumber ln1("60000");
    LongNumber ln2("300");
    LongNumber ln3 = ln1 / ln2;
    std::string str2 = getNumberString(ln3);
    EXPECT_EQ(str1, str2) << "Неверный результат деления";
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
