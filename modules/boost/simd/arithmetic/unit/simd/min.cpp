//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/arithmetic/include/functions/min.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/constant/constant.hpp>

NT2_TEST_CASE_TPL ( min_real__2_0,  BOOST_SIMD_SIMD_REAL_TYPES)
{
  using boost::simd::min;
  using boost::simd::tag::min_;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<min_(vT,vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;

  // specific values tests
  NT2_TEST_ULP_EQUAL(min(boost::simd::Inf<vT>(), boost::simd::Inf<vT>())[0], boost::simd::Inf<T>(), 0);
  NT2_TEST_ULP_EQUAL(min(boost::simd::Minf<vT>(), boost::simd::Minf<vT>())[0], boost::simd::Minf<T>(), 0);
  NT2_TEST_ULP_EQUAL(min(boost::simd::Mone<vT>(), boost::simd::Mone<vT>())[0], boost::simd::Mone<T>(), 0);
  NT2_TEST_ULP_EQUAL(min(boost::simd::Nan<vT>(), boost::simd::Nan<vT>())[0], boost::simd::Nan<T>(), 0);
  NT2_TEST_ULP_EQUAL(min(boost::simd::One<vT>(), boost::simd::One<vT>())[0], boost::simd::One<T>(), 0);
  NT2_TEST_ULP_EQUAL(min(boost::simd::Zero<vT>(), boost::simd::Zero<vT>())[0], boost::simd::Zero<T>(), 0);
  NT2_TEST_ULP_EQUAL(min(boost::simd::Nan<vT>(), boost::simd::One<vT>())[0], boost::simd::One<T>(), 0);
  NT2_TEST_ULP_EQUAL(min(boost::simd::One<vT>(), boost::simd::Nan<vT>())[0], boost::simd::Nan<T>(), 0);


  std::cout << min(boost::simd::Nan<vT>(), boost::simd::One<vT>())[0] << std::endl;
  std::cout << min(boost::simd::One<vT>(), boost::simd::Nan<vT>())[0] << std::endl;
}

NT2_TEST_CASE_TPL ( min_integer__2_0,  BOOST_SIMD_SIMD_INTEGRAL_TYPES)
{
  using boost::simd::min;
  using boost::simd::tag::min_;
  using boost::simd::native;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;

  // specific values tests
  NT2_TEST_ULP_EQUAL(min(boost::simd::Inf<vT>(), boost::simd::Inf<vT>())[0], boost::simd::Inf<T>(), 0);
  NT2_TEST_ULP_EQUAL(min(boost::simd::Minf<vT>(), boost::simd::Minf<vT>())[0], boost::simd::Minf<T>(), 0);
  NT2_TEST_ULP_EQUAL(min(boost::simd::Mone<vT>(), boost::simd::Mone<vT>())[0], boost::simd::Mone<T>(), 0);
  NT2_TEST_ULP_EQUAL(min(boost::simd::Nan<vT>(), boost::simd::Nan<vT>())[0], boost::simd::Nan<T>(), 0);
  NT2_TEST_ULP_EQUAL(min(boost::simd::One<vT>(), boost::simd::One<vT>())[0], boost::simd::One<T>(), 0);
  NT2_TEST_ULP_EQUAL(min(boost::simd::Zero<vT>(), boost::simd::Zero<vT>())[0], boost::simd::Zero<T>(), 0);
}
