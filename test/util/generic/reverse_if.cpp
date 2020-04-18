#include "doctest/doctest.h"

#include "util/generic/reverse_if.hpp"

#include <cctype>
#include <string>
#include <vector>

TEST_CASE("akarithm::reverse_if")
{
  std::string input = "h4ll5";
  std::string expected = "h5ll4";
  akarithm::reverse_if(input.begin(), input.end(), [](const char& x) -> bool {
    return std::isdigit(static_cast<int>(x));
  });
  CHECK(expected == input);
}

TEST_CASE("akarithm::reverse_if")
{
  std::vector<int> input = { 1, 2, 3, 4, 5 };
  std::vector<int> expected = { 1, 4, 3, 2, 5 };
  akarithm::reverse_if(input.begin(), input.end(), [](const int& x) -> bool {
    return x % 2 == 0;
  });
  CHECK(expected == input);
}

TEST_CASE("akarithm::reverse_if")
{
  std::string input = "hh";
  std::string expected = "hh";
  akarithm::reverse_if(input.begin(), input.end(), [](const char& x) -> bool {
    return std::isdigit(static_cast<int>(x));
  });
  CHECK(expected == input);
}

TEST_CASE("akarithm::reverse_if")
{
  std::vector<char> input = { 'h', 'g' };
  std::vector<char> expected = { 'g', 'h' };
  akarithm::reverse_if(input.begin(), input.end(), [](const char& x) -> bool {
    return std::isalpha(static_cast<int>(x));
  });
  CHECK(expected == input);
}

TEST_CASE("akarithm::reverse_if")
{
  std::string input = "34";
  std::string expected = "43";
  akarithm::reverse_if(input.begin(), input.end(), [](const char& x) -> bool {
    return std::isdigit(static_cast<int>(x));
  });
  CHECK(expected == input);
}

TEST_CASE("akarithm::reverse_if")
{
  std::string input = "";
  std::string expected = "";
  akarithm::reverse_if(input.begin(), input.end(), [](const char& x) -> bool {
    return std::isdigit(static_cast<int>(x));
  });
  CHECK(expected == input);
}

TEST_CASE("akarithm::reverse_if")
{
  std::string input = "3";
  std::string expected = "3";
  akarithm::reverse_if(input.begin(), input.end(), [](const char& x) -> bool {
    return std::isdigit(static_cast<int>(x));
  });
  CHECK(expected == input);
}

TEST_CASE("akarithm::reverse_if")
{
  std::string input = "4";
  std::string expected = "4";
  akarithm::reverse_if(input.begin(), input.end(), [](const char& x) -> bool {
    return std::isdigit(static_cast<int>(x));
  });
  CHECK(expected == input);
}

TEST_CASE("akarithm::reverse_if")
{
  std::string input = "hegxo";
  std::string expected = "oxgeh";
  akarithm::reverse_if(
    input.begin(), input.end(), [](const auto&) -> bool { return true; });
  CHECK(expected == input);
}