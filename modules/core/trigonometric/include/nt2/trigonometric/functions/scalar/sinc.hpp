//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TRIGONOMETRIC_FUNCTIONS_SCALAR_SINC_HPP_INCLUDED
#define NT2_TRIGONOMETRIC_FUNCTIONS_SCALAR_SINC_HPP_INCLUDED
#include <nt2/trigonometric/functions/sinc.hpp>
#include <nt2/include/functions/scalar/sin.hpp>
#include <nt2/include/functions/scalar/abs.hpp>
#include <nt2/include/functions/scalar/is_inf.hpp>
#include <nt2/include/constants/eps.hpp>
#include <nt2/include/constants/zero.hpp>
#include <nt2/include/constants/one.hpp>
#include <boost/simd/sdk/config.hpp>

namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::sinc_, tag::cpu_
                            , (A0)
                            , (scalar_< arithmetic_<A0> >)
                            )
  {
    typedef typename boost::dispatch::meta::as_floating<A0>::type result_type;
    NT2_FUNCTOR_CALL(1)
    {
      result_type z = a0;
      return z ? nt2::sin(z)/z : nt2::One<result_type>();
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::sinc_, tag::cpu_
                            , (A0)
                            , (scalar_< floating_<A0> >)
                            )
  {

    typedef A0 result_type;

    NT2_FUNCTOR_CALL(1)
    {
      #ifndef BOOST_SIMD_NO_INFINITIES
      if(nt2::is_inf(a0)) return nt2::Zero<A0>();
      #endif
      return (nt2::abs(a0) < nt2::Eps<A0>()) ? nt2::One<A0>() : nt2::sin(a0)/a0;
    }
  };
} }


#endif
