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
