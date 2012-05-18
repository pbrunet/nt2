/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#define NT2_UNIT_MODULE "nt2::rowvect function"

#include <nt2/table.hpp>
#include <nt2/include/functions/rowvect.hpp>
#include <nt2/include/functions/size.hpp>
#include <nt2/include/functions/ones.hpp>
#include <nt2/include/functions/ndims.hpp>

#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>
#include <nt2/sdk/unit/tests/exceptions.hpp>

NT2_TEST_CASE_TPL( rowvect_ofsize, (float) )
{
  nt2::table<T> r;
  nt2::table<T, nt2::_2D> y( nt2::of_size(4,4) );

  for(int j=1;j<=4;j++)
    for(int i=1;i<=4;i++)
      y(i,j) = T(i + 10*j);

  r = nt2::rowvect(y);
  int k = 1; 
  for(int j=1;j<=4;j++)
    for(int i=1;i<=4;i++, k++)
      NT2_TEST_EQUAL( T(r(k)) , T(y(i, j)) );
  NT2_TEST_EQUAL( nt2::ndims(r)  , 2 );
  NT2_TEST_EQUAL( nt2::size(r,2) , numel(y) );
  NT2_TEST_EQUAL( nt2::size(r,1) , 1 );
  NT2_TEST_EQUAL( nt2::size(r,3) , 1 );

}

NT2_TEST_CASE_TPL( rowvect_size, (float) )
{
  nt2::table<T> r;
  nt2::table<T, nt2::_2D> y( nt2::of_size(4,4) );

  for(int j=1;j<=4;j++)
    for(int i=1;i<=4;i++)
      y(i,j) = T(i + 10*j);

  r = nt2::rowvect(y);
  int k = 1; 
  for(int j=1;j<=4;j++)
    for(int i=1;i<=4;i++, k++)
      NT2_TEST_EQUAL( T(r(k)) , T(y(i, j)) );
  NT2_TEST_EQUAL( nt2::ndims(r)  , 2 );
  NT2_TEST_EQUAL( nt2::size(r,2) , numel(y) );
  NT2_TEST_EQUAL( nt2::size(r,1) , 1 );
  NT2_TEST_EQUAL( nt2::size(r,3) , 1 );

}

