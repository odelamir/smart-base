
#include <WiFi.h>
#include <Wire.h>
#include <ESP32Servo.h>
#include <Adafruit_NeoPixel.h>

const char* ssid = "ZTE_AC6ABF";
const char* password = "95213782";
#define servo_pin 18
#define buzz_pin 32
int locations[4]={0,0,0,0};
int temp[4]={0,0,0,0};
int i=0;
int page=1;
#define LM75_addr 0x48

#define firePin 13

#define open_led 19  // Which pin on the Arduino is connected to the NeoPix..els?

#define NUMPIXELS 24  // How many NeoPixels are attached to the Arduino?
int danger_stole=0;
int danger_life=0;
const byte TRIG_PIN_A = 2;
const byte ECHO_PIN_A = 15;

const byte TRIG_PIN_B = 14;
const byte ECHO_PIN_B = 27;

const byte TRIG_PIN_C = 23;
const byte ECHO_PIN_C = 33;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, open_led, NEO_GRB + NEO_KHZ800);

Servo my_servo;

int flag_stole=1;
WiFiClient client;
int flag_led=1;


WiFiServer server(80);
int flag=1;
String request , print_pasword = "you";
int Flag=1;
int flag_calling=1;
#define RXD2 16
#define TXD2 17

int j;




void setup() {
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  resetMp3();
  Serial.begin(115200);
  pixels.begin();
  configTemp(LM75_addr);
  Wire.begin();
  my_servo.attach(servo_pin);
  my_servo.write(0);  // Initial servo position (0 for closed)
  connectToWifi();
  server.begin();  // Start the server
  delay(6000);
  pinMode(TRIG_PIN_A, OUTPUT);
  pinMode(ECHO_PIN_A, INPUT);
  pinMode(TRIG_PIN_B, OUTPUT);
  pinMode(ECHO_PIN_B, INPUT);
  pinMode(TRIG_PIN_C, OUTPUT);
  pinMode(ECHO_PIN_C, INPUT);
 pinMode(firePin, INPUT);
  pixels.begin();
  configTemp(LM75_addr);
  Wire.begin();
  my_servo.attach(servo_pin);
  my_servo.write(0); 
}



void loop() {
  if(locations[1]||locations[2]||locations[3]<18&&flag_led){

    openLed();
  }
 
  if ( locations[1]+locations[2]+locations[3]>65&&flag) {

     danger_stole=1;
  openLed();
  OnBuzzer();
  closeDoor();
  if(flag_stole) {
        flag_stole=0;
         playFromFolder(2, 40);
       }
}

 if(danger_life&&temp[1]!=locations[1]){
    playFromFolder(2, locations[1]);
    temp[1]=locations[1];
    delay(5000);}
if(danger_life&&temp[2]!=locations[2]){
    playFromFolder(2, locations[2]);
    temp[2]=locations[2];
    delay(5000);}

    if(danger_life&&temp[3]!=locations[3]){
    playFromFolder(2, locations[3]);
    temp[3]=locations[3];
    delay(5000);}

 if (temperture()&&fire()&&Flag){
  danger_life=1;
  openLed();
  OnBuzzer();
openDoor();
}
 i=0;


connectToClient();


ultrasonic(TRIG_PIN_A, ECHO_PIN_A) ;
ultrasonic(TRIG_PIN_B, ECHO_PIN_B);
ultrasonic(TRIG_PIN_C, ECHO_PIN_C);
// //    if (ultrasonic(TRIG_PIN_A, ECHO_PIN_A) || ultrasonic(TRIG_PIN_B, ECHO_PIN_B) || ultrasonic(TRIG_PIN_C, ECHO_PIN_C))
// //    openLed();
// //   else
// //     closeLed();
// // Serial.println(  locations[1]+locations[2]+locations[3]);
// Serial.println( locations[1]);
//  Serial.println( locations[2]);
// Serial.println( locations[3]);
  delay(1000);

}
