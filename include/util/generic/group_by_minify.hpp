#pragma once

#include <iterator>
#include <numeric>
#include <vector>

namespace akarithm
{

template <
    typename CounterTy = std::size_t,
    typename IterTy,
    typename BinaryPredicate,
    typename ValueTy =
        typename std::iterator_traits<IterTy>::value_type,
    typename ReturnTy =
        typename std::vector<
            typename std::pair<ValueTy, CounterTy>>>
static constexpr auto
group_by_minify(
    IterTy iter_begin,
    IterTy iter_end,
    const BinaryPredicate &pred)
    -> ReturnTy
{
    if (iter_begin == iter_end)
        return {};
    return std::accumulate(
        std::next(iter_begin),
        iter_end,
        ReturnTy{std::pair{*iter_begin, 1}},
        [&](ReturnTy &acc,
            const ValueTy &rhs)
            -> ReturnTy {
            if (pred(acc.back().first, rhs))
                acc.back().second++;
            else
                acc.emplace_back(rhs, 1);
            return acc;
        });
}

} // namespace akarithm
