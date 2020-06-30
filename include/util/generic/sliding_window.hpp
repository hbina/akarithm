#pragma once

#include <functional>
#include <iterator>
#include <tuple>

namespace aka {

template<typename IterTy,
         typename DecisionFunction,
         typename FoundFunction,
         typename ValueTy = typename std::iterator_traits<IterTy>::value_type>
static constexpr auto
sliding_window(IterTy begin,
               IterTy end,
               const DecisionFunction& decision,
               const FoundFunction& found) -> std::pair<IterTy, IterTy>
{
  IterTy end_c = end;
  --end;
  while (begin != end) {
    if (found(*begin, *end))
      return { begin, end };
    else {
      if (decision(*begin, *end))
        ++begin;
      else
        --end;
    }
  }
  return { end_c, end_c };
}

} // namespace akarithm
