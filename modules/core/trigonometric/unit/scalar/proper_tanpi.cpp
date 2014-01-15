//==============================================================================
//         Copyright 2003 - 2013   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2013   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <nt2/trigonometric/include/functions/proper_tanpi.hpp>

#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>
#include <nt2/sdk/unit/tests/type_expr.hpp>
#include <nt2/sdk/unit/tests/ulp.hpp>
#include <nt2/sdk/unit/tests/basic.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/sdk/config.hpp>

#include <nt2/include/constants/half.hpp>
#include <nt2/include/constants/mhalf.hpp>
#include <nt2/include/constants/mone.hpp>
#include <nt2/include/constants/one.hpp>
#include <nt2/include/constants/quarter.hpp>
#include <nt2/include/constants/zero.hpp>
#include <nt2/include/constants/inf.hpp>
#include <nt2/include/constants/minf.hpp>
#include <nt2/include/constants/nan.hpp>

NT2_TEST_CASE_TPL ( proper_tanpi_real,  NT2_REAL_TYPES)
{
  using nt2::proper_tanpi;
  using nt2::tag::proper_tanpi_;

  typedef typename nt2::meta::call<proper_tanpi_(T)>::type r_t;
  typedef T wished_r_t;

  // return type conformity test
  NT2_TEST_TYPE_IS(r_t, wished_r_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  NT2_TEST_ULP_EQUAL(proper_tanpi(nt2::Half<T>()), nt2::Inf<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(proper_tanpi(nt2::Inf<T>()), nt2::Nan<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(proper_tanpi(nt2::Mhalf<T>()), nt2::Minf<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(proper_tanpi(nt2::Minf<T>()), nt2::Nan<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(proper_tanpi(nt2::Mone<T>()), nt2::Nan<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(proper_tanpi(nt2::Nan<T>()), nt2::Nan<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(proper_tanpi(nt2::One<T>()), nt2::Nan<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(proper_tanpi(nt2::Nan<T>()), nt2::Nan<r_t>(), 0);
#endif
  NT2_TEST_ULP_EQUAL(proper_tanpi(-nt2::Quarter<T>()), nt2::Mone<r_t>(), 1.0);
  NT2_TEST_ULP_EQUAL(proper_tanpi(nt2::Quarter<T>()), nt2::One<r_t>(), 1.0);
  NT2_TEST_ULP_EQUAL(proper_tanpi(nt2::Zero<T>()), nt2::Zero<r_t>(), 0.5);
}
