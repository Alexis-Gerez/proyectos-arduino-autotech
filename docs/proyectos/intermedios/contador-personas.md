# 🚶‍♀️ Contador de Personas con Sensor Infrarrojo y Arduino 🧮

¡Bienvenidos a otro emocionante proyecto educativo con Arduino! En este tutorial, aprenderemos a construir un **"Contador de Personas con Sensor Infrarrojo"**. Este proyecto es perfecto para aquellos interesados en aplicaciones de monitoreo, como contar personas que ingresan a una habitación o un evento. Utilizaremos un **sensor infrarrojo (IR)** para detectar el paso de personas y un **display de 7 segmentos** para mostrar el conteo. ¡Manos a la obra! 📊🔧

![Contador de Personas con Sensor Infrarrojo](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEhuX1bTB2iLPnoISPDPTGT6-akjf40SMPk8fw7N_lt08O9OEGv30jfJs1Qrda5HKZUX4kzpgdMceR4wDbw3ye2Sb5h6HxzHdSOdiR9AJMNNu2VJNUQf47YUIl_JZlSL_K4alrOBN7bZZ3WRw7GpsYKci3zhsacGdKk37H2qyx3kZJkTENPg5-C7s4X_uaXC/s1600/p8-contadordepersonasconarduinoysensorir.png)

**Contador de Personas con Sensor Infrarrojo y Arduino: Aprende a crear un contador utilizando sensores y displays con Arduino.**

## Enlace al Proyecto en Tinkercad - Contador de Personas

Explora cómo funciona este proyecto y experimenta con el circuito interactivo en Tinkercad. Haz clic en el siguiente enlace para acceder: [Contador de Personas - Proyecto en Tinkercad](https://www.tinkercad.com/things/4bcH808UVHa-proyecto-intermedio-contador-de-personas-con-sensor-ir?sharecode=2dmRNa2Lb-FjbMDLWFvIeYa6xcTys05dpuzUGPrHsww).

## Componentes Necesarios

Para llevar a cabo este proyecto, vamos a necesitar los siguientes componentes:

*   1 x Arduino Uno
*   1 x Sensor Infrarrojo (IR)
*   1 x Display de 7 Segmentos
*   7 x Resistencias de 220Ω
*   Cables de Conexión
*   1 x Protoboard
*   Fuente de Alimentación (USB de PC o batería externa)

## Todos los materiales necesarios los encontrarás en los siguientes enlaces:

*   [Kit de Arduino Uno R3 - Incluye todo lo necesario](https://amzn.to/4dQTpkX)
*   [Kit de módulos de sensores y componentes - Compatible con Arduino](https://amzn.to/3yGZIsk)

## Configuración del Circuito

### Diagrama de Conexión

![Diagrama de Conexión](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEhsWNU4uDLwkpRMUOS5PQPe38KdW__kv3Vb40vovUkfMni_YxNrIYCziPjXFZo5pdnjF7EYFixUKH4cagkR2HFetxrZTJME6xJnELJwmIIkuV9-nwh2kfVgfh-oWq41fWVZYGGPc-blglWcBHxYU2bMEL87Ej7EFb2ed61DwObdbFDdSo4XrnyWrHqBBN8o/s1600/pi2-ArduinoUno-proyecto-programacion-contadordepersonas.jpg)

### Conexiones:

*   **Sensor Infrarrojo (IR):**
    *   Conectar el pin de VCC del sensor infrarrojo a 5V de Arduino.
    *   Conectar el pin GND del sensor infrarrojo a GND de Arduino.
    *   Conectar el pin de salida (OUT) del sensor infrarrojo al pin 2 de Arduino.
*   **Display de 7 Segmentos:**
    *   Conectar los pines a, b, c, d, e, f, g del display de 7 segmentos a los pines 3, 4, 5, 6, 7, 8, 9 de Arduino respectivamente.
    *   Conectar cada pin del display a través de una resistencia de 220Ω para limitar la corriente.
    *   Conectar el pin de común cátodo o ánodo del display a GND o 5V dependiendo del tipo de display utilizado.

## Código para Controlar el Contador de Personas con Arduino

¡Aquí tienes el código completo! Puedes copiarlo fácilmente haciendo clic en el botón "Copiar Código".

<div style="border: 2px solid #007BFF; padding: 20px; background-color: #f0f8ff; position: relative; margin: 20px 0; border-radius: 8px;">
    <button onclick="copyCode()" style="background-color: #007BFF; color: white; padding: 10px 20px; border: none; cursor: pointer; position: absolute; right: 10px; top: 10px; border-radius: 5px; font-weight: bold;">Copiar Código</button>
    <pre id="codeContent" style="margin-top: 40px; overflow-x: auto;"><code>
// Definición de pines
const int sensorIRPin = 2;  // Pin del sensor infrarrojo
const int displayPins[7] = {3, 4, 5, 6, 7, 8, 9};  // Pines para el display de 7 segmentos

// Variables
int personCount = 0;  // Contador de personas
bool lastState = LOW;  // Estado anterior del sensor IR

void setup() {
  // Configuración del pin del sensor infrarrojo como entrada
  pinMode(sensorIRPin, INPUT);

  // Configuración de los pines del display de 7 segmentos como salida
  for (int i = 0; i < 7; i++) {
    pinMode(displayPins[i], OUTPUT);
    digitalWrite(displayPins[i], LOW);  // Inicializar los segmentos como apagados
  }

  Serial.begin(9600);  // Iniciar la comunicación serie para la depuración
}

void loop() {
  // Leer el estado del sensor infrarrojo
  bool currentState = digitalRead(sensorIRPin);

  // Detección de cambio de estado del sensor IR (persona pasa por la puerta)
  if (currentState == HIGH && lastState == LOW) {
    personCount++;  // Incrementar contador de personas
    Serial.print("Personas Contadas: ");
    Serial.println(personCount);
    mostrarNumero(personCount);  // Mostrar el conteo en el display
  }

  // Guardar el estado actual del sensor IR para la siguiente lectura
  lastState = currentState;

  delay(200);  // Pequeño retraso para evitar rebotes del sensor IR
}

// Función para mostrar números en el display de 7 segmentos
void mostrarNumero(int num) {
  // Definición de los números 0 a 9 en el display de 7 segmentos
  byte numeros[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0 (A, B, C, D, E, F encendidos; G apagado)
    {0, 1, 1, 0, 0, 0, 0}, // 1 (B, C encendidos; A, D, E, F, G apagados)
    {1, 1, 0, 1, 1, 0, 1}, // 2 (A, B, D, E, G encendidos; C, F apagados)
    {1, 1, 1, 1, 0, 0, 1}, // 3 (A, B, C, D, G encendidos; E, F apagados)
    {0, 1, 1, 0, 0, 1, 1}, // 4 (B, C, F, G encendidos; A, D, E apagados)
    {1, 0, 1, 1, 0, 1, 1}, // 5 (A, C, D, F, G encendidos; B, E apagados)
    {1, 0, 1, 1, 1, 1, 1}, // 6 (A, C, D, E, F, G encendidos; B apagado)
    {1, 1, 1, 0, 0, 0, 0}, // 7 (A, B, C encendidos; D, E, F, G apagados)
    {1, 1, 1, 1, 1, 1, 1}, // 8 (A, B, C, D, E, F, G encendidos)
    {1, 1, 1, 1, 0, 1, 1}  // 9 (A, B, C, D, F, G encendidos; E apagado)
  };

  for (int i = 0; i < 7; i++) {
    digitalWrite(displayPins[i], numeros[num % 10][i]);  // Mostrar el número en el display
  }
}
</code></pre>
</div>

## Explicación del Código

A continuación, explicamos cada línea del código para ayudarte a comprender su funcionamiento y a desarrollar un pensamiento crítico sobre su estructura y lógica:

1.  **Sensor Infrarrojo (IR):** Utiliza el pin 2 de Arduino para detectar el paso de personas. Detecta un cambio de estado de bajo a alto.
2.  **Display de 7 Segmentos:** Los pines 3-9 de Arduino controlan los segmentos del display, que muestra el conteo actual.
3.  **mostrarNumero(int num):** Toma el conteo actual y muestra el número correspondiente en el display de 7 segmentos.

## Problemas Comunes y Soluciones

*   **El sensor IR no detecta:** Verifica que el sensor esté correctamente conectado y que el pin de salida esté conectado al pin correcto de Arduino.
*   **El display no muestra correctamente los números:** Revisa las conexiones y asegúrate de que cada pin esté conectado a la resistencia y al pin correcto en Arduino.
*   **Rebote del sensor IR:** Agrega un pequeño retraso o debounce para evitar que el contador aumente incorrectamente.

## Desafío para el Usuario

¿Cómo podrías modificar el proyecto para contar tanto entradas como salidas de personas? ¡Déjanos tu idea en los comentarios!

<button onclick="toggleAnswer()" style="margin-top: 10px; background-color: #007BFF; color: white; padding: 10px; border: none; cursor: pointer; border-radius: 5px; font-weight: bold;">Mostrar Solución</button>

<div id="answer" style="display: none; margin-top: 20px; background-color: #d4edda; border: 1px solid #c3e6cb; padding: 20px; border-radius: 8px; color: #155724; position: relative;">
    <p>Para contar tanto entradas como salidas, puedes utilizar dos sensores IR, uno para detectar la entrada y otro para detectar la salida. Dependiendo de cuál se active primero, incrementas o decrementas el contador de personas.</p>
    <pre id="solutionCodeContent" style="background-color: #f8f9fa; padding: 10px; border-radius: 5px; border: 1px solid #eee;"><code>
// Modificación para contar entradas y salidas

const int entradaIRPin = 2;  // Pin del sensor infrarrojo de entrada
const int salidaIRPin = 3;  // Pin del sensor infrarrojo de salida

int personCount = 0;  // Contador de personas
bool lastEntradaState = LOW;  // Estado anterior del sensor de entrada
bool lastSalidaState = LOW;  // Estado anterior del sensor de salida

void setup() {
  pinMode(entradaIRPin, INPUT);
  pinMode(salidaIRPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  bool currentEntradaState = digitalRead(entradaIRPin);
  bool currentSalidaState = digitalRead(salidaIRPin);

  if (currentEntradaState == HIGH && lastEntradaState == LOW) {
    personCount++;
    mostrarNumero(personCount);
  }
  if (currentSalidaState == HIGH && lastSalidaState == LOW) {
    personCount--;
    mostrarNumero(personCount);
  }

  lastEntradaState = currentEntradaState;
  lastSalidaState = currentSalidaState;

  delay(200);
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
