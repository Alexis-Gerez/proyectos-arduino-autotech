# 🔢 Control de Display de 7 Segmentos con Arduino 📟

¡Hola, entusiasta de la electrónica! Hoy te traigo un proyecto emocionante que te ayudará a aprender a controlar un **display de 7 segmentos con Arduino**. Usaremos un Arduino Uno para mostrar números del 0 al 9 en un display de 7 segmentos utilizando una conexión multiplexada. Este proyecto es ideal para quienes desean aprender sobre la visualización de números en pantallas y la manipulación de hardware básico. ¡Vamos a comenzar! 😄

![Control de Display de 7 Segmentos](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEglM18ew2kUEypXKKiwZETsVRa3vR4KTpN60me58UAxYSQzzwnXrWadxKfQQmzerQjWoF_mR3kbVgvMq6DpXubcmdpVQcEsXvunseoMQ-gw50_1FzUT6eA7XUHoJv4lAfPQ7GWNxWAWdm4oWBmvUr0g30YmeN_n0P-KH8EFFoZYTqn0WhzeNRsDRsIEO7r5/s1600/p4.png)

**Control de Display de 7 Segmentos con Arduino: Aprende a mostrar números del 0 al 9 utilizando un display de 7 segmentos y Arduino.**

## Enlace al Proyecto en Tinkercad - Display de 7 Segmentos

Explora cómo funciona este proyecto y experimenta con el circuito interactivo en Tinkercad. Haz clic en el siguiente enlace para acceder: [Display de 7 Segmentos - Proyecto en Tinkercad](https://www.tinkercad.com/things/jh3ZNXUBGmb-inicial-proyecto4-display-de-7-segmentos?sharecode=yGoODI94qpqvH8v4-c-dSWQgMJ3Rjv0ELM-WtbdsfGo). Recuerda ajustar la conexión a CÁTODO en el contador de Tinkercad para que funcione correctamente.

## Componentes Necesarios

Para realizar este proyecto, necesitarás los siguientes componentes:

* 1 x Arduino Uno R3
* 1 x Display de 7 Segmentos de 1 dígito (cátodo común)
* 7 x Resistencias de 220 Ω
* Cables y protoboard

## Todos los materiales necesarios los encontrarás en los siguientes enlaces:

* [Kit de Arduino Uno R3 - Incluye Arduino y más](https://amzn.to/4dQTpkX)
* [Kit de módulos de sensores y componentes - Compatible con Arduino](https://amzn.to/3yGZIsk)

## Configuración del Circuito

### Diagrama de Conexión

![Diagrama de Conexión](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEiWsD9X4VkFZoZWJupnVS5UgBtFUJ2MDBF0gZ8O3k__g1e_zFJJoL_Lqv0HGoYeKMxEWXQunDMDv_9wKTgHEVb_JPmW9y6N74UzLQfYYUOxlSgSC7YnaEh9PgoL1r2ZBtwL-9m0v1NWb9ZjISMRv73M91_xxf8okuhvDP8tfTPv-8Hrt_qtElUzJtS4vrHQ/s1600/p4-ArduinoUno-proyecto-programacion-displaydigital.jpg)

### Conexiones:

* **Display de 7 Segmentos:**
    * Conecta los pines del display de 7 segmentos a los pines digitales del Arduino según el esquema siguiente: A - 2, B - 3, C - 4, D - 5, E - 6, F - 7, G - 8.
    * Conecta cada segmento a través de una resistencia de 220 Ω para limitar la corriente y proteger los LEDs.
    * Conecta el cátodo común del display a GND.

## Código para Controlar el Display de 7 Segmentos con Arduino

¡Hora de ensuciarnos las manos con un poco de código! Copia y pega este código en tu Arduino IDE, y prepárate para ver los números aparecer en el display de 7 segmentos:

<div style="border: 2px solid #007BFF; padding: 20px; background-color: #f0f8ff; position: relative; margin: 20px 0; border-radius: 8px;">
    <button onclick="copyCode()" style="background-color: #007BFF; color: white; padding: 10px 20px; border: none; cursor: pointer; position: absolute; right: 10px; top: 10px; border-radius: 5px; font-weight: bold;">Copiar Código</button>
    <pre id="codeContent" style="margin-top: 40px; overflow-x: auto;"><code>
// Declaración de los pines de los segmentos del display
int segA = 2;
int segB = 3;
int segC = 4;
int segD = 5;
int segE = 6;
int segF = 7;
int segG = 8;

void setup() {
  // Configuración de los pines como salidas
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
}

void loop() {
  // Iteramos sobre los números del 0 al 9
  for (int i = 0; i < 10; i++) {
    displayNumber(i); // Mostramos el número actual
    delay(1000); // Espera de 1 segundo entre números
  }
}

void displayNumber(int number) {
  // Encendemos/apagamos segmentos según el número a mostrar
  switch (number) {
    case 0: digitalWrite(segA, HIGH); digitalWrite(segB, HIGH); digitalWrite(segC, HIGH); digitalWrite(segD, HIGH); digitalWrite(segE, HIGH); digitalWrite(segF, HIGH); digitalWrite(segG, LOW); break;
    case 1: digitalWrite(segA, LOW); digitalWrite(segB, HIGH); digitalWrite(segC, HIGH); digitalWrite(segD, LOW); digitalWrite(segE, LOW); digitalWrite(segF, LOW); digitalWrite(segG, LOW); break;
    case 2: digitalWrite(segA, HIGH); digitalWrite(segB, HIGH); digitalWrite(segC, LOW); digitalWrite(segD, HIGH); digitalWrite(segE, HIGH); digitalWrite(segF, LOW); digitalWrite(segG, HIGH); break;
    case 3: digitalWrite(segA, HIGH); digitalWrite(segB, HIGH); digitalWrite(segC, HIGH); digitalWrite(segD, HIGH); digitalWrite(segE, LOW); digitalWrite(segF, LOW); digitalWrite(segG, HIGH); break;
    case 4: digitalWrite(segA, LOW); digitalWrite(segB, HIGH); digitalWrite(segC, HIGH); digitalWrite(segD, LOW); digitalWrite(segE, LOW); digitalWrite(segF, HIGH); digitalWrite(segG, HIGH); break;
    case 5: digitalWrite(segA, HIGH); digitalWrite(segB, LOW); digitalWrite(segC, HIGH); digitalWrite(segD, HIGH); digitalWrite(segE, LOW); digitalWrite(segF, HIGH); digitalWrite(segG, HIGH); break;
    case 6: digitalWrite(segA, HIGH); digitalWrite(segB, LOW); digitalWrite(segC, HIGH); digitalWrite(segD, HIGH); digitalWrite(segE, HIGH); digitalWrite(segF, HIGH); digitalWrite(segG, HIGH); break;
    case 7: digitalWrite(segA, HIGH); digitalWrite(segB, HIGH); digitalWrite(segC, HIGH); digitalWrite(segD, LOW); digitalWrite(segE, LOW); digitalWrite(segF, LOW); digitalWrite(segG, LOW); break;
    case 8: digitalWrite(segA, HIGH); digitalWrite(segB, HIGH); digitalWrite(segC, HIGH); digitalWrite(segD, HIGH); digitalWrite(segE, HIGH); digitalWrite(segF, HIGH); digitalWrite(segG, HIGH); break;
    case 9: digitalWrite(segA, HIGH); digitalWrite(segB, HIGH); digitalWrite(segC, HIGH); digitalWrite(segD, HIGH); digitalWrite(segE, LOW); digitalWrite(segF, HIGH); digitalWrite(segG, HIGH); break;
  }
}
</code></pre>
</div>

## Explicación del Código

A continuación, explicamos cada línea del código para ayudarte a comprender su funcionamiento y a desarrollar un pensamiento crítico sobre su estructura y lógica:

1. **int segA = 2; ... int segG = 8;:** Estas líneas declaran las variables para cada uno de los segmentos del display de 7 segmentos, asignándoles los pines de Arduino que los controlarán.
2. **void setup() { ... }:** La función `setup()` configura los pines de los segmentos como salidas digitales utilizando la función `pinMode()`. Esto es necesario para controlar cada segmento individualmente.
3. **void loop() { ... }:** La función `loop()` se ejecuta repetidamente en un bucle infinito. Utilizamos un bucle `for` para iterar del 0 al 9 y mostrar cada número en el display de 7 segmentos. Después de mostrar cada número, el programa espera un segundo antes de pasar al siguiente número.
4. **void displayNumber(int number) { ... }:** Esta función utiliza una declaración `switch` para establecer el estado de los segmentos del display según el número que se desee mostrar. Para cada número, los segmentos correspondientes se encienden (`HIGH`) o apagan (`LOW`) utilizando la función `digitalWrite()`.

## Problemas Comunes y Soluciones

* **El display no muestra números correctamente:** Verifica que las conexiones de cada segmento al Arduino sean correctas y que el cátodo común esté conectado a GND.
* **Los segmentos del display están demasiado tenues:** Asegúrate de que las resistencias utilizadas sean de 220 Ω. Resistencias de mayor valor pueden causar que los LEDs no se enciendan con suficiente brillo.
* **El número mostrado no cambia:** Verifica que el bucle `for` en el `loop()` esté funcionando correctamente y que el retardo (delay) sea el adecuado.

## Desafío para el Usuario

¿Cómo podrías modificar el proyecto para mostrar números más grandes (como el 10) o para contar hacia atrás? ¡Déjanos tu idea en los comentarios!

<button onclick="toggleAnswer()" style="margin-top: 10px; background-color: #007BFF; color: white; padding: 10px; border: none; cursor: pointer; border-radius: 5px; font-weight: bold;">Mostrar Solución</button>

<div id="answer" style="display: none; margin-top: 20px; background-color: #d4edda; border: 1px solid #c3e6cb; padding: 20px; border-radius: 8px; color: #155724; position: relative;">
    <p>Puedes modificar el código para incluir un segundo display de 7 segmentos. Conecta otro display y utiliza otro conjunto de pines digitales para controlarlo. Aquí tienes un ejemplo de cómo hacer esto:</p>
    <pre id="solutionCodeContent" style="background-color: #f8f9fa; padding: 10px; border-radius: 5px; border: 1px solid #eee;"><code>
// Añade estas líneas al código existente

int segA2 = 9; // Segundo display, segmento A
// ... Define los pines para los otros segmentos del segundo display

void setup() {
  // Configuración de pines para ambos displays
  pinMode(segA2, OUTPUT);
  // Configura el resto de los pines para el segundo display
}

void displayNumber2(int number) {
  // Similar a displayNumber(), pero controla el segundo display
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
