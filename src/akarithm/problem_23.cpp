#include "doctest/doctest.h"

#include "akarithm/problem_23.hpp"

TEST_CASE("problem 23 1")
{
    std::vector<ListNode<int> *> input = {
        new ListNode<>(1,
                       new ListNode<>(4,
                                      new ListNode<>(5))),
        new ListNode<>(1,
                       new ListNode<>(3,
                                      new ListNode<>(4))),
        new ListNode<>(2,
                       new ListNode<>(6))};
    ListNode<int> *expected =
        new ListNode<>(1,
                       new ListNode<>(1,
                                      new ListNode<>(2,
                                                     new ListNode<>(3,
                                                                    new ListNode<>(4,
                                                                                   new ListNode<>(4,
                                                                                                  new ListNode<>(5,
                                                                                                                 new ListNode<>(6))))))));
    const ListNode<int> *result = akarithm::mergeKLists(input);
    CHECK(*expected == *result);
    delete result;
}

TEST_CASE("problem 23 2")
{
    std::vector<ListNode<int> *> input = {};
    ListNode<int> *expected = nullptr;
    const ListNode<int> *result = akarithm::mergeKLists(input);
    CHECK(expected == result);
    delete result;
}

TEST_CASE("problem 23 3")
{
    std::vector<ListNode<int> *> input = {nullptr, nullptr};
    ListNode<int> *expected = nullptr;
    const ListNode<int> *result = akarithm::mergeKLists(input);
    CHECK(expected == result);
    delete result;
}

TEST_CASE("problem 23 4")
{
    std::vector<ListNode<int> *> input = {
        new ListNode<>(1,
                       new ListNode<>(4,
                                      new ListNode<>(5)))};
    ListNode<int> *expected = new ListNode<>(1, new ListNode<>(4, new ListNode<>(5)));
    const ListNode<int> *result = akarithm::mergeKLists(input);
    CHECK(*expected == *result);
    delete result;
}
