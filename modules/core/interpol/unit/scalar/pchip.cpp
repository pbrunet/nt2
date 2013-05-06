//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2::pchip function"

#include <nt2/table.hpp>
#include <nt2/include/functions/pchip.hpp>
#include <nt2/include/functions/linspace.hpp>
#include <nt2/include/functions/isequal.hpp>
#include <nt2/include/functions/sqr.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>
#include <nt2/sdk/unit/tests/basic.hpp>

NT2_TEST_CASE_TPL( pchip, (float))//(double))//NT2_TYPES )
{
  using nt2::_;
  nt2::table<T> x =  nt2::linspace(T(1),  T(4), 4);
  nt2::table<T> y =  nt2::sqr(nt2::linspace(T(2),  T(8), 4));
  nt2::table<T> xi=  nt2::linspace(T(1),  T(4), 7);
  T tr0[] = {4.0000,    9.1250,   16.0000,   24.95833333333333333,   36.0000,   48.9166666666666666,   64.0000};
  nt2::table<T> r0(nt2::of_size(1, 7), &tr0[0], &tr0[7]);
  NT2_DISPLAY(x);
  NT2_DISPLAY(y);
  NT2_DISPLAY(xi);
  nt2::table<T> yi =nt2::pchip(x, y, xi);
  std::cout << "extrap " <<  false <<  " extrapval " << "-" << std::endl;
  NT2_DISPLAY(yi);
  yi =nt2::pchip(x, y, xi, false);
  NT2_TEST_ULP_EQUAL(yi, r0, 10.0);
  std::cout << "extrap " <<  false <<  " extrapval " << "-" << std::endl;
  NT2_DISPLAY(yi);
  NT2_TEST_ULP_EQUAL(yi, r0, 10.0);

  std::cout << "extrap " <<  true <<  " extrapval " << "-" << std::endl;
  yi =nt2::pchip(x, y, xi, true);
  NT2_DISPLAY(yi);
  T z =  33;
  std::cout << "extrap " <<  "-" <<  " extrapval " << "33" << std::endl;
  yi =nt2::pchip(x, y, xi, z);
  NT2_TEST_ULP_EQUAL(yi, r0, 10.0);

  NT2_DISPLAY(yi);
  std::cout << "extrap " <<  "-" <<  " extrapval " << "33" << std::endl;
  yi =nt2::pchip(x, y, xi, T(33));
  NT2_DISPLAY(yi);
  NT2_TEST_ULP_EQUAL(yi, r0, 10.0);

}

NT2_TEST_CASE_TPL( pchip2, (float)(double))//NT2_TYPES )
{
  using nt2::_;
  nt2::table<T> x =  nt2::linspace(T(1),  T(4), 4);
  nt2::table<T> y =  nt2::linspace(T(2),  T(8), 4);
  nt2::table<T> xi=  nt2::linspace(T(1),  T(4), 11);
  NT2_DISPLAY(x);
  NT2_DISPLAY(y);
  NT2_DISPLAY(xi);
  nt2::table<T> y0 =nt2::pchip(x, y, xi), yi;
  std::cout << "extrap " <<  false <<  " extrapval " << "-" << std::endl;
  NT2_DISPLAY(y0);
  y0 =nt2::pchip(x, y, xi, false);
  std::cout << "extrap " <<  false <<  " extrapval " << "-" << std::endl;
  NT2_DISPLAY(yi);
  std::cout << "extrap " <<  true <<  " extrapval " << "-" << std::endl;
  yi =nt2::pchip(x, y, xi, true);
  NT2_TEST_EQUAL(y0, yi);
  NT2_DISPLAY(yi);
  T z =  33;
  std::cout << "extrap " <<  "-" <<  " extrapval " << "33" << std::endl;
  yi =nt2::pchip(x, y, xi, z);
  NT2_DISPLAY(yi);
  NT2_TEST_EQUAL(y0, yi);
  std::cout << "extrap " <<  "-" <<  " extrapval " << "33" << std::endl;
  yi =nt2::pchip(x, y, xi, T(33));
  NT2_DISPLAY(yi);
  NT2_TEST_EQUAL(y0, yi);
}
