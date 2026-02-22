/**
 * DAC -> ADC con Serial Plotter
 * Muestra ambas señales en tiempo real
 */

#define PIN_DAC 25
#define PIN_ADC 34

const uint8_t seno[32] = {
  128, 152, 176, 198, 218, 234, 245, 252,
  254, 252, 245, 234, 218, 198, 176, 152,
  128, 103,  79,  57,  37,  21,  10,   3,
  0,    3,  10,  21,  37,  57,  79, 103
};

int indice = 0;

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
  analogSetAttenuation(ADC_11db);
}

void loop() {
  // Generar señal
  dacWrite(PIN_DAC, seno[indice]);
  
  // Leer señal (convertir ADC 12 bits a escala DAC 8 bits para comparar)
  int adcValor = analogRead(PIN_ADC);
  int adcEscalado = map(adcValor, 0, 4095, 0, 255);
  
  // Enviar ambos valores al plotter
  Serial.print(seno[indice]);      // Valor enviado (azul)
  Serial.print(",");
  Serial.println(adcEscalado);     // Valor recibido (rojo)
  
  indice = (indice + 1) % 32;
  delayMicroseconds(500); // Frecuencia media
}