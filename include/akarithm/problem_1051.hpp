#pragma once

#include <vector>
#include <algorithm>

namespace akarithm
{

template <typename ValueTy>
static constexpr ValueTy heightChecker(const std::vector<ValueTy> &heights)
{
    std::vector<ValueTy> copy = heights;
    std::sort(copy.begin(), copy.end());
    ValueTy counter = 0;
    for (std::size_t iter = 0; iter < heights.size(); iter++)
    {
        if (copy[iter] != heights[iter])
            counter++;
    }
    return counter;
}

template <typename ValueTy>
static constexpr std::size_t heightChecker_zip(const std::vector<ValueTy> &heights)
{
    // FIXME :: There must be a more natural construct to zip through 2 iterators...cmon <algorithm>
    std::vector<ValueTy> copy = heights;
    std::sort(copy.begin(), copy.end());
    std::size_t counter = 0;
    for (std::size_t iter = 0; iter < copy.size() && iter < heights.size(); iter++)
    {
        const ValueTy p_left = heights[iter];
        const ValueTy p_right = copy[iter];
        if (p_left != p_right)
            counter++;
    }
    return counter;
}

} // namespace akarithm
