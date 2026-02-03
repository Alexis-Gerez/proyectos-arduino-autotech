#include <Servo.h> // SE DEFINE AL SERVOMOTOR

#define TRIG_PIN A0 // SE DEFINE EL SENSOR ULTRASONICO, TRIG VA AL PIN A0 DEL ARDUINO UNO.
#define ECHO_PIN A1 // SE DEFINE EL SENSOR ULTRASONICO, ECHO VA AL PIN A1 ARDUINO UNO.
#define MAX_DISTANCE 200

Servo myservo; // Crear un objeto servo

boolean goesForward = true; // Comienza avanzando
int distance = 100;
int speedSet = 180; // Velocidad del motor (ajustada a 180 para ambos motores)

const int ENA = 5; // Enable pin for motor A
const int IN1 = 8; // Motor A input 1
const int IN2 = 9; // Motor A input 2
const int ENB = 6; // Enable pin for motor B
const int IN3 = 10; // Motor B input 1
const int IN4 = 11; // Motor B input 2
const int BUZZER_PIN = 12; // Pin para el buzzer

void setup() {
  myservo.attach(3); // PIN PWM DEL SERVO VA AL PIN 3 DEL ARDUINO UNO.
  myservo.write(115); // Posicionar el servomotor en el centro
  delay(2000);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(BUZZER_PIN, OUTPUT); // Configuración del pin del buzzer

  Serial.begin(9600);
}

void loop() {
  int distanceR = 0;
  int distanceL = 0;
  delay(40);

  distance = readPing();

  if (distance <= 25) { // Detecta obstáculos a menos de 25 cm
    tone(BUZZER_PIN, 1000); // Emite un sonido con el buzzer
    moveStop();
    delay(200);
    moveBackward(); // Retrocede si encuentra un obstáculo
    delay(800);

    moveStop();
    delay(200);
    distanceR = lookRight();
    delay(200);
    distanceL = lookLeft();
    delay(200);

    if (distanceR >= distanceL) {
      turnRight();
      moveStop();
    } else {
      turnLeft();
      moveStop();
    }
  } else {
    noTone(BUZZER_PIN); // Apaga el sonido del buzzer si no hay obstáculos
    moveForward(); // Avanzar si no hay obstáculos
  }
}

int lookRight() {
  myservo.write(50); // Girar a la derecha
  delay(500);
  int distance = readPing();
  delay(100);
  myservo.write(115); // Volver al centro
  return distance;
}

int lookLeft() {
  myservo.write(170); // Girar a la izquierda
  delay(500);
  int distance = readPing();
  delay(100);
  myservo.write(115); // Volver al centro
  return distance;
}

int readPing() {
  long duration;
  int distance;
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;
  if (distance == 0) {
    distance = 250; // Valor predeterminado para distancia fuera de rango
  }
  return distance;
}

void moveStop() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void moveForward() { // CARRITO AVANZA
  analogWrite(ENA, speedSet);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENB, speedSet);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward() { // HACIA ATRAS
  analogWrite(ENA, speedSet);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENB, speedSet);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnRight() { // GIRA A LA DERECHA Y AVANZA
  analogWrite(ENA, speedSet);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENB, speedSet);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(300);
  moveForward();
}

void turnLeft() { // GIRA A LA IZQUIERDA Y AVANZA
  analogWrite(ENA, speedSet);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENB, speedSet);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(300);
  moveForward();
}
