//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_HYPERBOLIC_FUNCTIONS_GENERIC_COTH_HPP_INCLUDED
#define NT2_HYPERBOLIC_FUNCTIONS_GENERIC_COTH_HPP_INCLUDED
#include <nt2/hyperbolic/functions/coth.hpp>
#include <nt2/include/functions/tanh.hpp>
#include <nt2/include/functions/rec.hpp>
#include <nt2/include/functions/if_allbits_else.hpp>
#include <nt2/include/functions/is_eqz.hpp>
#include <nt2/include/functions/tofloat.hpp>


namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::coth_, tag::cpu_
                            , (A0)
                            , (generic_< arithmetic_<A0> >)
                            )
  {

    typedef typename boost::dispatch::meta::as_floating<A0>::type result_type;

    NT2_FUNCTOR_CALL(1)
    {
      return nt2::if_nan_else(nt2::is_eqz(a0), nt2::rec(nt2::tanh(nt2::tofloat(a0))));
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::coth_, tag::cpu_
                            , (A0)
                            , (generic_< floating_<A0> >)
                            )
  {

    typedef A0 result_type;

    NT2_FUNCTOR_CALL(1)
    {
      return nt2::rec(nt2::tanh(a0));
    }
  };
} }


#endif
