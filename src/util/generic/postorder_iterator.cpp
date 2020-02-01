#include "doctest/doctest.h"

#include "data_structure/postorder_iterator.hpp"
#include "data_structure/tree_node.hpp"

TEST_CASE("preorder iterator")
{
    const TreeNode<> *input =
        new TreeNode<>(1,
                       new TreeNode<>(2,
                                      new TreeNode<>(4,
                                                     new TreeNode<>(8),
                                                     new TreeNode<>(9)),
                                      new TreeNode<>(5,
                                                     new TreeNode<>(10),
                                                     new TreeNode<>(11))),
                       new TreeNode<>(3,
                                      new TreeNode<>(6,
                                                     new TreeNode<>(12),
                                                     new TreeNode<>(13)),
                                      new TreeNode<>(7,
                                                     new TreeNode<>(14),
                                                     new TreeNode<>(15))));
    akarithm::PostorderIterator iterator =
        akarithm::PostorderIterator(input);
    CHECK(15 == iterator.next()->val);
    CHECK(7 == iterator.next()->val);
    CHECK(14 == iterator.next()->val);
    CHECK(3 == iterator.next()->val);
    CHECK(13 == iterator.next()->val);
    CHECK(6 == iterator.next()->val);
    CHECK(12 == iterator.next()->val);
    CHECK(1 == iterator.next()->val);
    CHECK(11 == iterator.next()->val);
    CHECK(10 == iterator.next()->val);
    CHECK(5 == iterator.next()->val);
    CHECK(2 == iterator.next()->val);
    CHECK(9 == iterator.next()->val);
    CHECK(4 == iterator.next()->val);
    CHECK(8 == iterator.next()->val);
    CHECK(false == iterator.hasNext());
    delete input;
}
