#include <Python.h>
#include <structmember.h>
#include <k4a/k4a.h>
#include "gen.h"
static PyTypeObject py_k4a_device_configuration_tType =
{
PyVarObject_HEAD_INIT(NULL, 0)
.tp_name = "k4a.py_k4a_device_configuration_t",
.tp_doc = "Kinect for Azure generated py_k4a_device_configuration_t",
.tp_basicsize = sizeof(py_k4a_device_configuration_t),
.tp_itemsize = 0,
.tp_flags = Py_TPFLAGS_DEFAULT,
.tp_new = PyType_GenericNew,
};
static PyTypeObject py_k4a_calibration_extrinsics_tType =
{
PyVarObject_HEAD_INIT(NULL, 0)
.tp_name = "k4a.py_k4a_calibration_extrinsics_t",
.tp_doc = "Kinect for Azure generated py_k4a_calibration_extrinsics_t",
.tp_basicsize = sizeof(py_k4a_calibration_extrinsics_t),
.tp_itemsize = 0,
.tp_flags = Py_TPFLAGS_DEFAULT,
.tp_new = PyType_GenericNew,
};
static PyTypeObject py_k4a_calibration_intrinsics_tType =
{
PyVarObject_HEAD_INIT(NULL, 0)
.tp_name = "k4a.py_k4a_calibration_intrinsics_t",
.tp_doc = "Kinect for Azure generated py_k4a_calibration_intrinsics_t",
.tp_basicsize = sizeof(py_k4a_calibration_intrinsics_t),
.tp_itemsize = 0,
.tp_flags = Py_TPFLAGS_DEFAULT,
.tp_new = PyType_GenericNew,
};
static PyTypeObject py_k4a_calibration_camera_tType =
{
PyVarObject_HEAD_INIT(NULL, 0)
.tp_name = "k4a.py_k4a_calibration_camera_t",
.tp_doc = "Kinect for Azure generated py_k4a_calibration_camera_t",
.tp_basicsize = sizeof(py_k4a_calibration_camera_t),
.tp_itemsize = 0,
.tp_flags = Py_TPFLAGS_DEFAULT,
.tp_new = PyType_GenericNew,
};
static PyTypeObject py_k4a_calibration_tType =
{
PyVarObject_HEAD_INIT(NULL, 0)
.tp_name = "k4a.py_k4a_calibration_t",
.tp_doc = "Kinect for Azure generated py_k4a_calibration_t",
.tp_basicsize = sizeof(py_k4a_calibration_t),
.tp_itemsize = 0,
.tp_flags = Py_TPFLAGS_DEFAULT,
.tp_new = PyType_GenericNew,
};
static PyTypeObject py_k4a_version_tType =
{
PyVarObject_HEAD_INIT(NULL, 0)
.tp_name = "k4a.py_k4a_version_t",
.tp_doc = "Kinect for Azure generated py_k4a_version_t",
.tp_basicsize = sizeof(py_k4a_version_t),
.tp_itemsize = 0,
.tp_flags = Py_TPFLAGS_DEFAULT,
.tp_new = PyType_GenericNew,
};
static PyTypeObject py_k4a_hardware_version_tType =
{
PyVarObject_HEAD_INIT(NULL, 0)
.tp_name = "k4a.py_k4a_hardware_version_t",
.tp_doc = "Kinect for Azure generated py_k4a_hardware_version_t",
.tp_basicsize = sizeof(py_k4a_hardware_version_t),
.tp_itemsize = 0,
.tp_flags = Py_TPFLAGS_DEFAULT,
.tp_new = PyType_GenericNew,
};
static PyTypeObject py_k4a_imu_sample_tType =
{
PyVarObject_HEAD_INIT(NULL, 0)
.tp_name = "k4a.py_k4a_imu_sample_t",
.tp_doc = "Kinect for Azure generated py_k4a_imu_sample_t",
.tp_basicsize = sizeof(py_k4a_imu_sample_t),
.tp_itemsize = 0,
.tp_flags = Py_TPFLAGS_DEFAULT,
.tp_new = PyType_GenericNew,
};
bool initGenTypes() {
  if (PyType_Ready(&py_k4a_device_configuration_tType) < 0) return false;
  if (PyType_Ready(&py_k4a_calibration_extrinsics_tType) < 0) return false;
  if (PyType_Ready(&py_k4a_calibration_intrinsics_tType) < 0) return false;
  if (PyType_Ready(&py_k4a_calibration_camera_tType) < 0) return false;
  if (PyType_Ready(&py_k4a_calibration_tType) < 0) return false;
  if (PyType_Ready(&py_k4a_version_tType) < 0) return false;
  if (PyType_Ready(&py_k4a_hardware_version_tType) < 0) return false;
  if (PyType_Ready(&py_k4a_imu_sample_tType) < 0) return false;
  return true;
}
bool addGenTypes(PyObject* mod) {
  Py_INCREF(&py_k4a_device_configuration_tType);
  Py_INCREF(&py_k4a_calibration_extrinsics_tType);
  Py_INCREF(&py_k4a_calibration_intrinsics_tType);
  Py_INCREF(&py_k4a_calibration_camera_tType);
  Py_INCREF(&py_k4a_calibration_tType);
  Py_INCREF(&py_k4a_version_tType);
  Py_INCREF(&py_k4a_hardware_version_tType);
  Py_INCREF(&py_k4a_imu_sample_tType);
  if (
    PyModule_AddObject(mod, "py_k4a_device_configuration_t", (PyObject *)&py_k4a_device_configuration_tType) < 0 ||
    PyModule_AddObject(mod, "py_k4a_calibration_extrinsics_t", (PyObject *)&py_k4a_calibration_extrinsics_tType) < 0 ||
    PyModule_AddObject(mod, "py_k4a_calibration_intrinsics_t", (PyObject *)&py_k4a_calibration_intrinsics_tType) < 0 ||
    PyModule_AddObject(mod, "py_k4a_calibration_camera_t", (PyObject *)&py_k4a_calibration_camera_tType) < 0 ||
    PyModule_AddObject(mod, "py_k4a_calibration_t", (PyObject *)&py_k4a_calibration_tType) < 0 ||
    PyModule_AddObject(mod, "py_k4a_version_t", (PyObject *)&py_k4a_version_tType) < 0 ||
    PyModule_AddObject(mod, "py_k4a_hardware_version_t", (PyObject *)&py_k4a_hardware_version_tType) < 0 ||
    PyModule_AddObject(mod, "py_k4a_imu_sample_t", (PyObject *)&py_k4a_imu_sample_tType) < 0 ||
    false) {
      Py_DECREF(&py_k4a_device_configuration_tType);
      Py_DECREF(&py_k4a_calibration_extrinsics_tType);
      Py_DECREF(&py_k4a_calibration_intrinsics_tType);
      Py_DECREF(&py_k4a_calibration_camera_tType);
      Py_DECREF(&py_k4a_calibration_tType);
      Py_DECREF(&py_k4a_version_tType);
      Py_DECREF(&py_k4a_hardware_version_tType);
      Py_DECREF(&py_k4a_imu_sample_tType);
    return false;
  }
  return true;
}
