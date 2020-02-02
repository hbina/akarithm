#pragma once

#include <iterator>
#include <numeric>

namespace util
{
namespace generic
{

template <
    typename OutputIteratorType,
    typename Iterator,
    typename BinaryPredicate>
static constexpr OutputIteratorType
group_by_minify(
    Iterator iter_begin,
    Iterator iter_end,
    const BinaryPredicate &pred)
{
    using T = typename std::iterator_traits<Iterator>::value_type;
    return std::accumulate(
        std::next(iter_begin),
        iter_end,
        OutputIteratorType{std::make_pair(*iter_begin, 1)},
        [&](OutputIteratorType &acc,
            const T &rhs)
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

} // namespace generic
} // namespace util
