#pragma once

#include <iterator>
#include <numeric>
#include <type_traits>
#include <vector>

namespace aka {

template<typename IterTy,
         typename BinaryPredicate,
         typename FoldFunction,
         typename ValueTy = typename std::iterator_traits<IterTy>::value_type,
         typename GroupTy = typename std::vector<ValueTy>,
         typename GroupGroupTy = typename std::vector<GroupTy>,
         typename ResultTy =
           typename std::vector<std::result_of_t<FoldFunction(const GroupTy&)>>>
static constexpr auto
group_fold(IterTy iter_begin,
           IterTy iter_end,
           const BinaryPredicate& pred,
           const FoldFunction& fold) -> ResultTy
{
  if (iter_begin == iter_end) {
    return {};
  }

  GroupGroupTy group_of_groups{};

  GroupTy group{};
  group.emplace_back(*iter_begin);

  group_of_groups.emplace_back(group);
  iter_begin = std::next(iter_begin);

  while (iter_begin != iter_end) {
    if (pred(group_of_groups.back().back(), *iter_begin)) {
      group_of_groups.back().emplace_back(*iter_begin);
    } else {
      GroupTy group{};
      group.emplace_back(*iter_begin);
      group_of_groups.emplace_back(group);
    }
    iter_begin = std::next(iter_begin);
  }

  ResultTy result{};
  result.reserve(group_of_groups.size());

  for (const GroupTy& group : group_of_groups) {
    result.emplace_back(fold(group));
  }

  return result;
}

} // namespace akarithm
