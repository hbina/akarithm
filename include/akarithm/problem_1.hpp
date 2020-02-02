#pragma once

#include "util/generic/group_by.hpp"

#include <vector>

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
    // Accumulate to find the indices
    return {};
}

} // namespace akarithm
