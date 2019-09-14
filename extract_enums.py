#!/usr/bin/python3

import re

enum_started = False
regexp = re.compile('.*(K4A[A-Z0-9_]*).*')
with open('/usr/include/k4a/k4atypes.h', 'r') as header:
    line = header.readline()
    while line:
        if enum_started:
            result = regexp.match(line)
            if result:
                name = result.group(1)
                code = 'PyModule_AddObject(mod, "{}", PyLong_FromLong({}));'.format(name, name)
                print(code)
        if "typedef enum" in line:
            enum_started = True
        if "}" in line:
            enum_started = False
        line = header.readline()
    
