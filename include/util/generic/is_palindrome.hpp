#pragma once

#include <iterator>

namespace aka {

template<typename IterTy,
         typename ValueTy = typename std::iterator_traits<IterTy>::value_type>
static constexpr auto
is_palindrome_UnCheckedOdd(IterTy iter_begin, IterTy iter_end) -> bool
{
  while (iter_begin != --iter_end) {
    if (*(iter_begin++) != *(iter_end))
      return false;
  }
  return *iter_begin == *iter_end;
}

template<typename IterTy,
         typename ValueTy = typename std::iterator_traits<IterTy>::value_type>
static constexpr auto
is_palindrome_UnCheckedEven(IterTy iter_begin, IterTy iter_end) -> bool
{
  while (iter_begin != iter_end) {
    if (*(iter_begin++) != *(--iter_end))
      return false;
  }
  return true;
}

template<typename IterTy,
         typename ValueTy = typename std::iterator_traits<IterTy>::value_type>
static constexpr auto
is_palindrome(IterTy iter_begin, IterTy iter_end) -> bool
{
  if (std::distance(iter_begin, iter_end) % 2)
    return aka::is_palindrome_UnCheckedOdd(iter_begin, iter_end);
  else
    return aka::is_palindrome_UnCheckedEven(iter_begin, iter_end);
}

} // namespace aka
