import k4a

dev = k4a.Device()
if k4a.device_open(0, dev):
    serial = k4a.device_get_serialnum(dev)
    version = k4a.device_get_version(dev)
    print("Opened device {} {}\n".format(serial, version))

    config = k4a.DeviceConfiguration()
    config.
    if k4a.device_start_cameras(dev, config):
        k4a.device_stop_cameras(dev)
    else:
        print("Failed to start cameras!")
    k4a.device_close(dev)
    print("Closed")
else:
    print("Failed to open device")

