from setuptools import setup, Extension

setup (
    ext_modules = [Extension('kf', ['kalman.c'],),],
)
