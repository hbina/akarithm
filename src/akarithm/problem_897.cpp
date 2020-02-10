#include "doctest/doctest.h"

#include "akarithm/problem_897.hpp"

TEST_CASE("problem_897")
{
    akarithm::TreeNode<> *input =
        new akarithm::TreeNode<>(5,
                       new akarithm::TreeNode<>(3,
                                      new akarithm::TreeNode<>(2,
                                                     new akarithm::TreeNode<>(1),
                                                     nullptr),
                                      new akarithm::TreeNode<>(4)),
                       new akarithm::TreeNode<>(6,
                                      nullptr,
                                      new akarithm::TreeNode<>(8,
                                                     new akarithm::TreeNode<>(7),
                                                     new akarithm::TreeNode<>(9))));
    const akarithm::TreeNode<> *expected =
        new akarithm::TreeNode<>(1,
                       nullptr,
                       new akarithm::TreeNode<>(2,
                                      nullptr,
                                      new akarithm::TreeNode<>(3,
                                                     nullptr,
                                                     new akarithm::TreeNode<>(4,
                                                                    nullptr,
                                                                    new akarithm::TreeNode<>(5,
                                                                                   nullptr,
                                                                                   new akarithm::TreeNode<>(6,
                                                                                                  nullptr,
                                                                                                  new akarithm::TreeNode<>(7,
                                                                                                                 nullptr,
                                                                                                                 new akarithm::TreeNode<>(8,
                                                                                                                                nullptr,
                                                                                                                                new akarithm::TreeNode<>(9)))))))));
    delete input;
    delete expected;
}
