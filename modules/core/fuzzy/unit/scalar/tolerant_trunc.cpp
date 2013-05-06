//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 fuzzy toolbox - tolerant_trunc/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of fuzzy components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 04/03/2011
///
#include <nt2/fuzzy/include/functions/tolerant_trunc.hpp>
#include <nt2/include/constants/eps.hpp>
#include <nt2/include/constants/mone.hpp>
#include <nt2/include/constants/two.hpp>
#include <nt2/include/constants/zero.hpp>
#include <nt2/sdk/simd/logical.hpp>

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


NT2_TEST_CASE_TPL ( tolerant_trunc_real__3_0,  NT2_REAL_TYPES)
{

  using nt2::tolerant_trunc;
  using nt2::tag::tolerant_trunc_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<tolerant_trunc_(T)>::type r_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef T wished_r_t;


  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_EQUAL(tolerant_trunc(nt2::One<T>()), nt2::One<r_t>());
  NT2_TEST_EQUAL(tolerant_trunc(nt2::One<T>()-nt2::Eps<T>()), nt2::One<r_t>());
  NT2_TEST_EQUAL(tolerant_trunc(nt2::One<T>()-nt2::Two<T>()*nt2::Eps<T>()), nt2::One<r_t>());
  NT2_TEST_EQUAL(tolerant_trunc(nt2::One<T>()-nt2::Three<T>()*nt2::Eps<T>()), nt2::One<r_t>());
  NT2_TEST_EQUAL(tolerant_trunc(nt2::One<T>()-nt2::Four<T>()*nt2::Eps<T>()), nt2::Zero<r_t>());
} // end of test for floating_


