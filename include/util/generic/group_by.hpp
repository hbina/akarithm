#pragma once

#include <iterator>
#include <numeric>
#include <vector>

namespace akarithm
{

template <
    typename GroupType,
    typename IterTy,
    typename BinaryPredicate,
    typename ValueTy =
        typename std::iterator_traits<IterTy>::value_type,
    typename = std::enable_if_t<
        std::is_same_v<ValueTy,
                       typename GroupType::value_type>>>
static constexpr auto
group_by(
    IterTy iter_begin,
    IterTy iter_end,
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
            const ValueTy &rhs)
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

} // namespace akarithm
