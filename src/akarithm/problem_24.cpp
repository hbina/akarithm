#include "doctest/doctest.h"

#include "akarithm/problem_24.hpp"

TEST_CASE("problem_24")
{
    akarithm::ListNode<> *input =
        new akarithm::ListNode<>(1,
                       new akarithm::ListNode<>(2,
                                      new akarithm::ListNode<>(3,
                                                     new akarithm::ListNode<>(4))));
    const akarithm::ListNode<> *expected =
        new akarithm::ListNode<>(2,
                       new akarithm::ListNode<>(1,
                                      new akarithm::ListNode<>(4,
                                                     new akarithm::ListNode<>(3))));
    akarithm::ListNode<> *result = akarithm::swapPairs(input);
    CHECK(*expected == *result);
    delete expected;
    delete result;
}

TEST_CASE("problem_24")
{
    akarithm::ListNode<> *input =
        new akarithm::ListNode<>(1,
                       new akarithm::ListNode<>(2));
    const akarithm::ListNode<> *expected =
        new akarithm::ListNode<>(2,
                       new akarithm::ListNode<>(1));
    akarithm::ListNode<> *result = akarithm::swapPairs(input);
    CHECK(*expected == *result);
    delete expected;
    delete result;
}

TEST_CASE("problem_24")
{
    akarithm::ListNode<> *input =
        new akarithm::ListNode<>(1);
    const akarithm::ListNode<> *expected =
        new akarithm::ListNode<>(1);
    akarithm::ListNode<> *result = akarithm::swapPairs(input);
    CHECK(*expected == *result);
    delete expected;
    delete result;
}

TEST_CASE("problem_24")
{
    akarithm::ListNode<> *input = nullptr;
    const akarithm::ListNode<> *expected = nullptr;
    akarithm::ListNode<> *result = akarithm::swapPairs(input);
    CHECK(expected == result);
    delete expected;
    delete result;
}
