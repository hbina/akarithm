#include <doctest/doctest.h>

#include "util/generic/map.hpp"
#include "util/generic/zip.hpp"

#include <unordered_map>
#include <vector>

TEST_CASE("aka::map 1")
{
  const std::vector<std::pair<int, int>> input = { { 1, 2 },
                                                   { 3, 4 },
                                                   { 5, 6 } };
  const std::vector<int> result = aka::map<std::vector<int>>(
    std::cbegin(input), std::cend(input), [](const std::pair<int, int>& value) {
      return value.first * value.second;
    });
  aka::zip(std::cbegin(input),
                std::cend(input),
                std::cbegin(result),
                std::cend(result),
                [](const std::pair<int, int>& lhs, const int& rhs) {
                  CHECK(lhs.first * lhs.second == rhs);
                });
}
