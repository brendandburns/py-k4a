import k4a

dev = k4a.Device()
if k4a.device_open(0, dev):
    serial = k4a.device_get_serialnum(dev)
    version = k4a.device_get_version(dev)
    print("Opened device {} {}\n".format(serial, version))

    config = k4a.DeviceConfiguration()
    config.camera_fps = k4a.K4A_FRAMES_PER_SECOND_15
    config.color_format = k4a.K4A_IMAGE_FORMAT_COLOR_BGRA32
    config.color_resolution = k4a.K4A_COLOR_RESOLUTION_3072P

    if k4a.device_start_cameras(dev, config):
        k4a.device_stop_cameras(dev)
    else:
        print("Failed to start cameras!")
    k4a.device_close(dev)
    print("Closed")
else:
    print("Failed to open device")

