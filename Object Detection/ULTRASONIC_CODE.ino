//Run this code on arduino ide 

#include <NewPing.h>

#define buzL 2
#define buzR 4
#define SENSOR_NUM 2      // Number of sensors.
#define MAX_DISTANCE 300 // Maximum distance (in cm) to ping.
NewPing ultrasonic[SENSOR_NUM] = {   // Sensor object array.
  NewPing(9, 8, MAX_DISTANCE), // left Sensor
  NewPing(10, 11, MAX_DISTANCE)   //Right Sensor
};

int  distance[SENSOR_NUM];

void setup()
{
  Serial.begin(9600);
  pinMode (buzR, OUTPUT);
  pinMode (buzL, OUTPUT);
  digitalWrite(buzR, LOW);
  digitalWrite(buzL, LOW);
  delay(1000);
}

void loop() {
  for (int i = 0; i < SENSOR_NUM; i++) {
    distance[i] = ultrasonic[i].ping_cm();
  }
  checkcon();
  Serial.print(distance[0]);
  Serial.print(" , ");
  Serial.println(distance[1]);

}



void checkcon() {
  if ((distance[0] > 0) and (distance[0] < 100)) {
    digitalWrite(buzR, LOW);
    digitalWrite(buzL, HIGH);
    delay(100);
    digitalWrite(buzR, LOW);
    digitalWrite(buzL, LOW);
  }
  if ((distance[1] > 0) and (distance[1] < 100)) {
    digitalWrite(buzL, LOW);
    digitalWrite(buzR, HIGH);
    delay(100);
    digitalWrite(buzR, LOW);
    digitalWrite(buzL, LOW);
  }
}
