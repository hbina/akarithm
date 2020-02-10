#pragma once

#include <vector>

namespace util
{
namespace generic
{

template <
    typename IterTy,
    typename IntTy,
    typename ReturnTy = typename std::vector<
        typename std::vector<IntTy>>>
static constexpr void
two_sum(
    IterTy iter_begin,
    IterTy iter_end,
    const IntTy &target,
    ReturnTy &result)
{
}

template <
    typename IterTy,
    typename IntTy,
    typename ReturnTy = typename std::vector<
        typename std::vector<IntTy>>>
static constexpr auto
n_sum(
    IterTy iter_begin,
    IterTy iter_end,
    const IntTy &target,
    const IntTy &n,
    ReturnTy &result)
    -> ReturnTy
{
    if (target == 1)
    {
        std::for_each(
            iter_begin,
            iter_end,
            [&](const IntTy &value) {
                if (value == target)
                    result.push_back({value});
            });
    }
    else if (target == 2)
    {
        return two_sum(iter_begin, iter_end, target, result);
    }
    else
    {
        while (std::distance(iter_begin, iter_end) >= n)
        {
            n_sum(std::next(iter_begin),
                  iter_end,
                  target - *iter_begin,
                  n - 1,
                  result);
        }
    }
}

} // namespace generic
} // namespace util
