#pragma once

#include <vector>

namespace akarithm {

template<typename ValueTy = int>
class Node
{
public:
  ValueTy val;
  std::vector<Node<ValueTy>*> children;

  constexpr Node() = delete;

  constexpr Node(const ValueTy& p_val)
    : val(p_val)
  {}

  constexpr Node(const ValueTy& p_val,
                 const std::vector<Node<ValueTy>*>& p_children)
    : val(p_val)
    , children(p_children)
  {}

  constexpr ~Node()
  {
    for (Node<ValueTy>* x : children) {
      delete x;
    }
  }
};

} // namespace akarithm
