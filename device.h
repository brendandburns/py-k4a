#include <Python.h>
#include <k4a/k4a.h>

PyObject* device_get_installed_count(PyObject* self, PyObject* args);
PyObject* device_get_serial_num(PyObject* self, PyObject* args);
PyObject* device_open(PyObject* self, PyObject* args);
PyObject* device_get_version(PyObject* self, PyObject* args);
PyObject* device_close(PyObject* self, PyObject* args);
PyObject* device_start_cameras(PyObject* self, PyObject* args);
PyObject* device_stop_cameras(PyObject* self, PyObject* args);
PyObject* device_start_imu(PyObject* self, PyObject* args);
PyObject* device_stop_imu(PyObject* self, PyObject* args);
