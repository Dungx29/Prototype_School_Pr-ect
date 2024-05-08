#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

int light1 = 5;
int light2 = 6;
int light3 = 7;

SoftwareSerial Bluetooth(0, 1);
char Data;
void sendData(String transmitData){
Bluetooth.println(transmitData);}

void setup(){
    Bluetooth.begin(9600);
    pinMode(light1,OUTPUT);
    pinMode(light2,OUTPUT);
    pinMode(light3,OUTPUT);
}

void loop(){
    if(Bluetooth.available()){
        Data=Bluetooth.read();
        if(Data==('4')){
            digitalWrite(light1,1);
            sendData("Light one ON");
        }
        if(Data==('1')){
            digitalWrite(light1,0);
            sendData("Light one OFF");
        }
        if(Data==('5')){
            digitalWrite(light2,1);
            sendData("light two ON");
        }
        if(Data==('2')){
            digitalWrite(light2,0);
            sendData("light two OFF");
        }
        if(Data==('6')){
            digitalWrite(light3,1);
            sendData("Light three ON");
        }
        if(Data==('3')){
            digitalWrite(light3,0);
            sendData("Light three OFF");
        }
        if(Data==('9')){
            digitalWrite(light1,1);
            digitalWrite(light2,1);
            digitalWrite(light3,1);
            sendData("ALL LIGHTS ON");
        }
        if(Data==('0')){
            digitalWrite(light1,0);
            digitalWrite(light2,0);
            digitalWrite(light3,0);
            sendData("ALL LIGHTS OFF");
        }
    }
}
