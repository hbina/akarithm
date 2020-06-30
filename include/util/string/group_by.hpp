#pragma once

#include <algorithm>
#include <iterator>
#include <numeric>
#include <vector>

namespace aka {

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

  ReturnTy result = { std::string{ *iter_begin } };
  std::for_each(std::next(iter_begin), iter_end, [&](const ValueTy& x) {
    if (pred(result.back(), x)) {
      result.back().push_back(x);
    } else {
      result.push_back(std::string{ x });
    }
  });

  return result;
}
}
} // namespace akarithm
