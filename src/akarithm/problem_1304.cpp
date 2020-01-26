#include "doctest/doctest.h"

#include "akarithm/problem_1304.hpp"

#include <numeric>
#include <list>

TEST_CASE("problem_1304")
{
    const int input = 5;
    const std::vector<int> result = akarithm::sumZero(input);
    const int expected = 0;
    CHECK(expected == std::accumulate(
                          std::cbegin(result),
                          std::cend(result),
                          0));
}

TEST_CASE("problem_1304")
{
    const int input = 4;
    const std::vector<int> result = akarithm::sumZero(input);
    const int expected = 0;
    CHECK(expected == std::accumulate(
                          std::cbegin(result),
                          std::cend(result),
                          0));
}

TEST_CASE("problem_1304")
{
    const int input = 3;
    const std::vector<int> result = akarithm::sumZero(input);
    const int expected = 0;
    CHECK(expected == std::accumulate(
                          std::cbegin(result),
                          std::cend(result),
                          0));
}

TEST_CASE("problem_1304")
{
    const int input = 0;
    const std::vector<int> result = akarithm::sumZero(input);
    const int expected = 0;
    CHECK(expected == std::accumulate(
                          std::cbegin(result),
                          std::cend(result),
                          0));
}

TEST_CASE("problem_1304")
{
    const int input = 5;
    const std::list<int> result = akarithm::sumZero<int, std::list<int>>(input);
    const int expected = 0;
    CHECK(expected == std::accumulate(
                          std::cbegin(result),
                          std::cend(result),
                          0));
}
