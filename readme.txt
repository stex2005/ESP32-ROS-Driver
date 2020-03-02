                        
		    *********************************************

	            ::ROS_Arduino Esp8266 && Esp32 (Ubuntu 16.04)

		    *********************************************


1. Install ESP32 
If you have Arduino installed to ~/, modify the installation as follows, 

$cd ~/Arduino
$mkdir -p hardware/espressif
$cd hardware/espressif 
$git clone https://github.com/espressif/arduino-esp32.git esp32
$cd esp32 
$git submodule update --init --recursive
$cd tools $python3 get.py



2. Install ESP8266
2.1 Install Arduino IDE latest version. On Ubuntu 16.04 the Arduino IDE version from repos is too old, doesn't have Board Manager.
2.2 Go to File > Preferences and paste http://arduino.esp8266.com/stable/package_esp8266com_index.json  on Additional Boards Manager URLs.
2.3 Go to Tools > Board > Boards Manager and from Type dropdown select Contributed.
2.4 Select and install ESP8266 and Install



3. Install rosserial_arduino from 
You can install rosserial for Arduino by running: 

$sudo apt-get install ros-kinetic-rosserial-arduino
$sudo apt-get install ros-kinetic-rosserial
$cd <sketchbook>/libraries
$rm -rf ros_lib
$rosrun rosserial_arduino make_libraries.py 

After restarting your IDE, you should see ros_lib listed under examples 




4. replace all file in >> Home/Arduino/libraries/ros_lib
