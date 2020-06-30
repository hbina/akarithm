#include <doctest/doctest.h>

#include "util/generic/group_by.hpp"

#include <list>
#include <string>
#include <vector>

TEST_CASE("aka::group_by 1")
{
  const std::vector<int> input = { 1, 1, 2, 4, 6, 5, 7 };
  const std::vector<std::vector<int>> expected = { { 1, 1 },
                                                   { 2, 4, 6 },
                                                   { 5, 7 } };
  const auto result = aka::group_by(
    input.cbegin(), input.cend(), [](const int& lhs, const int& rhs) -> bool {
      return (lhs % 2) == (rhs % 2);
    });
  CHECK(expected == result);
}
