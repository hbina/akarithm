#pragma once

#include <iterator>
#include <numeric>
#include <vector>

namespace util
{
namespace generic
{

template <
    typename GroupType,
    typename Iterator,
    typename BinaryPredicate,
    typename T = typename std::iterator_traits<Iterator>::value_type,
    typename = std::enable_if_t<
        std::is_same_v<T,
                       typename GroupType::value_type>>>
static constexpr auto
group_by(
    Iterator iter_begin,
    Iterator iter_end,
    const BinaryPredicate &pred)
    -> std::vector<GroupType>
{
    std::vector<GroupType> result;
    result.push_back(GroupType{*iter_begin});
    return std::move(std::accumulate(
        std::next(iter_begin),
        iter_end,
        result,
        [&](std::vector<GroupType> &acc,
            const T &rhs)
            -> std::vector<GroupType> {
            if (pred(acc.back(), rhs))
            {
                acc.back().push_back(rhs);
            }
            else
            {
                acc.push_back(GroupType{rhs});
            }
            return acc;
        }));
}

} // namespace generic
} // namespace util
