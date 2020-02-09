#pragma once

#include <iterator>
#include <algorithm>

namespace akarithm
{

template <
    typename Iterable,
    typename ValueTy =
        typename std::iterator_traits<
        typename Iterable::iterator>::value_type>
static constexpr ValueTy
maxProfit_Sum(const Iterable &prices)
{
    ValueTy acc = ValueTy{};
    auto range = std::cbegin(prices);
    do
    {
        auto range_begin = range;
        range = std::is_sorted_until(
            range,
            std::cend(prices),
            [](const auto &lhs, const auto &rhs) -> bool {
                return lhs < rhs;
            });
        auto [min, max] = std::minmax_element(range_begin, range);
        if (min != max)
        {
            acc += *max - *min;
        }

    } while (range != std::cend(prices));
    return acc;
}

} // namespace akarithm
