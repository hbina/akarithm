#pragma once

#include <stack>

namespace akarithm
{

template <
    typename TreeType,
    typename ValueType = typename TreeType::value_type>
class PostorderIterator
{
private:
    std::stack<const TreeType *> stack;

    constexpr void
    parse_right_of(const TreeType *input)
    {
        while (input)
        {
            stack.push(input);
            input = input->right;
        }
    }

public:
    constexpr PostorderIterator(const TreeType *root)
    {
        parse_right_of(root);
    }

    constexpr auto
    next()
        -> const TreeType *
    {
        const TreeType *result = stack.top();
        stack.pop();
        parse_right_of(result->left);
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
