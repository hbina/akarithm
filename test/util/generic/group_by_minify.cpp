#include <doctest/doctest.h>

#include "util/generic/group_by_minify.hpp"

#include <list>
#include <string>
#include <vector>

using CharTy = typename std::string::value_type;

TEST_CASE("aka::group_by_minify 1")
{
  const std::vector<int> input = { 1, 1, 2, 4, 6, 5, 7 };
  const std::vector<std::pair<int, std::size_t>> expected = { { 1, 2 },
                                                              { 2, 3 },
                                                              { 5, 2 } };
  const auto result = aka::group_by_minify(
    input.cbegin(), input.cend(), [](const int& lhs, const int& rhs) -> bool {
      return (lhs % 2) == (rhs % 2);
    });
  CHECK(expected == result);
}

TEST_CASE("aka::group_by_minify 2")
{
  const std::list<int> input = { 1, 1, 2, 4, 6, 5, 7 };
  const std::vector<std::pair<int, std::size_t>> expected = { { 1, 2 },
                                                              { 2, 3 },
                                                              { 5, 2 } };
  const auto result = aka::group_by_minify(
    input.cbegin(), input.cend(), [](const int& lhs, const int& rhs) -> bool {
      return (lhs % 2) == (rhs % 2);
    });
  CHECK(expected == result);
}

TEST_CASE("aka::group_by_minify 3")
{
  const std::string input = "123123hello3213213world";
  const std::vector<std::pair<CharTy, std::size_t>> expected = {
    { '1', 6 }, { 'h', 5 }, { '3', 7 }, { 'w', 5 }
  };
  const auto result =
    aka::group_by_minify(input.cbegin(),
                              input.cend(),
                              [](const CharTy& lhs, const CharTy& rhs) -> bool {
                                return std::isalpha(lhs) == std::isalpha(rhs);
                              });
  CHECK(expected == result);
}

TEST_CASE("aka::group_by_minify")
{
  const std::string input = "hh123123hello3213213world33";
  const std::vector<std::pair<CharTy, std::size_t>> expected = {
    { 'h', 2 }, { '1', 6 }, { 'h', 5 }, { '3', 7 }, { 'w', 5 }, { '3', 2 }
  };
  const auto result =
    aka::group_by_minify(input.cbegin(),
                              input.cend(),
                              [](const CharTy& lhs, const CharTy& rhs) -> bool {
                                return std::isalpha(lhs) == std::isalpha(rhs);
                              });
  CHECK(expected == result);
}
