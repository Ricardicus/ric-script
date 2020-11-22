import os
from settings import *
import datetime

def test_vector_print():
  now = datetime.datetime.now()
  output_lines = [
  	str(now.hour),
    str(now.isocalendar()[1]),
    str(now.month),
    str(now.year)
  ]

  lib_script = callSample('time_of_day.ric')

  ric_result = os.popen(lib_script).read().splitlines()

  assert len(output_lines) == len(ric_result)

  for i in range(0,len(ric_result)):
    assert output_lines[i] == ric_result[i]

