/*
 * rosserial Publisher Example
 * Prints "hello world!"
 * This intend to connect to a Wifi Access Point
 * and a rosserial socket server.
 * You can launch the rosserial socket server with
 * roslaunch rosserial_server socket.launch
 * The default port is 11411
 *
 */

 /*
  * Command
  * $roslaunch rosserial_server socket.launch       (terminal 1)
  * $rostopic list                                  (terminal 2)
  * $rostopic echo chatter                          (terminal 3)
  */


 /*
  * Different between Example of Esp8266 and Esp32
 * ESP8266 --> #include <ESP8266WiFi.h>
 * EPS32 ----> #include <WiFi.h>
 */


//#include <ESP8266WiFi.h>
#include <WiFi.h>
#include <ros.h>
#include <std_msgs/String.h>

const char* ssid     = "Vodafone-33602205";
const char* password = "499358emzsfxi2c";
// Set the rosserial socket server IP address
IPAddress server(192,168,1,3);

// Set the rosserial socket server port
const uint16_t serverPort = 11411;

ros::NodeHandle nh;
// Make a chatter publisher
std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

// Be polite and say hello
char hello[13] = "hello world!";
uint16_t period = 50;
uint32_t last_time = 0;


void setup()
{
  // Use ESP8266 serial to monitor the process
  Serial.begin(115200);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  // Connect the ESP8266 the the wifi AP
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Set the connection to rosserial socket server
  nh.getHardware()->setConnection(server, serverPort);
  nh.initNode();

  // Another way to get IP
  Serial.print("IP = ");
  Serial.println(nh.getHardware()->getLocalIP());

  // Start to be polite
  nh.advertise(chatter);

  while (nh.connected()==0){
  nh.spinOnce();
  delay(100);
  }
}

void loop()
{
  
  if(millis() - last_time >= period)
    {
      last_time = millis();
      if (nh.connected())
      {
        //Serial.println("Connected");
        // Say hello
        str_msg.data = hello;
        chatter.publish( &str_msg );
      } else {
        Serial.println("Not Connected");
        
      }
    }
    nh.spinOnce();
    delay(10);

}
