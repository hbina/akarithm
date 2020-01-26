#include "doctest/doctest.h"

#include "akarithm/problem_106.hpp"

TEST_CASE("problem_106")
{
    const std::vector<int> input_1 = {9, 3, 15, 20, 7};
    const std::vector<int> input_2 = {9, 15, 7, 20, 3};
    const TreeNode<> *expected =
        new TreeNode<>(3,
                       new TreeNode<>(9),
                       new TreeNode<>(20,
                                      new TreeNode<>(15),
                                      new TreeNode<>(7)));
    const TreeNode<int> *result = akarithm::buildTreeInPost(input_1, input_2);
    CHECK(*expected == *result);
    delete result;
    delete expected;
}
