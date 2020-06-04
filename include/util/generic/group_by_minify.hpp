#pragma once

#include "util/generic/group_fold.hpp"

#include <iterator>
#include <numeric>
#include <vector>

namespace akarithm {

// NOTE: This is actually just a special case of `group_fold`.
// FIXME: Reimplement this to not use accumulate.
// This shit is too much.
template<typename CounterTy = std::size_t,
         typename IterTy,
         typename BinaryPredicate,
         typename ValueTy = typename std::iterator_traits<IterTy>::value_type,
         typename ReturnTy =
           typename std::vector<typename std::pair<ValueTy, CounterTy>>>
static constexpr auto
group_by_minify(IterTy iter_begin, IterTy iter_end, const BinaryPredicate& pred)
  -> ReturnTy
{
  return akarithm::group_fold(
    iter_begin,
    iter_end,
    [&](const ValueTy& lhs, const ValueTy& rhs) -> bool {
      return pred(lhs, rhs);
    },
    [](const std::vector<ValueTy>& group) -> std::pair<ValueTy, std::size_t> {
      return std::make_pair(group.front(), std::size(group));
    });
}

} // namespace akarithm
