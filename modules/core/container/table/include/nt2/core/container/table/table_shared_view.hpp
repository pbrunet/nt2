//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_CONTAINER_TABLE_TABLE_SHARED_VIEW_HPP_INCLUDED
#define NT2_CORE_CONTAINER_TABLE_TABLE_SHARED_VIEW_HPP_INCLUDED

#include <nt2/core/container/dsl/forward.hpp>
#include <nt2/sdk/memory/container_ref.hpp>
#include <nt2/sdk/memory/container_shared_ref.hpp>
#include <nt2/core/container/table/adapted/table_shared_view.hpp>
#include <boost/dispatch/dsl/semantic_of.hpp>

namespace nt2 { namespace container
{
  /* table_shared_view; an expression of a container_shared_ref terminal.
   * allows construction from an expression of a container_shared_ref terminal */
  template<typename T, typename S>
  struct table_shared_view
       : expression< boost::proto::basic_expr < boost::proto::tag::terminal
                                              , boost::proto::term< memory
                                                                  ::container_shared_ref<T,S, nt2::tag::table_,false>
                                                                  >
                                              , 0l
                                              >
                   , memory::container<T, S, nt2::tag::table_>&
                   >
  {
    typedef memory::container_shared_ref< T, S, nt2::tag::table_, false >   container_ref;
    typedef boost::proto::basic_expr< boost::proto::tag::terminal
                                    , boost::proto::term<container_ref>
                                    , 0l
                                    >                     basic_expr;
    typedef memory::container<T, S, nt2::tag::table_>&                      container_type;
    typedef expression<basic_expr, container_type>        nt2_expression;

    typedef typename container_ref::iterator              iterator;
    typedef typename container_ref::const_iterator        const_iterator;

    iterator begin()  const { return boost::proto::value(*this).begin(); }
    iterator end()    const { return boost::proto::value(*this).end();   }

    BOOST_FORCEINLINE
    table_shared_view()
    {
    }

    BOOST_FORCEINLINE
    table_shared_view( nt2_expression const& expr )
                     : nt2_expression(expr)
    {
    }

    template<typename S2, typename Sema2, bool Own>
    BOOST_FORCEINLINE
    table_shared_view( expression<  boost::proto::basic_expr
                                    < boost::proto::tag::terminal
                                    , boost::proto::term< memory::container_shared_ref<T,S2,Sema2,Own> >
                                    , 0l
                                    >
                                 , memory::container<T, S2,Sema2>&
                                 > const& expr
                     )
                     : nt2_expression(basic_expr::make(boost::proto::value(expr)))
    {
    }

    using nt2_expression::operator=;
  };

  template<typename T, typename S>
  struct table_shared_view<T const, S>
       : expression <  boost::proto::basic_expr
                      < boost::proto::tag::terminal
                      , boost::proto::term< memory::container_shared_ref< T const, S, nt2::tag::table_, false >
                      >
                    , 0l
                    >
                   , memory::container<T, S, nt2::tag::table_> const&
                   >
  {
    typedef memory::container_shared_ref< T const, S, nt2::tag::table_, false >   container_ref;
    typedef boost::proto::basic_expr< boost::proto::tag::terminal
                                    , boost::proto::term<container_ref>
                                    , 0l
                                    >                           basic_expr;
    typedef memory::container<T, S, nt2::tag::table_> const&                      container_type;
    typedef expression<basic_expr, container_type>              nt2_expression;

    typedef typename container_ref::iterator                    iterator;
    typedef typename container_ref::const_iterator              const_iterator;

    iterator begin()  const { return boost::proto::value(*this).begin(); }
    iterator end()    const { return boost::proto::value(*this).end();   }

    BOOST_FORCEINLINE
    table_shared_view()
    {
    }

    BOOST_FORCEINLINE
    table_shared_view( nt2_expression const& expr )
                     : nt2_expression(expr)
    {
    }

    template<typename U, typename S2, typename Sema2, bool Own>
    BOOST_FORCEINLINE
    table_shared_view( expression < boost::proto::basic_expr
                                    < boost::proto::tag::terminal
                                    , boost::proto::term< memory::container_shared_ref<U,S2,Sema2,Own> >
                                    , 0l
                                    >
                                 , memory::container<U, S2, Sema2> /*const?*/&
                                 > const& expr
                     )
                     : nt2_expression(basic_expr::make(boost::proto::value(expr)))
    {
    }

    using nt2_expression::operator=;
  };
} }

namespace nt2
{
  using nt2::container::table_shared_view;
}

#endif
