# ESP32 Integration with ROS Melodic (Ubuntu 18.04)                        

## Install ESP32 Add-on

Install Arduino IDE latest version. 

Go to File > Preferences and paste `https://dl.espressif.com/dl/package_esp32_index.json` on Additional Boards Manager URLs.

Go to Tools > Board > Boards Manager and from Type dropdown select Contributed.

Select and install ESP32 and Install.

## Install rosserial_arduino from apt-get

You can install rosserial for Arduino by running: 

`sudo apt-get install ros-kinetic-rosserial-arduino`

`sudo apt-get install ros-kinetic-rosserial`

`cd <sketchbook>/libraries`
 
`rm -rf ros_lib`

`rosrun rosserial_arduino make_libraries.py`

After restarting your IDE, you should see ros_lib listed under examples 

## Update ros_lib Library

Replace all .h and .cpp files that you find in this repository in Home/Arduino/libraries/ros_lib

## Modify the code

Add "WiFicredentials.h" with your WiFi SSID and PASS

`#define UID "YourSSID"`

`#define PASS "YourPassword"`

Check your roscore IP address and update it in the code.

## Run the code

 `roslaunch rosserial_server socket.launch`
 
 `rostopic list`
 
 `rostopic echo chatter`
 
 `rostopic hz chatter`

 

