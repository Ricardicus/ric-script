import os

EXECUTABLE = "ric"

def callSample(sample):
  if (os.name == 'nt'):
    # Windows
    binaryPath = os.path.join('..', 'install', 'bin', 'ric.exe')
    samplePath = os.path.join('..', 'samples', sample)
    return '{0} {1} '.format(binaryPath, samplePath)
  else:
    # Not windows
    return "./{0} ../samples/{1} ".format(EXECUTABLE, sample)

def callSampleArgs(sample, args):
  if (os.name == 'nt'):
    # Windows
    binaryPath = os.path.join('ric.exe')
    samplePath = os.path.join(sample)
    return '{0} {1} {2}'.format(binaryPath, samplePath, ' '.join(str(a) for a in args))
  else:
    # Not windows
    return './{0} {1} {2}'.format(EXECUTABLE, sample, ' '.join(str(a) for a in args))
