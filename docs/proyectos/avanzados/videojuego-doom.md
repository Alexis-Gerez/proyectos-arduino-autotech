# 💣 Videojuego Doom en Arduino Nano con Pantalla OLED 👾

¡Lleva el motor de raycasting más famoso de la historia a tu placa Arduino! En este proyecto de nivel ultra-avanzado, aprenderás a ejecutar una versión compacta del legendario **Doom** utilizando una pantalla OLED SSD1306. Exploraremos cómo recrear un entorno 3D, gestionar enemigos y renderizar gráficos retro en un hardware limitado. ¡Un verdadero desafío de ingeniería de software! 🚀

![Doom en Arduino](../../img/p18av-juegodoom.png)

**Domina el raycasting, la optimización de memoria y la renderización en tiempo real con este proyecto inspirado en el clásico Doom.**

## Introducción al Proyecto

¿Es posible jugar Doom en un Arduino Nano? ¡La respuesta es sí! Este proyecto utiliza un motor de renderización llamado "Raycasting" (el mismo que wolfenstein 3D) para crear la ilusión de profundidad en una pantalla de solo 128x64 píxeles. Aprenderás sobre matemáticas aplicadas a gráficos, gestión de memoria flash y comunicación I2C de alta velocidad.

## Componentes Necesarios

Para este reto técnico, necesitarás:

*   1 x Arduino Nano (recomendado por su tamaño) o Uno
*   1 x Pantalla OLED SSD1306 (128x64 píxeles) con I2C
*   5 x Pulsadores (Botones)
*   1 x Buzzer pasivo
*   1 x Protoboard y cables de conexión

## Todos los materiales necesarios los encontrarás en los siguientes enlaces:

*   [Kit de Arduino Uno R3 - Incluye todo lo necesario](https://amzn.to/4dQTpkX)
*   [Kit de módulos de sensores y componentes - Compatible con Arduino](https://amzn.to/3yGZIsk)

## Configuración del Circuito

### Diagrama de Conexión

![Diagrama de Conexión](../../img/p18-videojuego-doom.png)

### Conexiones de Control:

*   **Pantalla OLED:** SDA al Pin **A4**, SCL al Pin **A5**.
*   **Botones (Input):** Configurados en modo `INPUT_PULLUP` para controlar Arriba, Abajo, Izquierda, Derecha y Fuego.
*   **Buzzer:** Conectado al pin digital para efectos de sonido.

## Código del Motor Doom Nano

Debido a que este proyecto utiliza múltiples archivos de cabecera (.h) para los niveles y sprites, aquí presentamos el núcleo del sistema de renderización.

<div style="border: 2px solid #007BFF; padding: 20px; background-color: #f0f8ff; position: relative; margin: 20px 0; border-radius: 8px;">
    <button onclick="copyCode()" style="background-color: #007BFF; color: white; padding: 10px 20px; border: none; cursor: pointer; position: absolute; right: 10px; top: 10px; border-radius: 5px; font-weight: bold;">Copiar Núcleo del Código</button>
    <pre id="codeContent" style="margin-top: 40px; overflow-x: auto;"><code>
#include "constants.h"
#include "display.h"

// Variables globales del jugador
Player player;
Entity entity[MAX_ENTITIES];

void setup(void) {
  setupDisplay(); // Inicializa OLED
  input_setup();  // Configura botones
  sound_init();   // Sonidos iniciales
}

void loop() {
  // 1. Procesar Entradas (Movimiento)
  processInput();

  // 2. Motor de Raycasting (3D)
  renderMap();

  // 3. Dibujar Enemigos y Objetos
  renderEntities();

  // 4. Actualizar Interfaz (HUD)
  updateHud();

  display.display(); // Enviar a la pantalla
}

// Ejemplo de función de Raycasting simplificada
void renderMap() {
  for (int x = 0; x < SCREEN_WIDTH; x++) {
    // Calcula la dirección del rayo
    // Busca colisiones con paredes en el mapa
    // Calcula la altura de la pared según la distancia
    // Dibuja la línea vertical en la OLED
  }
}
</code></pre>
</div>

*Nota: Para que el juego funcione, debes descargar el repositorio completo de Doom Nano e incluir todos los archivos `.h` y `.cpp` en la misma carpeta que tu sketch.*

## Conceptos Avanzados de este Proyecto

1.  **Raycasting**: Es la técnica de proyectar rayos desde la posición del jugador para "sentir" las paredes. Cuanto más tarda el rayo en chocar, más lejos está la pared y más pequeña se dibuja.
2.  **Optimización de Memoria**: Arduino Nano tiene muy poca memoria RAM. El juego almacena los niveles y sprites en la memoria `PROGMEM` (Memoria Flash) para dejar la RAM libre para el motor de juego.
3.  **Búfer de Pantalla**: Se utiliza un búfer de memoria para dibujar todo el "cuadro" antes de enviarlo a la OLED, evitando que la imagen parpadee.

## Problemas Comunes y Soluciones

*   **Error "Out of Memory":** Asegúrate de no añadir demasiados niveles o enemigos nuevos si estás al límite de la capacidad del Nano.
*   **La pantalla se ve lenta:** El motor usa cálculos matemáticos intensos. Asegúrate de que la velocidad del bus I2C sea de 400kHz (`Wire.setClock(400000)`).
*   **Los botones no responden:** Verifica que uses resistencias Pull-Up o que los configures por código como `INPUT_PULLUP`.

## Desafío para el Alumno

El juego básico solo tiene un tipo de enemigo. ¿Podrías modificar el archivo `sprites.h` para añadir un nuevo enemigo con un patrón de ataque diferente o más puntos de vida?

<button onclick="toggleAnswer()" style="margin-top: 10px; background-color: #007BFF; color: white; padding: 10px; border: none; cursor: pointer; border-radius: 5px; font-weight: bold;">Mostrar Pista de Solución</button>

<div id="answer" style="display: none; margin-top: 20px; background-color: #d4edda; border: 1px solid #c3e6cb; padding: 20px; border-radius: 8px; color: #155724; position: relative;">
    <p>Debes definir nuevos mapas de bits (bytes) para el sprite del enemigo y agregarlo a la función <code>spawnEntity</code> en el código principal, asignándole un nuevo tipo de entidad.</p>
</div>

¡Que comience la acción! Haz historia programando el juego más icónico en tu Arduino. ¡A jugar! 🚀

<script>
function copyCode() {
    const codeContent = document.getElementById('codeContent').innerText;
    navigator.clipboard.writeText(codeContent);
    alert("¡Núcleo del código copiado!");
}

function toggleAnswer() {
    const answer = document.getElementById('answer');
    answer.style.display = (answer.style.display === 'none') ? 'block' : 'none';
}
</script>
