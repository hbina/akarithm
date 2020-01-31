#include "doctest/doctest.h"

#include "data_structure/preorder_iterator.hpp"

TEST_CASE("preorder iterator")
{
    const TreeNode<> *input =
        new TreeNode<>(1,
                       new TreeNode<>(2,
                                      new TreeNode<>(4),
                                      new TreeNode<>(5)),
                       new TreeNode<>(3));
    akarithm::PreorderIterator iterator =
        akarithm::PreorderIterator(input);
    CHECK(4 == iterator.next()->val);
    CHECK(2 == iterator.next()->val);
    CHECK(true == iterator.hasNext());
    CHECK(5 == iterator.next()->val);
    CHECK(true == iterator.hasNext());
    CHECK(1 == iterator.next()->val);
    CHECK(true == iterator.hasNext());
    CHECK(3 == iterator.next()->val);
    CHECK(false == iterator.hasNext());
    delete input;
}
