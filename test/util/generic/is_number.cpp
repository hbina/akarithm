#include <doctest/doctest.h>

#include "util/generic/is_number.hpp"

#include <vector>

TEST_CASE("aka::is_number")
{
  std::string input = "0123456789";
  bool expected = true;
  bool result = aka::is_number(std::cbegin(input), std::cend(input));
  CHECK(expected == result);
}

TEST_CASE("aka::is_number")
{
  std::string input = "4234234g";
  bool expected = false;
  bool result = aka::is_number(std::cbegin(input), std::cend(input));
  CHECK(expected == result);
}

TEST_CASE("aka::is_number -- using std::vector<char>")
{
  std::vector<char> input = { '1', '2', '3', '4' };
  bool expected = true;
  bool result = aka::is_number(std::cbegin(input), std::cend(input));
  CHECK(expected == result);
}
