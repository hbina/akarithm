#include "doctest/doctest.h"

#include "akarithm/problem_1281.hpp"

TEST_CASE("problem_1281")
{
    CHECK(15 == akarithm::subtractProductAndSum(234));
    CHECK(21 == akarithm::subtractProductAndSum(4421));
}
