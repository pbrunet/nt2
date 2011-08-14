//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_CONSTANT_CONSTANTS_GENERIC_MONE_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_CONSTANT_CONSTANTS_GENERIC_MONE_HPP_INCLUDED

#include <boost/simd/sdk/meta/float.hpp>
#include <boost/simd/sdk/meta/double.hpp>

namespace boost { namespace simd { namespace tag
{
  template<class Dummy>
  struct  Mone::apply<float,Dummy> 
        : meta::float_<0xbf800000UL> {};

  template<class Dummy>
  struct  Mone::apply<double,Dummy> 
        : meta::double_<0xbff0000000000000ULL> {};
} } }
#endif


