#include "doctest/doctest.h"

#include "util/string/group_by.hpp"

#include <list>
#include <string>
#include <vector>

TEST_CASE("akarithm::group_by 4")
{
  const std::string input = "123123hello3213213world";
  const std::vector<std::string> expected = {
    "123123", "hello", "3213213", "world"
  };
  const auto result = akarithm::string::group_by(
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
  const auto result = akarithm::string::group_by(
    input.cbegin(),
    input.cend(),
    [](const std::string& lhs, const auto& rhs) -> bool {
      return std::isalpha(lhs.back()) == std::isalpha(rhs);
    });
  CHECK(expected == result);
}
