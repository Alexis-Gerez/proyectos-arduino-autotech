# 🌤️ Estación Meteorológica Básica con Arduino y LCD I2C 🌡️

¡Bienvenidos a otro increíble proyecto educativo de electrónica con Arduino! En esta ocasión, vamos a construir una **Estación Meteorológica Básica** que muestra la temperatura y humedad en tiempo real utilizando un **sensor de temperatura TMP** y un **módulo de display LCD I2C**. Este proyecto es perfecto para quienes desean aprender sobre la integración de sensores y la visualización de datos. ¡Vamos a ello! 🚀

![Estación Meteorológica](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEga8W1w33ZWRFO3WcMblns43Up3AsVN2iH1uigcGmKo-RN0r2XhoFBXaPXn2YnDsrLihfSSy-g0htFJvdOAbvLGJencpfb80rsoINeZ06jbX0w5itR0uw0TR22TWYdps8mL99JcGY6rC4YEcnrdzuIkGmQS-aQQ3Ug1e8YcIeUs_Atf41_9WHwYGzQizo-a/s1600/p6.png)

**Estación Meteorológica Básica con Arduino y LCD I2C: Aprende a crear un sistema de monitoreo de temperatura utilizando Arduino y un sensor TMP.**

## Enlace al Proyecto en Tinkercad - Estación Meteorológica

Explora cómo funciona este proyecto y experimenta con el circuito interactivo en Tinkercad. Haz clic en el siguiente enlace para acceder: [Estación Meteorológica - Proyecto en Tinkercad](https://www.tinkercad.com/things/difK38ADcbr-proyecto-inicial-6-estacion-meteorologica-basica-con-i2c-y-lm35).

## Componentes Necesarios

Para construir esta estación meteorológica básica, necesitarás los siguientes componentes:

*   1 x Arduino Uno R3
*   1 x Sensor de Temperatura TMP
*   1 x Módulo LCD I2C (16x2)
*   1 x Protoboard
*   Cables de Conexión
*   Fuente de Alimentación (USB de la PC o batería externa)

## Todos los materiales necesarios los encontrarás en los siguientes enlaces:

*   [Kit de componentes Arduino Uno R3 - Incluye Arduino y más](https://amzn.to/4dQTpkX)
*   [Kit de módulos de sensores y componentes - Compatible con Arduino](https://amzn.to/3yGZIsk)

## Configuración del Circuito

### Diagrama de Conexión

![Diagrama de Conexión](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEgEIpOUqUyoJu6ALmBF3faPhyQWqimdAP24cSXQgUN4OlJhr6nX9R3koaeGN8ubWNs9EYXyQ4wt7_l_f8nj77HCXBjH28O5mdE-OzlTTUSi6A582U_mLj9X6awJ6Vqq80nh66-B8Yy6wLjCsy6KayNF7Uq2mI34q_rL-190Vt7TvPOBXvlIqLZ3FDeKWgzp/s1600/p6-ArduinoUno-proyecto-programacion-estacionmeteorologicaylm35.jpg)

### Conexiones:

*   **Sensor de Temperatura TMP:**
    *   Conecta VCC a 5V de Arduino.
    *   Conecta GND a GND de Arduino.
    *   Conecta la salida (Vout) al pin A0 de Arduino.
*   **Módulo LCD I2C:**
    *   Conecta VCC a 5V de Arduino.
    *   Conecta GND a GND de Arduino.
    *   Conecta SDA al pin A4 de Arduino.
    *   Conecta SCL al pin A5 de Arduino.

### Configuración de Simulación en Tinkercad:

Asegúrate de que la pantalla LCD I2C que elijas en Tinkercad sea del tipo basado en PCF8574. Configura la dirección I2C como 39 (0x27) para que funcione correctamente.

## Código para la Estación Meteorológica Básica con Arduino

¡Es hora de programar! Aquí tienes el código completo para tu proyecto de estación meteorológica básica. Simplemente copia y pega este código en tu Arduino IDE para empezar:

<div style="border: 2px solid #007BFF; padding: 20px; background-color: #f0f8ff; position: relative; margin: 20px 0; border-radius: 8px;">
    <button onclick="copyCode()" style="background-color: #007BFF; color: white; padding: 10px 20px; border: none; cursor: pointer; position: absolute; right: 10px; top: 10px; border-radius: 5px; font-weight: bold;">Copiar Código</button>
    <pre id="codeContent" style="margin-top: 40px; overflow-x: auto;"><code>
#include &lt;Wire.h&gt;
#include &lt;LiquidCrystal_I2C.h&gt;

// Inicialización del LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Dirección I2C 0x27 y pantalla de 16x2

// Pin del sensor de temperatura TMP
const int tempPin = A0;

void setup() {
  lcd.init();  // Inicializa el LCD
  lcd.backlight();  // Enciende la luz de fondo del LCD
  lcd.setCursor(0, 0);
  lcd.print("Estacion Met.");
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  delay(2000);
}

void loop() {
  // Lee el valor del sensor TMP
  int sensorValue = analogRead(tempPin);
  
  // Convierte el valor analógico a temperatura en Celsius
  float voltage = sensorValue * (5.0 / 1023.0);  // Conversión a voltaje
  float temperatureC = (voltage - 0.5) * 100;  // Conversión a grados Celsius
  
  // Muestra la temperatura en el LCD
  lcd.setCursor(6, 1);
  lcd.print(temperatureC);
  lcd.print(" C  ");  // Agrega espacio adicional para limpiar caracteres anteriores
  
  delay(1000);  // Actualiza cada segundo
}
</code></pre>
</div>

## Explicación del Código

A continuación, explicamos cada línea del código para ayudarte a comprender su funcionamiento y a desarrollar un pensamiento crítico sobre su estructura y lógica:

1.  **Inicialización del LCD I2C:** Se configura la dirección del LCD I2C (0x27) y el tamaño de la pantalla (16x2). La función `lcd.init()` inicializa la pantalla y `lcd.backlight()` enciende la luz de fondo para facilitar la lectura.
2.  **Pin del Sensor TMP:** Utiliza `analogRead(tempPin)` para leer la señal analógica del sensor de temperatura TMP.
3.  **Conversión de Señal Analógica:** Convierte la lectura analógica en un voltaje que luego se convierte a grados Celsius con la fórmula: `(voltage - 0.5) * 100`.
4.  **Visualización de Datos en el LCD:** Se muestra el texto inicial "Estacion Met." en la primera línea del LCD. En la segunda línea, el valor de la temperatura en grados Celsius se actualiza cada segundo.

## Problemas Comunes y Soluciones

*   **El LCD no muestra información:** Verifica que la dirección I2C del LCD sea la correcta (0x27 en este caso) y que las conexiones estén bien hechas.
*   **La temperatura no se muestra correctamente:** Asegúrate de que el sensor TMP esté conectado correctamente y de que la fórmula de conversión sea la adecuada.
*   **El código no se carga en el Arduino:** Revisa que el puerto y la placa correctos estén seleccionados en el Arduino IDE.

## Desafío para el Usuario

¿Cómo podrías mejorar esta estación meteorológica básica para mostrar una alerta visual o sonora si la temperatura supera un límite establecido? Podrías agregar un LED que parpadee o un buzzer que emita un sonido cuando la temperatura sea demasiado alta o baja. ¡Déjanos tu idea en los comentarios!

<button onclick="toggleAnswer()" style="margin-top: 10px; background-color: #007BFF; color: white; padding: 10px; border: none; cursor: pointer; border-radius: 5px; font-weight: bold;">Mostrar Solución</button>

<div id="answer" style="display: none; margin-top: 20px; background-color: #d4edda; border: 1px solid #c3e6cb; padding: 20px; border-radius: 8px; color: #155724; position: relative;">
    <p>Puedes añadir un LED o un buzzer al circuito y modificar el código para activar una alerta. Aquí tienes un ejemplo de cómo hacerlo:</p>
    <pre id="solutionCodeContent" style="background-color: #f8f9fa; padding: 10px; border-radius: 5px; border: 1px solid #eee;"><code>
// Añade estas líneas al código existente

const int ledPin = 13; // Pin del LED de alerta
const int buzzerPin = 8; // Pin del buzzer de alerta
const float tempLimit = 30.0; // Límite de temperatura

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  // El resto del setup() permanece igual
}

void loop() {
  // Código existente para leer el sensor y mostrar la temperatura
  if (temperatureC &gt; tempLimit) {
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
