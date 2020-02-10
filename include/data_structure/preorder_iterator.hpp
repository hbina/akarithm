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
    std::stack<TreeType *> stack;

    constexpr void
    parse_left_of(TreeType *input)
    {
        while (input)
        {
            stack.push(input);
            input = input->left;
        }
    }

public:
    constexpr PreorderIterator(TreeType *root)
    {
        parse_left_of(root);
    }

    constexpr auto
    next()
        -> TreeType *
    {
        TreeType *result = stack.top();
        stack.pop();
        parse_left_of(result->right);
        return result;
    }

    constexpr auto
    peek() const
        -> TreeType *
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
