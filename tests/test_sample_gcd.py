# Pytest suite for the ric script
# Stand in this directory on launch
import os
from settings import *
from random import randint, seed

# used in the test_gcd function
def gcd(a,b):
    if(b==0):
        return a
    else:
        return gcd(b,a%b)

def test_gcd():
    gcd_script = "./" + EXECUTABLE + " ../samples/gcd.ric "

    number_of_tests = 100

    seed(1)

    i = 0
    while ( i < number_of_tests ):
      number1 = randint(1, 100000)
      number2 = randint(1, 100000)

      python_result = gcd(number1, number2)

      ric_result = os.popen(gcd_script + str(number1) + " " + str(number2)).read()

      ric_result_int = int(ric_result.split("is: ")[1])

      assert python_result == ric_result_int

      i += 1
