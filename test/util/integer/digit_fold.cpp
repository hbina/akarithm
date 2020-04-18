#include "doctest/doctest.h"

#include <iostream>

#include "util/integer/digit_fold.hpp"

TEST_CASE("util::integer::fold_digit -- sum digits")
{
  const int input = 1234;
  const int result = akarithm::digit_fold(
    input, 0, [](int acc, int x) -> int { return acc + x; });
  const int expected = 10;
  CHECK(expected == result);
}
