//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 predicates toolbox - is_ord/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// cover test behavior of predicates components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 21/02/2011
///
#include <nt2/predicates/include/functions/is_ord.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <nt2/include/functions/max.hpp>
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
#include <nt2/sdk/meta/cardinal_of.hpp>
#include <nt2/include/functions/splat.hpp>
#include <nt2/include/functions/load.hpp>
#include <nt2/constant/constant.hpp>


NT2_TEST_CASE_TPL ( is_ord_real__2_0,  NT2_SIMD_REAL_TYPES)
{
  using nt2::is_ord;
  using nt2::tag::is_ord_;
  using nt2::load;
  using boost::simd::native;
  using nt2::meta::cardinal_of;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<is_ord_(vT,vT)>::type r_t;
  typedef typename nt2::meta::call<is_ord_(T,T)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;

  // random verifications
  static const nt2::uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    NT2_CREATE_BUF(tab_a0,T, NR, T(-10000), T(10000));
    NT2_CREATE_BUF(tab_a1,T, NR, T(-10000), T(10000));
    double ulp0, ulpd ; ulpd=ulp0=0.0;
    for(nt2::uint32_t j = 0; j < NR;j+=cardinal_of<n_t>::value)
      {
        vT a0 = load<vT>(&tab_a0[0],j);
        vT a1 = load<vT>(&tab_a1[0],j);
        r_t v = is_ord(a0,a1);
        for(nt2::uint32_t i = 0; i< cardinal_of<n_t>::value; i++)
        {

          NT2_TEST_EQUAL( v[i],ssr_t(nt2::is_ord (a0[i],a1[i])));
        }
      }

  }
} // end of test for floating_
