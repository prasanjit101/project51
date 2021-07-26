import numpy as np
import glob
import ctypes

libfile = glob.glob('build/*/*kf.so')[0]

mylib = ctypes.CDLL(libfile)

# including function from kalman.c
mylib.kf.restype = numpy.ctypeslib.ndpointer(dtype=numpy.float64)
mylib.kf.argtypes = [numpy.ctypeslib.ndpointer(dtype=numpy.float64),numpy.ctypeslib.ndpointer(dtype=numpy.float64)]

# calling function
# make class of kalman filter
# supporting of numpy arrays input to the c function
# make useful for any type of array


