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

## Instructions for Window Install
This may not be the most elegant or minimal solution, but it worked for me on two different Windows 10 machines.

### Prereqs.
* You have the Kinect SDK installed and `k4viewer` works for you.
	* Find (corresponding on your install) following directories/files:
		* `C:\Program Files\Azure Kinect SDK v1.2.0\sdk\include\k4a`
		* `C:\Program Files\Azure Kinect SDK v1.2.0\sdk\windows-desktop\x86\release\lib\k4a.lib`
		* `C:\Program Files\Azure Kinect SDK v1.2.0\sdk\windows-desktop\x86\release\bin\k4a.dll`
		* `C:\Program Files\Azure Kinect SDK v1.2.0\sdk\windows-desktop\x86\release\bin\k4a.pyd`
		* `C:\Program Files\Azure Kinect SDK v1.2.0\sdk\windows-desktop\x86\release\bin\depthengine_2_0.dll`
* You have Python 3.6 or newer development libraries installed. 
	* This may be installed on your computer simply as Python.  
	* Note the following directories and add them to your user Path
		* `C:\Users\amy\AppData\Local\Programs\Python\Python37\include`
		* `C:\Users\amy\AppData\Local\Programs\Python\Python37\DLLs`
		* `C:\Users\amy\AppData\Local\Programs\Python\Python37\libs`
* You have a C compiler
	* e.g., VS2019 with C++ desktop development tools, C++/CLI, and most recent Windows 10 SDK installed
		* Make sure your environmental variables are set, i.e. CMAKE_C_COMPILER should point to cl.exe inside VS2019
			* e.g., `C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\bin\Hostx86\x86\cl.exe`
* Copy elements from the SDK to your Python directories and set environment and path variables
	* Add following directory (equivalent on your machine) to your user Path
		* `C:\Program Files\Azure Kinect SDK v1.2.0\sdk\include`
		* at this time, make sure you also have the Python paths listed above
	* Copy the k4a folder of the SDK to your Python "include" folder (see example directories above)
	* Copy the k4a.dll and k4a.pyd of the SDK to your Python DLLs folder (see example directories above)
	* Copy the k4a.lib to your Python lib folder (see example directories above)
	* Create an environmental variable LINK pointing to k4a.lib, with quotes! 
		* e.g., `"C:\Program Files\Azure Kinect SDK v1.2.0\sdk\windows-desktop\amd64\release\lib\k4a.lib"`
* You have an Azure Kinect device

### Build/Install
```sh
git clone https://github.com/brendandburns/py-k4a.git
cd py-k4a
python setup.py build
python setup.py install
python example.py
```

If all goes well, this will leave a file named `test.jpg` in your directory with a single frame capture
from your device.

### TODO
Add support for Audio and IMU. Fix bugs. Accept PRs.