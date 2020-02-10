#include "doctest/doctest.h"

#include "akarithm/problem_107.hpp"

TEST_CASE("problem_107")
{
    const akarithm::TreeNode<> *input =
        new akarithm::TreeNode<>(3,
                       new akarithm::TreeNode<>(9),
                       new akarithm::TreeNode<>(20,
                                      new akarithm::TreeNode<>(15),
                                      new akarithm::TreeNode<>(7)));
    const std::vector<std::vector<int>> expected = {
        {3},
        {9, 20},
        {15, 7}};
    const std::vector<std::vector<int>> result = akarithm::levelOrderBottom(input);
    CHECK(expected == result);
    delete input;
}
