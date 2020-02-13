#include "doctest/doctest.h"

#include "akarithm/problem_1347.hpp"

#include <string>

TEST_CASE("problem 1347 1")
{
    const std::string input_1 = "bab";
    const std::string input_2 = "aba";
    const int expected = 1;
    const int result = akarithm::minSteps(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem 1347 2")
{
    const std::string input_1 = "leetcode";
    const std::string input_2 = "practice";
    const int expected = 5;
    const int result = akarithm::minSteps(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem 1347 3")
{
    const std::string input_1 = "anagram";
    const std::string input_2 = "mangaar";
    const int expected = 0;
    const int result = akarithm::minSteps(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem 1347 1")
{
    const std::string input_1 = "xxyyzz";
    const std::string input_2 = "xxyyzz";
    const int expected = 0;
    const int result = akarithm::minSteps(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem 1347 1")
{
    const std::string input_1 = "friend";
    const std::string input_2 = "family";
    const int expected = 4;
    const int result = akarithm::minSteps(input_1, input_2);
    CHECK(expected == result);
}

