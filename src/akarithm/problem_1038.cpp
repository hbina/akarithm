#include "doctest/doctest.h"

#include "akarithm/problem_1038.hpp"

TEST_CASE("problem_1038")
{
    akarithm::TreeNode<> *input =
        new akarithm::TreeNode<>(4,
                       new akarithm::TreeNode<>(1,
                                      new akarithm::TreeNode<>(0),
                                      new akarithm::TreeNode<>(2,
                                                     nullptr,
                                                     new akarithm::TreeNode<>(3))),
                       new akarithm::TreeNode<>(6,
                                      new akarithm::TreeNode<>(5),
                                      new akarithm::TreeNode<>(7,
                                                     nullptr,
                                                     new akarithm::TreeNode<>(8))));
    const akarithm::TreeNode<> *expected =
        new akarithm::TreeNode<>(30,
                       new akarithm::TreeNode<>(36,
                                      new akarithm::TreeNode<>(36),
                                      new akarithm::TreeNode<>(35,
                                                     nullptr,
                                                     new akarithm::TreeNode<>(33))),
                       new akarithm::TreeNode<>(21,
                                      new akarithm::TreeNode<>(26),
                                      new akarithm::TreeNode<>(15,
                                                     nullptr,
                                                     new akarithm::TreeNode<>(8))));
    const akarithm::TreeNode<> *result = akarithm::bstToGst(input);
    CHECK(*expected == *result);
    delete expected;
    delete result;
}

TEST_CASE("problem_1038")
{
    akarithm::TreeNode<double> *input =
        new akarithm::TreeNode<double>(4.0,
                       new akarithm::TreeNode<double>(1.0,
                                      new akarithm::TreeNode<double>(0.0),
                                      new akarithm::TreeNode<double>(2.0,
                                                     nullptr,
                                                     new akarithm::TreeNode<double>(3.0))),
                       new akarithm::TreeNode<double>(6.0,
                                      new akarithm::TreeNode<double>(5.0),
                                      new akarithm::TreeNode<double>(7.0,
                                                     nullptr,
                                                     new akarithm::TreeNode<double>(8.0))));
    const akarithm::TreeNode<double> *expected =
        new akarithm::TreeNode<double>(30.0,
                       new akarithm::TreeNode<double>(36.0,
                                      new akarithm::TreeNode<double>(36.0),
                                      new akarithm::TreeNode<double>(35.0,
                                                     nullptr,
                                                     new akarithm::TreeNode<double>(33.0))),
                       new akarithm::TreeNode<double>(21.0,
                                      new akarithm::TreeNode<double>(26.0),
                                      new akarithm::TreeNode<double>(15.0,
                                                     nullptr,
                                                     new akarithm::TreeNode<double>(8.0))));
    const akarithm::TreeNode<double> *result = akarithm::bstToGst(input);
    CHECK(*expected == *result);
    delete expected;
    delete result;
}
