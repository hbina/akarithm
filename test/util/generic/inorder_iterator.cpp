#include "doctest/doctest.h"

#include "data_structure/inorder_iterator.hpp"
#include "data_structure/tree_node.hpp"

TEST_CASE("preorder iterator")
{
  const akarithm::TreeNode<>* input = new akarithm::TreeNode<>(
    1,
    new akarithm::TreeNode<>(
      2,
      new akarithm::TreeNode<>(
        4, new akarithm::TreeNode<>(8), new akarithm::TreeNode<>(9)),
      new akarithm::TreeNode<>(
        5, new akarithm::TreeNode<>(10), new akarithm::TreeNode<>(11))),
    new akarithm::TreeNode<>(
      3,
      new akarithm::TreeNode<>(
        6, new akarithm::TreeNode<>(12), new akarithm::TreeNode<>(13)),
      new akarithm::TreeNode<>(
        7, new akarithm::TreeNode<>(14), new akarithm::TreeNode<>(15))));
  akarithm::InorderIterator iterator = akarithm::InorderIterator(input);
  CHECK(1 == iterator.next()->val);
  CHECK(2 == iterator.next()->val);
  CHECK(4 == iterator.next()->val);
  CHECK(8 == iterator.next()->val);
  CHECK(9 == iterator.next()->val);
  CHECK(5 == iterator.next()->val);
  CHECK(10 == iterator.next()->val);
  CHECK(11 == iterator.next()->val);
  CHECK(3 == iterator.next()->val);
  CHECK(6 == iterator.next()->val);
  CHECK(12 == iterator.next()->val);
  CHECK(13 == iterator.next()->val);
  CHECK(7 == iterator.next()->val);
  CHECK(14 == iterator.next()->val);
  CHECK(15 == iterator.next()->val);
  CHECK(false == iterator.hasNext());
  delete input;
}
