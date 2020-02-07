#pragma once

#include <type_traits>
#include <algorithm>
#include <numeric>
#include <map>
#include <array>
#include <cmath>
#include <vector>

namespace akarithm
{

//  TODO    ::  There ought to be a way to make this WAY more generic.
//  TODO    ::  This algorithm can be improved further by employing std::set
//              as the container for DP.
template <
    typename IntTy = std::size_t,
    typename = std::enable_if_t<std::is_integral_v<IntTy>>>
static constexpr auto
nthUglyNumber(const IntTy &n)
    -> IntTy
{
    if (n == 0)
        return 0;

    using TupleTy = typename std::array<IntTy, 3>;
    using TupleIndexTy = typename TupleTy::size_type;
    using DpTy = typename std::map<IntTy, TupleTy>;
    using DpIndexTy = typename DpTy::size_type;

    auto evaluate_tuple = [](const TupleTy &tuple)
        -> IntTy {
        auto pow2 = std::pow(2, tuple[0]);
        auto pow3 = std::pow(3, tuple[1]);
        auto pow5 = std::pow(5, tuple[2]);
        return static_cast<IntTy>(pow2 * pow3 * pow5);
    };

    auto find_lowest = [](const DpTy &dp) {
        return std::min_element(
            std::begin(dp), std::end(dp),
            [&](const auto &lhs, const auto &rhs)
                -> bool {
                return lhs.first < rhs.first;
            });
    };

    DpTy dp;
    dp.emplace(std::make_pair(
        evaluate_tuple({0, 0, 0}),
        TupleTy{0, 0, 0}));
    for (DpIndexTy iter = 1; iter != static_cast<DpIndexTy>(n); iter++)
    {
        // Find the lowest evaluation
        auto min = find_lowest(dp);
        auto [a, b, c] = min->second;
        // Create the next generation
        dp.emplace(std::make_pair(
            evaluate_tuple({a + 1, b, c}),
            TupleTy{a + 1, b, c}));
        dp.emplace(std::make_pair(
            evaluate_tuple({a, b + 1, c}),
            TupleTy{a, b + 1, c}));
        dp.emplace(std::make_pair(
            evaluate_tuple({a, b, c + 1}),
            TupleTy{a, b, c + 1}));
        // Remove the lowest one from the dp
        dp.erase(min);
    }

    return find_lowest(dp)->first;
}

} // namespace akarithm
