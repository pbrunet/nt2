/*******************************************************************************
 *         Copyright 2003-2012 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2011-2012 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_TOOLBOX_LINALG_FUNCTIONS_DETAILS_FULL_LU_SOLVE_HPP_INCLUDED
#define NT2_TOOLBOX_LINALG_FUNCTIONS_DETAILS_FULL_LU_SOLVE_HPP_INCLUDED

#include <nt2/toolbox/linalg/details/lapack/gesvx.hpp>   
#include <nt2/table.hpp>
#include <nt2/include/functions/height.hpp>
#include <nt2/include/functions/width.hpp>
#include <iostream>

//==============================================================================
// svd actual functor forward declaration
//==============================================================================

namespace nt2 { namespace details
{
  //============================================================================
  // full_lu_solve actual functor
  //============================================================================
  template<class A, class B = A> struct full_lu_solve_result
  {
    typedef typename A::value_type                       type_t;
    typedef typename A::index_type                      index_t; 
    typedef typename meta::as_real<type_t>::type        btype_t; 
    typedef nt2::table<type_t,nt2::matlab_index_>        ftab_t;
    typedef nt2::table<btype_t,nt2::matlab_index_>      fbtab_t;
    typedef nt2::table<nt2_la_int,nt2::matlab_index_>   fitab_t;
    typedef nt2::table<type_t,index_t>                    tab_t;
    typedef nt2::table<btype_t,index_t>                  btab_t;
    typedef nt2::table<nt2_la_int,index_t>               itab_t;
    
    ////////////////////////////////////////////////////////////////////////////
    // General LU Solver
    //  A is            N x N
    //  B is            N x nrhs
    ////////////////////////////////////////////////////////////////////////////
    full_lu_solve_result(A& a, B& b, const char & trans)
      :
      a_(a)
      , b_(b)
      , lda_(a_.leading_size())
      , ldb_(b_.leading_size())
      , n_(height(a))
      , nrhs_(width(b))
      , x_(nt2::of_size(n_, nrhs_))
      , ipiv_(nt2::of_size(n_, 1))
      , af_(nt2::of_size(n_, n_))
      , ferr_( nt2::of_size(n_, 1))
      , berr_( nt2::of_size(n_, 1))
      , r_( nt2::of_size(n_, 1))
      , c_( nt2::of_size(n_, 1))
    {
      char fact = 'N';
      char equed = 'N';
      nt2_la_int ldaf = af_.leading_size();
      nt2_la_int ldx  = x_.leading_size(); 
      nt2::details::gesvx (&fact, &trans, &n_, &nrhs_, a_.raw(), &lda_,
                          af_.raw(), &ldaf, ipiv_.raw(), &equed,
                          r_.raw(), c_.raw(), 
                          b_.raw(), &ldb_,
                          x_.raw(), &ldx, &rcond_,
                          ferr_.raw(), berr_.raw(), &info_);
      //NOT THERE      BOOST_ASSERT_MSG(info == 0, "Warning: Matrix is singular to working precision.");
    }
    ~full_lu_solve_result(){}
    itab_t ipiv()       const { return ipiv_; }
    btype_t rcond()     const { return rcond_;}
    nt2_la_int status() const { return info_; }
    tab_t  ferr()       const { return ferr_; }
    tab_t  berr()       const { return berr_; }
    tab_t  x()          const { return x_;    }
  private:
    ftab_t                a_;
    ftab_t                b_;
    nt2_la_int          lda_;
    nt2_la_int          ldb_;
    nt2_la_int            n_;
    nt2_la_int         nrhs_; 
    ftab_t                x_;
    fitab_t            ipiv_;
    nt2_la_int         info_;
    ftab_t               af_;
    ftab_t             ferr_;
    ftab_t             berr_;
    ftab_t                r_;
    ftab_t                c_;
    btype_t           rcond_; 
  };  
} }


#endif
