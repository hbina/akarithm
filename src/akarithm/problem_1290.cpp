#include "doctest/doctest.h"

#include "akarithm/problem_1290.hpp"

TEST_CASE("problem_1290")
{
    akarithm::ListNode<int> *input = new akarithm::ListNode<>(0);
    CHECK(0 == akarithm::getDecimalValue(input));
    delete input;
}

TEST_CASE("problem_1290")
{
    akarithm::ListNode<int> *input = new akarithm::ListNode<>(1);
    CHECK(1 == akarithm::getDecimalValue(input));
    delete input;
}

TEST_CASE("problem_1290")
{
    // lmao
    akarithm::ListNode<int> *input =
        new akarithm::ListNode<>(
            1,
            new akarithm::ListNode<>(0,
                           new akarithm::ListNode<>(0,
                                          new akarithm::ListNode<>(1,
                                                         new akarithm::ListNode<>(0,
                                                                        new akarithm::ListNode<>(0,
                                                                                       new akarithm::ListNode<>(1,
                                                                                                      new akarithm::ListNode<>(1,
                                                                                                                     new akarithm::ListNode<>(1,
                                                                                                                                    new akarithm::ListNode<>(0,
                                                                                                                                                   new akarithm::ListNode<>(0,
                                                                                                                                                                  new akarithm::ListNode<>(0,
                                                                                                                                                                                 new akarithm::ListNode<>(0,
                                                                                                                                                                                                new akarithm::ListNode<>(0,
                                                                                                                                                                                                               new akarithm::ListNode<>(0)))))))))))))));
    CHECK(
        18880 ==
        akarithm::getDecimalValue(input));
    delete input;
}

TEST_CASE("problem_1290")
{
    akarithm::ListNode<int> *input =
        new akarithm::ListNode<>(
            0,
            new akarithm::ListNode<>(0));
    CHECK(0 == akarithm::getDecimalValue(input));
    delete input;
}

TEST_CASE("problem_1290")
{
    akarithm::ListNode<int> *input =
        new akarithm::ListNode<>(
            1,
            new akarithm::ListNode<>(
                0,
                new akarithm::ListNode<>(1)));
    CHECK(5 == akarithm::getDecimalValue(input));
    delete input;
}
