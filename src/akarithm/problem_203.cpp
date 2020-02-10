#include "doctest/doctest.h"

#include "akarithm/problem_203.hpp"

TEST_CASE("problem_203")
{
    akarithm::ListNode<> *input =
        new akarithm::ListNode<>(1,
                       new akarithm::ListNode<>(2,
                                      new akarithm::ListNode<>(6,
                                                     new akarithm::ListNode<>(3,
                                                                    new akarithm::ListNode<>(4,
                                                                                   new akarithm::ListNode<>(5,
                                                                                                  new akarithm::ListNode<>(6)))))));
    const int input_2 = 6;
    const akarithm::ListNode<> *expected = new akarithm::ListNode<>(1,
                                                new akarithm::ListNode<>(2,
                                                               new akarithm::ListNode<>(3,
                                                                              new akarithm::ListNode<>(4,
                                                                                             new akarithm::ListNode<>(5)))));
    akarithm::ListNode<> *result = akarithm::removeElements(input, input_2);
    CHECK(*expected == *result);
    delete result;
    delete expected;
}

TEST_CASE("problem_203")
{
    akarithm::ListNode<> *input =
        new akarithm::ListNode<>(1,
                       new akarithm::ListNode<>(2,
                                      new akarithm::ListNode<>(6,
                                                     new akarithm::ListNode<>(3,
                                                                    new akarithm::ListNode<>(4,
                                                                                   new akarithm::ListNode<>(5,
                                                                                                  new akarithm::ListNode<>(6)))))));
    const int input_2 = 32;
    const akarithm::ListNode<> *expected =
        new akarithm::ListNode<>(1,
                       new akarithm::ListNode<>(2,
                                      new akarithm::ListNode<>(6,
                                                     new akarithm::ListNode<>(3,
                                                                    new akarithm::ListNode<>(4,
                                                                                   new akarithm::ListNode<>(5,
                                                                                                  new akarithm::ListNode<>(6)))))));
    akarithm::ListNode<> *result = akarithm::removeElements(input, input_2);
    CHECK(*expected == *result);
    delete result;
    delete expected;
}

TEST_CASE("problem_203")
{
    akarithm::ListNode<> *input = new akarithm::ListNode<>(1);
    const int input_2 = 1;
    const akarithm::ListNode<> *expected = nullptr;
    akarithm::ListNode<> *result = akarithm::removeElements(input, input_2);
    CHECK(expected == result);
    delete result;
    delete expected;
}

TEST_CASE("problem_203")
{
    akarithm::ListNode<> *input = nullptr;
    const int input_2 = 1;
    const akarithm::ListNode<> *expected = nullptr;
    akarithm::ListNode<> *result = akarithm::removeElements(input, input_2);
    CHECK(expected == result);
    delete result;
    delete expected;
}

TEST_CASE("problem_203")
{
    akarithm::ListNode<> *input =
        new akarithm::ListNode<>(1,
                       new akarithm::ListNode<>(1,
                                      new akarithm::ListNode<>(1)));
    const int input_2 = 1;
    const akarithm::ListNode<> *expected = nullptr;
    akarithm::ListNode<> *result = akarithm::removeElements(input, input_2);
    CHECK(expected == result);
    delete result;
    delete expected;
}

TEST_CASE("problem_203")
{
    akarithm::ListNode<> *input =
        new akarithm::ListNode<>(3,
                       new akarithm::ListNode<>(2,
                                      new akarithm::ListNode<>(1)));
    const int input_2 = 1;
    const akarithm::ListNode<> *expected =
        new akarithm::ListNode<>(3,
                       new akarithm::ListNode<>(2));
    akarithm::ListNode<> *result = akarithm::removeElements(input, input_2);
    CHECK(*expected == *result);
    delete result;
    delete expected;
}

TEST_CASE("problem_203")
{
    akarithm::ListNode<> *input =
        new akarithm::ListNode<>(1,
                       new akarithm::ListNode<>(2,
                                      new akarithm::ListNode<>(6,
                                                     new akarithm::ListNode<>(3,
                                                                    new akarithm::ListNode<>(4,
                                                                                   new akarithm::ListNode<>(5,
                                                                                                  new akarithm::ListNode<>(6)))))));
    const int input_2 = 6;
    const akarithm::ListNode<> *expected = new akarithm::ListNode<>(1,
                                                new akarithm::ListNode<>(2,
                                                               new akarithm::ListNode<>(3,
                                                                              new akarithm::ListNode<>(4,
                                                                                             new akarithm::ListNode<>(5)))));
    akarithm::ListNode<> *result = akarithm::removeElements(input, input_2);
    CHECK(*expected == *result);
    delete result;
    delete expected;
}

TEST_CASE("problem_203 -- If")
{
    akarithm::ListNode<> *input =
        new akarithm::ListNode<>(1,
                       new akarithm::ListNode<>(2,
                                      new akarithm::ListNode<>(6,
                                                     new akarithm::ListNode<>(3,
                                                                    new akarithm::ListNode<>(4,
                                                                                   new akarithm::ListNode<>(5,
                                                                                                  new akarithm::ListNode<>(6)))))));
    const akarithm::ListNode<> *expected =
        new akarithm::ListNode<>(1,
                       new akarithm::ListNode<>(3,
                                      new akarithm::ListNode<>(5)));
    akarithm::ListNode<> *result = akarithm::removeElements_If(
        input,
        [](const int &val) -> bool {
            return val % 2 == 0;
        });
    CHECK(*expected == *result);
    delete result;
    delete expected;
}
