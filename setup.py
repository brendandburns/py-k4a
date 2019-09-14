from distutils.core import setup, Extension
setup(name = 'k4a', version = '1.0',  \
   ext_modules = [Extension(
       'k4a',
       libraries= ['k4a'],
       sources= [ 'gen.c', 'device.c', 'module.c', 'types.c'])])