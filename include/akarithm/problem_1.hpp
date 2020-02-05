#pragma once

#include "util/generic/group_by_minify.hpp"
#include "util/generic/sliding_window.hpp"

#include <vector>
#include <iterator>
#include <algorithm>

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
    using PairType = std::pair<int, IndexType>;
    // Group up equivalent elements
    const auto tmp =
        util::generic::group_by_minify<std::vector<PairType>>(
            std::cbegin(nums),
            std::cend(nums),
            [](const int &lhs, const int &rhs)
                -> bool {
                return lhs == rhs;
            });
    // Get the indices and sort based on the value its pointing to
    std::vector<IndexType> indices;
    indices.resize(tmp.size());
    std::iota(std::begin(indices), std::end(indices), 0);
    std::sort(std::begin(indices), std::end(indices),
              [&](const IndexType &lhs, const IndexType &rhs)
                  -> bool {
                  return tmp[lhs].first < tmp[rhs].first;
              });
    // Find the sum pair using sliding window
    auto [left, right] =
        util::generic::sliding_window(
            std::cbegin(indices),
            std::cend(indices),
            [&](const IndexType &lhs, const IndexType &rhs)
                -> bool {
                return tmp[lhs].first + tmp[rhs].first < target;
            },
            [&](const IndexType &lhs, const IndexType &rhs)
                -> bool {
                return tmp[lhs].first + tmp[rhs].first == target;
            });
    // Accumulate to find the true indices
    auto left_i = 0;
    for (IndexType iter = 0; iter != *left; iter++)
    {
        left_i += tmp[iter].second;
    }
    auto right_i = 0;
    for (IndexType iter = 0; iter != *right; iter++)
    {
        right_i += tmp[iter].second;
    }
    return {left_i, right_i};
}

} // namespace akarithm
