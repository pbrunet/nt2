//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_SDK_CONSTANT_IMPL_COMPLEX_COMMON_HPP_INCLUDED
#define BOOST_SIMD_SDK_CONSTANT_IMPL_COMPLEX_COMMON_HPP_INCLUDED

#include <nt2/include/functor.hpp> // for constant_ and functor
#include <nt2/include/functions/bitwise_cast.hpp>
#include <nt2/sdk/complex/hierarchy.hpp>
#include <nt2/sdk/complex/meta/as_real.hpp>

namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( constant_<Tag>, tag::cpu_, (Tag)(A0)
                            , ((target_< generic_< complex_< arithmetic_<A0> > > >))
                            )
  {
    typedef typename A0::type result_type;
    BOOST_DISPATCH_FORCE_INLINE result_type operator()(A0 const&) const
    {
      typedef typename meta::as_real<result_type>::type real_t;
      return result_type(boost::dispatch::functor<Tag>()(boost::dispatch::meta::as_<real_t>()));
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( constant_<Tag>, tag::cpu_, (Tag)(A0)
                            , ((target_< generic_< imaginary_< arithmetic_<A0> > > >))
                            )
  {
    typedef typename A0::type result_type;
    BOOST_DISPATCH_FORCE_INLINE result_type operator()(A0 const&) const
    {
      typedef typename meta::as_real<result_type>::type real_t;
      return bitwise_cast<result_type>(boost::dispatch::functor<Tag>()(boost::dispatch::meta::as_<real_t>()));
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( constant_<Tag>, tag::cpu_, (Tag)(A0)
                            , ((target_< generic_< dry_< arithmetic_<A0> > > >))
                            )
  {
    typedef typename A0::type result_type;

    BOOST_DISPATCH_FORCE_INLINE result_type operator()(A0 const&) const
    {
      typedef typename meta::as_real<result_type>::type real_t;
      return bitwise_cast<result_type>(boost::dispatch::functor<Tag>()(boost::dispatch::meta::as_<real_t>()));
    }
  };
} }

#endif
