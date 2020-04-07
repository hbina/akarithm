#pragma once

#include "tree_node.hpp"

#include <optional>
#include <stack>

namespace akarithm {

template <typename TreeType, typename ValueTy = typename TreeType::value_type>
class BSTIterator {
private:
  std::stack<TreeType *> stack;

  constexpr void parse_node(TreeType *input) {
    while (input) {
      stack.push(input);
      input = input->left;
    }
  }

public:
  constexpr BSTIterator(TreeType *root) { parse_node(root); }

  constexpr auto next() -> TreeType * {
    TreeType *result = stack.top();
    stack.pop();
    parse_node(result->right);
    return result;
  }

  constexpr auto peek() const -> TreeType * { return stack.top(); }

  constexpr auto hasNext() const -> bool { return !stack.empty(); }
};

} // namespace akarithm
