## Alpha python library for Azure Kinect
This library is pre-alpha, weekend hack quality. It can capture single frames correctly, but it likely has lots of bugs, and there are definitely missing features.

### Prereqs.
* You have the Kinect SDK installed and `k4viewer` works for you.
* You have Python3 development libraries installed. (`apt-get install python3-dev`)
* You have an Azure Kinect device

### Build/Install
```sh
git clone https://github.com/brendandburns/py-k4a.git
cd py-k4a
python3 setup.py build
sudo python3 setup.py install
python3 example.py
```

If all goes well, this will leave a file named `test.jpg` in your directory with a single frame capture
from your device.

### TODO
Add support for Audio and IMU. Fix bugs. Accept PRs.