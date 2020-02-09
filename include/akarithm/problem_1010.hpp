#pragma once

#include <algorithm>
#include <vector>
#include <unordered_map>

namespace akarithm
{

template <typename ValueTy>
static constexpr std::size_t numPairsDivisibleBy60(
    const std::vector<ValueTy> &time)
{
    std::vector<ValueTy> map(60, 0);
    std::size_t counter = 0;
    for (std::size_t iter = 0; iter < time.size(); ++iter)
    {
        ValueTy val = time[iter] % 60;
        ValueTy diff = 60 - val;
        if (diff == 60)
            diff = 0;
        counter += map[diff];
        map[val]++;
    }
    return counter;
}

// NOTE :: This is a pretty bad algorithm that is O(n^2)
template <typename ValueTy>
static constexpr std::size_t numPairsDivisibleBy60_O2(
    const std::vector<int> &time)
{
    std::size_t counter = 0;
    for (std::size_t iter1 = 0; iter1 < time.size(); iter1++)
    {
        for (std::size_t iter = iter1 + 1; iter < time.size(); iter++)
        {
            if (((time[iter] + time[iter1]) % 60) == 0)
                counter++;
        }
    }
    return counter;
}

} // namespace akarithm
