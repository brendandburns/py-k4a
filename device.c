
#include <Python.h>
#include <structmember.h>
#include <k4a/k4a.h>

#include "types.h"

PyObject *device_get_installed_count(PyObject *self, PyObject *args)
{
    uint32_t count = k4a_device_get_installed_count();
    return PyLong_FromUnsignedLong(count);
}

PyObject *device_get_serial_num(PyObject *self, PyObject *args)
{
    size_t serial_size = 0;
    DeviceObject *obj;

    PyArg_ParseTuple(args, "O", &obj);

    k4a_device_get_serialnum(obj->device, NULL, &serial_size);

    char *serial = (char *)(malloc(serial_size));
    k4a_device_get_serialnum(obj->device, serial, &serial_size);

    PyObject *res = PyUnicode_FromString(serial);
    free(serial);
    return res;
}

PyObject *device_open(PyObject *self, PyObject *args)
{
    int ix;
    DeviceObject *obj;

    PyArg_ParseTuple(args, "iO", &ix, &obj);

    k4a_result_t result = k4a_device_open(ix, &(obj->device));
    if (result == K4A_RESULT_SUCCEEDED)
    {
        return Py_True;
    }
    return Py_False;
}

PyObject *device_get_version(PyObject *self, PyObject *args)
{
    DeviceObject *obj;
    k4a_hardware_version_t version;

    PyArg_ParseTuple(args, "O", &obj);

    k4a_device_get_version(obj->device, &version);

    return Py_BuildValue("((s (iii)) (s (iii)) (s (iii)) (s (iii)))",
                         "rgb",
                         version.rgb.major,
                         version.rgb.minor,
                         version.rgb.iteration,
                         "depth",
                         version.depth.major,
                         version.depth.minor,
                         version.depth.iteration,
                         "audio",
                         version.audio.major,
                         version.audio.minor,
                         version.audio.iteration,
                         "depth_sensor",
                         version.depth_sensor.major,
                         version.depth_sensor.minor,
                         version.depth_sensor.iteration);
}

PyObject *device_close(PyObject *self, PyObject *args)
{
    DeviceObject *obj;
    PyArg_ParseTuple(args, "O", &obj);

    k4a_device_close(obj->device);

    return Py_None;
}

PyObject *device_start_cameras(PyObject *self, PyObject *args)
{
    DeviceObject *obj;
    DeviceConfiguration *config;

    PyArg_ParseTuple(args, "OO", &obj, &config);

    // TODO convert this to use the native object.
    k4a_device_configuration_t k4a_conf = K4A_DEVICE_CONFIG_INIT_DISABLE_ALL;
    k4a_conf.color_format = config->color_format;
    k4a_conf.color_resolution = config->color_resolution;
    k4a_conf.depth_mode = config->depth_mode;
    k4a_conf.depth_delay_off_color_usec = config->depth_delay_off_color_usec;
    k4a_conf.camera_fps = config->camera_fps;
    k4a_conf.disable_streaming_indicator = config->disable_streaming_indicator;
    k4a_conf.subordinate_delay_off_master_usec = config->subordinate_delay_off_master_usec;
    k4a_conf.synchronized_images_only = config->synchronized_images_only;
    k4a_conf.wired_sync_mode = config->wired_sync_mode;

    k4a_result_t result = k4a_device_start_cameras(obj->device, &k4a_conf);
    return result == K4A_RESULT_SUCCEEDED ? Py_True : Py_False;
}

PyObject *device_stop_cameras(PyObject *self, PyObject *args)
{
    DeviceObject *obj;
    PyArg_ParseTuple(args, "O", &obj);

    k4a_device_stop_cameras(obj->device);

    return Py_None;
}
