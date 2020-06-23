#include <doctest/doctest.h>

#include "util/generic/fold_each_n.hpp"

#include <vector>

TEST_CASE("fold_each_n 1")
{
  const std::vector<int> input = { 1, 1, 2, 2, 3, 3, 4, 4 };
  const std::vector<int> expected = { 2, 4, 6, 8 };
  const std::vector<int> result = akarithm::fold_each_n<2>(
    std::cbegin(input),
    std::cend(input),
    std::vector<int>{},
    [](std::vector<int> acc, const int& lhs, const int& rhs) {
      acc.emplace_back(lhs + rhs);
      return acc;
    });
  CHECK(expected == result);
}

TEST_CASE("fold_each_n 2")
{
  const std::vector<int> input = { 1, 1, 2, 2, 3, 3, 4, 4 };
  const std::vector<int> expected = { 1, 2, 2, 3, 3, 3, 4, 4, 4, 4 };
  const std::vector<int> result = akarithm::fold_each_n<2>(
    std::cbegin(input),
    std::cend(input),
    std::vector<int>{},
    [](std::vector<int> acc, const int& lhs, const int& rhs) {
      for (int i = 0; i < rhs; i++) {
        acc.emplace_back(lhs);
      }
      return acc;
    });
  CHECK(expected == result);
}
