#pragma once

#include "util/generic/group_by_minify.hpp"
#include "util/generic/sliding_window.hpp"

#include <vector>
#include <iterator>
#include <algorithm>

// TODO ::  Once group_minify is merged, consider using it instead.
namespace akarithm
{

template <
    typename Iterable,
    typename ValueType = typename std::iterator_traits<
        typename Iterable::iterator>::value_type,
    typename IndexType =
        typename std::iterator_traits<
            typename Iterable::iterator>::difference_type>
static constexpr auto
twoSum(
    const Iterable &nums,
    const ValueType &target)
    -> Iterable
{
    // Get the indices and sort based on the value its pointing to
    std::vector<IndexType> indices;
    indices.resize(nums.size());
    std::iota(std::begin(indices), std::end(indices), 0);
    std::sort(std::begin(indices), std::end(indices),
              [&](const IndexType &lhs, const IndexType &rhs)
                  -> bool {
                  return nums[lhs] < nums[rhs];
              });
    // Find the sum pair using sliding window
    auto [left, right] =
        util::generic::sliding_window(
            std::cbegin(indices),
            std::cend(indices),
            [&](const IndexType &lhs, const IndexType &rhs)
                -> bool {
                return nums[lhs] + nums[rhs] < target;
            },
            [&](const IndexType &lhs, const IndexType &rhs)
                -> bool {
                return nums[lhs] + nums[rhs] == target;
            });
    return {static_cast<ValueType>(*left), static_cast<ValueType>(*right)};
}

} // namespace akarithm
