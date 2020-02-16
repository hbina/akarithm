#pragma once

#include <array>
#include <vector>
#include <algorithm>
#include <numeric>

namespace akarithm
{

template <
    typename IterTy,
    typename InnerIterTy =
        typename std::iterator_traits<IterTy>::value_type,
    typename ValueTy =
        typename std::iterator_traits<
            typename InnerIterTy::iterator>::value_type>
static constexpr auto
twoCitySchedCost(
    IterTy begin,
    IterTy end)
    -> ValueTy
{
    std::vector<std::array<ValueTy, 2>> transform;
    transform.reserve(std::distance(begin, end));

    std::transform(
        begin, end,
        std::back_inserter(transform),
        [](const InnerIterTy &v)
            -> std::array<ValueTy, 2> {
            return {v[0], v[1]};
        });

    std::nth_element(
        std::begin(transform),
        std::next(
            std::begin(transform),
            transform.size() / 2),
        std::end(transform),
        [](const std::array<ValueTy, 2> &lhs,
           const std::array<ValueTy, 2> &rhs)
            -> bool {
            return lhs[0] - lhs[1] < rhs[0] - rhs[1];
        });

    return std::accumulate(
               std::cbegin(transform),
               std::next(std::cbegin(transform), transform.size() / 2),
               0,
               [](ValueTy &acc, const std::array<ValueTy, 2> &v)
                   -> ValueTy {
                   return acc + v[0];
               }) +
           std::accumulate(
               std::next(std::cbegin(transform), transform.size() / 2),
               std::cend(transform),
               0,
               [](ValueTy &acc, const std::array<ValueTy, 2> &v)
                   -> ValueTy {
                   return acc + v[1];
               });
}

} // namespace akarithm