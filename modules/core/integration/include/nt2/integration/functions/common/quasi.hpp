//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_INTEGRATION_FUNCTIONS_COMMON_QUASI_HPP_INCLUDED
#define NT2_INTEGRATION_FUNCTIONS_COMMON_QUASI_HPP_INCLUDED
#include <nt2/integration/functions/quasi.hpp>
#include <nt2/core/include/functions/as_size.hpp>
#include <nt2/core/container/table/table.hpp>
#include <nt2/include/functions/run.hpp>
#include <nt2/include/functions/zeros.hpp>
#include <nt2/include/functions/sobol.hpp>
#include <nt2/include/functions/complement.hpp>
#include <nt2/include/functions/bitwise_xor.hpp>
#include <nt2/include/functions/ldexp.hpp>
#include <nt2/include/functions/multiplies.hpp>
#include <nt2/include/functions/minusone.hpp>
#include <nt2/include/functions/unary_minus.hpp>
#include <nt2/include/functions/ffs.hpp>
#include <nt2/include/functions/tofloat.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/include/constants/nbmantissabits.hpp>
#include <nt2/core/container/table/table.hpp>
namespace nt2 { namespace ext
{

  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::quasi_, tag::cpu_,
                              (A0)(A1),
                              (scalar_<integer_<A0> >)
                              (scalar_<integer_<A1> >)
    )
  {
    typedef typename  boost::proto::
      result_of::make_expr< nt2::tag::quasi_
      , container::domain
      , size_t
      , size_t
      , box<_2D>
      >::type             result_type;

    BOOST_FORCEINLINE result_type operator()(A0 const& a0, A1 const& a1) const
    {
      _2D sizee;
      sizee[0] = a0; sizee[1] = a1;
      return  boost::proto::
        make_expr<nt2::tag::quasi_, container::domain>
        ( size_t(a0)
        , size_t(a1)
        , boxify(sizee)
        );
    }
  };
  //============================================================================
  // rand evaluation
  //============================================================================
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::run_assign_, tag::cpu_
                            , (A0)(A1)(N)
                            , ((ast_<A0, nt2::container::domain>))
                              ((node_ < A1,nt2::tag::quasi_
                                      , N
                                      , nt2::container::domain
                                      >
                              ))
                            )
  {
    typedef A0&                                                  result_type;
    typedef typename A0::value_type                                   f_type;
    typedef typename nt2::meta::as_integer<f_type, unsigned>::type uint_type;
    typedef typename nt2::meta::as_integer<f_type>::type            int_type;
    typedef typename nt2::container::table<uint_type>                 tabi_t;

    result_type operator()(A0& x, A1& a1) const
    {
      uint_type dim =  boost::proto::child_c<0>(a1);
      uint_type nbpts = boost::proto::child_c<1>(a1);
      uint_type maxbit = nt2::Nbmantissabits<f_type>();
      int_type mmaxbit = -maxbit;
      static uint_type index = 0;
      static tabi_t ix =  nt2::zeros(nt2::of_size(dim, 1), nt2::meta::as_<uint_type>());
      static tabi_t iv =  sobol(dim);
      x.resize(nt2::of_size(dim, nbpts));
      nt2::container::table<uint_type> i = nt2::ffs(nt2::complement(nt2::_(index, index+nbpts-1)));
      for(uint_type l=1; l <= nbpts; ++l) //can we suppress this loop ?
      {
        ix = nt2::bitwise_xor(ix, iv(nt2::_(1, dim), i(l)));
        x(nt2::_, l)  = nt2::ldexp(nt2::tofloat(ix), mmaxbit);
      }
      index+= nbpts+1;
      return x;
    }
  };
} }

#endif
