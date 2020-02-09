#pragma once

#include <string>
#include <algorithm>

template <typename ValueTy>
static constexpr bool
is_vowel(const ValueTy &x)
{
    return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' ||
           x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U';
}

namespace akarithm
{

template <typename Iterable>
static constexpr Iterable
reverseVowels(const Iterable &s)
{
    using CharTy =
        typename std::iterator_traits<
            typename Iterable::iterator>::value_type;
    Iterable letters;
    letters.reserve(s.size());
    std::copy_if(
        s.crbegin(),
        s.crend(),
        std::back_inserter(letters),
        is_vowel<CharTy>);
    Iterable result = s;
    std::transform(
        s.cbegin(),
        s.cend(),
        result.begin(),
        [c = letters.cbegin()](const CharTy &x) mutable {
            return is_vowel(x) ? *(c++) : x;
        });
    return result;
}

} // namespace akarithm
