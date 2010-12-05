{ 'arity': 1,
  'dptch': ['float', 'double', 'arithmetic_'],
  'incld': ['#include <nt2/include/functions/exponent.hpp>'],
  'norst': False,
  'notes': [],
  'rnges': { 'real_': [['T(0)', 'T(10)']],
             'signed_int_': [['0', '100']],
             'unsigned_int_': [['0', '100']]},
  'rturn': { 'default': 'typename nt2::meta::as_integer<T, signed>::type'},
  'specv': { 'default': { },
             'real_': { 
                        'nt2::Minf<T>()': 'nt2::Zero<r_t>()',
                        'nt2::Mone<T>()': 'nt2::Zero<r_t>()',
                        'nt2::Nan<T>()': 'nt2::Zero<r_t>()',
                        'nt2::One<T>()': 'nt2::Zero<r_t>()',
                        'nt2::Zero<T>()': 'nt2::Zero<r_t>()',
                        'nt2::Two<T>()': 'nt2::One<r_t>()'},
             'signed_int_': { 'nt2::Mone<T>()': 'nt2::Zero<r_t>()',
                              'nt2::One<T>()': 'nt2::Zero<r_t>()',
                              'nt2::Zero<T>()': 'nt2::Zero<r_t>()',
                              'nt2::Two<T>()': 'nt2::One<r_t>()'},
             'unsigned_int_': { 'nt2::One<T>()': 'nt2::Zero<r_t>()',
                                'nt2::Zero<T>()': 'nt2::Zero<r_t>()',
                                'nt2::Two<T>()': 'nt2::One<r_t>()'}},
  'stamp': 'modified by jt the 04/12/2010',
  'tcall': {"real_" : "nt2::exponent(a0)", "default" : "nt2::exponent(double(a0))"},
  'types': ['real_', 'unsigned_int_', 'signed_int_'],
  'verif': None,
  'versn': '0.0'}
