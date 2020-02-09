#pragma once

#include <algorithm>
#include <vector>
#include <numeric>

namespace akarithm
{

template <typename ValueTy>
static constexpr ValueTy specialDivision(const ValueTy &value, const ValueTy &divisor)
{
    const ValueTy remainder = value % divisor;
    const ValueTy division = (value - remainder) / divisor;
    if (remainder == 0)
    {
        return division;
    }
    else
    {
        return division + 1;
    }
}

template <typename ValueTy>
static constexpr ValueTy accumulateResult(const std::vector<ValueTy> &nums, const ValueTy &divisor)
{
    return std::accumulate(nums.cbegin(), nums.cend(), 0, [&](ValueTy sum, const ValueTy &x) -> ValueTy {
        return std::move(sum) + specialDivision(x, divisor);
    });
}

template <typename ValueTy>
static constexpr ValueTy smallestDivisor_naive(const std::vector<ValueTy> &nums, ValueTy threshold)
{
    ValueTy divisor = 1;
    ValueTy result = accumulateResult(nums, divisor);
    while (result > threshold)
    {
        divisor++;
        result = accumulateResult(nums, divisor);
    }
    return divisor;
}

template <typename ValueTy>
static constexpr ValueTy smallestDivisor_guessFirst(const std::vector<ValueTy> &nums, ValueTy threshold)
{
    ValueTy sum = accumulateResult(nums, 1);
    ValueTy guess_divisor = sum / threshold;
    if (guess_divisor == 0)
    {
        return 1;
    }
    ValueTy result = accumulateResult(nums, guess_divisor);
    while (result > threshold)
    {
        guess_divisor++;
        result = accumulateResult(nums, guess_divisor);
    }
    return guess_divisor;
}

} // namespace akarithm
