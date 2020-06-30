#include <doctest/doctest.h>

#include "data_structure/preorder_iterator.hpp"
#include "data_structure/tree_node.hpp"

TEST_CASE("preorder iterator")
{
  const aka::TreeNode<>* input = new aka::TreeNode<>(
    1,
    new aka::TreeNode<>(
      2,
      new aka::TreeNode<>(
        4, new aka::TreeNode<>(8), new aka::TreeNode<>(9)),
      new aka::TreeNode<>(
        5, new aka::TreeNode<>(10), new aka::TreeNode<>(11))),
    new aka::TreeNode<>(
      3,
      new aka::TreeNode<>(
        6, new aka::TreeNode<>(12), new aka::TreeNode<>(13)),
      new aka::TreeNode<>(
        7, new aka::TreeNode<>(14), new aka::TreeNode<>(15))));
  aka::PreorderIterator iterator = aka::PreorderIterator(input);
  CHECK(8 == iterator.next()->val);
  CHECK(4 == iterator.next()->val);
  CHECK(9 == iterator.next()->val);
  CHECK(2 == iterator.next()->val);
  CHECK(10 == iterator.next()->val);
  CHECK(5 == iterator.next()->val);
  CHECK(11 == iterator.next()->val);
  CHECK(1 == iterator.next()->val);
  CHECK(12 == iterator.next()->val);
  CHECK(6 == iterator.next()->val);
  CHECK(13 == iterator.next()->val);
  CHECK(3 == iterator.next()->val);
  CHECK(14 == iterator.next()->val);
  CHECK(7 == iterator.next()->val);
  CHECK(15 == iterator.next()->val);
  CHECK(false == iterator.hasNext());
  delete input;
}
