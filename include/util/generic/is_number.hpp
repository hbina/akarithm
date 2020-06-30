#pragma once

#include <algorithm>
#include <iterator>
#include <string>
#include <type_traits>

namespace aka {

template<typename IterTy>
static constexpr bool
is_number(IterTy iter_begin, IterTy iter_end)
{
  using ValueTy = typename std::iterator_traits<IterTy>::value_type;

  return std::distance(iter_begin, iter_end) != 0 &&
         std::find_if(iter_begin, iter_end, [](const ValueTy& c) {
           return !std::isdigit(c);
         }) == iter_end;
}

} // namespace akarithm
