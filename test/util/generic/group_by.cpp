#include "doctest/doctest.h"

#include "util/generic/group_by.hpp"

#include <list>
#include <string>
#include <vector>

TEST_CASE("akarithm::group_by 1")
{
  const std::vector<int> input = { 1, 1, 2, 4, 6, 5, 7 };
  const std::vector<std::vector<int>> expected = { { 1, 1 },
                                                   { 2, 4, 6 },
                                                   { 5, 7 } };
  const auto result = akarithm::group_by<std::vector<int>>(
    input.cbegin(),
    input.cend(),
    [](const std::vector<int>& lhs, const int& rhs) -> bool {
      return (lhs.back() % 2) == (rhs % 2);
    });
  CHECK(expected == result);
}

TEST_CASE("akarithm::group_by 1 as list")
{
  const std::vector<int> input = { 1, 1, 2, 4, 6, 5, 7 };
  const std::vector<std::list<int>> expected = { { 1, 1 },
                                                 { 2, 4, 6 },
                                                 { 5, 7 } };
  const auto result = akarithm::group_by<std::list<int>>(
    input.cbegin(),
    input.cend(),
    [](const std::list<int>& lhs, const int& rhs) -> bool {
      return (lhs.back() % 2) == (rhs % 2);
    });
  CHECK(expected == result);
}

TEST_CASE("akarithm::group_by 2")
{
  const std::list<int> input = { 1, 1, 2, 4, 6, 5, 7 };
  const std::vector<std::list<int>> expected = { { 1, 1 },
                                                 { 2, 4, 6 },
                                                 { 5, 7 } };
  const auto result = akarithm::group_by<std::list<int>>(
    input.cbegin(),
    input.cend(),
    [](const std::list<int>& lhs, const int& rhs) -> bool {
      return (lhs.back() % 2) == (rhs % 2);
    });
  CHECK(expected == result);
}

TEST_CASE("akarithm::group_by 3")
{
  const std::list<int> input = { 1, 1, 2, 4, 6, 5, 7 };
  const std::vector<std::list<int>> expected = { { 1, 1 },
                                                 { 2, 4, 6 },
                                                 { 5, 7 } };
  const auto result = akarithm::group_by<std::list<int>>(
    input.cbegin(),
    input.cend(),
    [](const std::list<int>& lhs, const int& rhs) -> bool {
      return (lhs.back() % 2) == (rhs % 2);
    });
  CHECK(expected == result);
}

TEST_CASE("akarithm::group_by 4")
{
  const std::string input = "123123hello3213213world";
  const std::vector<std::string> expected = {
    "123123", "hello", "3213213", "world"
  };
  const auto result = akarithm::group_by<std::string>(
    input.cbegin(),
    input.cend(),
    [](const std::string& lhs, const auto& rhs) -> bool {
      return std::isalpha(lhs.back()) == std::isalpha(rhs);
    });
  CHECK(expected == result);
}

TEST_CASE("akarithm::group_by 5")
{
  const std::string input = "hh123123hello3213213world33";
  const std::vector<std::string> expected = { "hh",      "123123", "hello",
                                              "3213213", "world",  "33" };
  const auto result = akarithm::group_by<std::string>(
    input.cbegin(),
    input.cend(),
    [](const std::string& lhs, const auto& rhs) -> bool {
      return std::isalpha(lhs.back()) == std::isalpha(rhs);
    });
  CHECK(expected == result);
}
