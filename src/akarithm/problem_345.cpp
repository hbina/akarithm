#include "doctest/doctest.h"

#include "akarithm/problem_345.hpp"

TEST_CASE("problem_345")
{
    const std::string input = "hello";
    const std::string expected = "holle";
    const std::string result = akarithm::reverseVowels(input);
    CHECK(expected == result);
}

TEST_CASE("problem_345")
{
    const std::string input = "akarithm";
    const std::string expected = "leotcede";
    const std::string result = akarithm::reverseVowels(input);
    CHECK(expected == result);
}

TEST_CASE("problem_345")
{
    const std::string input = "aA";
    const std::string expected = "Aa";
    const std::string result = akarithm::reverseVowels(input);
    CHECK(expected == result);
}
