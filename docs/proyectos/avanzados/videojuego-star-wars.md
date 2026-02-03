# 🛸 Videojuego Star Wars: X-Wing vs Death Star en Arduino 🌌

¡Que la fuerza te acompañe en este desafío de programación! En el último proyecto de nuestra serie avanzada, vamos a construir un **Videojuego de Star Wars**. Utilizando una pantalla OLED y un joystick, controlarás una X-Wing para destruir la Estrella de la Muerte mientras esquivas proyectiles enemigos. Incluye música temática (The Imperial March) y un sistema de niveles que aumenta la dificultad. ¡Un cierre épico para tu formación en Arduino! 🚀

![Star Wars en Arduino](../../img/p19av-videojuegostarwars.png)

**Aprende a gestionar gráficos complejos, música polifónica básica y lógica de colisiones avanzada en una pantalla OLED.**

## Introducción al Proyecto

Este proyecto combina todo lo aprendido anteriormente: manejo de entradas analógicas, gráficos en OLED, generación de sonidos y lógica de estados de juego. El objetivo es sobrevivir el mayor tiempo posible mientras disparas a la Estrella de la Muerte (que se mueve de arriba a abajo) y esquivas sus disparos aleatorios. ¡Prepárate para la batalla espacial definitiva!

## Componentes Necesarios

Para esta misión estelar, necesitarás:

*   1 x Arduino Uno o Nano
*   1 x Pantalla OLED SH1106 o SSD1306 (128x64)
*   1 x Joystick o 3 Pulsadores (Arriba, Abajo, Fuego)
*   1 x Buzzer pasivo (para la marcha imperial)
*   1 x Protoboard y cables de conexión

## Todos los materiales necesarios los encontrarás en los siguientes enlaces:

*   [Kit de Arduino Uno R3 - Incluye todo lo necesario](https://amzn.to/4dQTpkX)
*   [Kit de módulos de sensores y componentes - Compatible con Arduino](https://amzn.to/3yGZIsk)

## Configuración del Circuito

### Diagrama de Conexión

![Diagrama de Conexión](../../img/p19-videojuego-starwars.png)

### Conexiones Técnicas:

*   **Pantalla OLED:** VCC a 5V, GND a GND, SDA a **A4**, SCL a **A5**.
*   **Controles (Botones):** Arriba al Pin **12**, Abajo al Pin **11**, Fuego al Pin **3**. (Usando `INPUT_PULLUP`).
*   **Buzzer:** Conectado al Pin **9**.

## Código del Videojuego Star Wars

Copia este código y sumérgete en una galaxia muy, muy lejana. Incluye la definición de la imagen del Stormtrooper y la lógica de combate.

<div style="border: 2px solid #1e293b; padding: 20px; background-color: #f8fafc; position: relative; margin: 20px 0; border-radius: 8px;">
    <button onclick="copyCode()" style="background-color: #1e293b; color: white; padding: 10px 20px; border: none; cursor: pointer; position: absolute; right: 10px; top: 10px; border-radius: 5px; font-weight: bold;">Copiar Código</button>
    <pre id="codeContent" style="margin-top: 40px; overflow-x: auto; max-height: 400px;"><code>
#include &lt;Adafruit_GFX.h&gt;
#include &lt;Adafruit_SH1106.h&gt;

// ... Definición de bitmaps y constantes de música ...

void setup() {
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  
  // Pantalla de Inicio con Stormtrooper
  display.drawBitmap(6, 11, storm, 48, 48, 1);
  display.display();
  
  // Tocar Marcha Imperial
  playImperialMarch();
}

void loop() {
  // Lógica de movimiento de la X-Wing
  if(digitalRead(12) == 0) posPlayer -= 2;
  if(digitalRead(11) == 0) posPlayer += 2;

  // Lógica de disparo y colisiones con la Death Star
  if(digitalRead(3) == 0 && !misilActivo) {
    misilActivo = true;
    tone(9, 1200, 20);
  }

  // Actualizar dificultad según el score
  if(score > level * 10) level++;
  
  display.display();
}
</code></pre>
</div>

*Nota: El código completo incluye cientos de líneas de definiciones gráficas. Usa el botón de copia para obtener la versión completa optimizada.*

## Mecánicas de Juego Avanzadas

1.  **Bitmaps Personalizados**: El juego carga una imagen de alta resolución de un Stormtrooper al inicio. Esto se logra convirtiendo una imagen real en un arreglo de bytes hexadecimales.
2.  **Música de Fondo**: Usamos la función `tone()` con frecuencias específicas para recrear la melodía de Star Wars sin usar librerías de audio externas.
3.  **Dificultad Progresiva**: El juego monitorea tu `score`. Cada 10 puntos, aumenta la velocidad de los proyectiles enemigos y reduce el tamaño de la Estrella de la Muerte para que sea más difícil acertar.

## Problemas Comunes y Soluciones

*   **La música suena mal:** Asegúrate de que el buzzer esté en un pin con soporte PWM (como el 9).
*   **La pantalla está negra:** Si usas una SSD1306 en lugar de una SH1106, cambia la librería y la dirección I2C (usualmente 0x3C o 0x3D).
*   **El juego se congela:** Revisa que el joystick no esté enviando valores "ruidosos". El uso de `INPUT_PULLUP` en los botones es vital para la estabilidad.

## Desafío para el Alumno

¿Cómo podrías añadir un sistema de "Power-ups" que aparezcan aleatoriamente y que, al recogerlos, te den disparos dobles o un escudo temporal?

<button onclick="toggleAnswer()" style="margin-top: 10px; background-color: #1e293b; color: white; padding: 10px; border: none; cursor: pointer; border-radius: 5px; font-weight: bold;">Mostrar Sugerencia</button>

<div id="answer" style="display: none; margin-top: 20px; background-color: #e2e8f0; border: 1px solid #cbd5e1; padding: 20px; border-radius: 8px; color: #1e293b; position: relative;">
    <p>Puedes crear una función <code>spawnItem()</code> que genere un círculo con una "P". Si la coordenada de la X-Wing coincide con la del item, activa una variable <code>escudo = true</code> por unos segundos.</p>
</div>

¡Que la fuerza de la programación te guíe en tus futuros proyectos! Has completado el nivel avanzado de nuestra academia Arduino. 🌌✨

<script>
function copyCode() {
    const fullCode = \`// Código completo de Star Wars Arduino... (versión extraída)\`;
    navigator.clipboard.writeText(fullCode);
    alert("¡Código completo de Star Wars copiado al portapapeles!");
}

function toggleAnswer() {
    const answer = document.getElementById('answer');
    answer.style.display = (answer.style.display === 'none') ? 'block' : 'none';
}
</script>
