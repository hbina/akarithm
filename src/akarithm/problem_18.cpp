#include "doctest/doctest.h"

#include "akarithm/problem_18.hpp"

#include <algorithm>

//  TODO    ::  How to test this?

TEST_CASE("problem 18 1")
{
    const std::vector<int> input_1 = {-3, -2, -1, 0, 0, 1, 2, 3};
    const int input_2 = 0;
    const std::vector<std::vector<int>> result =
        akarithm::fourSum(input_1, input_2);
}

TEST_CASE("problem 18 2")
{
    const std::vector<int> input_1 = {1, 0, -1, 0, -2, 2};
    const int input_2 = 0;
    const std::vector<std::vector<int>> result =
        akarithm::fourSum(input_1, input_2);
}
