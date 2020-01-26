#include "doctest/doctest.h"

#include "akarithm/problem_535.hpp"

TEST_CASE("problem_535")
{
    const TreeNode<> input = TreeNode<>(
        3,
        new TreeNode<>(9),
        new TreeNode<>(20,
                       new TreeNode<>(15),
                       new TreeNode<>(7)));
    int expected = 3;
    CHECK(expected == akarithm::maxDepth(&input));
}

TEST_CASE("problem_535")
{
    const TreeNode<> input = TreeNode<>(3);
    int expected = 1;
    CHECK(expected == akarithm::maxDepth(&input));
}

TEST_CASE("problem_535")
{
    TreeNode<> *input = nullptr;
    int expected = 0;
    CHECK(expected == akarithm::maxDepth(input));
}

TEST_CASE("problem_535")
{
    const TreeNode<> *input =
        new TreeNode<>(3,
                       nullptr,
                       new TreeNode<>(20,
                                      nullptr,
                                      new TreeNode<>(7,
                                                     nullptr,
                                                     new TreeNode<>(7))));
    const int expected = 4;
    const int result = static_cast<int>(akarithm::maxDepth(input));
    CHECK(expected == result);
    delete input;
}
