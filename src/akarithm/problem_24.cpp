#include "doctest/doctest.h"

#include "akarithm/problem_24.hpp"

TEST_CASE("problem_24")
{
    ListNode<> *input =
        new ListNode<>(1,
                       new ListNode<>(2,
                                      new ListNode<>(3,
                                                     new ListNode<>(4))));
    const ListNode<> *expected =
        new ListNode<>(2,
                       new ListNode<>(1,
                                      new ListNode<>(4,
                                                     new ListNode<>(3))));
    ListNode<> *result = akarithm::swapPairs(input);
    CHECK(*expected == *result);
    delete expected;
    delete result;
}

TEST_CASE("problem_24")
{
    ListNode<> *input =
        new ListNode<>(1,
                       new ListNode<>(2));
    const ListNode<> *expected =
        new ListNode<>(2,
                       new ListNode<>(1));
    ListNode<> *result = akarithm::swapPairs(input);
    CHECK(*expected == *result);
    delete expected;
    delete result;
}

TEST_CASE("problem_24")
{
    ListNode<> *input =
        new ListNode<>(1);
    const ListNode<> *expected =
        new ListNode<>(1);
    ListNode<> *result = akarithm::swapPairs(input);
    CHECK(*expected == *result);
    delete expected;
    delete result;
}

TEST_CASE("problem_24")
{
    ListNode<> *input = nullptr;
    const ListNode<> *expected = nullptr;
    ListNode<> *result = akarithm::swapPairs(input);
    CHECK(expected == result);
    delete expected;
    delete result;
}
