
#include <AccelStepper.h>

// Define the stepper motor and the pins that is connected to
AccelStepper stepper1(1, 5, 9); // (Typeof driver: with 2 pins, STEP, DIR)
AccelStepper stepper2(1, 6, 10);

int Button1 = 11;
int Button2 = 12;
int Button3 = 13;
int Button4 = 4;

int top_state = 0;
int top_state2 = 0;
int top_begin = 0;

int bot_pos = 0;
int bot_step = 15;

int top_step = 0;
int top_end = 60000000;
int top_end2 = 60;
bool rot = false;

void setup() {

  Serial.begin(9600);

  stepper1.setMaxSpeed(500); // Set maximum speed value for the stepper 1000
  stepper1.setAcceleration(50); // Set acceleration value for the stepper 500
  stepper1.setCurrentPosition(0); // Set the current position to 0 steps

  stepper2.setMaxSpeed(250); // Set maximum speed value for the stepper 1000
  stepper2.setAcceleration(50); // Set acceleration value for the stepper 500
  stepper2.setCurrentPosition(0);// Set the current position to 0 steps

  pinMode(Button1, INPUT_PULLUP);
  pinMode(Button2, INPUT_PULLUP);
  pinMode(Button3, INPUT_PULLUP);
  pinMode(Button4, INPUT_PULLUP);

}

void loop() {

  int Button1State = digitalRead(Button1);
  int Button2State = digitalRead(Button2);
  int Button3State = digitalRead(Button3);
  int Button4State = digitalRead(Button4);
  Serial.println(top_step);
  //Serial.println(top_state);

  if (Button1State == LOW and rot == false and top_state == 0) {
    
    rot = true;
    top_state += 1;
  }

  if (rot == true) {

    stepper2.moveTo(top_end); 
    stepper2.run();
    top_step += 1;
  
    }

  Button1State = digitalRead(Button1);

  if (Button1State == LOW and rot == true and top_state >= 1 and top_step >= 200) {
    rot = false;
    top_state = 0;
    top_step = 0;
    delay(200);

  }


  if (Button4State == LOW and top_state2 == 0) {
    stepper2.moveTo(top_end2); // Set desired move: 800 steps (in quater-step resolution that's one rotation)
    stepper2.runToPosition(); // Moves the motor to target position w/ acceleration/ deceleration and it blocks until is in position
    top_state2 += 1;
    
  }
  
  Button4State = digitalRead(Button4);

  if (Button4State == LOW and top_state2 == 1) {
    stepper2.moveTo(top_begin); // Set desired move: 800 steps (in quater-step resolution that's one rotation)
    stepper2.runToPosition(); // Moves the motor to target position w/ acceleration/ deceleration and it blocks until is in position
    top_state2 -= 1;
  
  }



  if (Button2State == LOW) {
    bot_pos += bot_step;
    stepper1.moveTo(bot_pos); 
    stepper1.runToPosition();
  
    
  }
  Button2State = digitalRead(Button2);
  if (Button3State == LOW ) {
    bot_pos -= bot_step;
    stepper1.moveTo(bot_pos); 
    stepper1.runToPosition(); 

  }
  
}