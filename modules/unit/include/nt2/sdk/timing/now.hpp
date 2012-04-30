//==============================================================================
//         Copyright 2003 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_SDK_TIMING_NOW_HPP_INCLUDED
#define NT2_SDK_TIMING_NOW_HPP_INCLUDED

#include <nt2/sdk/config/types.hpp>
#include <nt2/sdk/timing/config.hpp>

namespace nt2 { namespace details
{
  typedef nt2::uint64_t   cycles_t;
  NT2_UNIT_DECL double    now();
  inline cycles_t         read_cycles();
} }

#include <nt2/sdk/timing/details/cycles.hpp>

#endif
