
#pragma once

#include <stack>

namespace akarithm {

template <typename TreeType, typename ValueTy = typename TreeType::value_type>
class InorderIterator {
private:
  std::stack<TreeType *> stack;

  constexpr void parse_node(TreeType *input) {
    if (!input)
      return;
    if (input->right)
      stack.push(input->right);
    if (input->left)
      stack.push(input->left);
    stack.push(input);
  }

public:
  constexpr InorderIterator(TreeType *root) { stack.push(root); }

  constexpr auto next() -> TreeType * {
    TreeType *result = stack.top();
    stack.pop();
    parse_node(result);
    stack.pop();
    return result;
  }

  constexpr auto peek() const -> TreeType * { return stack.top(); }

  constexpr auto hasNext() const -> bool { return !stack.empty(); }
};

} // namespace akarithm
