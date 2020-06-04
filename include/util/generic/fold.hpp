#pragma once

#include <functional>
#include <type_traits>

namespace akarithm {

template<typename OutputType, typename IterTy, typename AddFunction>
static constexpr auto
fold(IterTy iter_lhs_begin,
     IterTy iter_lhs_end,
     OutputType acc,
     const AddFunction& add) -> OutputType
{
  while (iter_lhs_begin != iter_lhs_end) {
    acc = add(acc, *iter_lhs_begin);
    iter_lhs_begin++;
  }
  return acc;
}

template<typename IterTy,
         typename AddFunction,
         typename OutputType = typename std::invoke_result_t<
           AddFunction,
           typename std::iterator_traits<IterTy>::value_type,
           typename std::iterator_traits<IterTy>::value_type>>
static constexpr auto
fold(IterTy iter_lhs_begin, IterTy iter_lhs_end, const AddFunction& add)
  -> OutputType
{
  OutputType acc = {};
  while (iter_lhs_begin != iter_lhs_end) {
    acc = add(acc, *iter_lhs_begin);
    iter_lhs_begin++;
  }
  return acc;
}

} // namespace akarithm
