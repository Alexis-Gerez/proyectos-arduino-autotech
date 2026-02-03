#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Configuración del sensor ultrasónico
#define TRIGGER_PIN 9
#define ECHO_PIN 10
#define MAX_DISTANCE 200  // Distancia máxima en cm

// Configuración del buzzer
#define BUZZER_PIN 11

// Configuración de la pantalla LCD I2C (dirección 0x27)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Inicializar la pantalla LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Distancia:");

  // Inicializar los pines del sensor y buzzer
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Inicializar la comunicación serie
  Serial.begin(9600);
}

void loop() {
  // Enviar un pulso al sensor ultrasónico
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  // Leer la duración del pulso de retorno
  long duration = pulseIn(ECHO_PIN, HIGH);

  // Calcular la distancia en cm
  int distance = duration * 0.034 / 2;

  // Mostrar la distancia en la pantalla LCD
  lcd.setCursor(0, 1);
  if (distance == 0 || distance >= 200) {
    lcd.print("Fuera de rango   ");
  } else {
    lcd.print(distance);
    lcd.print(" cm           ");
  }

  // Mostrar la distancia en el monitor serie
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Activar el buzzer si la distancia es menor o igual a 25 cm
  if (distance > 0 && distance <= 25) {
    digitalWrite(BUZZER_PIN, HIGH);  // Encender el buzzer
  } else {
    digitalWrite(BUZZER_PIN, LOW);   // Apagar el buzzer
  }

  delay(100);
}
