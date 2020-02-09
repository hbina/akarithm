#pragma once

#include <iterator>
#include <algorithm>

namespace akarithm
{

template <
    typename Iterable,
    typename DifferenceTy =
        typename std::iterator_traits<
            typename Iterable::const_iterator>::difference_type>
static constexpr auto
removeDuplicates(Iterable &nums)
    -> DifferenceTy
{
    return std::distance(
        std::begin(nums),
        std::unique(
            std::begin(nums),
            std::end(nums)));
}

} // namespace akarithm
