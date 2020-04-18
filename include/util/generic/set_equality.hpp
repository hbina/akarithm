#include <type_traits>
#include <unordered_set>

//  TODO    ::  Implement set_equality_If
namespace akarithm {

template<typename IterTyLhs,
         typename IterTyRhs,
         typename = std::enable_if<std::is_same_v<
           typename std::iterator_traits<IterTyLhs>::value_type,
           typename std::iterator_traits<IterTyRhs>::value_type>>>
static constexpr auto
set_equality(IterTyLhs lhs_begin,
             IterTyLhs lhs_end,
             IterTyRhs rhs_begin,
             IterTyRhs rhs_end) -> bool
{
  using ValueTy =
    std::common_type_t<typename std::iterator_traits<IterTyLhs>::value_type,
                       typename std::iterator_traits<IterTyRhs>::value_type>;
  const auto lhs = std::unordered_set<ValueTy>(lhs_begin, lhs_end);
  const auto rhs = std::unordered_set<ValueTy>(rhs_begin, rhs_end);
  return lhs == rhs;
}

template<
  typename IterTyLhs,
  typename IterTyRhs,
  typename = std::enable_if<std::is_same_v<typename IterTyLhs::value_type,
                                           typename IterTyRhs::value_type>>>
static constexpr bool
set_equality(IterTyLhs lhs, IterTyRhs rhs)
{
  return set_equality(
    std::cbegin(lhs), std::cend(lhs), std::cbegin(rhs), std::cend(rhs));
}

} // namespace akarithm
