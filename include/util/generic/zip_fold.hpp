#pragma once

#include "util/generic/zip.hpp"

#include <iterator>

namespace aka {

template<typename OutputType,
         typename IterTyLhs,
         typename IterTyRhs,
         typename DotFunction,
         typename AddFunction>
static constexpr auto
zip_fold(IterTyLhs iter_lhs_begin,
         IterTyLhs iter_lhs_end,
         IterTyRhs iter_rhs_begin,
         IterTyRhs iter_rhs_end,
         OutputType acc,
         const DotFunction& dot,
         const AddFunction& add) -> OutputType
{
  while (iter_lhs_begin != iter_lhs_end && iter_rhs_begin != iter_rhs_end) {
    acc = add(acc, dot(*iter_lhs_begin, *iter_rhs_begin));
    iter_lhs_begin++;
    iter_rhs_begin++;
  }
  return acc;
}

} // namespace akarithm
