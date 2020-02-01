#include "doctest/doctest.h"

#include "akarithm/problem_653.hpp"

TEST_CASE("problem 653")
{
    const TreeNode<> *input_1 =
        new TreeNode<>(5,
                       new TreeNode<>(3,
                                      new TreeNode<>(2),
                                      new TreeNode<>(4)),
                       new TreeNode<>(6,
                                      nullptr,
                                      new TreeNode<>(7)));
    const int input_2 = 9;
    const bool expected = true;
    const bool result = akarithm::findTarget(input_1, input_2);
    CHECK(expected == result);
}
