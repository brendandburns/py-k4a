#include <Python.h>
#include <structmember.h>
#include <k4a/k4a.h>

#include "types.h"

#ifndef __PY_K4A_CAPTURE__
#define __PY_K4A_CAPTURE__

PyObject* device_get_capture(PyObject* self, PyObject* args);
PyObject* py_capture_get_depth_image(PyObject* self, PyObject* args);
PyObject* py_capture_get_color_image(PyObject* self, PyObject* args);
PyObject* py_capture_get_ir_image(PyObject* self, PyObject* args);
PyObject* py_image_get_buffer(PyObject* self, PyObject* args);
PyObject* py_image_get_width_pixels(PyObject* self, PyObject* args);
PyObject* py_image_get_height_pixels(PyObject* self, PyObject* args);
PyObject* py_image_get_stride_bytes(PyObject* self, PyObject* args);
PyObject* py_image_release(PyObject* self, PyObject* args);
PyObject* py_capture_release(PyObject* self, PyObject* args);
#endif