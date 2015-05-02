from setuptools import setup, Extension
#from distutils.core import setup, Extension

#ext_modules = []

ext_module = Extension('systemd/_daemon',
                      libraries = ['systemd'],
                      sources = ['systemd/_daemon.c',
                                 'systemd/_journal.c',
                                 'systemd/_reader.c',
                                 'systemd/id128.c',
                                 'systemd/login.c',
                                 'systemd/pyutil.c'],
                      include_dirs = ['../../src/shared',
                                      '../../src/systemd'],
                      define_macros = [('PACKAGE_VERSION', '219')])

#cjournal = Extension('systemd/_journal',
                      #libraries = ['systemd-journal'],
                      #sources = ['systemd/_journal.c'])

setup (name = 'systemd',
       version = '219',
       description = 'Native interface to the facilities of systemd',
       author_email = 'david@davidstrauss.net',
       url = 'http://www.freedesktop.org/software/systemd/python-systemd/',
       py_modules = ['systemd.journal', 'systemd.daemon'],
       ext_modules = [ext_module])