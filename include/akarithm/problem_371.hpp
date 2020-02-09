#pragma once

#include <utility>
#include <iostream>
#include <bitset>

namespace akarithm
{

template <typename ValueTy>
static constexpr std::pair<ValueTy, ValueTy> full_adder(const ValueTy &a, const ValueTy &b, const ValueTy &c)
{
    return {(a ^ b) ^ c, ((a ^ b) & c) | (a & b)};
}

template <typename ValueTy>
ValueTy getSum(const ValueTy &x_input, const ValueTy &y_input)
{
    ValueTy x = x_input;
    ValueTy y = y_input;
    while (y != 0)
    {
        ValueTy carry = x & y;
        x = x ^ y;
        y = carry << 1;
    }
    return x;
}

} // namespace akarithm
