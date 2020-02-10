#include "doctest/doctest.h"

#include "akarithm/problem_537.hpp"

TEST_CASE("problem_537")
{
    const akarithm::TreeNode<> *input_1 =
        new akarithm::TreeNode<>(5,
                       new akarithm::TreeNode<>(4,
                                      new akarithm::TreeNode<>(11,
                                                     new akarithm::TreeNode<>(7),
                                                     new akarithm::TreeNode<>(2)),
                                      nullptr),
                       new akarithm::TreeNode<>(8,
                                      new akarithm::TreeNode<>(13),
                                      new akarithm::TreeNode<>(4,
                                                     nullptr,
                                                     new akarithm::TreeNode<>(1))));
    const int input_2 = 22;
    const bool expected = true;
    const bool result = akarithm::hasPathSum(input_1, input_2);
    CHECK(expected == result);
    delete input_1;
}

TEST_CASE("problem_537")
{
    const akarithm::TreeNode<> *input_1 = nullptr;
    const int input_2 = 1;
    const bool expected = false;
    const bool result = akarithm::hasPathSum(input_1, input_2);
    CHECK(expected == result);
}

TEST_CASE("problem_537 -- [1], 0 ==> false")
{
    const akarithm::TreeNode<> *input_1 = new akarithm::TreeNode<>(1);
    const int input_2 = 0;
    const bool expected = false;
    const bool result = akarithm::hasPathSum(input_1, input_2);
    CHECK(expected == result);
    delete input_1;
}

TEST_CASE("problem_537 -- [1,2], 1 ==> true")
{
    const akarithm::TreeNode<> *input_1 =
        new akarithm::TreeNode<>(1,
                       new akarithm::TreeNode<>(2),
                       nullptr);
    const int input_2 = 1;
    const bool expected = false;
    const bool result = akarithm::hasPathSum(input_1, input_2);
    CHECK(expected == result);
    delete input_1;
}

TEST_CASE("problem_537 -- [-2,null, -3], -5 ==> true")
{
    const akarithm::TreeNode<> *input_1 =
        new akarithm::TreeNode<>(-2,
                       nullptr,
                       new akarithm::TreeNode<>(-3));
    const int input_2 = -5;
    const bool expected = true;
    const bool result = akarithm::hasPathSum(input_1, input_2);
    CHECK(expected == result);
    delete input_1;
}
