# 🪟 Ventana Automatizada con Fotoresistencia y Arduino 🤖

¡Hola, entusiasta de la tecnología! Hoy te traigo un proyecto innovador que te ayudará a mejorar la eficiencia energética y la comodidad en tu hogar: **Ventana Automatizada**. Utilizaremos un Arduino Uno, un servomotor y una fotoresistencia para abrir o cerrar una ventana automáticamente en función de la cantidad de luz en la habitación. ¡Es una manera genial de poner la tecnología al servicio de tu vida diaria! 😄

![Ventana Automatizada con Arduino](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEg35B7pMlEeIo38G_7e-Wr8IPHmyTbAHQ16Nc6_R6GP18s0Ocy9HzR8FyRIR8_zbLDgCLlg3qG8kUymc0siAl2mv21NDTJyyCo9_t-rGE8Bve2Bz01Ae9nw4Ak79lj2VK-cmJNvwByp2srLvhG2iTSHExvxlJLzSZFIuM24JvOTVNWgZJjcjSg5lVZaBBMx/s1600/p2d.png)

**Automatización de Ventanas con Arduino y Fotoresistencia: Proyecto educativo con Arduino para controlar una ventana según la luz ambiental.**

## Enlace al Proyecto en Tinkercad - Ventana Automatizada

Explora cómo funciona este proyecto y experimenta con el circuito interactivo en Tinkercad. Haz clic en el siguiente enlace para acceder: [Ventana Automatizada - Proyecto en Tinkercad](https://www.tinkercad.com/things/0PtlXJaAZtG-desafio-proyecto2-ventana-automatizada).

## Componentes Necesarios

Para realizar este proyecto, necesitarás los siguientes componentes:

*   1 x Arduino UNO R3
*   1 x Servomotor
*   1 x Fotoresistencia (LDR)
*   1 x Resistencia fija (10K ohm)
*   Cables y protoboard

## Todos los materiales necesarios los encontrarás en los siguientes enlaces:

*   [Kit de Arduino Uno R3 - Incluye todo lo necesario](https://amzn.to/4dQTpkX)
*   [Kit de módulos de sensores y servomotores - Compatible con Arduino](https://amzn.to/3yGZIsk)

## Configuración del Circuito

### Diagrama de Conexión

![Diagrama de Conexión](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEiqE47kpUexTP5qn-xBd0HV7X5CNUMynSj_9YUqiJl-jAeEbk9GT1L5BWBHS2YOqOMEF1FyYdIFEpPiea4pUM7wzXvOv7FbmJwDuODqkHGCCsXHTSvdrr24HV1rd2ecxX7_kbupHv0VXCg2VCeggBFYxOQ84r_ci-zMTCkDLw7rcywjm9VHyjzYxCftb7EQ/s1600/Diagrama%20de%20conexiones.jpg)

### Conexiones:

*   **Fotoresistencia:**
    *   Conecta un terminal de la fotoresistencia a 5V.
    *   Conecta el otro terminal de la fotoresistencia a un terminal de la resistencia fija de 10K ohm.
    *   Conecta el otro terminal de la resistencia fija a GND.
    *   Conecta el punto medio (entre la fotoresistencia y la resistencia fija) al pin A0 de Arduino.
*   **Servomotor:**
    *   Conecta el cable de señal del servomotor al pin digital 3 de Arduino.
    *   Conecta el cable de alimentación del servomotor a 5V.
    *   Conecta el cable de tierra del servomotor a GND.

## Código para Control de Ventanas con Fotoresistencia

¡Aquí tienes el código completo! Puedes copiarlo fácilmente haciendo clic en el botón "Copiar Código".

<div style="border: 2px solid #007BFF; padding: 20px; background-color: #f0f8ff; position: relative; margin: 20px 0; border-radius: 8px;">
    <button onclick="copyCode()" style="background-color: #007BFF; color: white; padding: 10px 20px; border: none; cursor: pointer; position: absolute; right: 10px; top: 10px; border-radius: 5px; font-weight: bold;">Copiar Código</button>
    <pre id="codeContent" style="margin-top: 40px; overflow-x: auto;"><code>
// Incluimos la librería Servo para controlar el servomotor
#include &lt;Servo.h&gt;

// Creamos un objeto Servo para controlar el servomotor
Servo servo_3;
int lightSensorPin = A0; // Pin donde está conectada la fotoresistencia
int threshold = 500; // Umbral para la luz (ajustar según sea necesario)

void setup() {
  pinMode(lightSensorPin, INPUT); // Configuramos el pin del sensor de luz como entrada
  Serial.begin(9600); // Iniciamos la comunicación serie a 9600 baudios
  servo_3.attach(3, 500, 2500); // Adjuntamos el servomotor al pin 3 con un rango de pulsos
}

void loop() {
  int lightLevel = analogRead(lightSensorPin); // Leemos el nivel de luz del sensor
  Serial.println(lightLevel); // Mostramos el nivel de luz en el Monitor Serie

  if (lightLevel < threshold) {
    // Oscuridad - Cerrar la ventana
    servo_3.write(180);
  } else {
    // Luz - Abrir la ventana
    servo_3.write(0);
  }
  delay(10); // Retardo para mejorar el rendimiento de la simulación
}
</code></pre>
</div>

## Explicación del Código

A continuación, explicamos cada línea del código para ayudarte a comprender su funcionamiento y a desarrollar un pensamiento crítico sobre su estructura y lógica:

1.  **#include &lt;Servo.h&gt;:** Esta línea incluye la librería `Servo.h`, que proporciona las funciones necesarias para controlar un servomotor con Arduino. Esta librería es esencial para manipular el servomotor mediante comandos sencillos.
2.  **Servo servo_3;:** Aquí creamos un objeto llamado `servo_3` de tipo `Servo`. Este objeto representará el servomotor que controlaremos en el código, permitiéndonos manejarlo como una entidad con propiedades y métodos.
3.  **int lightSensorPin = A0;:** Definimos una variable entera `lightSensorPin` que almacena el número del pin de Arduino al que está conectada la fotoresistencia. En este caso, usamos el pin A0, que es un pin analógico capaz de leer señales variables.
4.  **int threshold = 500;:** Esta línea establece el umbral de luz con el que el sistema decidirá si abrir o cerrar la ventana. Si el nivel de luz es menor que 500, consideramos que es "oscuro" y el servomotor cerrará la ventana.
5.  **void setup() { ... }:** La función `setup()` se ejecuta una sola vez al iniciar el Arduino. Aquí se configuran las entradas y salidas, y se establece la comunicación serial:
    *   `pinMode(lightSensorPin, INPUT);` configura el pin `lightSensorPin` como una entrada, para que pueda leer valores de la fotoresistencia.
    *   `Serial.begin(9600);` inicia la comunicación serial a 9600 baudios, lo que permite enviar datos al monitor serie para monitoreo en tiempo real.
    *   `servo_3.attach(3, 500, 2500);` vincula el servomotor al pin digital 3 de Arduino, con un rango de pulso específico que determina su movimiento.
6.  **void loop() { ... }:** La función `loop()` se ejecuta repetidamente en un bucle infinito. Aquí es donde se realizan las lecturas del sensor y los movimientos del servomotor:
    *   `int lightLevel = analogRead(lightSensorPin);` lee el nivel de luz de la fotoresistencia y lo guarda en la variable `lightLevel`. Este valor puede variar de 0 (oscuridad total) a 1023 (luz máxima).
    *   `Serial.println(lightLevel);` imprime el valor de `lightLevel` en el Monitor Serie, permitiendo visualizar los cambios de luz en tiempo real.
    *   `if (lightLevel < threshold) { ... }` verifica si el nivel de luz es inferior al umbral (`threshold`). Si es así, el código dentro del bloque se ejecuta:
        *   `servo_3.write(180);` mueve el servomotor a 180 grados, cerrando la ventana porque se considera "oscuro".
    *   `else { ... }` Si el nivel de luz es igual o superior al umbral, se ejecuta el bloque de código en `else`:
        *   `servo_3.write(0);` mueve el servomotor a 0 grados, abriendo la ventana porque se considera "luz".
    *   `delay(10);` introduce una pausa de 10 milisegundos antes de la siguiente iteración del bucle, mejorando el rendimiento de la simulación y evitando lecturas inestables del sensor.

## Problemas Comunes y Soluciones

*   **El servomotor no se mueve:** Verifica que las conexiones sean correctas y que el servomotor esté recibiendo suficiente alimentación. Revisa el pin de control y asegúrate de que esté conectado al pin 3 de Arduino.
*   **El sensor de luz no responde:** Asegúrate de que la fotoresistencia esté conectada correctamente y de que el divisor de voltaje esté funcionando. Revisa las conexiones a 5V, GND, y el pin A0 de Arduino.
*   **El valor de luz en el monitor serie no cambia:** Puede ser que el umbral esté configurado incorrectamente. Ajusta el valor del umbral (`threshold`) para adaptarlo a las condiciones de luz de tu entorno.

## Desafío para el Usuario

¿Cómo podrías modificar el proyecto para incluir un segundo servomotor que controle otra ventana al mismo tiempo, pero con un umbral de luz diferente? ¡Déjanos tu idea en los comentarios!

<button onclick="toggleAnswer()" style="margin-top: 10px; background-color: #007BFF; color: white; padding: 10px; border: none; cursor: pointer; border-radius: 5px; font-weight: bold;">Mostrar Solución</button>

<div id="answer" style="display: none; margin-top: 20px; background-color: #d4edda; border: 1px solid #c3e6cb; padding: 20px; border-radius: 8px; color: #155724; position: relative;">
    <p>Podrías declarar otro objeto Servo y un nuevo umbral para el segundo servomotor. Luego, duplicarías la lógica en el <code>loop()</code> para controlar cada servo de manera independiente:</p>
    <pre id="solutionCodeContent" style="background-color: #f8f9fa; padding: 10px; border-radius: 5px; border: 1px solid #eee;"><code>
// Añade estas líneas al código existente

Servo servo_4; // Segundo servomotor
int threshold2 = 700; // Umbral diferente para el segundo servomotor

// En el setup():
servo_4.attach(4, 500, 2500); // Adjuntamos el segundo servomotor al pin 4

// En el loop():
if (lightLevel < threshold2) {
  servo_4.write(180); // Control del segundo servomotor
} else {
  servo_4.write(0);
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
