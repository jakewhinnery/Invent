// When the button is clicked the gripper will change from Open->closed or closed->open

#include <Servo.h>  //add '<' and '>' before and after servo.h

// Creates our servo object
Servo myServo; 

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;// CHANGE THIS TO THE PIN YOU CONNECT THE BUTTON TO
const int servoPin = 9;// CHANGE THIS TO THE PIN YOU PUT THE PWM (orange) TO

// variables will change:
int clampButtonState = 0;         // variable for reading the pushbutton status
int clampOpenClose = 0;           
int past = 1; // to prevent open and closing when button held down.

void setup()
{
  Serial.begin(9600);      // starts serial monitor
  myServo.attach(servoPin);                
 
  pinMode(buttonPin, INPUT_PULLUP); // make buttonPin a receiving pin, default is HIGH
  pinMode(LED_BUILTIN, OUTPUT); //Built-in LED, to tell us the state of the clamp
  
}
 
void loop()
{
  // read the state of the pushbutton value:
  clampButtonState = digitalRead(buttonPin);   
  Serial.println(clampButtonState); // displays the servo value
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (clampButtonState == LOW) {
    if (past == 1) {
      // turn LED on:
      if (clampOpenClose == 0) {
        digitalWrite(LED_BUILTIN, HIGH);
        myServo.write(60);
             // Make your servo turn to Open Position 
        clampOpenClose = 1;
      } else {
        digitalWrite(LED_BUILTIN, LOW);
        myServo.write(0);
             // Make your servo turn to Closed Position
        clampOpenClose = 0;
      }
      past = 0;   
    }
       
  } else {
    past = 1;
  }
}
