#include "long_num.hpp"

#include <algorithm>
#include <cstring>
#include <iostream>

using al::LongNumber;

LongNumber::LongNumber()
{
    numbers = new int[1];
    numbers[0] = 0;
    length = 1;
    sign = 1;
}

LongNumber::LongNumber(int length, int sign)
{
    this->length = length;
    this->sign = sign;

    numbers = new int[length];
    for (int i = 0; i < length; i++) {
        numbers[i] = 0;
    }
}

LongNumber::LongNumber(const char* const str)
{
    int begin = 0;

    if (str[0] == '-') {
        sign = -1;
        begin++;
    } else {
        sign = 1;
    }

    length = get_length(str + begin);
    numbers = new int[length];

    for (int i = 0; i < length; i++) {
        numbers[i] = str[begin + i] - '0';
    }

    if (length == 1 && numbers[0] == 0) {
        sign = 1;
    }
}

LongNumber::LongNumber(const LongNumber& x)
{
    length = x.length;
    sign = x.sign;

    numbers = new int[length];
    for (int i = 0; i < length; i++) {
        numbers[i] = x.numbers[i];
    }
}

LongNumber::LongNumber(LongNumber&& x)
{
    numbers = x.numbers;
    length = x.length;
    sign = x.sign;

    x.numbers = nullptr;
    x.length = 0;
    x.sign = 1;
}

LongNumber::~LongNumber()
{
    delete[] numbers;
    numbers = nullptr;
}

LongNumber& LongNumber::operator = (const char* const str)
{
    LongNumber temp(str);
    delete[] numbers;

    length = temp.length;
    sign = temp.sign;

    numbers = new int[length];
    for (int i = 0; i < length; i++) {
        numbers[i] = temp.numbers[i];
    }

    return *this;
}

LongNumber& LongNumber::operator = (const LongNumber& x)
{
    if (this == &x) {
        return *this;
    }
    delete[] numbers;

    length = x.length;
    sign = x.sign;

    numbers = new int[length];
    for (int i = 0; i < length; i++) {
        numbers[i] = x.numbers[i];
    }

    return *this;
}

LongNumber& LongNumber::operator = (LongNumber&& x)
{
    if (this == &x) {
        return *this;
    }

    delete[] numbers;

    numbers = x.numbers;
    length = x.length;
    sign = x.sign;

    x.numbers = nullptr;
    x.length = 0;
    x.sign = 1;

    return *this;
}

bool LongNumber::operator == (const LongNumber& x) const
{
    if (sign != x.sign) {
        return false;
    }

    if (length != x.length) {
        return false;
    }

    for (int i = 0; i < length; i++) {
        if (numbers[i] != x.numbers[i]) {
            return false;
        }
    }

    return true;
}

bool LongNumber::operator != (const LongNumber& x) const
{
    return !(*this == x);
}

bool LongNumber::operator > (const LongNumber& x) const
{
    if (sign != x.sign) {
        return sign > x.sign;
    }

    if (length != x.length) {
        if (sign == 1) {
            return length > x.length;
        } else {
            return length < x.length;
        }
    }

    for (int i = 0; i < length; i++) {
        if (numbers[i] != x.numbers[i]) {
            if (sign == 1) {
                return numbers > x.numbers;
            } else {
                return numbers < x.numbers;
            }
        }
    }

    return false;
}

bool LongNumber::operator < (const LongNumber& x) const
{
    return !(*this > x) && !(*this == x);
}

bool LongNumber::operator >= (const LongNumber& x) const 
{
    return (*this > x) || (*this == x);
}

bool LongNumber::operator <= (const LongNumber& x) const 
{
    return (*this < x) || (*this == x);
}

LongNumber LongNumber::operator - () const 
{
	LongNumber result = *this;
	result.sign = -sign;
	return result;
}

LongNumber LongNumber::operator + (const LongNumber& x) const
{
    if (sign != x.sign) {
        if (sign == -1) {
            return x - (-(*this));
        } else {
            return *this - (-x);
        }
    }

    int new_len = std::max(length, x.length) + 1;
    int* result = new int[new_len]();

    int last_dgt_num_idx = length - 1;
    int last_dgt_x_idx = x.length - 1;
    int last_dgt_new_idx = new_len - 1;

    int carry = 0;

    while (last_dgt_num_idx >= 0 || last_dgt_x_idx >= 0 || carry > 0) {
        int sum = carry;

        if (last_dgt_num_idx >= 0) {
            sum += numbers[last_dgt_num_idx--];
        }

        if (last_dgt_x_idx >= 0) {
            sum += x.numbers[last_dgt_x_idx--];
        }

        result[last_dgt_new_idx--] = sum % 10;

        carry = sum / 10;
    }

    LongNumber res;
    delete[] res.numbers;

    int begin = 0;
    while (begin < new_len && result[begin] == 0) {
        begin++;
    }

    if (begin == new_len) {
        res.length = 1;
        res.numbers = new int[res.length];
        res.numbers[0] = 0;
        res.sign = 1;
    } else {
        res.length = new_len - begin;
        res.numbers = new int[res.length];
        for (int i = 0; i < res.length; i++) {
            res.numbers[i] = result[begin + 1];
        }
        res.sign = sign;
    }

    delete[] result;

    return res;
}

LongNumber LongNumber::operator - (const LongNumber& x) const
{
    return *this + (-x);
}

LongNumber LongNumber::operator * (const LongNumber& x) const
{
    if (this->is_zero() || x.is_zero()) {
        return LongNumber();
    }

    int new_len = length + x.length;
    int* result = new int[new_len]();

    for (int last_dgt_num_idx = length - 1; last_dgt_num_idx > 0; last_dgt_num_idx--) {
        int carry = 0;
        for (int last_dgt_x_idx = x.length - 1; last_dgt_x_idx > 0; last_dgt_x_idx--) {
            int position = last_dgt_num_idx + last_dgt_x_idx + 1;
            int new_dgt = numbers[last_dgt_num_idx] * x.numbers[last_dgt_x_idx] + result[position] + carry;
            result[position] = new_dgt / 10;
        }
        result[last_dgt_num_idx] += carry;
    }

    LongNumber res;
    delete[] res.numbers;

    int begin = 0;
    while (begin < new_len && result[begin] == 0) {
        begin++;
    }

    if (begin == new_len) {
        res.length = 1;
        res.numbers = new int[res.length];
        res.numbers[0] = 0;
        res.sign = 1;
    } else {
        res.length = new_len - begin;
        res.numbers = new int[res.length];
        for (int i = 0; i < res.length; i++) {
            res.numbers[i] = result[begin + 1];
        }
        res.sign = sign * x.sign;
    }

    delete[] result;

    return res;

}

LongNumber LongNumber::operator / (const LongNumber& x) const
{
    if (this->is_zero() || x.is_zero()) {
        return LongNumber();
    }

    LongNumber result("0");
    LongNumber remains = *this;

    while (remains >= x) {
        remains = remains - x;
        result = result + LongNumber("1");
    }
    result.sign = sign * x.sign;

    return result;
}

LongNumber LongNumber::operator % (const LongNumber& x) const
{
    if (this->is_zero() || x.is_zero()) {
        return LongNumber();
    }

    LongNumber remains = *this;
    while (remains >= x) {
        remains = remains - x;
    }

    remains.sign = 1;

    return remains;
}

bool LongNumber::is_negative() const noexcept
{
    return sign == -1;
}

bool LongNumber::is_zero() const noexcept
{
    return length == 1 && numbers[0] == 0;
}

int LongNumber::get_length(const char* const str) const noexcept
{
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    return len;
}

namespace al {
    std::ostream& operator << (std::ostream &os, const LongNumber& x)
    {
        if (x.sign == -1) {
            os << '-';
        }

        for (int i = 0; i < x.length; i++) {
            os << x.numbers[i];
        }

        return os;
    }
}
