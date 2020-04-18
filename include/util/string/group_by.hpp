#pragma once

#include <iterator>
#include <numeric>
#include <vector>

namespace akarithm {

namespace string {

template<typename IterTy,
         typename BinaryPredicate,
         typename ValueTy = typename std::iterator_traits<IterTy>::value_type,
         typename ReturnTy = typename std::vector<typename std::string>>
static constexpr auto
group_by(IterTy iter_begin, IterTy iter_end, const BinaryPredicate& pred)
  -> ReturnTy
{
  if (iter_begin == iter_end)
    return {};
  return std::accumulate(std::next(iter_begin),
                         iter_end,
                         ReturnTy{ std::string{ *iter_begin } },
                         [&](ReturnTy& acc, const ValueTy& rhs) -> ReturnTy {
                           if (pred(acc.back(), rhs)) {
                             acc.back().push_back(rhs);
                           } else {
                             acc.push_back(std::string{ rhs });
                           }
                           return acc;
                         });
}
}
} // namespace akarithm
