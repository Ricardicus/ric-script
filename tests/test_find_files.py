import os
from settings import *

def test_find_files():

  output_lines = ['./test_find_files.py','./test_class.py','./test_ric_lib.py','./test_xattr.py','./test_locals_globals.py','./test_list_dir.py','./test_vector_print.py','./test_time_of_day.py','./test_args.py','./test_sample_function_within_function.py','./settings.py','./test_sample_gcd.py','./test_string_manipulations.py','./test_func_ptr.py','./test_load.py','./test_math.py','./test_dict_print.py']

  if ( os.name == 'nt' ):
    # due to the fact that Windows uses backslash
    # instead of forward slashes.
    output_lines = [x.split("/")[1] for x in output_lines]

    script = callSample('find_files.ric')

    ric_result = os.popen(script).read().splitlines()

    assert len(output_lines) == len(ric_result)
    assert len(set(output_lines)) == len(set(ric_result))
    for n in output_lines:

      found = False
      for r in ric_result:
        print(n)
        print(r)
        if n in r:
          found = True

      assert(found)


  else:

    script = callSample('find_files.ric')

    ric_result = os.popen(script).read().splitlines()

    assert len(output_lines) == len(ric_result)
    assert len(set(output_lines)) == len(set(ric_result))
    for n in output_lines:
      assert(n in ric_result)


