import os

EXECUTABLE = "../builddir/src/ric"

def callSample(sample):
  if (os.name == 'nt'):
    # Windows
    binaryPath = os.path.join('..', 'builddir', 'src', 'ric.exe')
    samplePath = os.path.join('..', 'samples', sample)
    return binaryPath + " " + samplePath + " "
  else:
    # Not windows
    return "./" + EXECUTABLE + " ../samples/" + sample + " "

def callSampleArgs(sample, args):
  if (os.name == 'nt'):
    # Windows
    binaryPath = os.path.join('..', 'builddir', 'src', 'ric.exe')
    samplePath = os.path.join('..', 'samples', sample)
    argsString = " "
    for arg in args:
      argsString += str(arg) + " "
    return binaryPath + " " + samplePath + argsString
  else:
    # Not windows
    argsString = " "
    for arg in args:
      argsString += str(arg) + " "
    return "./" + EXECUTABLE + " ../samples/" + sample + argsString