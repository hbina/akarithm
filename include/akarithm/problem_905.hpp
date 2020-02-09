#pragma once

#include <vector>
#include <algorithm>

namespace akarithm
{

template <typename ValueTy>
static constexpr std::vector<ValueTy> sortArrayByParity(
    const std::vector<ValueTy> &A)
{
    std::vector<ValueTy> result;
    result.reserve(A.size());

    for (const ValueTy &value : A)
    {
        if (!(value % 2))
        {
            result.push_back(value);
        }
    }
    for (const ValueTy &value : A)
    {
        if (value % 2)
        {
            result.push_back(value);
        }
    }
    return result;
}

template <typename ValueTy>
static constexpr std::vector<ValueTy> sortArrayByParity_stdStablePartition(
    std::vector<ValueTy> &result)
{
    std::stable_partition(result.begin(), result.end(), [](const ValueTy &a) -> bool {
        return !(a % 2);
    });
    return result;
}

} // namespace akarithm
