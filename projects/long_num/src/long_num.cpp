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
                return numbers[i] > x.numbers[i];
            } else {
                return numbers[i] < x.numbers[i];
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
        LongNumber a = *this;
        LongNumber b = x;
        
        a.sign = 1;
        b.sign = 1;

        bool a_bigger = (a > b);
        bool result_negative = false;

        if (!a_bigger) {
            LongNumber temp = a;
            a = b;
            b = temp;
            result_negative = true;
        }

        int* res_arr = new int[a.length]();
        
        for (int i = 0; i < a.length; i++) {
            res_arr[i] = a.numbers[i];
        }

        int borrow = 0;
        int a_pos = a.length - 1;
        int b_pos = b.length - 1;

        while (a_pos >= 0) {
            int digit_a = res_arr[a_pos];
            int digit_b;
            if (b_pos >= 0) {
                digit_b = b.numbers[b_pos];
            } else {
                digit_b = 0;
            }

            int sub = digit_a - digit_b - borrow;

            if (sub < 0) {
                sub += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }

            res_arr[a_pos] = sub;
            a_pos--;
            b_pos--;
        }


        int start = 0;
        while (start < a.length - 1 && res_arr[start] == 0) {
            start++;
        }

        LongNumber res(a.length - start, 1);
        for (int i = 0; i < res.length; i++) {
            res.numbers[i] = res_arr[start + i];
        }

        if (res.length == 1 && res.numbers[0] == 0) {
            res.sign = 1;
        } else {
            if (sign == -1) {
                result_negative = !result_negative;
            }
            if (result_negative) {
                res.sign = -1;
            } else {
                res.sign = 1;
            }
        }

        delete[] res_arr;
        return res;
    }

    int max_len = std::max(length, x.length) + 1;
    int* res_arr = new int[max_len]();

    int carry = 0;
    int last_dgt_num_idx = length - 1;
    int last_dgt_x_idx = x.length - 1;
    int last_dgt_new_idx = max_len - 1;

    while (last_dgt_num_idx >= 0 || last_dgt_x_idx >= 0 || carry > 0) {
        int sum = carry;

        if (last_dgt_num_idx >= 0) {
            sum += numbers[last_dgt_num_idx];
            last_dgt_num_idx--;
        }

        if (last_dgt_x_idx >= 0) {
            sum += x.numbers[last_dgt_x_idx];
            last_dgt_x_idx--;
        }

        res_arr[last_dgt_new_idx] = sum % 10;
        carry = sum / 10;
        last_dgt_new_idx--;
    }


    int start = 0;
    while (start < max_len && res_arr[start] == 0) {
        start++;
    }

    if (start == max_len) {
        LongNumber zero;
        delete[] res_arr;
        return zero;
    }

    LongNumber res(max_len - start, sign);
    for (int i = 0; i < res.length; i++) {
        res.numbers[i] = res_arr[start + i];
    }

    delete[] res_arr;
    return res;
}

LongNumber LongNumber::operator - (const LongNumber& x) const
{
    LongNumber neg_x = x;
    neg_x.sign = -neg_x.sign;
    return *this + neg_x;
}

LongNumber LongNumber::operator * (const LongNumber& x) const
{
    if (this->is_zero() || x.is_zero()) {
        return LongNumber();
    }

    int new_len = length + x.length;
    int* result = new int[new_len]();

    for (int last_dgt_num_idx = length - 1; last_dgt_num_idx >= 0; last_dgt_num_idx--) {
        int carry = 0;
        for (int last_dgt_x_idx = x.length - 1; last_dgt_x_idx >= 0; last_dgt_x_idx--) {
            int position = last_dgt_num_idx + last_dgt_x_idx + 1;
            int new_dgt = numbers[last_dgt_num_idx] * x.numbers[last_dgt_x_idx] + result[position] + carry;
            result[position] = new_dgt % 10;
            carry = new_dgt / 10;
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
            res.numbers[i] = result[begin + i];
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

    LongNumber dividend = *this;
    LongNumber divisor = x;
    dividend.sign = 1;
    divisor.sign = 1;

    if (dividend < divisor) {
        return LongNumber();
    }

    LongNumber quotient(dividend.length, 1);
    LongNumber current("0");

    for (int i = 0; i < dividend.length; i++) {
       current = current * LongNumber("10");
        
        LongNumber digit(1, 1);
        digit.numbers[0] = dividend.numbers[i];
        current = current + digit;

        int quotient_digit = 0;
        for (int q = 0; q <= 9; q++) {
            LongNumber product = divisor * LongNumber(std::to_string(q).c_str());
            if (product <= current) {
                quotient_digit = q;
            } else {
                break;
            }
        }

        quotient.numbers[i] = quotient_digit;

        LongNumber product = divisor * LongNumber(std::to_string(quotient_digit).c_str());
        current = current - product;
    }

    int begin = 0;
    while (begin < quotient.length - 1 && quotient.numbers[begin] == 0) {
        begin++;
    }

    LongNumber result(quotient.length - begin, this->sign * x.sign);
    for (int i = 0; i < result.length; i++) {
        result.numbers[i] = quotient.numbers[begin + i];
    }

    if (result.length == 1 && result.numbers[0] == 0) {
        result.sign = 1;
    }

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

    std::string getNumberString(const al::LongNumber& x) {
    std::string result = "";
   
    if (x.sign == -1) {
        result += "-";
    }
    
    for (int i = 0; i < x.length; i++) {
        result += std::to_string(x.numbers[i]);
    }
    
    return result;
}
}

