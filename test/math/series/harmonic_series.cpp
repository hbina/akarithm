#include <doctest/doctest.h>

#include "math/series/harmonic_series.hpp"

TEST_CASE("aka::math::series::harmonic_series 1")
{
  const int input = 3;
  const double expected = 1.8333333333333333;
  const auto result = aka::harmonic_series(input);
  CHECK(result == expected);
}
