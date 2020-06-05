#pragma once

#include <cstddef>

namespace akarithm {

template<typename IntTy = std::size_t, typename ResultTy = double>
static constexpr auto
harmonic_series(const IntTy& iteration) -> ResultTy
{
  IntTy i = {};
  ResultTy result = {};
  while (i != iteration) {
    result += static_cast<ResultTy>(1) /
              (static_cast<ResultTy>(1) + static_cast<ResultTy>(i));
    i++;
  }
  return result;
}

}
