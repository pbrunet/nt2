//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_MEMORY_OVERLOAD_HPP_INCLUDED
#define BOOST_SIMD_MEMORY_OVERLOAD_HPP_INCLUDED

/*!
  @file
  @brief Defines SIMD aware new and delete overload decorator macro and class
**/

#include <cstddef>
#include <boost/simd/memory/allocate.hpp>
#include <boost/simd/memory/deallocate.hpp>
#include <boost/simd/memory/parameters.hpp>

/*!
  @brief Define alignment aware new and delete overload into a given POD type

  When used at class scope, BOOST_SIMD_MEMORY_OVERLOAD_NEW_DELETE generates
  code for overloaded new and delete operator that use aligned allocation
  function over an arbitrary alignment boundary @c Alignment.

  @param Alignment Alignment boundary in bytes to use for dynamic allocation
         of current type.
**/
#define BOOST_SIMD_MEMORY_OVERLOAD_NEW_DELETE(Alignment)                       \
void* operator new(std::size_t sz, const std::nothrow_t& throw_status)         \
{                                                                              \
  return boost::simd::allocate<Alignment>(sz, throw_status);                   \
}                                                                              \
                                                                               \
void* operator new(std::size_t sz)                                             \
{                                                                              \
  return boost::simd::allocate<Alignment>(sz);                                 \
}                                                                              \
                                                                               \
void* operator new[](std::size_t sz, const std::nothrow_t& throw_status)       \
{                                                                              \
  return boost::simd::allocate<Alignment>(sz, throw_status);                   \
}                                                                              \
                                                                               \
void* operator new[](std::size_t sz)                                           \
{                                                                              \
  return boost::simd::allocate<Alignment>(sz);                                 \
}                                                                              \
                                                                               \
void operator delete(void* m)                                                  \
{                                                                              \
  boost::simd::deallocate(m);                                                  \
}                                                                              \
                                                                               \
void operator delete[](void* m)                                                \
{                                                                              \
  boost::simd::deallocate(m);                                                  \
}                                                                              \
                                                                               \
void operator delete(void* m, const std::nothrow_t&)                           \
{                                                                              \
  boost::simd::deallocate(m);                                                  \
}                                                                              \
                                                                               \
void operator delete[](void* m, const std::nothrow_t&)                         \
{                                                                              \
  boost::simd::deallocate(m);                                                  \
}                                                                              \
/**/

/*!
  @brief Define SIMD aware new and delete overload into a given POD type

  When used at class scope, BOOST_SIMD_MEMORY_OVERLOAD_NEW_DELETE_SIMD generates
  code for overloaded new and delete operator that use aligned allocation
  function to satisfy current SIMD architecture alignment constraint.
**/
#define BOOST_SIMD_MEMORY_OVERLOAD_NEW_DELETE_SIMD()                           \
BOOST_SIMD_MEMORY_OVERLOAD_NEW_DELETE(BOOST_SIMD_CONFIG_ALIGNMENT)             \
/**/

namespace boost { namespace simd
{
  /*!
    @brief

    When used as a base class, aligned_object adds overloaded new and delete
    operators that use aligned allocation function over an arbitrary alignment
    boundary @c Alignment.

    @tparam Alignment Alignment boundary in bytes to use for dynamic allocation
            of child type.
  **/
  template<std::size_t Alignment = BOOST_SIMD_CONFIG_ALIGNMENT>
  struct aligned_object
  {
    public:

    /**
      @brief Static integral constant containing current alignment constraints

      alignment_value gives access to the alignment constraint from the
      child type.
     */
    static const std::size_t alignment_value = Alignment;

    #if !defined(DOXYGEN_ONLY)
    BOOST_SIMD_MEMORY_OVERLOAD_NEW_DELETE(Alignment)
    #endif
  };
} }

#endif
