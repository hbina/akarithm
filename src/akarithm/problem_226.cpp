#include "doctest/doctest.h"

#include "akarithm/problem_226.hpp"

TEST_CASE("problem__226")
{
    akarithm::TreeNode<> *input =
        new akarithm::TreeNode<>(4,
                       new akarithm::TreeNode<>(
                           2,
                           new akarithm::TreeNode<>(1),
                           new akarithm::TreeNode<>(3)),
                       new akarithm::TreeNode<>(7,
                                      new akarithm::TreeNode<>(6),
                                      new akarithm::TreeNode<>(9)));
    const akarithm::TreeNode<int> *expected =
        new akarithm::TreeNode<>(4,
                       new akarithm::TreeNode<>(
                           7,
                           new akarithm::TreeNode<>(9),
                           new akarithm::TreeNode<>(6)),
                       new akarithm::TreeNode<>(2,
                                      new akarithm::TreeNode<>(3),
                                      new akarithm::TreeNode<>(1)));
    const akarithm::TreeNode<> *result = akarithm::invertTree(input);
    CHECK(*expected == *result);
    delete expected;
    delete result;
}
