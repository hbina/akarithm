#include "doctest/doctest.h"

#include "akarithm/problem_106.hpp"

TEST_CASE("problem_106")
{
    const std::vector<int> input_1 = {9, 3, 15, 20, 7};
    const std::vector<int> input_2 = {9, 15, 7, 20, 3};
    const akarithm::TreeNode<> *expected =
        new akarithm::TreeNode<>(3,
                       new akarithm::TreeNode<>(9),
                       new akarithm::TreeNode<>(20,
                                      new akarithm::TreeNode<>(15),
                                      new akarithm::TreeNode<>(7)));
    const akarithm::TreeNode<int> *result = akarithm::buildTreeInPost(input_1, input_2);
    CHECK(*expected == *result);
    delete result;
    delete expected;
}
