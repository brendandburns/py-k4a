#include <Python.h>
#include <structmember.h>
#include <k4a/k4a.h>

#ifndef __PY_K4A_TYPES__
#define __PY_K4A_TYPES__

typedef struct {
    PyObject_HEAD
    k4a_device_t device;
} DeviceObject;

typedef struct {
    PyObject_HEAD
    k4a_image_format_t color_format;
    k4a_color_resolution_t color_resolution;
    k4a_depth_mode_t depth_mode;
    k4a_fps_t camera_fps;
    bool synchronized_images_only;
    int32_t depth_delay_off_color_usec;
    k4a_wired_sync_mode_t wired_sync_mode;
    uint32_t subordinate_delay_off_master_usec;
    bool disable_streaming_indicator;
} DeviceConfiguration;

typedef struct {
    PyObject_HEAD
    uint32_t major;
    uint32_t minor;
    uint32_t iteration;
} VersionInfo;

typedef struct {
    PyObject_HEAD
    VersionInfo* rgb;
} HardwareVersion;

void Hardware_dealloc(HardwareVersion* self);

bool initTypes();
bool addTypes();
void registerEnums(PyObject *mod);

#endif