# 🎵 Caja Musical Controlada por Luz con Arduino 🎶

¡Hola, amante de la música y la tecnología! Hoy vamos a crear un proyecto emocionante que te permitirá explorar el mundo de los sensores y la generación de sonidos con Arduino: **Caja Musical Controlada por Luz con Arduino**. Este proyecto es perfecto para aprender cómo usar un fotoresistor para detectar luz y un buzzer para generar diferentes tonos. ¡Vamos a sumergirnos en la magia de la música electrónica! 🎼🌞

![Caja Musical Controlada por Luz](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEi53DXY5ihQ8KIXvDzVPMGu25zmmmz_M9qDtOR0KTWxt8oYgYhbuGLgoXZr9KPvbeZtTNh9kTsL4XxsRi1m-FpEwo1pGjaRfXJGANujNg5AHwbh9HbZdMEl4grn6d_g8cRE3ZZoU8uPF3jyfz0WwrGm-Q1COUoqJJTEZZxTiEZ44ryAW7HdC4Ph-9HZl2Kp/s1600/p7-cajamusical.png)

**Caja Musical Controlada por Luz con Arduino: Aprende a crear una caja musical interactiva utilizando un fotoresistor y un buzzer.**

## Enlace al Proyecto en Tinkercad - Caja Musical

Explora cómo funciona este proyecto y experimenta con el circuito interactivo en Tinkercad. Haz clic en el siguiente enlace para acceder: [Caja Musical - Proyecto en Tinkercad](https://www.tinkercad.com/things/llEivh1TEnx-proyecto-inicial-caja-musical-controlada-por-luz).

## Componentes Necesarios

Para realizar este proyecto, necesitarás los siguientes componentes:

*   1 x Arduino UNO
*   1 x Fotoresistor (LDR)
*   1 x Buzzer Piezoeléctrico
*   1 x Resistencia de 10 kΩ
*   Cables de Conexión
*   Protoboard

## Todos los materiales necesarios los encontrarás en los siguientes enlaces:

*   [Kit de Arduino Uno R3 - Incluye todo lo necesario](https://amzn.to/4dQTpkX)
*   [Kit de módulos de sensores y componentes - Compatible con Arduino](https://amzn.to/3yGZIsk)

## Configuración del Circuito

### Diagrama de Conexión

![Diagrama de Conexión](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEjwym1mDJ_FSkQNVGF9KlTk65sSVVtM2zvtoucvp1Z7a8UYWok-Mug08W5JYA-zRBQkYgGZMJHtuDy959IxKDgTBnG8hDbvMbdm-hVdO51Th1VAVXsbi7MAZWikyTHbDaHVipqBtmLbLQ-TyFznS7PxvhiEdFfJk_P_offhVZngLxI5go5Ya9FBL2Y5K9Vx/s1600/p7-ArduinoUno-proyecto-programacion-cajamusicalconldrypiezo.jpg)

### Conexiones:

*   **Fotoresistor (LDR):**
    *   Conecta un terminal del LDR a 5V de Arduino.
    *   Conecta el otro terminal del LDR a A0 de Arduino y al mismo tiempo a un extremo de la resistencia de 10 kΩ.
    *   Conecta el otro extremo de la resistencia de 10 kΩ a GND de Arduino.
*   **Buzzer:**
    *   Conecta el pin positivo (+) del buzzer al pin 8 de Arduino.
    *   Conecta el pin negativo (-) del buzzer a GND de Arduino.

## Código para Controlar la Caja Musical con Luz

¡Aquí tienes el código completo! Puedes copiarlo fácilmente haciendo clic en el botón "Copiar Código".

<div style="border: 2px solid #007BFF; padding: 20px; background-color: #f0f8ff; position: relative; margin: 20px 0; border-radius: 8px;">
    <button onclick="copyCode()" style="background-color: #007BFF; color: white; padding: 10px 20px; border: none; cursor: pointer; position: absolute; right: 10px; top: 10px; border-radius: 5px; font-weight: bold;">Copiar Código</button>
    <pre id="codeContent" style="margin-top: 40px; overflow-x: auto;"><code>
// Definición de pines
const int ldrPin = A0;  // Pin del fotoresistor
const int buzzerPin = 8;  // Pin del buzzer

// Variables
int ldrValue = 0;  // Valor leído del fotoresistor
int toneFrequency = 0;  // Frecuencia del tono que se reproducirá

void setup() {
  pinMode(ldrPin, INPUT);  // Configuración del pin del fotoresistor como entrada
  pinMode(buzzerPin, OUTPUT);  // Configuración del pin del buzzer como salida
  Serial.begin(9600);  // Iniciar la comunicación serie para la depuración
}

void loop() {
  ldrValue = analogRead(ldrPin);  // Leer el valor del fotoresistor
  
  // Mostrar el valor del fotoresistor en el monitor serie
  Serial.print("Nivel de Luz: ");
  Serial.println(ldrValue);

  // Calcular la frecuencia del tono basado en el nivel de luz
  if (ldrValue < 300) {  // Luz baja
    toneFrequency = 262;  // Nota C4 (Do)
    Serial.println("Reproduciendo: Do (C4)");
  } else if (ldrValue >= 300 && ldrValue < 600) {  // Luz media
    toneFrequency = 330;  // Nota E4 (Mi)
    Serial.println("Reproduciendo: Mi (E4)");
  } else {  // Luz alta
    toneFrequency = 392;  // Nota G4 (Sol)
    Serial.println("Reproduciendo: Sol (G4)");
  }

  // Reproducir el tono correspondiente en el buzzer
  tone(buzzerPin, toneFrequency);
  delay(500);  // Duración del tono
  noTone(buzzerPin);  // Apagar el buzzer
  delay(500);  // Pausa entre tonos

  delay(1000);  // Espera 1 segundo antes de la siguiente lectura
}
</code></pre>
</div>

## Explicación del Código

A continuación, explicamos cada línea del código para ayudarte a comprender su funcionamiento y a desarrollar un pensamiento crítico sobre su estructura y lógica:

1.  **const int ldrPin = A0;:** Definimos el pin A0 para leer el valor del fotoresistor (LDR).
2.  **const int buzzerPin = 8;:** Configuramos el pin 8 para conectar el buzzer piezoeléctrico, que generará los tonos.
3.  **analogRead(pin):** Esta función lee el valor analógico del LDR, que cambia según la cantidad de luz que recibe.
4.  **if (ldrValue < 300) { ... }:** Esta estructura condicional selecciona el tono a reproducir dependiendo del nivel de luz detectado por el LDR. Se reproducen diferentes notas musicales (C4, E4, G4) basadas en los rangos de luz.
5.  **tone(buzzerPin, toneFrequency):** Esta función genera el tono correspondiente en el buzzer basado en la frecuencia calculada.
6.  **noTone(buzzerPin):** Esta función detiene la generación del tono en el buzzer después de la duración especificada.

## Problemas Comunes y Soluciones

*   **El buzzer no suena:** Verifica que las conexiones del buzzer sean correctas y que el pin de salida esté configurado correctamente en el código.
*   **El fotoresistor no responde a los cambios de luz:** Asegúrate de que el fotoresistor esté conectado correctamente y de que la resistencia de 10 kΩ esté en el lugar adecuado para crear un divisor de tensión.
*   **Los tonos son incorrectos:** Revisa los valores de las frecuencias asignadas en el código y ajusta los rangos de luz si es necesario.

## Desafío para el Usuario

¿Cómo podrías modificar el proyecto para agregar más notas o crear una melodía completa en función del nivel de luz? ¡Déjanos tu idea en los comentarios!

<button onclick="toggleAnswer()" style="margin-top: 10px; background-color: #007BFF; color: white; padding: 10px; border: none; cursor: pointer; border-radius: 5px; font-weight: bold;">Mostrar Solución</button>

<div id="answer" style="display: none; margin-top: 20px; background-color: #d4edda; border: 1px solid #c3e6cb; padding: 20px; border-radius: 8px; color: #155724; position: relative;">
    <p>Puedes crear un array de frecuencias para cada nota musical y usar un bucle para recorrer el array en función del nivel de luz. Aquí tienes un ejemplo:</p>
    <pre id="solutionCodeContent" style="background-color: #f8f9fa; padding: 10px; border-radius: 5px; border: 1px solid #eee;"><code>
// Añade estas líneas al código existente

const int melody[] = {262, 294, 330, 349, 392};  // Array de notas (C4, D4, E4, F4, G4)
int melodyIndex = 0;  // Índice de la nota actual

void loop() {
  ldrValue = analogRead(ldrPin);
  melodyIndex = map(ldrValue, 0, 1023, 0, 4);  // Mapear el valor de luz a un índice de nota

  tone(buzzerPin, melody[melodyIndex]);  // Reproducir la nota correspondiente
  delay(500);
  noTone(buzzerPin);
  delay(500);
}
</code></pre>
    <button onclick="copySolutionCode()" style="background-color: #007BFF; color: white; padding: 8px 16px; border: none; cursor: pointer; border-radius: 5px; margin-top: 10px; font-weight: bold;">Copiar Código de Solución</button>
</div>

¡Espero que disfrutes creando este proyecto tanto como yo disfruto compartiéndolo contigo! Recuerda que la práctica hace al maestro, así que sigue experimentando y adaptando este código a nuevas ideas. ¡Nos encantaría ver tus creaciones! 🚀

Si te ha gustado este artículo, por favor compártelo y suscríbete a nuestro blog para más proyectos interesantes. ¡Hasta la próxima aventura tecnológica! 🎵

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
