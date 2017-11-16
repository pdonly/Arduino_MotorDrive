/* Adapted from:
Robot arm DC motor Control, Adapted from 
 *  "Arduino DC Motor Control - PWM | H-Bridge | L298N
         Example 02 - Arduino Robot Car Control
    by Dejan Nedelkovski, www.HowToMechatronics.com"
    
 On Nov 11, 2017
    JPD
 
 */

#define enA 9
#define in1 4
#define in2 5
#define enB 10
#define in3 6
#define in4 7

int motorSpeedA = 0;
int motorSpeedB = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  int aAxis = analogRead(A0); // Read POT a
  int bAxis = analogRead(A1); // Read POT b
  Serial.print("a");
  Serial.print(aAxis);
  Serial.print("  ");
  Serial.print("b");
  Serial.println(bAxis);

  // aAxis Control
  if(aAxis < 470) {
    // set motor A backward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // convert declining aAxis readings to increasing 8bit value for PWM to motor speed
    motorSpeedA = map(aAxis, 470, 0, 0, 255);
  }
  else if (aAxis > 550) {
    // set motor A forward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    //convert declining aAxis readings to increasing 8bit value for PWM to motor speed
    motorSpeedA = map(aAxis, 550, 1023, 0, 255);
  }
  // If POT is centered don't move
  else {
    motorSpeedA = 0;
  }
  if(bAxis < 470) {
    //set motor B backward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    // convert reading to PWM
    motorSpeedB = map(bAxis, 470, 0, 0, 255);
  }
  else if (bAxis > 550) {
    //set motor B forward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    // convert POT reading to PWM
    motorSpeedB = map(bAxis, 550, 1023, 0, 255);
  }
  else {
    motorSpeedB = 0;
  }
  //Prevent motor buzzing at low speeds
  if (motorSpeedA < 70) {
    motorSpeedA = 0;
  }
  if (motorSpeedB < 70) {
    motorSpeedB = 0;
  }

  analogWrite(enA, motorSpeedA); 
  analogWrite(enB, motorSpeedB);
  
  
  }

