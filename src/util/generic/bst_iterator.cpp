#include "doctest/doctest.h"

#include "data_structure/bst_iterator.hpp"
#include "data_structure/tree_node.hpp"

TEST_CASE("bst iterator")
{
    const TreeNode<> *input =
        new TreeNode<>(7,
                       new TreeNode<>(3),
                       new TreeNode<>(15,
                                      new TreeNode<>(9),
                                      new TreeNode<>(20)));
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
