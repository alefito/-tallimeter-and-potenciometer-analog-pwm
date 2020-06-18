#include <NewPing.h>

#define TRIGGER_PIN  12
#define ECHO_PIN     11
#define MAX_DISTANCE 200

/*Crear el objeto de la clase NewPing*/
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);


const int analogInPin = A0;
const int analogOutPin = 9;

int sensorValue = 0;
int outputValue = 0;


void setup() {
  Serial.begin(9600);
}

void loop() {
  
  delay(1);
  
  int uS = sonar.ping_median();
  
  Serial.print("Altura: ");
  Serial.print(uS / US_ROUNDTRIP_CM);
  Serial.println("cm");
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  digitalWrite(13, HIGH);
  delay(uS / US_ROUNDTRIP_CM * 10);
  digitalWrite(13, LOW);
  delay(uS / US_ROUNDTRIP_CM * 10);

  outputValue = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(analogOutPin, outputValue);
  Serial.print("potenciometro = ");
  Serial.print(sensorValue / 2 + 1);
  Serial.print("\t salida = ");
  Serial.println(outputValue + 47);
  digitalWrite(13, HIGH);
  delay(uS / US_ROUNDTRIP_CM * 10);
  digitalWrite(13, LOW);
  delay(uS / US_ROUNDTRIP_CM * 10);
}
