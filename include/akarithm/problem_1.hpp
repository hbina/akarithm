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
    typename ValueTy = typename std::iterator_traits<
        typename Iterable::iterator>::value_type,
    typename IndexTy =
        typename std::iterator_traits<
            typename Iterable::iterator>::difference_type>
static constexpr auto
twoSum(
    const Iterable &nums,
    const ValueTy &target)
    -> Iterable
{
    // Get the indices and sort based on the value its pointing to
    std::vector<IndexTy> indices;
    indices.resize(nums.size());
    std::iota(std::begin(indices), std::end(indices), 0);
    std::sort(std::begin(indices), std::end(indices),
              [&](const IndexTy &lhs, const IndexTy &rhs)
                  -> bool {
                  return nums[lhs] < nums[rhs];
              });
    // Find the sum pair using sliding window
    auto [left, right] =
        akarithm::sliding_window(
            std::cbegin(indices),
            std::cend(indices),
            [&](const IndexTy &lhs, const IndexTy &rhs)
                -> bool {
                return nums[lhs] + nums[rhs] < target;
            },
            [&](const IndexTy &lhs, const IndexTy &rhs)
                -> bool {
                return nums[lhs] + nums[rhs] == target;
            });
    return {static_cast<ValueTy>(*left), static_cast<ValueTy>(*right)};
}

} // namespace akarithm
