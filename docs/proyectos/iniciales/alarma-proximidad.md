# 🚨 Alarma de Proximidad para el Hogar con Arduino 🏠

¡Bienvenidos a un emocionante proyecto educativo de electrónica! Hoy vamos a crear una **Alarma de Proximidad para el Hogar** usando Arduino y un **Sensor de Movimiento PIR**. Esta alarma es perfecta para aprender cómo funcionan los sistemas de seguridad modernos y cómo los podemos implementar fácilmente en nuestros hogares. Además, entenderemos cómo programar en Arduino y a interactuar con sensores y otros componentes electrónicos. ¡Vamos allá! 🚀

![Alarma de Proximidad](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEjFpwVC43U_A1Zjxc0KA8TkZ12IRoKr7WEVbiUaNSyW8WAh7NvsWpiK0AiOyOPbjPRXn2kZ0l1N-YZtCbbsgNXJk5wQYzV2-bHM5HWpIwNVMdjK8S9jBdPAM96EJeREm-UFmp0ggi7J9xGxYT3VDezWPjc5AwrnycSWvSZxOyZMjlmS-NHZlrhnuVYwRGdv/s1600/p5.png)

**Alarma de Proximidad con Sensor PIR y Arduino: Aprende a crear un sistema de seguridad con Arduino para tu hogar.**

## Enlace al Proyecto en Tinkercad - Alarma de Proximidad

Explora cómo funciona este proyecto y experimenta con el circuito interactivo en Tinkercad. Haz clic en el siguiente enlace para acceder: [Alarma de Proximidad - Proyecto en Tinkercad](https://www.tinkercad.com/things/j4NMk2OUF4J-proyecto-inicial-5-alarma-de-proximidad-para-el-hogar-?sharecode=-IFUAA_IrLOp_EIe8rX6y2p30trvpNQpU1_RG0iFODU).

## Componentes Necesarios

Para realizar este proyecto, necesitarás los siguientes componentes:

*   1 x Arduino Uno R3
*   1 x Sensor de Movimiento PIR
*   1 x Buzzer o Bocina
*   2 x LEDs (indicadores visuales)
*   2 x Resistencias de 220 Ω (para los LEDs)
*   Cables de Conexión
*   1 x Protoboard
*   Fuente de Alimentación (USB de PC o batería externa)

## Todos los materiales necesarios los encontrarás en los siguientes enlaces:

*   [Kit de componentes Arduino Uno R3 - Incluye Arduino y más](https://amzn.to/4dQTpkX)
*   [Kit de módulos de sensores y componentes - Compatible con Arduino](https://amzn.to/3yGZIsk)

## Configuración del Circuito

### Diagrama de Conexión

![Diagrama de Conexión](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEjXu5CSrbvxriSFbAGyo7db-VrmAL-0Uyw3YG6z9eLbEkl6pjp_VT7_0BdJ09YtvLxtV6vk_Tcez6KEobvWtNCNcqcr23yGyyVzMgzr-HjdqHSXnY71Ebe1xmu22P5sxwTdNWYPsgvB09Asfe7jjQ73ufp4D4kimQ9UjOTmUt3xUrP9TA7l9xijKTmTpDC7/s1600/p5-ArduinoUno-proyecto-programacion-alarmadeproximidadparaelhogar.jpg)

### Conexiones:

*   **Sensor PIR:**
    *   Conecta VCC a 5V del Arduino.
    *   Conecta GND a GND del Arduino.
    *   Conecta OUT al pin A0 de Arduino.
*   **Buzzer o Bocina:**
    *   Conecta un pin del buzzer al pin 6 de Arduino.
    *   Conecta el otro pin del buzzer a GND.
*   **LEDs:**
    *   LED1: Ánodo al pin digital 5 de Arduino, cátodo a GND a través de una resistencia de 220Ω.
    *   LED2: Ánodo al pin digital 7 de Arduino, cátodo a GND a través de una resistencia de 220Ω.

## Código para la Alarma de Proximidad con Arduino

¡Es hora de programar! Aquí tienes el código completo para tu proyecto de alarma de proximidad. Simplemente copia y pega este código en tu Arduino IDE para empezar:

<div style="border: 2px solid #007BFF; padding: 20px; background-color: #f0f8ff; position: relative; margin: 20px 0; border-radius: 8px;">
    <button onclick="copyCode()" style="background-color: #007BFF; color: white; padding: 10px 20px; border: none; cursor: pointer; position: absolute; right: 10px; top: 10px; border-radius: 5px; font-weight: bold;">Copiar Código</button>
    <pre id="codeContent" style="margin-top: 40px; overflow-x: auto;"><code>
int codigo;
bool estado = false;  // Cambiado a tipo booleano para mayor claridad
const int led1 = 5;
const int led2 = 7;
const int bocina = 6;
const int sensor = A0;
const int contra = 1234;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(bocina, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (!estado) {  // Si la alarma no está activada
    Serial.println("🔒 INGRESA CÓDIGO DE ACTIVACIÓN");
    while (Serial.available() == 0) {}  // Esperar hasta que haya datos disponibles
    codigo = Serial.parseInt();
    if (codigo == contra) {  // Si el código es correcto
      Serial.println("✅ ALARMA ACTIVADA");
      estado = true;  // Cambia el estado a activado
    }
  }

  if (estado) {  // Si la alarma está activada
    Serial.println("🔔 ALARMA ACTIVADA - INGRESE CÓDIGO PARA DESACTIVAR");
    if (Serial.available() > 0) {
      codigo = Serial.parseInt();
      if (codigo == contra) {  // Si el código es correcto
        Serial.println("🛑 ALARMA DESACTIVADA SIN MOVIMIENTO");
        estado = false;  // Cambia el estado a desactivado
        noTone(bocina);  // Apagar la bocina
        digitalWrite(led1, LOW);  // Apagar LED1
        digitalWrite(led2, LOW);  // Apagar LED2
      }
    }
  }

  if (estado && digitalRead(sensor) == HIGH) {  // Si la alarma está activada y se detecta movimiento
    Serial.println("🚨 MOVIMIENTO DETECTADO");
    Serial.println("⏳ INGRESE EL CÓDIGO PARA DESACTIVAR LA ALARMA");

    while (estado) {  // Mientras la alarma esté activada
      tone(bocina, 2500);  // Sonar la bocina
      digitalWrite(led1, LOW);  // Parpadear LED1 y LED2
      digitalWrite(led2, HIGH);
      delay(1000);
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      delay(1000);

      if (Serial.available() > 0) {  // Si se ingresa un código
        codigo = Serial.parseInt();
        if (codigo == contra) {  // Si el código es correcto
          Serial.println("🔕 ALARMA DESACTIVADA");
          noTone(bocina);  // Apagar la bocina
          digitalWrite(led1, LOW);  // Apagar LED1
          digitalWrite(led2, LOW);  // Apagar LED2
          estado = false;  // Cambiar el estado a desactivado
        }
      }
    }
  }
}
</code></pre>
</div>

## Explicación del Código

A continuación, explicamos cada línea del código para ayudarte a comprender su funcionamiento y a desarrollar un pensamiento crítico sobre su estructura y lógica:

1.  **Variables Globales:** Se declaran las variables globales como `codigo`, `estado`, `led1`, `led2`, `bocina`, `sensor`, y `contra`, que controlan el comportamiento de la alarma y su activación/desactivación.
2.  **void setup() { ... }:** La función `setup()` configura los pines de los LEDs, el buzzer y el sensor como entradas o salidas y también inicia la comunicación serial para interactuar con el usuario a través del monitor serie.
3.  **void loop() { ... }:** La función `loop()` se ejecuta repetidamente en un bucle infinito. Dentro del bucle, se realizan las siguientes tareas:
    *   **Activación de Alarma:** Si la alarma no está activada, solicita un código de activación a través del monitor serie.
    *   **Desactivación de Alarma:** Una vez activada la alarma, puede desactivarse introduciendo el código correcto.
    *   **Detección de Movimiento:** Si la alarma está activada y el sensor PIR detecta movimiento, la bocina suena y los LEDs parpadean. La alarma puede desactivarse introduciendo el código correcto.

## Problemas Comunes y Soluciones

*   **El buzzer no suena:** Verifica que las conexiones del buzzer sean correctas y que el pin de control esté correctamente asignado en el código.
*   **El sensor PIR no detecta movimiento:** Asegúrate de que el sensor esté conectado correctamente y de que esté bien orientado para detectar movimiento en el área deseada.
*   **El código no se registra en el monitor serie:** Verifica que la velocidad de baudios en el monitor serie esté configurada a 9600 y que el puerto serie correcto esté seleccionado.

## Desafío para el Usuario

¿Cómo podrías modificar el proyecto para agregar un segundo sensor PIR para cubrir un área más amplia? ¡Déjanos tu idea en los comentarios!

<button onclick="toggleAnswer()" style="margin-top: 10px; background-color: #007BFF; color: white; padding: 10px; border: none; cursor: pointer; border-radius: 5px; font-weight: bold;">Mostrar Solución</button>

<div id="answer" style="display: none; margin-top: 20px; background-color: #d4edda; border: 1px solid #c3e6cb; padding: 20px; border-radius: 8px; color: #155724; position: relative;">
    <p>Puedes agregar otro sensor PIR en una posición diferente y modificar el código para verificar ambos sensores. Aquí tienes un ejemplo de cómo hacerlo:</p>
    <pre id="solutionCodeContent" style="background-color: #f8f9fa; padding: 10px; border-radius: 5px; border: 1px solid #eee;"><code>
// Añade estas líneas al código existente

const int sensor2 = A1; // Segundo sensor PIR

void setup() {
  pinMode(sensor2, INPUT); // Configura el segundo sensor como entrada
}

void loop() {
  // Si cualquiera de los dos sensores detecta movimiento
  if (estado && (digitalRead(sensor) == HIGH || digitalRead(sensor2) == HIGH)) {
    // El resto del código de detección se mantiene igual
  }
}
</code></pre>
    <button onclick="copySolutionCode()" style="background-color: #007BFF; color: white; padding: 8px 16px; border: none; cursor: pointer; border-radius: 5px; margin-top: 10px; font-weight: bold;">Copiar Código de Solución</button>
</div>

¡Espero que disfrutes creando este proyecto tanto como yo disfruto compartiéndolo contigo! Recuerda que la práctica hace al maestro, así que sigue experimentando y adaptando este código a nuevas ideas. ¡Nos encantaría ver tus creaciones! 🚀

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
