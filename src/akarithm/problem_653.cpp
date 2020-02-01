#include "doctest/doctest.h"

#include "akarithm/problem_653.hpp"

TEST_CASE("problem 653 1")
{
    const TreeNode<> *input_1 =
        new TreeNode<>(5,
                       new TreeNode<>(3,
                                      new TreeNode<>(2),
                                      new TreeNode<>(4)),
                       new TreeNode<>(6,
                                      nullptr,
                                      new TreeNode<>(7)));
    const int input_2 = 9;
    const bool expected = true;
    const bool result = akarithm::findTarget(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem 653 2")
{
    const TreeNode<> *input_1 =
        new TreeNode<>(2,
                       new TreeNode<>(1),
                       new TreeNode<>(3));
    const int input_2 = 3;
    const bool expected = true;
    const bool result = akarithm::findTarget(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem 653 3")
{
    const TreeNode<> *input_1 =
        new TreeNode<>(2,
                       nullptr,
                       new TreeNode<>(1));
    const int input_2 = 3;
    const bool expected = true;
    const bool result = akarithm::findTarget(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem 653 4")
{
    const TreeNode<> *input_1 =
        new TreeNode<>(2,
                       new TreeNode<>(1),
                       nullptr);
    const int input_2 = 3;
    const bool expected = true;
    const bool result = akarithm::findTarget(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem 653 5")
{
    const TreeNode<> *input_1 = nullptr;
    const int input_2 = 3;
    const bool expected = false;
    const bool result = akarithm::findTarget(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem 653 6")
{
    const TreeNode<> *input_1 =
        new TreeNode<>(2);
    const int input_2 = 3;
    const bool expected = false;
    const bool result = akarithm::findTarget(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem 653 7")
{
    const TreeNode<> *input_1 =
        new TreeNode<>(0,
                       new TreeNode<>(-1,
                                      new TreeNode<>(-3),
                                      nullptr),
                       new TreeNode<>(2,
                                      nullptr,
                                      new TreeNode<>(4)));
    const int input_2 = -4;
    const bool expected = true;
    const bool result = akarithm::findTarget(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem 653 8")
{
    const TreeNode<> *input_1 =
        new TreeNode<>(1);
    const int input_2 = 2;
    const bool expected = false;
    const bool result = akarithm::findTarget(input_1, input_2);
    CHECK(expected == result);
}
