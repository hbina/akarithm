#pragma once

#include "util/generic/group_by_minify.hpp"

#include <map>
#include <array>
#include <algorithm>
#include <functional>

namespace akarithm
{

// TODO ::  This algorithm is really slow...
template <
    typename IterTy,
    typename ValueTy =
        typename std::iterator_traits<IterTy>::value_type,
    typename CounterTy = std::size_t>
static constexpr auto
minSetSize(
    IterTy iter_begin,
    IterTy iter_end)
    -> ValueTy
{
    using PairTy = std::pair<ValueTy, CounterTy>;
    std::vector<ValueTy> arr;
    std::copy(iter_begin, iter_end, std::back_inserter(arr));
    std::sort(std::begin(arr), std::end(arr));
    auto tmp =
        akarithm::group_by_minify<std::vector<PairTy>>(
            std::cbegin(arr),
            std::cend(arr),
            std::equal_to{});
    std::sort(
        std::begin(tmp),
        std::end(tmp),
        [](const PairTy &lhs,
           const PairTy &rhs) -> bool {
            return lhs.second < rhs.second;
        });
    ValueTy acc = {};
    return static_cast<ValueTy>(std::count_if(
        std::cbegin(tmp),
        std::cend(tmp),
        [&](const auto &value)
            -> bool {
            acc += static_cast<ValueTy>(value.second);
            return acc > static_cast<ValueTy>(arr.size() / 2);
        }));
}
} // namespace akarithm
