#pragma once

#include <numeric>
#include <vector>
#include <array>
#include <unordered_map>

namespace akarithm
{

template <
    typename Iterator,
    typename ValueTy =
        typename std::iterator_traits<Iterator>::value_type,
    typename CounterTy = int,
    std::size_t DivisorValue = 60>
static constexpr auto
numPairsDivisibleBy60(
    const Iterator begin,
    const Iterator end)
    -> CounterTy
{
    using IndexTy =
        typename std::array<CounterTy, DivisorValue>::size_type;
    using MapTy =
        typename std::array<CounterTy, DivisorValue>;
    using PairTy =
        typename std::pair<CounterTy, MapTy>;
    return std::accumulate(
               begin, end,
               PairTy{0, {0}},
               [](PairTy &acc, const ValueTy &v)
                   -> PairTy {
                   const IndexTy x_contribution = static_cast<IndexTy>(v % DivisorValue);
                   const IndexTy x_need = (DivisorValue - x_contribution) % 60;
                   acc.first += acc.second[x_need];
                   acc.second[x_contribution]++;
                   return acc;
               })
        .first;
}

// NOTE :: This is a pretty bad algorithm that is O(n^2)
template <
    typename ValueTy,
    typename CounterTy>
static constexpr auto
numPairsDivisibleBy60_O2(
    const std::vector<int> &time)
    -> CounterTy
{
    CounterTy counter = 0;
    for (std::size_t iter1 = 0; iter1 < time.size(); iter1++)
    {
        for (std::size_t iter = iter1 + 1; iter < time.size(); iter++)
        {
            if (((time[iter] + time[iter1]) % 60) == 0)
                counter++;
        }
    }
    return counter;
}

} // namespace akarithm
