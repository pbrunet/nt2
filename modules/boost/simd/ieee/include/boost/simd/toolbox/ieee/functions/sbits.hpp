//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef BOOST_SIMD_TOOLBOX_IEEE_FUNCTIONS_SBITS_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_IEEE_FUNCTIONS_SBITS_HPP_INCLUDED
#include <boost/simd/include/simd.hpp>
#include <boost/dispatch/include/functor.hpp>

/*!
 * \internal functor \endinternal
 * \ingroup boost_simd_ieee
 * \defgroup sbits sbits function
 *
 * \par Description
 * The function return signed integer value which has the same bits of the input
 *
 * \par Header file
 * 
 * \code
 * #include <nt2/include/functions/sbits.hpp>
 * \endcode
 * 
 * 
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template <class A0>
 *     meta::call<tag::sbits_(A0)>::type
 *     sbits(const A0 & a0);
 * }
 * \endcode
 *
 * \param a0 is the unique parameter of sbits
 * 
 * \return a value of the same type as the parameter
 *  
 * \internal end_functor \endinternal
**/

namespace boost { namespace simd { namespace tag
  {         
    /*!
     * \internal tag \endinternal
     * \file
     * \brief Define the tag sbits_ of functor sbits 
     *        in namespace boost::simd::tag
     * \internal end_tag \endinternal
    **/
    struct sbits_ {};
  }
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::sbits_, sbits, 1)
} }

#endif

// modified by jt the 25/12/2010
