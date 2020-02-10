#include "doctest/doctest.h"

#include "akarithm/problem_173.hpp"

TEST_CASE("problem_173")
{
    const akarithm::TreeNode<> *input =
        new akarithm::TreeNode<>(7,
                       new akarithm::TreeNode<>(3),
                       new akarithm::TreeNode<>(15,
                                      new akarithm::TreeNode<>(9),
                                      new akarithm::TreeNode<>(20)));
    akarithm::BSTIterator iterator =
        akarithm::BSTIterator(input);
    CHECK(3 == iterator.next()->val);
    CHECK(7 == iterator.next()->val);
    CHECK(true == iterator.hasNext());
    CHECK(9 == iterator.next()->val);
    CHECK(true == iterator.hasNext());
    CHECK(15 == iterator.next()->val);
    CHECK(true == iterator.hasNext());
    CHECK(20 == iterator.next()->val);
    CHECK(false == iterator.hasNext());
    delete input;
}
