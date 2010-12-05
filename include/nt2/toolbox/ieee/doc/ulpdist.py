{ 'arity': 2,
  'dptch': ['bool_', 'real_', 'arithmetic_'],
  'incld': [],
  'norst': False,
  'notes': [],
  'rnges': { 'real_': [['T(-10)', 'T(10)'], ['T(-10)', 'T(10)']],
             'signed_int_': [['-100', '100'], ['-100', '100']],
             'unsigned_int_': [['0', '100'], ['0', '100']]},
  'rturn': { 'default': 'typename boost::result_of<nt2::meta::arithmetic(T)>::type'},
  'specv': { 'default': { },
             'real_': { 'nt2::Inf<T>()': 'nt2::Zero<r_t>()',
                        'nt2::Minf<T>()': 'nt2::Zero<r_t>()',
                        'nt2::Mone<T>()': 'nt2::Zero<r_t>()',
                        'nt2::Nan<T>()': 'nt2::Zero<r_t>()',
                        'nt2::One<T>()': 'nt2::Zero<r_t>()',
                        'nt2::Zero<T>()': 'nt2::Zero<r_t>()'},
             'signed_int_': { 'nt2::Mone<T>()': 'nt2::Zero<r_t>()',
                              'nt2::One<T>()': 'nt2::Zero<r_t>()',
                              'nt2::Zero<T>()': 'nt2::Zero<r_t>()'},
             'unsigned_int_': { 'nt2::One<T>()': 'nt2::Zero<r_t>()',
                                'nt2::Zero<T>()': 'nt2::Zero<r_t>()'}},
  'stamp': 'modified by jt the 04/12/2010',
  'tcall': None,
  'types': ['real_', 'unsigned_int_', 'signed_int_'],
  'verif': None,
  'versn': '0.0'}
