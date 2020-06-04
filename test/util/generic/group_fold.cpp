#include "doctest/doctest.h"

#include "util/generic/group_fold.hpp"

#include <list>
#include <string>
#include <vector>

TEST_CASE("akarithm::group_fold 1")
{
  const std::vector<int> input = { 1, 1, 2, 4, 6, 5, 7 };
  const std::vector<int> expected = { 2, 12, 12 };
  const std::vector<int> result = akarithm::group_fold(
    input.cbegin(),
    input.cend(),
    [](const int& lhs, const int& rhs) -> bool {
      return (lhs % 2) == (rhs % 2);
    },
    [](const std::vector<int>& group) -> int {
      return std::accumulate(std::cbegin(group), std::cend(group), 0);
    });
  CHECK(expected == result);
}
