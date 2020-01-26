#include "doctest/doctest.h"

#include "akarithm/problem_371.hpp"

TEST_CASE("problem_371")
{
    CHECK(3 == akarithm::getSum(1, 2));
    CHECK(7 == akarithm::getSum(5, 2));
    CHECK(-1 == akarithm::getSum(-3, 2));
    CHECK(8 == akarithm::getSum(10, -2));
    CHECK(5 == akarithm::getSum(3, 2));
    CHECK(-11 == akarithm::getSum(-11, 0));
    CHECK(0 == akarithm::getSum(0, 0));
    CHECK(0 == akarithm::getSum(-1, 1));
}
