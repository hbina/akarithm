#include "doctest/doctest.h"

#include "util/generic/zip_fold.hpp"

#include <functional>
#include <list>
#include <vector>

TEST_CASE("zip accumulate 1")
{
  const std::vector<int> input_1 = { 1, 2, 3, 4, 5 };
  const std::vector<int> input_2 = { 1, 2, 3, 4, 5 };
  const int expected = 55;
  const int result = akarithm::zip_fold(std::cbegin(input_1),
                                        std::cend(input_1),
                                        std::cbegin(input_2),
                                        std::cend(input_2),
                                        0,
                                        std::multiplies{},
                                        std::plus{});
  CHECK(expected == result);
}

TEST_CASE("zip accumulate 2")
{
  const std::vector<int> input_1 = { 1, 2, 3, 4, 5 };
  const std::vector<int> input_2 = { 1, 2, 3, 4, 5 };
  const bool expected = true;
  const bool result = akarithm::zip_fold(std::cbegin(input_1),
                                         std::cend(input_1),
                                         std::cbegin(input_2),
                                         std::cend(input_2),
                                         true,
                                         std::equal_to{},
                                         std::logical_and{});
  CHECK(expected == result);
}

TEST_CASE("zip accumulate 3")
{
  const std::list<int> input_1 = { 1, 2, 3, 4, 5 };
  const std::list<int> input_2 = { 1, 2, 3, 4, 5 };
  const bool expected = true;
  const bool result = akarithm::zip_fold(std::cbegin(input_1),
                                         std::cend(input_1),
                                         std::cbegin(input_2),
                                         std::cend(input_2),
                                         true,
                                         std::equal_to{},
                                         std::logical_and{});
  CHECK(expected == result);
}
