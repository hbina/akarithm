#pragma once

#include <vector>

namespace akarithm
{

template <typename ValueTy>
static constexpr std::vector<ValueTy> fairCandySwap(const std::vector<ValueTy> &A, const std::vector<ValueTy> &B)
{
    bool flags[100001] = {false};
    ValueTy sum_b = 0;
    for (const ValueTy &i : B)
    {
        flags[i] = true;
        sum_b += i;
    }

    ValueTy sum_a = 0;
    for (const ValueTy &i : A)
        sum_a += i;

    std::vector<ValueTy> result(2, 0);
    for (const ValueTy &i : A)
    {
        const ValueTy target = (sum_b - sum_a) / 2 + i;
        if (target >= 0 && target <= 100000 && flags[target])
        {
            result[0] = i;
            result[1] = target;
            break;
        }
    }
    return result;
}

} // namespace akarithm
