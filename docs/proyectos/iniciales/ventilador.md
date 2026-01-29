# 🌡️ Proyecto Nivel Principiante: Controlador de Ventilador Basado en Temperatura con Velocidad Variable 🌬️

¡Bienvenidos a otro proyecto educativo emocionante con Arduino! Hoy, vamos a construir un **"Controlador de Ventilador Basado en Temperatura con Velocidad Variable"**. Este proyecto es ideal para quienes desean aprender cómo controlar un motor DC (ventilador) en función de la temperatura medida por un sensor, ajustando la velocidad del ventilador automáticamente según el calor detectado. 🚀

[![p10-controladordeventilador](../../img/p10-controladordeventilador.png)](https://www.tinkercad.com/things/8TGPeUxToWX-principiante-proyecto4-controlador-ventilador)

<p align="center"><strong>Aprende a construir un controlador de ventilador con Arduino utilizando un sensor de temperatura TMP36 y un motor DC con velocidad variable.</strong></p>

## Enlace al Proyecto en Tinkercad - Controlador de Ventilador

Explora cómo funciona este proyecto y experimenta con el circuito interactivo en Tinkercad. Haz clic en el siguiente enlace para acceder: [Controlador de Ventilador - Proyecto en Tinkercad](https://www.tinkercad.com/things/k9gTNfxRxnQ-proyecto-i-controlador-de-ventilador-basado-en-temperatura?sharecode=-4ygAQYwuDf3Tu4zDW9FWpRwzp-T4sphVu6-jyC0ZVY).

## Componentes Necesarios

Para llevar a cabo este proyecto, necesitarás los siguientes componentes:

*   1 x Arduino Uno
*   1 x Sensor de Temperatura TMP36
*   1 x Motor DC (como Ventilador)
*   1 x Transistor NPN (ej. 2N2222 o BC547)
*   1 x Diodo de protección (ej. 1N4007)
*   1 x Resistencia 220Ω
*   Fuente de Alimentación Externa (9V o 12V)
*   Protoboard y Cables de Conexión

## Todos los materiales necesarios los encontrarás en los siguientes enlaces:

*   [Kit de Arduino Uno R3 - Incluye todo lo necesario](https://amzn.to/4dQTpkX)
*   [Kit de módulos de sensores y componentes - Compatible con Arduino](https://amzn.to/3yGZIsk)

## Configuración del Circuito

### Diagrama de Conexión

![p10-diagrama-conexion](../../img/p10-diagrama-conexion.jpg)

### Conexiones:

*   **Sensor de Temperatura TMP36:**
    *   **Pin 1 (VCC)** del TMP36 a **5V** de Arduino.
    *   **Pin 2 (Vout)** del TMP36 a **pin A0** de Arduino.
    *   **Pin 3 (GND)** del TMP36 a **GND** de Arduino.
*   **Conexión del Motor DC con el Transistor:**
    *   **Colector del Transistor (C)** al **terminal negativo del Motor DC**.
    *   **Emisor del Transistor (E)** a **GND**.
    *   **Base del Transistor (B)** conectada al **pin 9** de Arduino a través de una resistencia de **220Ω**.
    *   **Terminal positivo del Motor DC** a **+9V** o **+12V** (fuente externa).
    *   Conectar un **diodo de protección (1N4007)** en paralelo al motor, con el cátodo al positivo del motor y el ánodo al colector del transistor.

## Código para Controlar el Ventilador con Arduino

¡Aquí tienes el código completo! Puedes copiarlo fácilmente haciendo clic en el botón "Copiar Código".

<div style="border: 2px solid #007BFF; padding: 20px; background-color: #f0f8ff; position: relative; margin: 20px 0; border-radius: 8px;">
    <button onclick="copyCode()" style="background-color: #007BFF; color: white; padding: 10px 20px; border: none; cursor: pointer; position: absolute; right: 10px; top: 10px; border-radius: 5px; font-weight: bold;">Copiar Código</button>
    <pre id="codeContent" style="margin-top: 40px; overflow-x: auto;"><code class="language-cpp">
// Definición de pines
const int tempPin = A0;  // Pin de entrada del sensor de temperatura TMP36
const int fanPin = 9;    // Pin de control del ventilador (PWM) conectado a la base del transistor NPN

// Variables
int tempValue = 0;  // Valor leído del sensor de temperatura
float temperatureC = 0;  // Temperatura en grados Celsius
int fanSpeed = 0;  // Velocidad del ventilador

void setup() {
  pinMode(tempPin, INPUT);  // Configuración del pin del sensor de temperatura como entrada
  pinMode(fanPin, OUTPUT);  // Configuración del pin del ventilador como salida
  Serial.begin(9600);  // Iniciar la comunicación serie para la depuración
  Serial.println("Sistema de Control de Ventilador Iniciado");
}

void loop() {
  tempValue = analogRead(tempPin);  // Leer el valor del sensor de temperatura

  // Conversión a temperatura en grados Celsius para TMP36
  temperatureC = (tempValue * (5.0 / 1024.0) - 0.5) * 100.0;
  
  // Mostrar la temperatura en el monitor serie
  Serial.print("Temperatura: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  // Control del ventilador basado en la temperatura
  if (temperatureC > 30.0) {  // Si la temperatura es mayor a 30°C
    fanSpeed = map(temperatureC, 30, 50, 128, 255);  // Ajustar velocidad del ventilador (50% a 100%)
    analogWrite(fanPin, fanSpeed);  // Controlar la velocidad del ventilador
    Serial.print("Ventilador: ON a velocidad ");
    Serial.println(fanSpeed);
  } else {
    analogWrite(fanPin, 0);  // Apagar el ventilador
    Serial.println("Ventilador: OFF");
  }

  delay(1000);  // Espera 1 segundo antes de la siguiente lectura
}
</code></pre>
</div>

## Explicación del Código

A continuación, explicamos cada línea del código para ayudarte a comprender su funcionamiento y a desarrollar un pensamiento crítico sobre su estructura y lógica:

1.  **Sensor de Temperatura TMP36:** Conectado al pin A0 de Arduino, mide la temperatura ambiente. La salida analógica del TMP36 se convierte a temperatura en grados Celsius.
2.  **Motor DC (Ventilador):** Controlado por un transistor conectado al pin 9 de Arduino. Se utiliza una señal PWM para variar la velocidad del ventilador en función de la temperatura medida.
3.  **Control de Velocidad Variable del Ventilador:** Si la temperatura medida es mayor a 30°C, el ventilador se enciende automáticamente y ajusta su velocidad según el calor detectado, variando de un 50% a 100% de su capacidad. Si la temperatura es menor o igual a 30°C, el ventilador permanece apagado.

## Problemas Comunes y Soluciones

*   **El sensor de temperatura no da lecturas precisas:** Asegúrate de que el sensor TMP36 esté correctamente conectado y que el código esté configurado para el rango de temperatura adecuado.
*   **El ventilador no se enciende:** Verifica que el transistor esté conectado correctamente y que el pin 9 de Arduino esté generando una señal PWM.
*   **El ventilador siempre está a la misma velocidad:** Asegúrate de que la función `map()` esté configurada correctamente y que la temperatura varíe dentro del rango esperado.

## Desafío para el Usuario

¿Cómo podrías modificar el proyecto para que el ventilador tenga más niveles de velocidad en función de rangos de temperatura más específicos? ¡Déjanos tu idea en los comentarios!

<button onclick="toggleAnswer()" style="margin-top: 10px; background-color: #007BFF; color: white; padding: 10px; border: none; cursor: pointer; border-radius: 5px; font-weight: bold;">Mostrar Solución</button>

<div id="answer" style="display: none; margin-top: 20px; background-color: #d4edda; border: 1px solid #c3e6cb; padding: 20px; border-radius: 8px; color: #155724; position: relative;">
    <p>Podrías agregar más condiciones <code>if</code> y <code>else if</code> para establecer diferentes velocidades según la temperatura. Por ejemplo, podrías establecer velocidades de 25%, 50%, 75% y 100% según rangos de temperatura como 25-30°C, 30-35°C, 35-40°C, y 40-50°C.</p>
    <pre id="solutionCodeContent" style="background-color: #f8f9fa; padding: 10px; border-radius: 5px; border: 1px solid #eee;"><code>
// Modificación para múltiples niveles de velocidad del ventilador

void loop() {
  tempValue = analogRead(tempPin);
  temperatureC = (tempValue * (5.0 / 1024.0) - 0.5) * 100.0;
  
  Serial.print("Temperatura: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  if (temperatureC > 40.0) {
    analogWrite(fanPin, 255);  // 100% velocidad
  } else if (temperatureC > 35.0) {
    analogWrite(fanPin, 191);  // 75% velocidad
  } else if (temperatureC > 30.0) {
    analogWrite(fanPin, 128);  // 50% velocidad
  } else if (temperatureC > 25.0) {
    analogWrite(fanPin, 64);   // 25% velocidad
  } else {
    analogWrite(fanPin, 0);    // Apagar ventilador
  }

  delay(1000);
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
