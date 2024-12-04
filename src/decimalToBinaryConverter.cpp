#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

int ledPin1 = 13;
int ledPin2 = 12;
int ledPin3 = 11;
int ledPin4 = 10;
int ledPin5 = 9;
int ledPin6 = 8;
int ledPin7 = 7;
int ledPin8 = 6;
int pinArray[] = {13, 12, 11, 10, 9, 8, 7, 6};
String userInput;
boolean runLoop;

void setup()
{
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);
  pinMode(ledPin8, OUTPUT);

  for (int i = 0; i <= 8; i++) {
    digitalWrite(pinArray[i], HIGH);
    delay(100);
    digitalWrite(pinArray[i], LOW);
  }

  runLoop = false;
  
  Serial.println("please Enter a number between 1 and 255");
}

void loop()
{
  
  if (Serial.available())
  {
    Serial.println("Start");
    userInput = Serial.readString();
    Serial.print("You Typed: ");
    Serial.println(userInput);

    runLoop = true;
  }

  while (runLoop == true) {

      int userInputInt = userInput.toInt();

      if (userInputInt >= 256 || userInputInt <= 0) {
        Serial.println("Error - Your Number is to HIGH or to LOW, Please Try Again");
        userInputInt = 0;
        runLoop = false;    
        Serial.println("please Enter a number between 1 and 255");
        break;
      }
    
      for (int i = 0; i < 8; i++)
      {

        if (userInputInt > 0) {
          int light = userInputInt % 2;

          if (light == 1){
            digitalWrite(pinArray[i], HIGH);
            Serial.println("High");
          } else if (light == 0){
            digitalWrite(pinArray[i], LOW);
            Serial.println("Low");
          }

          userInputInt /= 2;
        } else {
          digitalWrite(pinArray[i], LOW);
        }
      }
    Serial.println("please Enter a number between 1 and 255");
    runLoop = false;    
    }

}