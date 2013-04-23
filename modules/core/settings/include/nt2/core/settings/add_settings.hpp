//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_SETTINGS_ADD_SETTINGS_HPP_INCLUDED
#define NT2_CORE_SETTINGS_ADD_SETTINGS_HPP_INCLUDED

/*!
  @file
  @brief Defines the add_settings meta-function
**/

#include <nt2/core/settings/settings.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/proto/expr.hpp>

namespace nt2 { namespace meta
{
  /*!
    @brief

    @tparam
    @tparam
  **/
  template<typename Type, typename Settings = void>
  struct add_settings
  {
    typedef nt2::settings type(Type,Settings);
  };

  /// INTERNAL ONLY
  template<typename T, typename S>
  struct add_settings<T&, S>
  {
    typedef typename add_settings<T, S>::type& type;
  };

  /// INTERNAL ONLY
  template<typename T, typename S>
  struct add_settings<T const, S>
  {
    typedef typename add_settings<T, S>::type const type;
  };

  /// INTERNAL ONLY
  template<typename Type>
  struct add_settings<Type,void>
  {
    typedef Type type;
  };

  /// INTERNAL ONLY
  template<typename Type>
  struct add_settings<Type, nt2::settings()>
  {
    typedef Type type;
  };

  /// INTERNAL ONLY
  template<typename T0, typename S0>
  struct add_settings<nt2::settings(T0), nt2::settings(S0)>
  {
    typedef nt2::settings type(T0,S0);
  };

  /// INTERNAL ONLY
  template<typename T0>
  struct add_settings<nt2::settings(T0), void>
  {
    typedef T0 type;
  };

  /// INTERNAL ONLY
  #define M0(z,n,t)                                               \
  template<typename Type, BOOST_PP_ENUM_PARAMS(n,typename S)>     \
  struct add_settings< Type, settings(BOOST_PP_ENUM_PARAMS(n,S))> \
  {                                                               \
    typedef nt2::settings type(Type,BOOST_PP_ENUM_PARAMS(n,S));   \
  };                                                              \
  /**/

  /// INTERNAL ONLY
  BOOST_PP_REPEAT_FROM_TO(2,NT2_META_MAX_OPTIONS_NB,M0,~)

  #undef M0

  /// INTERNAL ONLY
  template<typename T, typename S>
  struct add_settings < boost::proto::basic_expr< boost::proto::tag::terminal
                                                , boost::proto::term<T>
                                                , 0l
                                                >
                      , S
                      >
  {
    typedef boost::proto::basic_expr< boost::proto::tag::terminal
                                    , boost::proto::term<typename add_settings<T, S>::type>
                                    , 0l
                                    >                               type;
  };

  /// INTERNAL ONLY
  template<typename Expr, typename Semantic, typename S>
  struct add_settings< nt2::container::expression<Expr, Semantic>, S >
  {
    typedef nt2::container::expression< typename add_settings<Expr, S>::type
                                      , typename add_settings<Semantic, S>::type
                                      >                             type;
  };
} }

#endif
