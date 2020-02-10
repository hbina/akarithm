#include "doctest/doctest.h"

#include "akarithm/problem_21.hpp"

TEST_CASE("problem_21")
{
    akarithm::ListNode<> *input_1 = new akarithm::ListNode<>(1,
                                         new akarithm::ListNode<>(2,
                                                        new akarithm::ListNode<>(4)));
    akarithm::ListNode<> *input_2 = new akarithm::ListNode<>(1,
                                         new akarithm::ListNode<>(3,
                                                        new akarithm::ListNode<>(4)));
    akarithm::ListNode<> *expected = new akarithm::ListNode<>(1,
                                          new akarithm::ListNode<>(1,
                                                         new akarithm::ListNode<>(2,
                                                                        new akarithm::ListNode<>(3,
                                                                                       new akarithm::ListNode<>(4,
                                                                                                      new akarithm::ListNode<>(4))))));
    akarithm::ListNode<> *result = akarithm::mergeTwoLists(input_1, input_2);
    CHECK(*expected == *result);
    delete result;
    delete expected;
}

TEST_CASE("problem_21")
{
    akarithm::ListNode<> *input_1 = nullptr;
    akarithm::ListNode<> *input_2 = nullptr;
    akarithm::ListNode<> *expected = nullptr;
    akarithm::ListNode<> *result = akarithm::mergeTwoLists(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem_21")
{
    akarithm::ListNode<> *input_1 = new akarithm::ListNode<>(1);
    akarithm::ListNode<> *input_2 = new akarithm::ListNode<>(3);
    akarithm::ListNode<> *expected = new akarithm::ListNode<>(1,
                                          new akarithm::ListNode<>(3));
    akarithm::ListNode<> *result = akarithm::mergeTwoLists(input_1, input_2);
    CHECK(*expected == *result);
    delete result;
    delete expected;
}

TEST_CASE("problem_21")
{
    akarithm::ListNode<> *input_1 = new akarithm::ListNode<>(1);
    akarithm::ListNode<> *input_2 = nullptr;
    akarithm::ListNode<> *expected = new akarithm::ListNode<>(1);
    akarithm::ListNode<> *result = akarithm::mergeTwoLists(input_1, input_2);
    CHECK(*expected == *result);
    delete result;
    delete expected;
}

TEST_CASE("problem_21")
{
    akarithm::ListNode<> *input_1 = nullptr;
    akarithm::ListNode<> *input_2 = new akarithm::ListNode<>(1);
    akarithm::ListNode<> *expected = new akarithm::ListNode<>(1);
    akarithm::ListNode<> *result = akarithm::mergeTwoLists(input_1, input_2);
    CHECK(*expected == *result);
    delete result;
    delete expected;
}
