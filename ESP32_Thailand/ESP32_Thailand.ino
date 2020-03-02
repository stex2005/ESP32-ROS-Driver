#include <stdlib.h>
#include "WiFi.h"
#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Empty.h>
#include "esp_system.h"
#include <Ticker.h>
Ticker ticker;

const char* ssid     = "TP-LINK_0D3914";
const char* password = "08696427";

// Set the rosserial socket server IP address
IPAddress server(192,168,1,101);
// Set the rosserial socket server port
const uint16_t serverPort = 11411;
//************************************************//

//---------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------//
std_msgs::String str_msg;
ros::Publisher esp32("agc03_status", &str_msg);

ros::NodeHandle nh;
//ros::Subscriber<std_msgs::String> sub("agc03_cmd", cmd_ESP);
//---------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------//
//------------------- Setup -------------------------------//
void setup()
{
Serial.begin(115200);
//Serial2.begin(115200);
Serial.println();
Serial.print("Connecting to ");
Serial.println(ssid);

//*****************************************//
// Connect the ESP32 the the wifi AP
WiFi.begin(ssid, password);
//WiFi.begin(ssid);
while (WiFi.status() != WL_CONNECTED)
{
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());
Serial.println(WiFi.macAddress());

//---Set the connection to rosserial socket server----------//
// Set the connection to rosserial socket server
nh.getHardware()->setConnection(server, serverPort);

nh.advertise(esp32);

// Check nh.Connected
while(nh.connected() == 0)
{
nh.spinOnce();
Serial.println("Not Connected to rosserial socket server");
delay(100);
}
Serial.println("Connected to rosserial socket server");
//*****************************************//

}

//------------------- Loop ---------------------//
void loop()
{
if(nh.connected() == 1)
{
Serial.println("Connected");
// Say hello
str_msg.data = hello;
esp32.publish( &str_msg );
}
else
{
Serial.println("Not Connected");
ESP.restart();
}
while(nh.connected() == 0)
{
nh.spinOnce();
Serial.println("Not Connected to rosserial socket server");
delay(100);
}
//nh.spinOnce();
//delay(1);
}
