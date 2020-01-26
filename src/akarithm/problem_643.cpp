#include "doctest/doctest.h"

#include "akarithm/problem_643.hpp"

TEST_CASE("problem_643")
{
    const std::vector<int> input_1 = {1, 12, -5, -6, 50, 3};
    const std::size_t input_2 = 4;
    const double expected = 12.75;
    const double result = akarithm::findMaxAverage(input_1, input_2);
    CHECK(expected == result);
}
