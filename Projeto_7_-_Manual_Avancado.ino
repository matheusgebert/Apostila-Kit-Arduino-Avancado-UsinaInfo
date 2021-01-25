#include <IRremote.h>
#include <Servo.h>

Servo servo;

int pinoreceptor = 4;
int rele = 5;
int servomotor = 9;
int angulo = 0;

float comando;

IRrecv receptor(pinoreceptor);
decode_results resultado;

void setup() {
  Serial.begin(9600);
  receptor.enableIRIn();
  pinMode(rele, OUTPUT);

  servo.attach(servomotor);

}

void loop() {
  if (receptor.decode(&resultado)) {

    Serial.print("0x");
    Serial.println(resultado.value, HEX);
    comando = (resultado.value);

    if (comando == 0xFF6897) {
      digitalWrite(rele, HIGH);
    }

    if (comando == 0xFFB04F) {
      digitalWrite(rele, LOW);
    }

    if (comando == 0xFF18E7) {
      servo.write(0);
    }

    if (comando == 0xFF4AB5) {
      servo.write(180);
    }

    receptor.resume();
  }
  delay(10);
}
