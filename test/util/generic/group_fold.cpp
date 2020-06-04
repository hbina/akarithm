#include "doctest/doctest.h"

#include "util/generic/fold.hpp"
#include "util/generic/group_fold.hpp"

#include <list>
#include <string>
#include <vector>

/// Groups odd/even elements.
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

/// Returns the original vector by passing in false and identitiy function.
TEST_CASE("akarithm::group_fold 2")
{
  const std::vector<int> input = { 1, 1, 2, 4, 6, 5, 7 };
  const std::vector<int> expected = { 1, 1, 2, 4, 6, 5, 7 };
  const std::vector<int> result = akarithm::group_fold(
    input.cbegin(),
    input.cend(),
    [](const int& lhs, const int& rhs) -> bool { return false; },
    [](const std::vector<int>& group) -> int { return group.back(); });
  CHECK(expected == result);
}

/// Perform a fold by passing in true and fold function.
TEST_CASE("akarithm::group_fold 3")
{
  const std::vector<int> input = { 1, 2, 3 };
  const std::vector<int> expected = { 6 };
  const std::vector<int> result = akarithm::group_fold(
    input.cbegin(),
    input.cend(),
    [](const int& lhs, const int& rhs) -> bool { return true; },
    [](const std::vector<int>& group) -> int {
      return akarithm::fold(std::cbegin(group), std::cend(group), std::plus{});
    });
  CHECK(expected == result);
}
