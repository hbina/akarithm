#include "doctest/doctest.h"

#include "akarithm/problem_1.hpp"

#include "util/generic/set_equality.hpp"

TEST_CASE("problem 1")
{
    const std::vector<int> input_1 = {2, 7, 11, 15};
    const int input_2 = 9;
    const std::vector<int> expected = {0, 1};
    const std::vector<int> result = akarithm::twoSum(input_1, input_2);
    CHECK(util::generic::set_equality(
        std::cbegin(expected),
        std::cend(expected),
        std::cbegin(result),
        std::cend(result)));
}

TEST_CASE("problem 1")
{
    const std::vector<int> input_1 = {3, 2, 4};
    const int input_2 = 7;
    const std::vector<int> expected = {1, 2};
    const std::vector<int> result = akarithm::twoSum(input_1, input_2);
    CHECK(util::generic::set_equality(
        std::cbegin(expected),
        std::cend(expected),
        std::cbegin(result),
        std::cend(result)));
}
