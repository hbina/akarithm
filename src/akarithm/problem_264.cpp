#include "doctest/doctest.h"

#include "akarithm/problem_264.hpp"

#include <vector>

TEST_CASE("problem 264 1")
{
    const int input = 10;
    const int expected = 12;
    const int result = akarithm::nthUglyNumber(input);
    CHECK(expected == result);
}

TEST_CASE("problem 264 2")
{
    const int input = 306;
    const int expected = 92160;
    // const int result = akarithm::nthUglyNumber(input);
    // CHECK(expected == result);
}

TEST_CASE("problem 264 3")
{
    const int input = 1;
    const int expected = 1;
    const int result = akarithm::nthUglyNumber(input);
    CHECK(expected == result);
}

TEST_CASE("problem 264 4")
{
    const std::vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const std::vector<int> expected = {1, 2, 3, 4, 5, 6, 8, 9, 10, 12};
    CHECK(input.size() == expected.size());
    for (std::vector<int>::size_type iter = 0; iter != input.size(); iter++)
        CHECK(expected[iter] == akarithm::nthUglyNumber(input[iter]));
}
