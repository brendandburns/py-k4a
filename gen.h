#include <Python.h>
#include <structmember.h>
#include <k4a/k4a.h>
#ifndef __K4A_GEN_H__
#define __K4A_GEN_H__
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
}
py_k4a_device_configuration_t;
typedef struct {
  PyObject_HEAD
  float rotation[9];
  float translation[3];
}
py_k4a_calibration_extrinsics_t;
typedef struct {
  PyObject_HEAD
  k4a_calibration_model_type_t type;
  unsigned int parameter_count;
  k4a_calibration_intrinsic_parameters_t parameters;
}
py_k4a_calibration_intrinsics_t;
typedef struct {
  PyObject_HEAD
  k4a_calibration_extrinsics_t extrinsics;
  k4a_calibration_intrinsics_t intrinsics;
  int resolution_width;
  int resolution_height;
  float metric_radius;
}
py_k4a_calibration_camera_t;
typedef struct {
  PyObject_HEAD
  k4a_calibration_camera_t depth_camera_calibration;
  k4a_calibration_camera_t color_camera_calibration;
  k4a_depth_mode_t depth_mode;
  k4a_color_resolution_t color_resolution;
}
py_k4a_calibration_t;
typedef struct {
  PyObject_HEAD
  uint32_t major;
  uint32_t minor;
  uint32_t iteration;
}
py_k4a_version_t;
typedef struct {
  PyObject_HEAD
  k4a_version_t rgb;
  k4a_version_t depth;
  k4a_version_t audio;
  k4a_version_t depth_sensor;
  k4a_firmware_build_t firmware_build;
  k4a_firmware_signature_t firmware_signature;
}
py_k4a_hardware_version_t;
typedef struct {
  PyObject_HEAD
  float temperature;
  k4a_float3_t acc_sample;
  uint64_t acc_timestamp_usec;
  k4a_float3_t gyro_sample;
  uint64_t gyro_timestamp_usec;
}
py_k4a_imu_sample_t;
bool initGenTypes();
bool addGenTypes();
#endif
