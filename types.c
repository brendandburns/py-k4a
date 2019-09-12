#include <Python.h>
#include <structmember.h>
#include <k4a/k4a.h>

#include "types.h"

static PyTypeObject DeviceType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "k4a.Device",
    .tp_doc = "Kinect for Azure Device",
    .tp_basicsize = sizeof(DeviceObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
};

static PyMemberDef DeviceConfiguration_members[] = {
    {"color_format", T_UINT, offsetof(DeviceConfiguration, color_format), 0, "color format enum"},
    {"color_resolution", T_UINT, offsetof(DeviceConfiguration, color_resolution), 0, "color resolution enum"},
    {"depth_mode", T_UINT, offsetof(DeviceConfiguration, depth_mode), 0, "depth mode enum"},
    {"camera_fps", T_UINT, offsetof(DeviceConfiguration, camera_fps), 0, "camera fps enum"},
    {"synchronized_images_only", T_BOOL, offsetof(DeviceConfiguration, synchronized_images_only), 0, "synchronized images only"},
    {"delay_depth_off_color_usec", T_INT, offsetof(DeviceConfiguration, depth_delay_off_color_usec), 0, "depth delay off color usec"},
    {"wired_sync_mode", T_UINT, offsetof(DeviceConfiguration, wired_sync_mode), 0, "wired sync mode enum"},
    {"subordinate_delay_off_master_usec", T_UINT, offsetof(DeviceConfiguration, subordinate_delay_off_master_usec), 0, "subordinate delay off master usec"},
    {"disable_streaming_indicator", T_BOOL, offsetof(DeviceConfiguration, disable_streaming_indicator), 0, "disable streaming indicator"},
    {NULL}  /* Sentinel */
};

static PyTypeObject DeviceConfigurationType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "k4a.DeviceConfiguration",
    .tp_doc = "Kinect for Azure Device Configuration",
    .tp_basicsize = sizeof(DeviceConfiguration),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
    .tp_new = PyType_GenericNew,
    .tp_members = DeviceConfiguration_members,
};

static PyMemberDef Version_members[] = {
    {"major", T_UINT, offsetof(VersionInfo, major), 0,
     "major version"},
    {"minor", T_UINT, offsetof(VersionInfo, minor), 0,
     "minor version"},
    {"iteration", T_INT, offsetof(VersionInfo, iteration), 0,
     "iteration version"},
    {NULL}  /* Sentinel */
};

static PyTypeObject VersionType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "k4a.VersionInfo",
    .tp_doc = "Kinect for Azure Version Info",
    .tp_basicsize = sizeof(VersionInfo),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_members = Version_members,
};

static PyMemberDef Hardware_members[] = {
    {"rgb", T_OBJECT_EX, offsetof(HardwareVersion, rgb), 0,
     "rgb version"},
    {NULL}  /* Sentinel */
};

void Hardware_dealloc(HardwareVersion* self)
{
    Py_XDECREF(self->rgb);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyTypeObject HardwareType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "k4a.HardwareVersion",
    .tp_doc = "Kinect for Azure Hardware Version Info",
    .tp_basicsize = sizeof(HardwareVersion),
    .tp_itemsize = 0,
    .tp_dealloc = (destructor) Hardware_dealloc,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_members = Hardware_members,
};

bool initTypes() {
    if (PyType_Ready(&DeviceType) < 0 ||
        PyType_Ready(&DeviceConfigurationType) < 0) {
        return false;
    }
    return true;
}

bool addTypes(PyObject* mod) {
    Py_INCREF(&DeviceType);
    Py_INCREF(&DeviceConfigurationType);
    if (PyModule_AddObject(mod, "Device", (PyObject *) &DeviceType) < 0 ||
        PyModule_AddObject(mod, "DeviceConfiguration", (PyObject*) &DeviceConfigurationType) < 0) {
        Py_DECREF(&DeviceType);
        Py_DECREF(&DeviceConfigurationType);
        return false;
    }
    return true;
}