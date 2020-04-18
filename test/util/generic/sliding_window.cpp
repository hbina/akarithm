#include "doctest/doctest.h"

#include "util/generic/sliding_window.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

TEST_CASE("sliding window 1 -- sum pair")
{
  std::vector<int> input_1 = { 8, 3, 2, 1, 22, 6, 7, 8, 55, 5, 13 };
  const int input_2 = 11;
  std::sort(std::begin(input_1), std::end(input_1));
  const auto [left, right] = akarithm::sliding_window(
    std::cbegin(input_1),
    std::cend(input_1),
    [&](const int lhs, const int rhs) -> bool { return lhs + rhs < input_2; },
    [&](const int lhs, const int rhs) -> bool { return lhs + rhs == input_2; });
  CHECK(input_2 == (*left + *right));
}
