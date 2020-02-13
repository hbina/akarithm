#pragma once

#include "util/generic/iter_to_set.hpp"

#include <map>
#include <algorithm>
#include <numeric>

namespace akarithm
{

template <
    typename StringTy,
    typename CounterTy = int,
    typename CharTy =
        typename StringTy::value_type>
static constexpr auto
minSteps(
    const StringTy &s,
    const StringTy &t)
    -> CounterTy
{
    auto set_s = akarithm::into_frequency_map(
        std::cbegin(s),
        std::cend(s));
    auto set_t = akarithm::into_frequency_map(
        std::cbegin(t),
        std::cend(t));
    decltype(set_s) set_r;
    std::set_difference(
        std::cbegin(set_s), std::cend(set_s),
        std::cbegin(set_t), std::cend(set_t),
        std::inserter(set_r, std::end(set_r)),
        [](const auto &lhs, const auto &rhs)
            -> bool {
            return lhs.first < rhs.first;
        });
    return std::accumulate(
        std::cbegin(set_r), std::cend(set_r),
        0,
        [](CounterTy acc, const auto &v)
            -> CounterTy {
            return acc += v.second;
        });
}

} // namespace akarithm
