#include <doctest/doctest.h>

#include "util/generic/zip.hpp"

#include <iostream>
#include <list>
#include <vector>

TEST_CASE("aka::zip test")
{
  const std::vector<int> input_1 = { 0, 1, 2, 3, 4 };
  const std::vector<int> input_2 = { 0, 1, 2, 3, 4 };
  aka::zip(std::cbegin(input_1),
                std::cend(input_1),
                std::cbegin(input_2),
                std::cend(input_2),
                [](const auto& lhs, const auto& rhs) { CHECK(lhs == rhs); });
}

TEST_CASE("aka::zip test")
{
  const std::list<int> input_1 = { 0, 1, 2, 3, 4 };
  const std::list<int> input_2 = { 0, 1, 2, 3, 4 };
  aka::zip(std::cbegin(input_1),
                std::cend(input_1),
                std::cbegin(input_2),
                std::cend(input_2),
                [](const auto& lhs, const auto& rhs) { CHECK(lhs == rhs); });
}
