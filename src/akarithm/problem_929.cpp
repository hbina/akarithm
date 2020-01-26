#include "doctest/doctest.h"

#include "akarithm/problem_929.hpp"

TEST_CASE("problem_929")
{
    const std::vector<std::string> input = {"test.email+alex@akarithm.com", "test.e.mail+bob.cathy@akarithm.com", "testemail+david@lee.tcode.com"};
    const int expected = 2;
    const int result = akarithm::numUniqueEmails(input);
    CHECK(expected == result);
}
