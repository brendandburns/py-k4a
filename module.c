#include <Python.h>
#include <structmember.h>

#include <k4a/k4a.h>

#include "types.h"
#include "device.h"

static PyMethodDef methods[] = {
    { "device_get_installed_count", device_get_installed_count, METH_NOARGS, "Gets installed device count" },
    { "device_open", device_open, METH_VARARGS, "Open a device"},
    { "device_close", device_close, METH_VARARGS, "Close a device"},
    { "device_get_version", device_get_version, METH_VARARGS, "Get device version(s)"},
    { "device_get_serialnum", device_get_serial_num, METH_VARARGS, "Get device serial number"},
    { "device_start_cameras", device_start_cameras, METH_VARARGS, "Start device cameras"},
    { "device_stop_cameras", device_stop_cameras, METH_VARARGS, "Stop device cameras"},
    { NULL, NULL, 0, NULL }
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "k4a",
    "Kinect For Azure",
    -1,
    methods
};

// Initializes our module using our above struct
PyMODINIT_FUNC PyInit_k4a(void)
{
    if (!initTypes()) {
        return NULL;
    }

    PyObject *mod = PyModule_Create(&module);
    if (mod == NULL) {
        return NULL;
    }

    if (!addTypes(mod)) {
        Py_DECREF(mod);
        return NULL;
    }

    return mod;
}