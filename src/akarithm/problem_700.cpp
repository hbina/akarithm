#include "doctest/doctest.h"

#include "akarithm/problem_700.hpp"

TEST_CASE("problem_700")
{
    akarithm::TreeNode<> *expected =
        new akarithm::TreeNode<>(2,
                       new akarithm::TreeNode<>(1),
                       new akarithm::TreeNode<>(3));
    const akarithm::TreeNode<> *input =
        new akarithm::TreeNode<>(4,
                       expected,
                       new akarithm::TreeNode<>(7));
    const auto result = akarithm::searchBST(input, 2);
    CHECK(expected == result);
    delete input;
}
