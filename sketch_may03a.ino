#include <Servo.h>
//#include </home/pi/Desktop/HardwareSerial.h>
String readString, JS_ADC_0, JS_ADC_1,JS_ADC_2;

int n1 ,n2, n3, sum;



// Joystick Settings



static const int LOW_range0=-1000;

static const int HIGH_range0=1000;

static const int LOW_range1=-1000;

static const int HIGH_range1=1000;

static const int LOW_range2=-1000;

static const int HIGH_range2=1000;



 

 // ESC/Thruster Settings

  static const int MAX_FWD_REV_THROTTLE = 300; // Value between 0-400

  static const int MAX_TURN_THROTTLE = 300; // Value between 0-400

  static const int MAX_VERTICAL_THROTTLE = 300; // Value between 0-400

  static const int CENTER_THROTTLE = 1500;



 

  // Arduino Pins

  

  byte thruster_X1 = 6;//6

  byte thruster_X2 = 8;

  byte thruster_Z = 5; //5

  byte thruster_Z2 = 7; 

  byte thruster_Y =4 ; // 4

  //byte thruster_Y2 =3 ;


 
 

  // Servos



  Servo thrusterLeft;

  Servo thrusterRight;

  Servo thrusterVertical;

  Servo thrusterVertical2;

  Servo thrusterMID;

  //Servo thrusterMID2;

  



void setup() {

  Serial.begin(9600);

  thrusterLeft.attach(thruster_X1); 

  thrusterRight.attach(thruster_X2);

  thrusterVertical.attach(thruster_Z);

  thrusterVertical2.attach(thruster_Z2);

  thrusterMID.attach(thruster_Y);
  
  //thrusterMID2.attach(thruster_Y2);



  thrusterLeft.writeMicroseconds(CENTER_THROTTLE);

  thrusterRight.writeMicroseconds(CENTER_THROTTLE);

  thrusterVertical.writeMicroseconds(CENTER_THROTTLE);

  thrusterVertical2.writeMicroseconds(CENTER_THROTTLE);

  thrusterMID.writeMicroseconds(CENTER_THROTTLE);
  
  //thrusterMID2.writeMicroseconds(CENTER_THROTTLE);

   Serial.println("servo-test-1.0"); // so I can keep track of what is loaded

  

  delay(7000); 

  



}



void loop() 

{




   while (Serial.available()) {

    delay(3);  //delay to allow buffer to fill

    if (Serial.available() > 0) {

      char c = Serial.read();  //gets one byte from serial buffer

      if (c == '\n') break;

      readString += c; //makes the string readString

    }

    

  }

  



  if (readString.length() >0) {

      //Serial.println(readString); //see what was received

     

      // expect a string like 07002100 containing the two servo positions     

      JS_ADC_0 = readString.substring(0, 5); //get the first five characters

      JS_ADC_1 = readString.substring(5, 10); //get the next five characters

      JS_ADC_2 = readString.substring(15, 20); //get the next five characters

          



       n1 = JS_ADC_0.toInt();

       n2 = JS_ADC_1.toInt();

       n3 = JS_ADC_2.toInt();

       sum = n1+n2;



       

  if (sum>1000 || sum<-1000 || sum==0)

  {

    n1 = n1/1.6;

    n2 = n2/1.6;

  }

               

    readString="";

  }





int forwardCommand    = map(n1, // Read raw joystick value

                              LOW_range0, // Joystick low value

                              HIGH_range0, // Joystick high value

                              -MAX_FWD_REV_THROTTLE, // Command low value

                              MAX_FWD_REV_THROTTLE); // Command high value

          

                              

 int turnCommand       = map(n2, // Read raw joystick value

                              LOW_range1, // Joystick low value

                              HIGH_range2, // Joystick high value

                              -MAX_TURN_THROTTLE, // Command low value

                              MAX_TURN_THROTTLE); // Command high value

                             

  int verticalCommand   = map(n3, // Read raw joystick value

                              LOW_range2, // Joystick low value

                              HIGH_range2, // Joystick high value

                              -MAX_VERTICAL_THROTTLE, // Command low value

                              MAX_VERTICAL_THROTTLE); // Command high value     



 // Combine the "stopped" command with forward, turn, and vertical and send 

  // to the ESCs.

  thrusterLeft.writeMicroseconds(CENTER_THROTTLE+((forwardCommand)));

  thrusterRight.writeMicroseconds(CENTER_THROTTLE+((forwardCommand)));

  thrusterMID.writeMicroseconds(CENTER_THROTTLE+((turnCommand)));

 // thrusterMID2.writeMicroseconds(CENTER_THROTTLE+((-turnCommand)));

  thrusterVertical.writeMicroseconds(CENTER_THROTTLE+verticalCommand);

  thrusterVertical2.writeMicroseconds(CENTER_THROTTLE-verticalCommand);

  

  Serial.print("Fwd: "); Serial.print(forwardCommand);

  Serial.print("\t"); 

  Serial.print("Turn: "); Serial.print(turnCommand);

  Serial.print("\t"); 

  Serial.print("Vert: "); Serial.print(verticalCommand);

  Serial.print("\t"); 

  Serial.print("Left: "); Serial.print(CENTER_THROTTLE+(forwardCommand+turnCommand));

  Serial.print("\t"); 

  Serial.print("Right: "); Serial.print(CENTER_THROTTLE+(forwardCommand-turnCommand));

  Serial.print("\t"); 

  Serial.print("MID: "); Serial.print(CENTER_THROTTLE+(forwardCommand-turnCommand));

  Serial.print("\t"); 

  Serial.print("sum: "); Serial.print(sum);

  Serial.print("\t"); 

  Serial.print("n1: "); Serial.print(n1);

  Serial.print("\t"); 

  Serial.print("n2: "); Serial.print(n2);

  Serial.print("\t"); 

  Serial.println("");

   delay(100);

                                                     

}#include <Servo.h>
#include </home/pi/Desktop/HardwareSerial.h>
String readString, JS_ADC_0, JS_ADC_1,JS_ADC_2;

int n1 ,n2, n3, sum;



// Joystick Settings



static const int LOW_range0=-1000;

static const int HIGH_range0=1000;

static const int LOW_range1=-1000;

static const int HIGH_range1=1000;

static const int LOW_range2=-1000;

static const int HIGH_range2=1000;



 

 // ESC/Thruster Settings

  static const int MAX_FWD_REV_THROTTLE = 300; // Value between 0-400

  static const int MAX_TURN_THROTTLE = 300; // Value between 0-400

  static const int MAX_VERTICAL_THROTTLE = 300; // Value between 0-400

  static const int CENTER_THROTTLE = 1500;



 

  // Arduino Pins

  

  byte thruster_X1 = 6;//6

  byte thruster_X2 = 8;

  byte thruster_Z = 5; //5

  byte thruster_Z2 = 7; 

  byte thruster_Y =4 ; // 4

  byte thruster_Y2 =3 ;


 
 

  // Servos



  Servo thrusterLeft;

  Servo thrusterRight;

  Servo thrusterVertical;

  Servo thrusterVertical2;

  Servo thrusterMID;

  Servo thrusterMID2;

  



void setup() {

  Serial.begin(9600);

  thrusterLeft.attach(thruster_X1); 

  thrusterRight.attach(thruster_X2);

  thrusterVertical.attach(thruster_Z);

  thrusterVertical2.attach(thruster_Z2);

  thrusterMID.attach(thruster_Y);
  
  thrusterMID2.attach(thruster_Y2);



  thrusterLeft.writeMicroseconds(CENTER_THROTTLE);

  thrusterRight.writeMicroseconds(CENTER_THROTTLE);

  thrusterVertical.writeMicroseconds(CENTER_THROTTLE);

  thrusterVertical2.writeMicroseconds(CENTER_THROTTLE);

  thrusterMID.writeMicroseconds(CENTER_THROTTLE);
  
  thrusterMID2.writeMicroseconds(CENTER_THROTTLE);

   Serial.println("servo-test-1.0"); // so I can keep track of what is loaded

  

  delay(7000); 

  



}



void loop() 

{




   while (Serial.available()) {

    delay(3);  //delay to allow buffer to fill

    if (Serial.available() > 0) {

      char c = Serial.read();  //gets one byte from serial buffer

      if (c == '\n') break;

      readString += c; //makes the string readString

    }

    

  }

  



  if (readString.length() >0) {

      //Serial.println(readString); //see what was received

     

      // expect a string like 07002100 containing the two servo positions     

      JS_ADC_0 = readString.substring(0, 5); //get the first five characters

      JS_ADC_1 = readString.substring(5, 10); //get the next five characters

      JS_ADC_2 = readString.substring(15, 20); //get the next five characters

          



       n1 = JS_ADC_1.toInt();

       n2 = JS_ADC_0.toInt();

       n3 = JS_ADC_2.toInt();

       sum = n1+n2;



       

  if (sum>1000 || sum<-1000 || sum==0)

  {

    n1 = n1/1.6;

    n2 = n2/1.6;

  }

               

    readString="";

  }





int forwardCommand    = map(n1, // Read raw joystick value

                              LOW_range0, // Joystick low value

                              HIGH_range0, // Joystick high value

                              -MAX_FWD_REV_THROTTLE, // Command low value

                              MAX_FWD_REV_THROTTLE); // Command high value

          

                              

 int turnCommand       = map(n2, // Read raw joystick value

                              LOW_range1, // Joystick low value

                              HIGH_range2, // Joystick high value

                              -MAX_TURN_THROTTLE, // Command low value

                              MAX_TURN_THROTTLE); // Command high value

                             

  int verticalCommand   = map(n3, // Read raw joystick value

                              LOW_range2, // Joystick low value

                              HIGH_range2, // Joystick high value

                              -MAX_VERTICAL_THROTTLE, // Command low value

                              MAX_VERTICAL_THROTTLE); // Command high value     



 // Combine the "stopped" command with forward, turn, and vertical and send 

  // to the ESCs.

  thrusterLeft.writeMicroseconds(CENTER_THROTTLE+((forwardCommand)));

  thrusterRight.writeMicroseconds(CENTER_THROTTLE+((forwardCommand)));

  thrusterMID.writeMicroseconds(CENTER_THROTTLE+((turnCommand)));

  thrusterMID2.writeMicroseconds(CENTER_THROTTLE+((-turnCommand)));

  thrusterVertical.writeMicroseconds(CENTER_THROTTLE+verticalCommand);

  thrusterVertical2.writeMicroseconds(CENTER_THROTTLE-verticalCommand);

  

  Serial.print("Fwd: "); Serial.print(forwardCommand);

  Serial.print("\t"); 

  Serial.print("Turn: "); Serial.print(turnCommand);

  Serial.print("\t"); 

  Serial.print("Vert: "); Serial.print(verticalCommand);

  Serial.print("\t"); 

  Serial.print("Left: "); Serial.print(CENTER_THROTTLE+(forwardCommand+turnCommand));

  Serial.print("\t"); 

  Serial.print("Right: "); Serial.print(CENTER_THROTTLE+(forwardCommand-turnCommand));

  Serial.print("\t"); 

  Serial.print("MID: "); Serial.print(CENTER_THROTTLE+(forwardCommand-turnCommand));

  Serial.print("\t"); 

  Serial.print("sum: "); Serial.print(sum);

  Serial.print("\t"); 

  Serial.print("n1: "); Serial.print(n1);

  Serial.print("\t"); 

  Serial.print("n2: "); Serial.print(n2);

  Serial.print("\t"); 

  Serial.println("");

   delay(100);

                                                     

}
