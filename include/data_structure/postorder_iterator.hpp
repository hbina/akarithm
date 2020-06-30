#pragma once

#include <stack>

namespace aka {

template<typename TreeType, typename ValueTy = typename TreeType::value_type>
class PostorderIterator
{
private:
  std::stack<TreeType*> stack;

  constexpr void parse_right_of(TreeType* input)
  {
    while (input) {
      stack.push(input);
      input = input->right;
    }
  }

public:
  constexpr PostorderIterator(TreeType* root) { parse_right_of(root); }

  constexpr auto next() -> TreeType*
  {
    TreeType* result = stack.top();
    stack.pop();
    parse_right_of(result->left);
    return result;
  }

  constexpr auto peek() const -> TreeType* { return stack.top(); }

  constexpr auto hasNext() const -> bool { return !stack.empty(); }
};

} // namespace akarithm
