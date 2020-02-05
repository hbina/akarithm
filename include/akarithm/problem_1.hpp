#pragma once

#include "util/generic/group_by.hpp"

#include "util/generic/sliding_window.hpp"

#include <vector>
#include <iterator>

// TODO ::  Once group_minify is merged, consider using it instead.
namespace akarithm
{
static auto
twoSum(
    const std::vector<int> &nums,
    const int target)
    -> std::vector<int>
{
    using IndexType =
        typename std::iterator_traits<std::vector<int>::iterator>::difference_type;
    const auto tmp =
        util::generic::group_by<std::vector<std::vector<int>>>(
            std::cbegin(nums),
            std::cend(nums),
            [](const auto &lhs, const auto &rhs)
                -> bool {
                return lhs == rhs;
            });
    // Sliding window accumulate
    auto [left, right] =
        util::generic::sliding_window(
            std::cbegin(tmp),
            std::cend(tmp),
            [&](const std::vector<int> &lhs,
                const std::vector<int> &rhs)
                -> bool {
                return lhs[0] + rhs[0] < target;
            },
            [&](const std::vector<int> &lhs,
                const std::vector<int> &rhs)
                -> bool {
                return lhs[0] + rhs[0] == target;
            });
    // Accumulate to find the indices
    auto left_i = std::accumulate(
        std::cbegin(tmp),
        left,
        0,
        [](IndexType acc, const std::vector<int> &value)
            -> IndexType {
            return acc + value.size();
        });
    auto right_i = std::accumulate(
        std::cbegin(tmp),
        right,
        0,
        [](IndexType acc, const std::vector<int> &value)
            -> IndexType {
            return acc + value.size();
        });
    return {left_i, right_i};
}

} // namespace akarithm
