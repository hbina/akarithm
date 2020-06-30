#include <doctest/doctest.h>

#include "data_structure/bst_iterator.hpp"
#include "data_structure/tree_node.hpp"

TEST_CASE("bst iterator")
{
  const aka::TreeNode<>* input = new aka::TreeNode<>(
    7,
    new aka::TreeNode<>(3),
    new aka::TreeNode<>(
      15, new aka::TreeNode<>(9), new aka::TreeNode<>(20)));
  aka::BSTIterator iterator = aka::BSTIterator(input);
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
