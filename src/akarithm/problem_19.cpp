#include "doctest/doctest.h"

#include "akarithm/problem_19.hpp"

TEST_CASE("problem_19")
{
    akarithm::ListNode<> *input_1 =
        new akarithm::ListNode<>(1,
                       new akarithm::ListNode<>(2,
                                      new akarithm::ListNode<>(3,
                                                     new akarithm::ListNode<>(4,
                                                                    new akarithm::ListNode<>(5)))));
    int input_2 = 2;
    akarithm::ListNode<> *expected =
        new akarithm::ListNode<>(1,
                     new akarithm::ListNode<>(2,
                                  new akarithm::ListNode<>(3,
                                               new akarithm::ListNode<>(5))));
    akarithm::ListNode<> *result = akarithm::removeNthFromEnd(input_1, input_2);
    CHECK(*expected == *result);
    delete expected;
    delete result;
}

TEST_CASE("problem_19")
{
    akarithm::ListNode<> *input_1 =
        new akarithm::ListNode(1);
    int input_2 = 1;
    akarithm::ListNode<> *expected = nullptr;
    akarithm::ListNode<> *result = akarithm::removeNthFromEnd(input_1, input_2);
    CHECK(expected == result);
    delete expected;
    delete result;
}
