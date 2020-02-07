#pragma once

#include "util/generic/group_by_minify.hpp"
#include "util/generic/sliding_window.hpp"

#include <vector>
#include <algorithm>
#include <functional>

namespace akarithm
{

template <
    typename IntTy,
    typename ResultTy = typename std::vector<std::vector<IntTy>>>
static constexpr auto
fourSum(
    const std::vector<IntTy> &nums,
    const IntTy &target)
    -> ResultTy
{
    using PairTy = std::pair<IntTy, std::size_t>;

    auto arr = nums;
    std::sort(std::begin(arr), std::end(arr));
    auto tmp =
        util::generic::group_by_minify<std::vector<PairTy>>(
            std::cbegin(arr),
            std::cend(arr),
            std::equal_to{});
    auto outer_left = std::cbegin(tmp);
    auto outer_right = std::prev(std::cend(tmp));
    ResultTy result;
    while (std::distance(outer_left, outer_right) > 2)
    {
        auto inner_left = std::next(outer_left);
        auto inner_right = std::prev(outer_right);
        while (inner_left != inner_right)
        {
            IntTy sum = outer_left->first + outer_right->first + inner_left->first + inner_right->first;
            if (sum == target)
                result.push_back({outer_left->first, outer_right->first, inner_left->first, inner_right->first});
            if (sum > target)
                inner_right = std::prev(inner_right);
            else
                inner_left = std::prev(inner_left);
        }
        IntTy nearest_sum = outer_left->first + outer_right->first + std::next(outer_left)->first + std::prev(outer_right)->first;
        if (nearest_sum > target)
            outer_right = std::prev(outer_right);
        else
            outer_left = std::prev(outer_left);
    }
    return std::accumulate(
        std::cbegin(tmp),
        std::cend(tmp),
        result,
        [&](ResultTy &acc, const PairTy &value)
            -> ResultTy {
            if (value.second > 3 && value.first * 4 == target)
                acc.push_back({value.first, value.first, value.first, value.first});
            return acc;
        });
}

} // namespace akarithm
