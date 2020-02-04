#pragma once

#include "util/generic/group_by.hpp"

#include <vector>
#include "util/generic/sliding_window.hpp"

// TODO ::  Once group_minify is merged, consider using it instead.
namespace akarithm
{
static auto
twoSum(
    const std::vector<int> &nums,
    const int target)
    -> std::vector<int>
{
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
            [](const std::vector<int> &lhs,
               const std::vector<int> &rhs)
                -> bool {
                return lhs[0] < rhs[0];
            },
            [&](const std::vector<int> &lhs,
                const std::vector<int> &rhs)
                -> bool {
                return lhs[0] + rhs[0] == target;
            });
    // Accumulate to find the indices
    return {};
}

} // namespace akarithm
