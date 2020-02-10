#include "doctest/doctest.h"

#include "akarithm/problem_938.hpp"

TEST_CASE("problem_938")
{
    const akarithm::TreeNode<> *input =
        new akarithm::TreeNode<>(10,
                       new akarithm::TreeNode<>(5,
                                      new akarithm::TreeNode<>(3),
                                      new akarithm::TreeNode<>(7)),
                       new akarithm::TreeNode<>(15,
                                      nullptr,
                                      new akarithm::TreeNode<>(18)));
    const int expected = 32;
    const int result = akarithm::rangeSumBST_recursion(input, 7, 15);
    CHECK(expected == result);
    delete input;
}
