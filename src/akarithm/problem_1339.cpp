#include "doctest/doctest.h"

#include "akarithm/problem_1339.hpp"

TEST_CASE("problem 5330 1")
{
    const akarithm::TreeNode<> *input =
        new akarithm::TreeNode<>(1,
                       nullptr,
                       new akarithm::TreeNode<>(2,
                                      new akarithm::TreeNode<>(3),
                                      new akarithm::TreeNode<>(4,
                                                     new akarithm::TreeNode(5),
                                                     new akarithm::TreeNode<>(6))));
    const int expected = 90;
    // const int result = akarithm::maxProduct(input);
    // CHECK(expected == result);
}
