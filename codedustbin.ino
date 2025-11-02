#include <Servo.h>
#define TRIGGER_PIN 9
#define ECHO_PIN 6
#define SERVO_PIN 11
#define MAXDISTANCE 20
long duration;
int distance;
int open = 90;
int close = 0;

Servo servo;

void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER_PIN, OUTPUT );
  pinMode(ECHO_PIN, INPUT);
  servo.attach(SERVO_PIN);
  servo.write(close);
  // put your setup code here, to run once:
}

void loop() {
  long duration, distance;
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration / 2) / 29.1;

  if(distance <= MAXDISTANCE){
    servo.write(90);
    delay(1000);

  } else{
    servo.write(0);
    delay(1000);
  }
  Serial.print("Distance: ");
  Serial.println(distance);
  Serial.print("cm");
  
 

}
