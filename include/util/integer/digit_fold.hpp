#pragma once

#include <type_traits>

namespace akarithm {

template<typename F,
         typename IntTy = int,
         typename = typename std::enable_if_t<std::is_integral_v<IntTy>>>
static constexpr auto
digit_fold(IntTy a, IntTy acc, const F& f) -> IntTy
{
  while (a != 0) {
    IntTy digit = a % 10;
    acc = f(acc, digit);
    a /= 10;
  }
  return acc;
}

} // namespace akarithm
