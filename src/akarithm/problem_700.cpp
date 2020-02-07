#include "doctest/doctest.h"

#include "akarithm/problem_700.hpp"

TEST_CASE("problem_700")
{
    const auto expected =
        new TreeNode<int>(2,
                          new TreeNode<int>(1),
                          new TreeNode<int>(3));
    const TreeNode<int> *input =
        new TreeNode<int>(4,
                          expected,
                          new TreeNode<int>(7));
    const auto result = akarithm::searchBST(input, 2);
    CHECK(expected == result);
    delete input;
}
