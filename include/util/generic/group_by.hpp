#pragma once

#include <iterator>
#include <numeric>
#include <vector>

namespace aka {

template<typename IterTy,
         typename BinaryPredicate,
         typename ValueTy = typename std::iterator_traits<IterTy>::value_type,
         typename GroupTy = typename std::vector<ValueTy>,
         typename ReturnTy = typename std::vector<GroupTy>>
static constexpr auto
group_by(IterTy iter_begin, IterTy iter_end, const BinaryPredicate& pred)
  -> ReturnTy
{
  if (iter_begin == iter_end) {
    return {};
  }

  ReturnTy result = {};

  GroupTy group = {};
  group.emplace_back(*iter_begin);

  result.emplace_back(group);
  iter_begin = std::next(iter_begin);

  while (iter_begin != iter_end) {
    if (pred(result.back().back(), *iter_begin)) {
      result.back().emplace_back(*iter_begin);
    } else {
      GroupTy group = {};
      group.emplace_back(*iter_begin);
      result.emplace_back(group);
    }
    iter_begin = std::next(iter_begin);
  }
  return result;
}

} // namespace akarithm
