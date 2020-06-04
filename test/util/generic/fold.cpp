#include <doctest/doctest.h>

#include "util/generic/fold.hpp"

#include <vector>

TEST_CASE("akarithm::fold 1")
{
  const std::vector<int> input = { 1, 2, 3, 4, 5 };
  const int expected = 15;
  const int result =
    akarithm::fold(std::cbegin(input), std::cend(input), std::plus{});
  CHECK(expected == result);
}