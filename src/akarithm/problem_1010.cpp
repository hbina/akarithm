#include "doctest/doctest.h"

#include "akarithm/problem_1010.hpp"

TEST_CASE("problem_1010")
{
    const std::vector<int> input = {30, 20, 150, 100, 40};
    const int expected = 3;
    const int result = static_cast<int>(akarithm::numPairsDivisibleBy60(input));
    CHECK(expected == result);
}
