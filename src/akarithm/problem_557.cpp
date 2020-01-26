#include "doctest/doctest.h"

#include "akarithm/problem_557.hpp"

TEST_CASE("problem_557")
{
    const std::string input = "Let's take akarithm contest";
    const std::string expected = "s'teL ekat edoCteeL tsetnoc";
    const std::string result = akarithm::reverseWords(input);
    CHECK(expected == result);
}
