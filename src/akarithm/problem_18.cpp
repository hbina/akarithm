#include "doctest/doctest.h"

#include "akarithm/problem_18.hpp"

#include <algorithm>

TEST_CASE("problem 18")
{
    const std::vector<int> input_1 = {1, 0, -1, 0, -2, 2};
    const int input_2 = 0;
    std::vector<std::vector<int>> expected = {
        {-1, 0, 0, 1},
        {-2, -1, 1, 2},
        {-2, 0, 0, 2}};
    std::vector<std::vector<int>> result =
        akarithm::fourSum(input_1, input_2);
    std::sort(std::begin(expected), std::end(expected));
    std::sort(std::begin(result), std::end(result));
    // CHECK(expected == result);
}
