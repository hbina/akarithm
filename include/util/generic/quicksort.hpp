#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>

namespace akarithm {

template<typename IterTy>
static constexpr auto
get_last_element(IterTy begin, IterTy end) -> IterTy
{
  while (std::next(begin) != end) {
    begin = std::next(begin);
  }
  return begin;
}

template<typename IterTy, typename CompFn>
static constexpr void
quicksort_InsideImplementation(IterTy begin, IterTy end, CompFn f)
{
  using ValueTy = typename std::iterator_traits<IterTy>::value_type;
  std::cout << "hello?" << std::endl;
  if (begin != end) {
    auto last = get_last_element(begin, end);
    auto p =
      std::partition(begin, end, [&](const ValueTy& x) { return x < *last; });
    akarithm::quicksort_InsideImplementation(begin, p, f);
    akarithm::quicksort_InsideImplementation(p, end, f);
  }
}

template<typename IterTy, typename CompFn>
static constexpr void
quicksort(IterTy begin, IterTy end, CompFn f)
{
  akarithm::quicksort_InsideImplementation(begin, end, f);
}

template<typename IterTy>
static constexpr void
quicksort(IterTy begin, IterTy end)
{
  akarithm::quicksort_InsideImplementation(begin, end, std::less{});
}

}
