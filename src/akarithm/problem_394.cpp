#include "doctest/doctest.h"

#include "akarithm/problem_394.hpp"

TEST_CASE("problem_394")
{
    CHECK(std::string("aaabcbc") == akarithm::decodeString("3[a]2[bc]"));
    CHECK(std::string("accaccacc") == akarithm::decodeString("3[a2[c]]"));
    CHECK(std::string("abcabccdcdcdef") == akarithm::decodeString("2[abc]3[cd]ef"));
}
