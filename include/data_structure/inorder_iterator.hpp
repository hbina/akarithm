
#pragma once

#include <stack>

namespace akarithm
{

template <
    typename TreeType,
    typename ValueType = typename TreeType::value_type>
class InorderIterator
{
private:
    std::stack<const TreeType *> stack;

    constexpr void
    parse_node(const TreeType *input)
    {
        if (!input)
            return;
        if (input->right)
            stack.push(input->right);
        if (input->left)
            stack.push(input->left);
        stack.push(input);
    }

public:
    constexpr InorderIterator(const TreeType *root)
    {
        stack.push(root);
    }

    constexpr auto
    next()
        -> const TreeType *
    {
        const TreeType *result = stack.top();
        stack.pop();
        parse_node(result);
        stack.pop();
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
