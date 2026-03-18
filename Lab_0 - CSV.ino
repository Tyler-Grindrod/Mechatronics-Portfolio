// Pins to read data from
#define Sensor1 A0 // This a different way to define the variable more in line with C++.
#define Sensor2 A1 // This is a personal prefrence to use #define to declare pins since
#define Sensor3 A2 // it is easier to distinguish from regular variables. However, both
#define Sensor4 A3 // this way and the way shown in the lab are acceptable to declare pins.
#define Sensor5 A4 
#define Sensor6 A5
#define Button 2

//Raw data variables.

int rData1 = 0;
int rData2 = 0;
int rData3 = 0;
int rData4 = 0;
int rData5 = 0;
int rData6 = 0;

//Tranformation from bits to Volts.
float B2v = 5/1023; //5Vv=1023bits
//Transformed data variables.
float Data1 = 0;
float Data2 = 0;
float Data3 = 0;
float Data4 = 0;
float Data5 = 0;
float Data6 = 0;
// Button state Variable
int State=0; // 1=Pressed; 0=Release

void setup() {

// put your setup code here, to run once:
pinMode (Button, INPUT) ;//Declare button pin as an input to the arduino.
Serial.begin (9600) ; //Start serial communication
delay(100);//Slight delay to allow serial to begin.

Serial .println("Sensor1, Sensor2, Sensor3, Sensor4, Sensor5, Sensor6, ButtonState") ;//Print titles of colums only once per code initialization

}
 
void loop() {
  // put your main code here, to run repeatedly:
  // Read analog sensor data
  rData1 = analogRead(Sensor1); 
  rData2 = analogRead(Sensor2);
  rData3 = analogRead(Sensor3);  
  rData4 = analogRead(Sensor4); 
  rData5 = analogRead(Sensor5); 
  rData6 = analogRead(Sensor6); 
  //Transform Raw Data
  Data1=rData1* B2v;
  Data2=rData2* B2v;
  Data3=rData3* B2v;
  Data4=rData4* B2v;
  Data5=rData5* B2v;
  Data6=rData6* B2v;
  // Check for that of the Button.
  if(digitalRead(Button)==LOW) {//If button is pressed in the singal will be 0(Volts)
    State=1;
  }
  else {//When the button is not pressed the signal will be 5V = HIGH
    State=0;
  }

  //Print all variable to the Serial Monitor
  Serial.print(Data1);//Print data value and keep going on the same line.
  Serial.print(","); // Add comma deliminator to be easier o read, and to create a CSV  

  Serial.print(Data2);
  Serial.print(",");

  Serial.print(Data3);
  Serial.print(",");

  Serial.print(Data4);
  Serial.print(",");

  Serial.print(Data5);
  Serial.print(",");

  Serial.print(Data6);
  Serial.print(",");

  Serial.print(State); //Print state and end the line
 

}
