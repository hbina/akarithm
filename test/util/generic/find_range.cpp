#include <doctest/doctest.h>

#include "util/generic/find_range.hpp"

#include <vector>
#include <string>

TEST_CASE("find_range 1")
{
  const std::string input_1 = "abcXYZfghijklmnopqrstuvwxyz";
  const std::string input_2 = "XYZ";
  const auto expected = input_1.cbegin() + 3;
  const auto result = aka::find_range(
    input_1.cbegin(), input_1.cend(), input_2.cbegin(), input_2.cend());
  CHECK(expected == result);
}

TEST_CASE("find_range 2")
{
  const std::vector<int> input_1 = { 1, 2, 3, 4, 5, 6 };
  const std::vector<int> input_2 = { 3, 4 };
  const auto expected = input_1.cbegin() + 2;
  const auto result = aka::find_range(
    input_1.cbegin(), input_1.cend(), input_2.cbegin(), input_2.cend());
  CHECK(expected == result);
}

TEST_CASE("find_range 3")
{
  const std::string input_1 = "abcXYZ";
  const std::string input_2 = "XYZ";
  const auto expected = input_1.cbegin() + 3;
  const auto result = aka::find_range(
    input_1.cbegin(), input_1.cend(), input_2.cbegin(), input_2.cend());
  CHECK(expected == result);
}

TEST_CASE("find_range 4")
{
  const std::string input_1 = "XYZ";
  const std::string input_2 = "XYZ";
  const auto expected = input_1.cbegin();
  const auto result = aka::find_range(
    input_1.cbegin(), input_1.cend(), input_2.cbegin(), input_2.cend());
  CHECK(expected == result);
}

TEST_CASE("find_range 5")
{
  const std::string input_1 = "abcXZ";
  const std::string input_2 = "XYZ";
  const auto expected = input_1.cbegin() + 5;
  const auto result = aka::find_range(
    input_1.cbegin(), input_1.cend(), input_2.cbegin(), input_2.cend());
  CHECK(expected == result);
}
