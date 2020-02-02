#include "doctest/doctest.h"

#include "akarithm/problem_5330.hpp"

TEST_CASE("problem 5330 1")
{
    const TreeNode<> *input =
        new TreeNode<>(1,
                       nullptr,
                       new TreeNode<>(2,
                                      new TreeNode<>(3),
                                      new TreeNode<>(4,
                                                     new TreeNode(5),
                                                     new TreeNode<>(6))));
    const int expected = 90;
    const int result = akarithm::maxProduct(input);
    CHECK(expected == result);
}
