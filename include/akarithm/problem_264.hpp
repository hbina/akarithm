#pragma once

#include <type_traits>
#include <algorithm>
#include <numeric>
#include <set>
#include <array>
#include <cmath>
#include <vector>

namespace akarithm
{

//  TODO    ::  There ought to be a way to make this WAY more generic.
//  TODO    ::  This algorithm can be improved further by employing std::set
//              as the container for DP.
template <
    typename IntTy,
    typename = std::enable_if_t<std::is_integral_v<IntTy>>>
static constexpr auto
nthUglyNumber(const IntTy &n)
    -> IntTy
{
    if (n == 0)
        return 0;

    using TupleTy = typename std::array<IntTy, 3>;
    using TupleIndexTy = typename TupleTy::size_type;
    using DpTy = typename std::set<TupleTy>;
    using DpIndexTy = typename DpTy::size_type;

    auto evaluate_tuple = [](const TupleTy &tuple)
        -> IntTy {
        auto pow2 = std::pow(2, tuple[0]);
        auto pow3 = std::pow(3, tuple[1]);
        auto pow5 = std::pow(5, tuple[2]);
        return static_cast<IntTy>(pow2 * pow3 * pow5);
    };

    DpTy dp = {{0, 0, 0}};
    for (DpIndexTy iter = 1; iter != static_cast<DpIndexTy>(n); iter++)
    {
        // Push all possible combinations into the dp
        std::vector<TupleTy> tmp;
        tmp.reserve(dp.size() * 3);
        for (const auto &[a, b, c] : dp)
        {
            tmp.push_back({a + 1, b, c});
            tmp.push_back({a, b + 1, c});
            tmp.push_back({a, b, c + 1});
        }
        tmp.reserve(tmp.size());
        for (const TupleTy &t : tmp)
            dp.emplace(t);

        // Find the lowest evaluation
        auto min =
            std::min_element(
                std::begin(dp), std::end(dp),
                [&](const TupleTy &lhs, const TupleTy &rhs)
                    -> bool {
                    return evaluate_tuple(lhs) < evaluate_tuple(rhs);
                });

        // Remove the lowest one from the dp
        dp.erase(min);
    }

    return evaluate_tuple(*std::min_element(
        std::begin(dp), std::end(dp),
        [&](const TupleTy &lhs, const TupleTy &rhs)
            -> bool {
            return evaluate_tuple(lhs) < evaluate_tuple(rhs);
        }));
}

} // namespace akarithm
