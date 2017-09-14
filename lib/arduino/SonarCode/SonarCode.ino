#include <NewPing.h>

/*
 * Posted on http://randomnerdtutorials.com
 * created by http://playground.arduino.cc/Code/NewPing
*/

#include <NewPing.h>
 
#define TRIGGER_PIN_R 5
#define ECHO_PIN_R 11

#define TRIGGER_PIN_L 6
#define ECHO_PIN_L 12

#define MAX_DISTANCE 200

int enacted_pin = 3;
int right_pin = 2;
int left_pin = 4;


long inches_left, inches_right;
 
NewPing sonar_R(TRIGGER_PIN_R, ECHO_PIN_R, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
 NewPing sonar_L(TRIGGER_PIN_L, ECHO_PIN_L, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
   Serial.begin(9600);

     pinMode(enacted_pin, OUTPUT);
  pinMode(left_pin, OUTPUT);
  pinMode(right_pin, OUTPUT);

  digitalWrite(enacted_pin, LOW);
  digitalWrite(right_pin, LOW);
  digitalWrite(left_pin, LOW);
}
 
void loop() {
   delay(2);
   unsigned int inches_left = sonar_L.ping_cm();
      unsigned int inches_right = sonar_R.ping_cm();

   Serial.print(inches_right);
   Serial.print("cm, ");
      Serial.print(inches_left);
   Serial.println("cm");

   if (((inches_left > 1) && (inches_left < 50)) || ((inches_right > 1) && (inches_right < 50)))
  {
    digitalWrite(enacted_pin, HIGH);
    if(inches_left > 1 && inches_left <50)
    {
      digitalWrite(left_pin, HIGH);
    }
    else
    {
      digitalWrite(left_pin, LOW);
    }
    
    if (inches_right > 3 && inches_right < 30)
    {
      digitalWrite(right_pin, HIGH);
    }
    else
    {
      digitalWrite(right_pin, LOW);
    }
  }
  else
  {
    digitalWrite(enacted_pin, LOW);
    digitalWrite(right_pin, LOW);
    digitalWrite(left_pin, LOW);
  }
}

