#pragma once

#include <type_traits>
#include <algorithm>
#include <numeric>
#include <vector>
#include <array>
#include <cmath>

namespace akarithm
{

//  TODO    ::  There ought to be a way to make this WAY more generic.
//  TODO    ::  This algorithm can be improved further by employing std::set
//              as the container for DP.
template <
    typename IntType,
    typename = std::enable_if_t<std::is_integral_v<IntType>>>
static constexpr auto
nthUglyNumber(const IntType &n)
    -> IntType
{
    if (n == 0)
        return 0;

    using TupleType = typename std::array<IntType, 3>;
    using DpType = typename std::vector<TupleType>;
    using IndexType = typename DpType::size_type;

    auto evaluate_tuple = [](const TupleType &tuple)
        -> IntType {
        auto pow2 = std::pow(2, tuple[0]);
        auto pow3 = std::pow(3, tuple[1]);
        auto pow5 = std::pow(5, tuple[2]);
        return static_cast<IntType>(pow2 * pow3 * pow5);
    };

    DpType dp(n);
    for (IndexType iter = 1; iter != dp.size(); iter++)
    {
        TupleType next_step = dp[iter - 1];
        next_step[0]++;
        next_step[1]++;
        next_step[2]++;

        for (IndexType iter2 = 0; iter2 != iter; iter2++)
        {
            for (IndexType iter3 = 0; iter3 != 3; iter3++)
            {
                TupleType test_tuple = dp[iter2];
                test_tuple[iter3]++;
                if (evaluate_tuple(test_tuple) > evaluate_tuple(dp[iter - 1]) && evaluate_tuple(test_tuple) < evaluate_tuple(next_step))
                    next_step = test_tuple;
            }
        }
        dp[iter] = next_step;
    }

    return evaluate_tuple(dp.back());
}

} // namespace akarithm
