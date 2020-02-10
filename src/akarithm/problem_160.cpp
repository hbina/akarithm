#include "doctest/doctest.h"

#include "akarithm/problem_160.hpp"

TEST_CASE("problem_160")
{
    akarithm::ListNode<int> *c1 =
        new akarithm::ListNode<int>(6,
                          new akarithm::ListNode<int>(
                              7,
                              new akarithm::ListNode<int>(
                                  8,
                                  nullptr)));
    akarithm::ListNode<int> *a1 =
        new akarithm::ListNode<int>(1,
                          new akarithm::ListNode<int>(
                              2,
                              c1));
    akarithm::ListNode<int> *b1 =
        new akarithm::ListNode<int>(3,
                          new akarithm::ListNode<int>(
                              4,
                              new akarithm::ListNode<int>(
                                  5,
                                  c1)));
    akarithm::ListNode<int> *result = akarithm::getIntersectionNode(a1, b1);
    CHECK(*c1 == *result);
    // Solely for cleanup purposes...
    b1->next->next->next = nullptr;
    delete a1;
    delete b1;
}
