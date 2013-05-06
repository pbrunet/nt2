//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 complex.exponential toolbox - exp2/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of exponential components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 08/12/2010
///
#include <nt2/include/functions/exp2.hpp>
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/sdk/meta/as_floating.hpp>
#include <nt2/sdk/meta/as_signed.hpp>
#include <nt2/sdk/meta/upgrade.hpp>
#include <nt2/sdk/meta/downgrade.hpp>
#include <nt2/sdk/meta/scalar_of.hpp>
#include <boost/dispatch/meta/as_floating.hpp>
#include <boost/type_traits/common_type.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>

#include <nt2/constant/constant.hpp>


NT2_TEST_CASE_TPL ( exp2_real__1_0,  NT2_REAL_TYPES)
{

  using nt2::exp2;
  using nt2::tag::exp2_;
  typedef std::complex<T> cT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<exp2_(cT)>::type r_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename nt2:: meta::as_complex<T>::type wished_r_t;


  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;
  double ulpd;
  ulpd=0.0;

  // specific values tests
  NT2_TEST_ULP_EQUAL(exp2(cT(nt2::Inf<T>())), cT(nt2::Inf<T>()), 0);
  NT2_TEST_EQUAL(exp2(cT(nt2::Minf<T>())), cT(nt2::Zero<T>()));
  NT2_TEST_EQUAL(exp2(cT(nt2::Mone<T>())), cT(nt2::Half<T>()));
  NT2_TEST_EQUAL(exp2(cT(nt2::Nan<T>())), cT(nt2::Nan<T>()));
  NT2_TEST_EQUAL(exp2(cT(nt2::One<T>())), cT(nt2::Two<T>()));
  NT2_TEST_EQUAL(exp2(cT(nt2::Zero<T>())), cT(nt2::One<T>()));
} // end of test for floating_
