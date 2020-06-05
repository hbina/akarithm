#include <doctest/doctest.h>

#include "math/series/harmonic_series.hpp"

TEST_CASE("akarithm::math::series::harmonic_series 1")
{
  const int input = 3;
  const double expected = 1.8333333333333333;
  const auto result = akarithm::harmonic_series(input);
  CHECK(result == expected);
}
