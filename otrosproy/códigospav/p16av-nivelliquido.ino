#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Configuración del sensor de nivel de agua
#define WATER_SENSOR_PIN A0
#define MAX_WATER_LEVEL 1023  // Nivel máximo del sensor de agua (valor analógico máximo)
#define MIN_WATER_LEVEL 0     // Nivel mínimo del sensor de agua (valor analógico mínimo)

// Configuración del buzzer
#define BUZZER_PIN 11

// Configuración de la pantalla LCD I2C (dirección 0x27)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Inicializar la pantalla LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Nivel de Comb:");

  // Inicializar el pin del sensor y buzzer
  pinMode(WATER_SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Inicializar la comunicación serie
  Serial.begin(9600);
}

void loop() {
  // Leer el valor del sensor de nivel de agua
  int sensorValue = analogRead(WATER_SENSOR_PIN);

  // Filtrar valores fuera de rango
  if (sensorValue < MIN_WATER_LEVEL) {
    sensorValue = MIN_WATER_LEVEL;
  } else if (sensorValue > MAX_WATER_LEVEL) {
    sensorValue = MAX_WATER_LEVEL;
  }

  // Convertir el valor del sensor a un porcentaje
  int fuelLevel = map(sensorValue, MIN_WATER_LEVEL, MAX_WATER_LEVEL, 0, 100);

  // Mostrar el nivel de combustible en la pantalla LCD
  lcd.setCursor(0, 1);
  lcd.print("Nivel: ");
  lcd.print(fuelLevel);
  lcd.print("%    ");

  // Mostrar el nivel de combustible en el monitor serie
  Serial.print("Nivel de Combustible: ");
  Serial.print(fuelLevel);
  Serial.println("%");

  // Activar el buzzer si el nivel de combustible es menor o igual a 20%
  if (fuelLevel <= 20) {
    digitalWrite(BUZZER_PIN, HIGH);  // Encender el buzzer
  } else {
    digitalWrite(BUZZER_PIN, LOW);   // Apagar el buzzer
  }

  delay(1000);
}
