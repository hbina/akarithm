#include "doctest/doctest.h"

#include "akarithm/problem_1347.hpp"

TEST_CASE("problem 1347 1")
{
    const std::string input_1 = "2019-06-29";
    const std::string input_2 = "2019-06-30";
    const int expected = 1;
    const int resullt = akarithm::daysBetweenDates(input_1, input_2);
    CHECK(expected == resullt);
}

TEST_CASE("problem 1347 2")
{
    const std::string input_1 = "2020-01-15";
    const std::string input_2 = "2019-12-31";
    const int expected = 15;
    const int resullt = akarithm::daysBetweenDates(input_1, input_2);
    CHECK(expected == resullt);
}
