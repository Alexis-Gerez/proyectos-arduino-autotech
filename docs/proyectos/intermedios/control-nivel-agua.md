# 🌊 Control de Nivel de Agua con Arduino, Sensor Ultrasónico, Servo Motor y Display de 7 Segmentos 🚰

¡Bienvenidos a un emocionante proyecto de nivel intermedio con Arduino! Este proyecto titulado "**Control de Nivel de Agua con Arduino**" se centra en el uso de un sensor ultrasónico para medir el nivel de agua, un servo motor para simular la apertura o cierre de una válvula, y un display de 7 segmentos para mostrar el estado del nivel de agua en tiempo real. Este proyecto es perfecto para aquellos que buscan profundizar en la programación de Arduino y en la integración de múltiples componentes electrónicos en un sistema. ¡Vamos a ello! 🚀

![Control de Nivel de Agua](../../img/p7-control-agua.png)

**Control de Nivel de Agua con Arduino: Aprende a medir el nivel de agua con un sensor ultrasónico y controlar una válvula simulada con un servo motor.**

## Enlace al Proyecto en Tinkercad - Control de Nivel de Agua

Explora cómo funciona este proyecto y experimenta con el circuito interactivo en Tinkercad. Haz clic en el siguiente enlace para acceder: [Control de Nivel de Agua - Proyecto en Tinkercad](https://www.tinkercad.com/things/3N63yFVGyDS-proyecto-intermedio-1-control-de-nivel-de-agua-con-ultrasonico?sharecode=ECt_GNZzw1PsMI3Qll-QVU2P65au0cj61814xxkKF-M).

## Componentes Necesarios

Para llevar a cabo este proyecto, vamos a necesitar los siguientes componentes:

*   1 x Arduino Uno
*   1 x Sensor Ultrasónico HC-SR04
*   1 x Servo Motor
*   1 x Display de 7 Segmentos
*   Cables de Conexión
*   1 x Protoboard
*   Fuente de Alimentación (USB de la PC o batería externa)

## Todos los materiales necesarios los encontrarás en los siguientes enlaces:

*   [Kit de Arduino Uno R3 - Incluye todo lo necesario](https://amzn.to/4dQTpkX)
*   [Kit de módulos de sensores y componentes - Compatible con Arduino](https://amzn.to/3yGZIsk)

## Configuración del Circuito

### Diagrama de Conexión

![Diagrama de Conexión](../../img/p7-diagrama-agua.jpg)

### Conexiones:

*   **Sensor Ultrasónico HC-SR04:**
    *   Conecta VCC a 5V de Arduino.
    *   Conecta GND a GND de Arduino.
    *   Conecta Trig al pin 8 de Arduino.
    *   Conecta Echo al pin 9 de Arduino.
*   **Servo Motor:**
    *   Conecta VCC (cable rojo) a 5V de Arduino.
    *   Conecta GND (cable negro) a GND de Arduino.
    *   Conecta Señal (cable amarillo) al pin 3 de Arduino.
*   **Display de 7 Segmentos:**
    *   Conectar los segmentos (A-G) a los pines digitales de Arduino: 4, 5, 6, 7, 10, 11, 12.
    *   Conecta VCC a 5V de Arduino.
    *   Conecta GND a GND de Arduino.

### Conexión en Tinkercad (Simulación)

Para simular correctamente este proyecto en Tinkercad, asegúrate de seguir estas instrucciones:

*   **Conectar el Display de 7 Segmentos:** Asegúrate de usar un display común cátodo (o ajustar la configuración si es un ánodo común).
*   **Configurar el Sensor Ultrasónico:** Asegúrate de que el sensor HC-SR04 esté correctamente colocado en el protoboard y conectado a los pines indicados.

## Código para el Control de Nivel de Agua con Arduino

¡Es hora de programar! Aquí tienes el código completo para tu proyecto de control de nivel de agua. Simplemente copia y pega este código en tu Arduino IDE para empezar:

<div style="border: 2px solid #007BFF; padding: 20px; background-color: #f0f8ff; position: relative; margin: 20px 0; border-radius: 8px;">
    <button onclick="copyCode()" style="background-color: #007BFF; color: white; padding: 10px 20px; border: none; cursor: pointer; position: absolute; right: 10px; top: 10px; border-radius: 5px; font-weight: bold;">Copiar Código</button>
    <pre id="codeContent" style="margin-top: 40px; overflow-x: auto;"><code>
#include <Servo.h>  // Librería para controlar el servo

// Definición de pines
const int trigPin = 8;
const int echoPin = 9;
const int servoPin = 3;
const int displayPins[7] = {4, 5, 6, 7, 10, 11, 12}; // Pines para el display de 7 segmentos

Servo myServo;  // Crear un objeto Servo

void setup() {
  // Configuración del sensor ultrasónico
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Configuración del servo
  myServo.attach(servoPin);
  
  // Configuración del display de 7 segmentos
  for (int i = 0; i < 7; i++) {
    pinMode(displayPins[i], OUTPUT);
    digitalWrite(displayPins[i], LOW); // Inicializar los segmentos como apagados
  }

  // Inicialización de la posición del servo
  myServo.write(90);  // Posición media
  Serial.begin(9600);  // Iniciar la comunicación serie
}

void loop() {
  long duration;
  int distance;
  
  // Enviar un pulso de sonido
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Leer la duración del pulso de retorno
  duration = pulseIn(echoPin, HIGH);
  
  // Calcular la distancia en cm
  distance = duration * 0.034 / 2;

  // Mostrar distancia en el monitor serie
  Serial.print("Nivel de Agua: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Control del servo y display basado en el nivel de agua
  if (distance >= 20 && distance < 50) {  // Nivel bajo (20-50 cm)
    myServo.write(0);  // Cerrar válvula
    mostrarNumero(0);  // Mostrar "0" en el display
    Serial.println("Nivel de Agua: Bajo (0)");
  } else if (distance >= 50 && distance < 80) {  // Nivel medio (50-80 cm)
    myServo.write(90);  // Posición media de la válvula
    mostrarNumero(1);  // Mostrar "1" en el display
    Serial.println("Nivel de Agua: Medio (1)");
  } else if (distance >= 80 && distance <= 100) {  // Nivel alto (80-100 cm)
    myServo.write(180);  // Abrir válvula
    mostrarNumero(2);  // Mostrar "2" en el display
    Serial.println("Nivel de Agua: Alto (2)");
  } else {
    // Si la distancia es inválida o fuera de rango, mostrar un error en el display
    mostrarNumero(3);  // Mostrar "3" para indicar error o fuera de rango
    Serial.println("Nivel de Agua: Error (3)");
  }

  delay(1000);  // Espera 1 segundo antes de la siguiente lectura
}

// Función para mostrar números en el display de 7 segmentos
void mostrarNumero(int num) {
  // Definición de los números 0 a 3 en el display de 7 segmentos
  byte numeros[4][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0 (A, B, C, D, E, F encendidos; G apagado)
    {0, 1, 1, 0, 0, 0, 0}, // 1 (B, C encendidos; A, D, E, F, G apagados)
    {1, 1, 0, 1, 1, 0, 1}, // 2 (A, B, D, E, G encendidos; C, F apagados)
    {1, 1, 1, 1, 0, 0, 1}  // 3 (A, B, C, D, G encendidos; E, F apagados)
  };
  
  for (int i = 0; i < 7; i++) {
    digitalWrite(displayPins[i], numeros[num][i]);
  }
}
</code></pre>
</div>

## Explicación del Código

A continuación, explicamos cada línea del código para ayudarte a comprender su funcionamiento y a desarrollar un pensamiento crítico sobre su estructura y lógica:

1.  **Configuración de Pines y Componentes:** Se configuran los pines para el sensor ultrasónico, el servo motor y el display de 7 segmentos. Esto asegura que cada componente funcione correctamente.
2.  **Sensor Ultrasónico:** Los pines `trigPin` y `echoPin` se utilizan para enviar y recibir pulsos ultrasónicos que permiten calcular la distancia.
3.  **Servo Motor:** Utilizamos el pin `servoPin` para controlar la posición de la válvula simulada.
4.  **Display de 7 Segmentos:** Usamos los pines 4, 5, 6, 7, 10, 11 y 12 para controlar los segmentos del display y mostrar números.
5.  **Control del Nivel de Agua:** Según el nivel de agua medido por el sensor ultrasónico, se ajusta la posición del servo motor para abrir o cerrar una válvula simulada. Dependiendo del rango de la distancia detectada, se muestra un número en el display de 7 segmentos indicando el nivel de agua: "0" para nivel bajo, "1" para nivel medio, "2" para nivel alto y "3" para error.

## Problemas Comunes y Soluciones

*   **El Display de 7 Segmentos no muestra información correcta:** Verifica que las conexiones de los segmentos del display estén correctamente conectadas a los pines de Arduino.
*   **El Servo Motor no se mueve:** Asegúrate de que el servo esté correctamente conectado al pin 3 de Arduino y de que esté recibiendo alimentación suficiente.
*   **El Sensor Ultrasónico no responde:** Revisa que los pines de `Trig` y `Echo` estén conectados correctamente y que el sensor esté orientado adecuadamente para medir la distancia.

## Desafío para el Usuario

¿Cómo podrías mejorar este proyecto para incluir un sistema de alerta de sobrellenado? Por ejemplo, podrías agregar un LED que parpadee o un buzzer que suene cuando el nivel de agua exceda un límite seguro. ¡Deja tus ideas en los comentarios!

<button onclick="toggleAnswer()" style="margin-top: 10px; background-color: #007BFF; color: white; padding: 10px; border: none; cursor: pointer; border-radius: 5px; font-weight: bold;">Mostrar Solución</button>

<div id="answer" style="display: none; margin-top: 20px; background-color: #d4edda; border: 1px solid #c3e6cb; padding: 20px; border-radius: 8px; color: #155724; position: relative;">
    <p>Puedes añadir un LED o un buzzer al circuito y modificar el código para activar una alerta. Aquí tienes un ejemplo de cómo hacerlo:</p>
    <pre id="solutionCodeContent" style="background-color: #f8f9fa; padding: 10px; border-radius: 5px; border: 1px solid #eee;"><code>
// Añade estas líneas al código existente

const int ledPin = 13; // Pin del LED de alerta
const int buzzerPin = 8; // Pin del buzzer de alerta
const float waterLimit = 90.0; // Límite de nivel de agua en cm

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  // El resto del setup() permanece igual
}

void loop() {
  // Código existente para leer el sensor y mostrar el nivel de agua
  if (distance > waterLimit) {
    digitalWrite(ledPin, HIGH); // Enciende el LED
    tone(buzzerPin, 1000); // Activa el buzzer
  } else {
    digitalWrite(ledPin, LOW); // Apaga el LED
    noTone(buzzerPin); // Apaga el buzzer
  }
}
</code></pre>
    <button onclick="copySolutionCode()" style="background-color: #007BFF; color: white; padding: 8px 16px; border: none; cursor: pointer; border-radius: 5px; margin-top: 10px; font-weight: bold;">Copiar Código de Solución</button>
</div>

¡Espero que disfrutes construyendo este proyecto tanto como yo disfruto compartiéndolo contigo! Recuerda que la práctica hace al maestro, así que sigue experimentando y adaptando este código a nuevas ideas. ¡Nos encantaría ver tus creaciones! 🚀

Si te ha gustado este artículo, por favor compártelo y suscríbete a nuestro blog para más proyectos interesantes. ¡Hasta la próxima aventura tecnológica!

<script>
function copyCode() {
    const codeContent = document.getElementById('codeContent').innerText;
    navigator.clipboard.writeText(codeContent);
    alert("¡Código copiado al portapapeles!");
}

function toggleAnswer() {
    const answer = document.getElementById('answer');
    if (answer.style.display === 'none' || answer.style.display === '') {
        answer.style.display = 'block';
    } else {
        answer.style.display = 'none';
    }
}

function copySolutionCode() {
    const solutionCodeContent = document.getElementById('solutionCodeContent').innerText;
    navigator.clipboard.writeText(solutionCodeContent);
    alert("¡Código de la solución copiado al portapapeles!");
}
</script>
