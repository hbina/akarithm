#pragma once

#include <iterator>
#include <numeric>
#include <vector>

namespace akarithm
{

template <
    typename GroupTy,
    typename IterTy,
    typename BinaryPredicate,
    typename ValueTy =
        typename std::iterator_traits<IterTy>::value_type,
    typename = std::enable_if_t<
        std::is_same_v<ValueTy,
                       typename GroupTy::value_type>>>
static constexpr auto
group_by(
    IterTy iter_begin,
    IterTy iter_end,
    const BinaryPredicate &pred)
    -> std::vector<GroupTy>
{
    if (iter_begin == iter_end)
        return {};
    std::vector<GroupTy> result;
    result.push_back(GroupTy{*iter_begin});
    return std::move(std::accumulate(
        std::next(iter_begin),
        iter_end,
        result,
        [&](std::vector<GroupTy> &acc,
            const ValueTy &rhs)
            -> std::vector<GroupTy> {
            if (pred(acc.back(), rhs))
            {
                acc.back().push_back(rhs);
            }
            else
            {
                acc.push_back(GroupTy{rhs});
            }
            return acc;
        }));
}

} // namespace akarithm
