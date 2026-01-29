# 🚨 Luces de Emergencia con Arduino 💡

¡Hola, entusiasta de la tecnología! Hoy te traigo un proyecto emocionante que te ayudará a crear un sistema de señalización simple usando Arduino, LEDs y un pulsador: **Señal de Advertencia con LEDs**. Este proyecto es perfecto para aprender sobre la programación de microcontroladores y la manipulación de hardware básico. ¡Es una manera genial de ver cómo el código interactúa con el mundo físico! 😄

![Señal de Advertencia con LEDs y Arduino](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEijfLPS_jaKyIX4jSRXU7FEmcATH8AyYXKDLeWi7LXq7pY3lid9Y9OLAeFiGkzoVr0uV6sjiqa3AdLua0OaRAGciLQp4HXKso8UCf2LI-Tw73ZtAPZCb6iU38VzLJeT1mxbTxLsoQjJKuKLJixKTCV96u1nPlhEendHWMjWoJwyLyFRgLgjZ2aO1eZ1DQ_Q/s1600/p1.png)

**Aprende a crear un sistema de señalización con LEDs y un pulsador utilizando Arduino.**

## Enlace al Proyecto en Tinkercad - Señal de Advertencia

Explora cómo funciona este proyecto y experimenta con el circuito interactivo en Tinkercad. Haz clic en el siguiente enlace para acceder: [Señal de Advertencia - Proyecto en Tinkercad](https://www.tinkercad.com/things/8TGPeUxToWX-inicial-proyecto1-senal-de-advertencia).

## Componentes Necesarios

Para realizar este proyecto, necesitarás los siguientes componentes:

*   1 x Arduino UNO
*   1 x LED Verde
*   2 x LEDs Rojos
*   1 x Pulsador
*   3 x Resistencias de 220 Ω
*   1 x Resistencia de 10 kΩ
*   Cables y protoboard

## Todos los materiales necesarios los encontrarás en los siguientes enlaces:

*   [Kit de Arduino Uno R3 - Incluye todo lo necesario](https://amzn.to/4dQTpkX)
*   [Kit de módulos de sensores y componentes - Compatible con Arduino](https://amzn.to/3yGZIsk)

## Configuración del Circuito

### Diagrama de Conexión

![Diagrama de Conexión](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEgik_h0nhfMcd_F16qqDgDj7iDK6DPnci-wzkmzl3NXgcYwM2ZgFHQ8Mt0FewU0gvaQ-pLbM-rcDNhLJRdeHFRFUx0UWo4w3EHtR4pbZEB4LD1ScFEwq1Yxn8CGosFB_aaNLjrb_0kTCMQX7fmqWXuMCd6fi9yFJYRVUjq9brH7K-dHgrFxt-ZgYYaa2tgf/s1600/p1-ArduinoUno-proyecto-programacion-se%C3%B1aldeadvertencia.jpg)

### Conexiones:

*   **LEDs:**
    *   Conecta el cátodo del LED verde al pin 3 de Arduino.
    *   Conecta el cátodo de un LED rojo al pin 4 de Arduino y el otro LED rojo al pin 5.
    *   Conecta los ánodos de los LEDs a resistencias de 220 Ω y luego a GND.
*   **Pulsador:**
    *   Conecta un terminal del pulsador al pin digital 2 de Arduino.
    *   Conecta el otro terminal del pulsador a GND a través de una resistencia de 10 kΩ.
    *   Conecta el punto común entre la resistencia y el pulsador a 5V.

## Código para Controlar la Señal de Advertencia con LEDs

¡Aquí tienes el código completo! Puedes copiarlo fácilmente haciendo clic en el botón "Copiar Código".

<div style="border: 2px solid #007BFF; padding: 20px; background-color: #f0f8ff; position: relative; margin: 20px 0; border-radius: 8px;">
    <button onclick="copyCode()" style="background-color: #007BFF; color: white; padding: 10px 20px; border: none; cursor: pointer; position: absolute; right: 10px; top: 10px; border-radius: 5px; font-weight: bold;">Copiar Código</button>
    <pre id="codeContent" style="margin-top: 40px; overflow-x: auto;"><code>
// Declaramos la variable para almacenar el estado del pulsador
int switchState = 0;

void setup() {
  pinMode(3, OUTPUT); // LED verde
  pinMode(4, OUTPUT); // LED rojo del medio
  pinMode(5, OUTPUT); // LED rojo de la derecha
  pinMode(2, INPUT);  // Pulsador
}

void loop() {
  switchState = digitalRead(2); // Leer el estado del pulsador

  if (switchState == LOW) { 
    // El pulsador no está presionado
    digitalWrite(3, HIGH); // Encender LED verde
    digitalWrite(4, LOW);  // Apagar LED rojo del medio
    digitalWrite(5, LOW);  // Apagar LED rojo de la derecha
  } else { 
    // El pulsador está presionado
    digitalWrite(3, LOW);  // Apagar LED verde
    digitalWrite(4, HIGH); // Encender LED rojo del medio
    digitalWrite(5, LOW);  // Apagar LED rojo de la derecha
    delay(250);            // Pausa de un cuarto de segundo
    digitalWrite(4, LOW);  // Apagar LED rojo del medio
    digitalWrite(5, HIGH); // Encender LED rojo de la derecha
    delay(250);            // Pausa de un cuarto de segundo
  }
}
</code></pre>
</div>

## Explicación del Código

A continuación, explicamos cada línea del código para ayudarte a comprender su funcionamiento y a desarrollar un pensamiento crítico sobre su estructura y lógica:

1.  **int switchState = 0;**: Declara una variable llamada `switchState` para almacenar el estado del pulsador. Inicialmente, se le asigna el valor 0, lo que indica que el pulsador no está presionado. Esta variable nos permite "recordar" qué está pasando en el hardware.
2.  **pinMode(pin, mode)**: Esta función configura los pines como entradas o salidas en la función `setup()`. Los pines 3, 4 y 5 están configurados como salidas para enviar energía a los LEDs, mientras que el pin 2 está configurado como entrada para recibir la señal del pulsador.
3.  **digitalRead(2)**: Esta función lee el estado eléctrico del pin 2. En nuestro circuito, nos dirá si el pulsador está enviando corriente o no.
4.  **Estructura condicional if/else**: Es el "corazón" de la lógica. Verifica si `switchState` es `LOW`. Si se cumple, ejecuta la parte tranquila (LED verde); de lo contrario, ejecuta la parte de advertencia (LEDs rojos parpadeando).
5.  **digitalWrite(pin, value)**: Controla el flujo de energía. `HIGH` para encender y `LOW` para apagar. Así creamos la secuencia visual.
6.  **delay(250)**: Introduce una pausa necesaria de 250 milisegundos para que el ojo humano pueda percibir el cambio de un LED a otro, creando el efecto de parpadeo de emergencia.

## Problemas Comunes y Soluciones

*   **Los LEDs no se encienden:** Verifica que las conexiones sean correctas y que los LEDs estén conectados en la polaridad correcta (pata larga a positivo).
*   **El pulsador no responde:** Asegúrate de que la resistencia de 10 kΩ (pull-down) esté bien conectada para evitar señales falsas ("ruido").
*   **El parpadeo es muy rápido:** Puedes aumentar el valor del `delay()` a 500 para un parpadeo más pausado.

## Desafío para el Usuario

¿Cómo podrías modificar el proyecto para que los LEDs parpadeen de manera más rápida o más lenta según cuánto tiempo lleves presionando el botón? ¡Déjanos tu idea en los comentarios!

<button onclick="toggleAnswer()" style="margin-top: 10px; background-color: #007BFF; color: white; padding: 10px; border: none; cursor: pointer; border-radius: 5px; font-weight: bold;">Mostrar Solución</button>

<div id="answer" style="display: none; margin-top: 20px; background-color: #d4edda; border: 1px solid #c3e6cb; padding: 20px; border-radius: 8px; color: #155724; position: relative;">
    <p>Podrías usar la función <code>millis()</code> para medir el tiempo que el pulsador está presionado y ajustar el tiempo de <code>delay()</code> dinámicamente:</p>
    <pre id="solutionCodeContent" style="background-color: #f8f9fa; padding: 10px; border-radius: 5px; border: 1px solid #eee;"><code>
// Ejemplo conceptual
unsigned long pressTime = millis();
// ... lógica de temporización ...
if (pressDuration < 1000) {
  delay(100); // Rápido
} else {
  delay(500); // Lento
}
</code></pre>
    <button onclick="copySolutionCode()" style="background-color: #007BFF; color: white; padding: 8px 16px; border: none; cursor: pointer; border-radius: 5px; margin-top: 10px; font-weight: bold;">Copiar Código de Solución</button>
</div>

¡Espero que disfrutes creando este proyecto tanto como yo disfruto compartiéndolo contigo! Recuerda que la práctica hace al maestro. ¡Nos encantaría ver tus creaciones! 🚀

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
