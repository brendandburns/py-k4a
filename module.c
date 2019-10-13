#include <Python.h>
#include <structmember.h>

#include <k4a/k4a.h>

#include "types.h"
#include "capture.h"
#include "device.h"
#include "gen.h"

static PyMethodDef methods[] = {
    { "device_get_installed_count", device_get_installed_count, METH_NOARGS, "Gets installed device count" },
    { "device_open", device_open, METH_VARARGS, "Open a device"},
    { "device_close", device_close, METH_VARARGS, "Close a device"},
    { "device_get_version", device_get_version, METH_VARARGS, "Get device version(s)"},
    { "device_get_serialnum", device_get_serial_num, METH_VARARGS, "Get device serial number"},
    { "device_start_cameras", device_start_cameras, METH_VARARGS, "Start device cameras"},
    { "device_stop_cameras", device_stop_cameras, METH_VARARGS, "Stop device cameras"},
    { "device_get_capture", device_get_capture, METH_VARARGS, "Get a capture"},
    { "capture_get_depth_image", py_capture_get_depth_image, METH_VARARGS, "Get a depth image"},
    { "capture_get_color_image", py_capture_get_color_image, METH_VARARGS, "Get a color image"},
    { "image_get_buffer", py_image_get_buffer, METH_VARARGS, "Get buffer from an image"},
    { "image_get_width_pixels", py_image_get_width_pixels, METH_VARARGS, "Get the image width"},
    { "image_get_height_pixels", py_image_get_height_pixels, METH_VARARGS, "Get the image height"},
    { "image_get_stride_bytes", py_image_get_stride_bytes, METH_VARARGS, "Get stride width in bytes"},
    { "image_release", py_image_release, METH_VARARGS, "Release image"},
    { "capture_release", py_capture_release, METH_VARARGS, "Release capture"},
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
    if (!initTypes() || !initGenTypes()) {
        return NULL;
    }

    PyObject *mod = PyModule_Create(&module);
    if (mod == NULL) {
        return NULL;
    }

    if (!addTypes(mod) || !addGenTypes(mod)) {
        Py_DECREF(mod);
        return NULL;
    }

    registerEnums(mod);

    return mod;
}