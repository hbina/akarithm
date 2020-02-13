#pragma once

#include <map>
#include <algorithm>
#include <iterator>

namespace akarithm
{

template <
    typename IterTy,
    typename CounterTy = int,
    typename ValueTy =
        typename std::iterator_traits<IterTy>::value_type,
    typename MapTy = std::map<ValueTy, CounterTy>>
static constexpr auto
into_frequency_map(
    IterTy begin,
    IterTy end)
    -> MapTy
{
    MapTy result;
    std::for_each(
        begin,
        end,
        [&](const ValueTy &v) {
            result[v]++;
        });
    return result;
}

} // namespace akarithm
