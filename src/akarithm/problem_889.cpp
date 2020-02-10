#include "doctest/doctest.h"

#include "akarithm/problem_889.hpp"

TEST_CASE("problem_889")
{
    const std::vector<int> input_1 = {1, 2, 4, 5, 3, 6, 7};
    const std::vector<int> input_2 = {4, 5, 2, 6, 7, 3, 1};
    const akarithm::TreeNode<> *expected =
        new akarithm::TreeNode<>(1,
                       new akarithm::TreeNode<>(2,
                                      new akarithm::TreeNode<>(4),
                                      new akarithm::TreeNode<>(5)),
                       new akarithm::TreeNode<>(3,
                                      new akarithm::TreeNode<>(6),
                                      new akarithm::TreeNode<>(7)));
    const akarithm::TreeNode<> *result = akarithm::constructFromPrePost(input_1, input_2);
    CHECK(*expected == *result);
    delete result;
    delete expected;
}
