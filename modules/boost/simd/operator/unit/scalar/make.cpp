//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 operator toolbox - make/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of operator components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 18/02/2011
///
#include <boost/simd/operator/include/functions/make.hpp>
#include <boost/simd/sdk/simd/native.hpp>

#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/include/constants/real.hpp>
#include <boost/simd/include/constants/infinites.hpp>

//COMMENTED
NT2_TEST_CASE_TPL ( make_integer__2_0,  BOOST_SIMD_INTEGRAL_TYPES)
{

//   using boost::simd::make;
//   using boost::simd::tag::make_;
//   typedef typename boost::dispatch::meta::as_integer<T>::type iT;
//   typedef typename boost::dispatch::meta::call<make_(T,T)>::type r_t;
//   typedef typename boost::dispatch::meta::upgrade<T>::type u_t;
//   typedef T wished_r_t;


//   // return type conformity test
//   NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
//   std::cout << std::endl;

//   // specific values tests
//   NT2_TEST_EQUAL(make(boost::simd::One<T>(), boost::simd::One<T>()), boost::simd::One<r_t>());
//   NT2_TEST_EQUAL(make(boost::simd::One<T>(),boost::simd::Zero<T>()), boost::simd::Zero<r_t>());
//   NT2_TEST_EQUAL(make(boost::simd::Zero<T>(), boost::simd::Zero<T>()), boost::simd::Zero<r_t>());
// } // end of test for integer_

// NT2_TEST_CASE_TPL ( make_real__2_0,  BOOST_SIMD_REAL_TYPES)
// {

//   using boost::simd::make;
//   using boost::simd::tag::make_;
//   typedef typename boost::dispatch::meta::as_integer<T>::type iT;
//   typedef typename boost::dispatch::meta::call<make_(T,T)>::type r_t;
//   typedef typename boost::dispatch::meta::upgrade<T>::type u_t;
//   typedef T wished_r_t;


//   // return type conformity test
//   NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
//   std::cout << std::endl;

//   // specific values tests
//   NT2_TEST_EQUAL(make(boost::simd::Inf<T>(), boost::simd::Inf<T>()), boost::simd::Inf<r_t>());
//   NT2_TEST_EQUAL(make(boost::simd::Minf<T>(), boost::simd::Minf<T>()), boost::simd::Minf<r_t>());
//   NT2_TEST_EQUAL(make(boost::simd::Nan<T>(), boost::simd::Nan<T>()), boost::simd::Nan<r_t>());
//   NT2_TEST_EQUAL(make(boost::simd::One<T>(),boost::simd::Zero<T>()), boost::simd::Zero<r_t>());
//   NT2_TEST_EQUAL(make(boost::simd::Zero<T>(), boost::simd::Zero<T>()), boost::simd::Zero<r_t>());
// } // end of test for floating_
