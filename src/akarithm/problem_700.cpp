#include "doctest/doctest.h"

#include "akarithm/problem_700.hpp"

TEST_CASE("problem_700")
{
    TreeNode<> *expected =
        new TreeNode<>(2,
                       new TreeNode<>(1),
                       new TreeNode<>(3));
    const TreeNode<> *input =
        new TreeNode<>(4,
                       expected,
                       new TreeNode<>(7));
    const auto result = akarithm::searchBST(input, 2);
    CHECK(expected == result);
    delete input;
}
