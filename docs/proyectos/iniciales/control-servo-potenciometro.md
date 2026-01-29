# ¡Controla un Servomotor con un Potenciómetro y Arduino! 🕹️

¡Hola, entusiasta de Arduino! Hoy te traigo un proyecto emocionante que combina mecánica y electrónica: **Control de un Servomotor mediante un Potenciómetro**. Usaremos un Arduino Uno para ajustar la posición de un servomotor según la rotación de un potenciómetro. Es un proyecto perfecto para aprender sobre el control de movimiento, y te prometo que lo disfrutarás tanto como yo disfruté creándolo. 😄

![Control de Servomotor con Potenciómetro](../../img/p2-servo-pot.png)

**Control de Servomotor con Potenciómetro y Arduino: Aprende a ajustar la posición de un servomotor usando un potenciómetro con Arduino.**

## Enlace al Proyecto en Tinkercad - Control de Servomotor con Potenciómetro

Si quieres ver este proyecto en acción, visita el siguiente enlace en Tinkercad: [Control de Servomotor con Potenciómetro - Proyecto en Tinkercad](https://www.tinkercad.com/things/4lt8KIwv8Uw-inicial-proyecto2-control-de-un-servo-mediante-potenciometro). Recuerda ajustar los componentes según la configuración indicada para que todo funcione correctamente.

## Componentes Necesarios

Para construir este proyecto, necesitarás los siguientes componentes:

*   1 x Arduino Uno R3
*   1 x Potenciómetro de 250 kΩ
*   1 x Microservomotor Posicional

## Todos los materiales necesarios los encontrarás en los siguientes enlaces:

*   [Kit de componentes Arduino Uno R3 - Incluye Arduino y más](https://amzn.to/4dQTpkX)
*   [Kit de módulos de sensores y servomotores - Compatible con Arduino](https://amzn.to/3yGZIsk)

## Configuración del Circuito

### Diagrama de Conexión

![Diagrama de Conexión](../../img/p2-diagrama-servo.jpg)

### Conexiones:

*   **Potenciómetro:**
    *   Conecta el pin central del potenciómetro al pin analógico A0 de Arduino.
    *   Conecta un extremo del potenciómetro a 5V y el otro a GND.
*   **Servomotor:**
    *   Conecta el cable de señal del servomotor al pin digital 3 de Arduino.
    *   Conecta el cable de alimentación del servomotor a 5V.
    *   Conecta el cable de tierra del servomotor a GND.

## Código para Controlar el Servomotor con Potenciómetro

¡Hora de ensuciarnos las manos con un poco de código! Copia y pega este código en tu Arduino IDE, y prepárate para ver la magia en acción:

<div style="border: 2px solid #007BFF; padding: 20px; background-color: #f0f8ff; position: relative; margin: 20px 0; border-radius: 8px;">
    <button onclick="copyCode()" style="background-color: #007BFF; color: white; padding: 10px 20px; border: none; cursor: pointer; position: absolute; right: 10px; top: 10px; border-radius: 5px; font-weight: bold;">Copiar Código</button>
    <pre id="codeContent" style="margin-top: 40px; overflow-x: auto;"><code>
// Incluimos la librería Servo para controlar el servomotor
#include &lt;Servo.h&gt;

// Creamos un objeto Servo para controlar el servomotor
Servo servo_3;
int potPin = A0; // Pin donde está conectado el potenciómetro
int servoPin = 3; // Pin donde está conectado el servomotor

void setup() {
  pinMode(potPin, INPUT); // Configuramos el pin del potenciómetro como entrada
  Serial.begin(9600); // Iniciamos la comunicación serie a 9600 baudios
  servo_3.attach(servoPin); // Adjuntamos el servomotor al pin 3
}

void loop() {
  int potValue = analogRead(potPin); // Leemos el valor del potenciómetro
  Serial.println(potValue); // Mostramos el valor leído en el Monitor Serie

  int angle = map(potValue, 0, 1023, 0, 180); // Convertimos el valor leído a un ángulo
  servo_3.write(angle); // Movemos el servomotor al ángulo calculado
  delay(10); // Retardo para mejorar el rendimiento de la simulación
}
</code></pre>
</div>

## Explicación del Código

A continuación, explicamos cada línea del código para ayudarte a comprender su funcionamiento y a desarrollar un pensamiento crítico sobre su estructura y lógica:

1.  **#include &lt;Servo.h&gt;:** Esta línea incluye la librería `Servo.h`, que proporciona las funciones necesarias para controlar un servomotor con Arduino. Esta librería es esencial para manipular el servomotor mediante comandos sencillos.
2.  **Servo servo_3;:** Aquí creamos un objeto llamado `servo_3` de tipo `Servo`. Este objeto representará el servomotor que controlaremos en el código, permitiéndonos manejarlo como una entidad con propiedades y métodos.
3.  **int potPin = A0;:** Definimos una variable entera `potPin` que almacena el número del pin de Arduino al que está conectado el potenciómetro. En este caso, usamos el pin A0, que es un pin analógico capaz de leer señales variables.
4.  **int servoPin = 3;:** Esta línea establece el pin digital al que está conectado el servomotor. Aquí, usamos el pin 3.
5.  **void setup() { ... }:** La función `setup()` se ejecuta una sola vez al iniciar el Arduino. Aquí se configuran las entradas y salidas, y se establece la comunicación serial:
    *   `pinMode(potPin, INPUT);` configura el pin `potPin` como una entrada, para que pueda leer valores del potenciómetro.
    *   `Serial.begin(9600);` inicia la comunicación serial a 9600 baudios, lo que permite enviar datos al monitor serie para monitoreo en tiempo real.
    *   `servo_3.attach(servoPin);` vincula el servomotor al pin digital 3 de Arduino.
6.  **void loop() { ... }:** La función `loop()` se ejecuta repetidamente en un bucle infinito. Aquí es donde se realizan las lecturas del sensor y los movimientos del servomotor:
    *   `int potValue = analogRead(potPin);` lee el valor del potenciómetro y lo guarda en la variable `potValue`. Este valor puede variar de 0 (posición mínima) a 1023 (posición máxima).
    *   `Serial.println(potValue);` imprime el valor de `potValue` en el Monitor Serie, permitiendo visualizar los cambios en tiempo real.
    *   `int angle = map(potValue, 0, 1023, 0, 180);` convierte el valor leído del potenciómetro (rango de 0 a 1023) en un ángulo para el servomotor (rango de 0 a 180 grados).
    *   `servo_3.write(angle);` mueve el servomotor al ángulo calculado, controlando su posición de manera precisa.
    *   `delay(10);` introduce una pausa de 10 milisegundos antes de la siguiente iteración del bucle, mejorando el rendimiento de la simulación y evitando lecturas inestables del sensor.

## Problemas Comunes y Soluciones

*   **El servomotor no se mueve:** Verifica que las conexiones sean correctas y que el servomotor esté recibiendo suficiente alimentación. Revisa el pin de control y asegúrate de que esté conectado al pin 3 de Arduino.
*   **El potenciómetro no responde:** Asegúrate de que el potenciómetro esté conectado correctamente y de que el circuito esté funcionando. Revisa las conexiones a 5V, GND, y el pin A0 de Arduino.
*   **El valor del potenciómetro en el monitor serie no cambia:** Puede ser que haya un problema con las conexiones o que el potenciómetro esté defectuoso. Revisa todas las conexiones y prueba con otro potenciómetro si es necesario.

## Desafío para el Usuario

¿Cómo podrías modificar el proyecto para controlar más de un servomotor utilizando un segundo potenciómetro? ¡Déjanos tu idea en los comentarios!

<button onclick="toggleAnswer()" style="margin-top: 10px; background-color: #007BFF; color: white; padding: 10px; border: none; cursor: pointer; border-radius: 5px; font-weight: bold;">Mostrar Solución</button>

<div id="answer" style="display: none; margin-top: 20px; background-color: #d4edda; border: 1px solid #c3e6cb; padding: 20px; border-radius: 8px; color: #155724; position: relative;">
    <p>Puedes declarar otro objeto Servo y un segundo potenciómetro. Luego, duplicarías la lógica en el <code>loop()</code> para controlar cada servo de manera independiente:</p>
    <pre id="solutionCodeContent" style="background-color: #f8f9fa; padding: 10px; border-radius: 5px; border: 1px solid #eee;"><code>
// Añade estas líneas al código existente

Servo servo_4; // Segundo servomotor
int potPin2 = A1; // Segundo potenciómetro
int servoPin2 = 4; // Pin para el segundo servomotor

// En el setup():
servo_4.attach(servoPin2); // Adjuntamos el segundo servomotor al pin 4

// En el loop():
int potValue2 = analogRead(potPin2); // Leer el segundo potenciómetro
int angle2 = map(potValue2, 0, 1023, 0, 180); // Convertir a ángulo
servo_4.write(angle2); // Control del segundo servomotor
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
