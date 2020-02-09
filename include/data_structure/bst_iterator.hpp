#pragma once

#include "tree_node.hpp"

#include <stack>
#include <optional>

namespace akarithm
{

template <
    typename TreeType,
    typename ValueTy =
        typename TreeType::value_type>
class BSTIterator
{
private:
    std::stack<const TreeType *> stack;

    constexpr void
    parse_node(const TreeType *input)
    {
        while (input)
        {
            stack.push(input);
            input = input->left;
        }
    }

public:
    constexpr BSTIterator(const TreeType *root)
    {
        parse_node(root);
    }

    constexpr auto
    next()
        -> const TreeType *
    {
        const TreeType *result = stack.top();
        stack.pop();
        parse_node(result->right);
        return result;
    }

    constexpr auto
    peek() const
        -> const TreeType *
    {
        return stack.top();
    }

    constexpr auto
    hasNext() const
        -> bool
    {
        return !stack.empty();
    }
};

} // namespace akarithm
