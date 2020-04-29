#include "doctest/doctest.h"

#include "util/generic/quicksort.hpp"

#include <vector>

TEST_CASE("fuck u 1")
{
  std::vector<int> input = { 6, 5, 4, 3, 2, 1 };
  const std::vector<int> expected = { 1, 2, 3, 4, 5, 6 };
  akarithm::quicksort(std::begin(input), std::end(input));
  // CHECK(input == expected);
}