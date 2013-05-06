//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 trigonometric toolbox - rem_pio2_medium/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// cover test behavior of trigonometric components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 11/02/2011
///
#include <nt2/trigonometric/include/functions/rem_pio2_medium.hpp>
#include <nt2/include/functions/max.hpp>
#include <boost/fusion/tuple.hpp>
#include <nt2/trigonometric/constants.hpp>
#include <nt2/trigonometric/include/functions/rem_pio2.hpp>

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


NT2_TEST_CASE_TPL ( rem_pio2_medium_real__1_0,  NT2_REAL_TYPES)
{

  using nt2::rem_pio2_medium;
  using nt2::tag::rem_pio2_medium_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<rem_pio2_medium_(T)>::type r_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename nt2::meta::call<rem_pio2_medium_(T)>::type wished_r_t;
  typedef typename nt2::meta::call<nt2::tag::rem_pio2_(T)>::type f_t;



  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;
  double ulpd;
  ulpd=0.0;

  // random verifications
  static const nt2::uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    NT2_CREATE_BUF(tab_a0,T, NR, nt2::Zero<T>(), 64*nt2::Pi<T>());
    double ulp0, ulpd ; ulpd=ulp0=0.0;
    T a0;
    for(nt2::uint32_t j =0; j < NR; ++j )
      {
        std::cout << "for param "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << std::endl;
        r_t r = nt2::rem_pio2_medium(a0);
        f_t rf= nt2::rem_pio2(a0);
        NT2_TEST_ULP_EQUAL( r.second, boost::fusion::get<1>(nt2::rem_pio2(a0)), 0.5);
        if (ulpd>ulp0) ulp0=ulpd;
        NT2_TEST_ULP_EQUAL( r.first, boost::fusion::get<0>(nt2::rem_pio2(a0)), 0);
        if (ulpd>ulp0) ulp0=ulpd;

//         r_t0 r0 = boost::fusion::get<1>(r);
//         r_t1 r2 = boost::fusion::get<0>(r);
//         NT2_TEST_ULP_EQUAL( r0, boost::fusion::get<0>(nt2::rem_pio2(a0)), 0.5);
//         if (ulpd>ulp0) ulp0=ulpd;
//         NT2_TEST_ULP_EQUAL( r2, boost::fusion::get<1>(nt2::rem_pio2(a0)), 0);
//         if (ulpd>ulp0) ulp0=ulpd;
     }
     std::cout << "max ulp found is: " << ulp0 << std::endl;
   }
} // end of test for floating_
