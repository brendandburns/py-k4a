import k4a
import faulthandler

faulthandler.enable()

dev = k4a.Device()
if k4a.device_open(0, dev):
    serial = k4a.device_get_serialnum(dev)
    version = k4a.device_get_version(dev)
    print("Opened device {} {}\n".format(serial, version))

    config = k4a.DeviceConfiguration()
    config.color_format = k4a.K4A_IMAGE_FORMAT_COLOR_MJPG
    config.color_resolution = k4a.K4A_COLOR_RESOLUTION_2160P
    config.depth_mode = k4a.K4A_DEPTH_MODE_NFOV_UNBINNED
    config.camera_fps = k4a.K4A_FRAMES_PER_SECOND_30
    config.synchronized_images_only = True

    if k4a.device_start_cameras(dev, config):
        capture = k4a.Capture()
        res = k4a.device_get_capture(dev, capture, 1000)
        if res == k4a.K4A_WAIT_RESULT_SUCCEEDED:
            img = k4a.capture_get_color_image(capture)
            if img:
                w = k4a.image_get_width_pixels(img)
                h = k4a.image_get_height_pixels(img)
                s = k4a.image_get_stride_bytes(img)
                print('Capture: {} x {} @ {}'.format(h, w, s / w))

                try:
                    with open('test.jpg', 'wb') as fp:
                        fp.write(k4a.image_get_buffer(img))
                        fp.flush()
                        fp.close()

                        k4a.image_release(img) #I think this is working
                        k4a.capture_release(capture) #I don't think this is working
                except:
                    import sys
                    print("Unexpected error:", sys.exc_info()[0])
            else:
                print('get image failed!')
        else:
            print('Capture failed!')
    else:
        print("Failed to start cameras!")

    k4a.device_stop_cameras(dev)
    k4a.device_close(dev)
    print("Closed")
else:
    print("Failed to open device")

