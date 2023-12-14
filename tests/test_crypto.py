import os
from settings import *

def test_crypto():
  output_lines = [
   "f3eb8cf6a3b3c89508f9416c87ca40cd99bf174cdff3bad9acb47968b3c48c51",
    "05b972dcf28374406d13e879724bfe3b",
    "8+uM9qOzyJUI+UFsh8pAzZm/F0zf87rZrLR5aLPEjFE=",
    "Bbly3PKDdEBtE+h5ckv+Ow==",
    "f3eb8cf6a3b3c89508f9416c87ca40cd99bf174cdff3bad9acb47968b3c48c51",
    "05b972dcf28374406d13e879724bfe3b",
    "aGVqc2Fu",
    "68656a73616e",
    "hejsan",
    "hejsan"
  ]

  lib_script = callSample('crypto.ric')

  ric_result = os.popen(lib_script).read().splitlines()

  assert len(output_lines) == len(ric_result)

  for i in range(0,len(ric_result)):
    assert output_lines[i] == ric_result[i]

