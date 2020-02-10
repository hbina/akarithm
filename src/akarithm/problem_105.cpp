#include "doctest/doctest.h"

#include "akarithm/problem_105.hpp"

TEST_CASE("problem_105")
{
    const std::vector<int> input_1 = {3, 9, 20, 15, 7};
    const std::vector<int> input_2 = {9, 3, 15, 20, 7};
    const akarithm::TreeNode<> *expected =
        new akarithm::TreeNode<>(3,
                       new akarithm::TreeNode<>(9),
                       new akarithm::TreeNode<>(20,
                                      new akarithm::TreeNode<>(15),
                                      new akarithm::TreeNode<>(7)));
    const akarithm::TreeNode<> *result = akarithm::buildTreePreIn(input_1, input_2);
    CHECK(*expected == *result);
    delete result;
    delete expected;
}
