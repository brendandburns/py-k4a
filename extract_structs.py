#!/usr/bin/python3

import re

# TODO: use arg for this...
# gen_header = True
gen_header = False


print('#include <Python.h>')
print('#include <structmember.h>')
print('#include <k4a/k4a.h>')

if gen_header is True:
    print('#ifndef __K4A_GEN_H__')
    print('#define __K4A_GEN_H__')
else:
    print('#include "gen.h"')

struct_started = False
regexp = re.compile('.*(k4a[a-z0-9_]+).*')
field = re.compile('[\\s]*([a-z0-9_\\s\\[\\]]+);.*')
members = []
types = []
name = ''
with open('/usr/include/k4a/k4atypes.h', 'r') as header:
    line = header.readline()
    while line:
        if struct_started:
            result = field.match(line)
            if result:
                members.append(result.group(1))
        if 'typedef struct' in line:
            result = regexp.match(line)
            if result:
                struct_started = True
                name = 'py_{}'.format(result.group(1))
                members = []
        if "}" in line and struct_started:
            struct_started = False
            types.append(name)
            if gen_header is True:
                print('typedef struct {')
                print('  PyObject_HEAD')
                for member in members:
                    print('  {};'.format(member))
                print('}')
                print('{};'.format(name))
            else:
                print('static PyTypeObject {}Type ='.format(name))
                print('{')
                print('PyVarObject_HEAD_INIT(NULL, 0)')
                print('.tp_name = "k4a.{}",'.format(name))
                print('.tp_doc = "Kinect for Azure generated {}",'.format(name))
                print('.tp_basicsize = sizeof({}),'.format(name))
                print('.tp_itemsize = 0,')
                print('.tp_flags = Py_TPFLAGS_DEFAULT,')
                print('.tp_new = PyType_GenericNew,')
                print('};')
            members = []
        line = header.readline()

if not gen_header:
    print('bool initGenTypes() {')
    for type_name in types:
        print('  if (PyType_Ready(&{}Type) < 0) return false;'.format(type_name))
    print('  return true;')
    print('}')

    print('bool addGenTypes(PyObject* mod) {')
    for type_name in types:
        print('  Py_INCREF(&{}Type);'.format(type_name))
    print ('  if (')
    for type_name in types:
        print('    PyModule_AddObject(mod, "{}", (PyObject *)&{}Type) < 0 ||'.format(type_name, type_name))
    print('    false) {')
    for type_name in types:
        print('      Py_DECREF(&{}Type);'.format(type_name))
    print('    return false;')
    print('  }')
    print('  return true;')
    print('}')

if gen_header is True:
    print('bool initGenTypes();')
    print('bool addGenTypes();')
    print('#endif')
    
