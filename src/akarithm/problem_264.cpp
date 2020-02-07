#include "doctest/doctest.h"

#include "akarithm/problem_264.hpp"

#include <vector>

TEST_CASE("problem 264 1")
{
    const std::size_t input = 10;
    const std::size_t expected = 12;
    const std::size_t result = akarithm::nthUglyNumber(input);
    CHECK(expected == result);
}

TEST_CASE("problem 264 2")
{
    const std::size_t input = 306;
    const std::size_t expected = 92160;
    const std::size_t result = akarithm::nthUglyNumber(input);
    CHECK(expected == result);
}

TEST_CASE("problem 264 3")
{
    const std::size_t input = 1407;
    const std::size_t expected = 536870912;
    const std::size_t result = akarithm::nthUglyNumber(input);
    CHECK(expected == result);
}

TEST_CASE("problem 264 3")
{
    const std::size_t input = 1;
    const std::size_t expected = 1;
    const std::size_t result = akarithm::nthUglyNumber(input);
    CHECK(expected == result);
}

TEST_CASE("problem 264 4")
{
    const std::vector<std::size_t> input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const std::vector<std::size_t> expected = {1, 2, 3, 4, 5, 6, 8, 9, 10, 12};
    CHECK(input.size() == expected.size());
    for (std::vector<std::size_t>::size_type iter = 0; iter != input.size(); iter++)
        CHECK(expected[iter] == akarithm::nthUglyNumber(input[iter]));
}
