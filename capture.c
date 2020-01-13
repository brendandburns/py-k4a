#include <Python.h>
#include <structmember.h>
#include <k4a/k4a.h>

#include "types.h"

PyObject* device_get_capture(PyObject* self, PyObject* args)
{
    DeviceObject *obj;
    CaptureObject *capture;
    int timeout_ms;

    PyArg_ParseTuple(args, "OOi", &obj, &capture, &timeout_ms);

    k4a_wait_result_t res = k4a_device_get_capture(obj->device, &(capture->capture), timeout_ms);
    return PyLong_FromUnsignedLong(res);
}

PyObject* py_capture_get_depth_image(PyObject* self, PyObject* args)
{
    CaptureObject* obj;
    PyArg_ParseTuple(args, "O", &obj);

    ImageObject* imgObj = newImageObject();
    imgObj->image = k4a_capture_get_depth_image(obj->capture);

    if (imgObj->image == NULL) {
        return Py_None;
    }

    return (PyObject*) imgObj;
}

PyObject* py_capture_get_color_image(PyObject* self, PyObject* args)
{
    CaptureObject* obj;
    PyArg_ParseTuple(args, "O", &obj);

    ImageObject* imgObj = newImageObject();
    imgObj->image = k4a_capture_get_color_image(obj->capture);

    if (imgObj->image == NULL) {
        return Py_None;
    }

    return (PyObject*) imgObj;
}

PyObject* py_capture_get_ir_image(PyObject* self, PyObject* args)
{
    CaptureObject* obj;
    PyArg_ParseTuple(args, "O", &obj);

    ImageObject* imgObj = newImageObject();
    imgObj->image = k4a_capture_get_ir_image(obj->capture);

    if (imgObj->image == NULL) {
        return Py_None;
    }

    return (PyObject*) imgObj;
}


PyObject* py_image_get_buffer(PyObject* self, PyObject* args)
{
    ImageObject* obj;
    PyArg_ParseTuple(args, "O", &obj);

    uint8_t* buffer = k4a_image_get_buffer(obj->image);
    size_t size = k4a_image_get_size(obj->image);

    return PyByteArray_FromStringAndSize((const char*) buffer, size);
}

PyObject* py_image_get_width_pixels(PyObject* self, PyObject* args)
{
    ImageObject* obj;
    PyArg_ParseTuple(args, "O", &obj);

    return PyLong_FromLong(k4a_image_get_width_pixels(obj->image));
}

PyObject* py_image_get_height_pixels(PyObject* self, PyObject* args)
{
    ImageObject* obj;
    PyArg_ParseTuple(args, "O", &obj);

    return PyLong_FromLong(k4a_image_get_height_pixels(obj->image));
}

PyObject* py_image_get_stride_bytes(PyObject* self, PyObject* args)
{
    ImageObject* obj;
    PyArg_ParseTuple(args, "O", &obj);

    return PyLong_FromLong(k4a_image_get_stride_bytes(obj->image));
}

PyObject* py_image_release(PyObject* self, PyObject* args)
{
    ImageObject* obj;
    PyArg_ParseTuple(args, "O", &obj);

    k4a_image_release(obj->image);

    return Py_None;
}

PyObject* py_capture_release(PyObject* self, PyObject* args)
{
    CaptureObject* obj;
    PyArg_ParseTuple(args, "O", &obj);

    k4a_capture_release(obj->capture);

    return Py_None;
}
