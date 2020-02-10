#pragma once

#include <iterator>
#include <numeric>

namespace akarithm
{

template <
    typename OutputIteratorType,
    typename IterTy,
    typename BinaryPredicate>
static constexpr OutputIteratorType
group_by_minify(
    IterTy iter_begin,
    IterTy iter_end,
    const BinaryPredicate &pred)
{
    using ValueTy =
        typename std::iterator_traits<IterTy>::value_type;
    if (iter_begin == iter_end)
        return {};
    return std::accumulate(
        std::next(iter_begin),
        iter_end,
        OutputIteratorType{std::make_pair(*iter_begin, 1)},
        [&](OutputIteratorType &acc,
            const ValueTy &rhs)
            -> OutputIteratorType {
            if (pred(acc.back().first, rhs))
            {
                acc.back().second++;
            }
            else
            {
                acc.push_back(std::make_pair(rhs, 1));
            }
            return acc;
        });
}

} // namespace akarithm
