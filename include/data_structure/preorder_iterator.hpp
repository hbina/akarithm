#pragma once

#include <stack>

namespace akarithm
{

template <
    typename TreeType,
    typename ValueTy =
        typename TreeType::value_type>
class PreorderIterator
{
private:
    std::stack<const TreeType *> stack;

    constexpr void
    parse_left_of(const TreeType *input)
    {
        while (input)
        {
            stack.push(input);
            input = input->left;
        }
    }

public:
    constexpr PreorderIterator(const TreeType *root)
    {
        parse_left_of(root);
    }

    constexpr auto
    next()
        -> const TreeType *
    {
        const TreeType *result = stack.top();
        stack.pop();
        parse_left_of(result->right);
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
