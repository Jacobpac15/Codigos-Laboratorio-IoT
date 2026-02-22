/**
 * Laboratorio IoT - DAC + Osciloscopio
 * Genera onda senoidal en GPIO25
 * 
 * Conexión: GPIO25 -> Osciloscopio
 *           GND -> Osciloscopio
 */

#define PIN_DAC 25  // GPIO25 para DAC1

// Tabla de onda senoidal (32 valores simple)
// Valores de 0-255 para el DAC
const uint8_t seno[32] = {
  128, 152, 176, 198, 218, 234, 245, 252,
  254, 252, 245, 234, 218, 198, 176, 152,
  128, 103,  79,  57,  37,  21,  10,   3,
  0,    3,  10,  21,  37,  57,  79, 103
};

int indice = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("Generando onda senoidal en GPIO25");
  Serial.println("Conecta el osciloscopio a GPIO25 y GND");
}

void loop() {
  // Escribir valor actual en el DAC
  dacWrite(PIN_DAC, seno[indice]);
  
  // Avanzar al siguiente valor
  indice = (indice + 1) % 32;
  
  // Ajusta este delay para cambiar la frecuencia
  // 100µs = ~312 Hz, 500µs = ~62 Hz, 50µs = ~625 Hz
  delayMicroseconds(200);
}