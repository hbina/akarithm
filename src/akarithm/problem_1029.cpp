#include "doctest/doctest.h"

#include "akarithm/problem_1029.hpp"

TEST_CASE("problem 1029 1")
{
    const std::vector<std::vector<int>> input = {{10, 20}, {30, 200}, {400, 50}, {30, 20}};
    const int expected = 110;
    const int result = akarithm::twoCitySchedCost(
        std::cbegin(input),
        std::cend(input));
    CHECK(expected == result);
}