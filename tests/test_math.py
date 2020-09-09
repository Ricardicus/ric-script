import os
from settings import *

def test_vector_print():
  output_lines = [
"2.000000",
"2.828427",
"1.414214",
"8.000000",
"16.000000",
"32.000000",
"4.605170",
"5.298317",
"6.907755",
"0.001593",
"0.000000",
"-0.999999",
"1.000000",
"-0.001593",
"0.000000",
"2.718282",
"7.389056",
"2.000000",
"2.000000",
"1337.000000",
"1337.000000",
"1337.000000",
"1338.000000"
  ]

  lib_script = callSample('math.ric')

  ric_result = os.popen(lib_script).read().splitlines()

  assert len(output_lines) == len(ric_result)

  for i in range(0,len(ric_result)):
    assert output_lines[i] == ric_result[i]

