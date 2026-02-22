/**
 * Laboratorio IoT - Prueba ADC con Generador de Señales
 * Conexión: Generador de señales -> GPIO34
 */

#define PIN_ADC 15        // GPIO34 como entrada ADC
#define ADC_RESOLUTION 12  // 12 bits (0-4095)
#define ADC_MAX 4095.0
#define V_REF 3.3          // Voltaje de referencia

// Variables para almacenar lecturas
const int NUM_SAMPLES = 256;  // Número de muestras
int samples[NUM_SAMPLES];     // Array circular
int sampleIndex = 0;

// Control de tiempo
unsigned long lastPrint = 0;
const int PRINT_INTERVAL = 100;  // ms

void setup() {
  Serial.begin(115200);
  
  // Configurar ADC
  analogReadResolution(ADC_RESOLUTION);
  analogSetAttenuation(ADC_11db);  // Rango 0-3.3V
  
  Serial.println("=================================");
  Serial.println("PRUEBA: ADC + GENERADOR DE SEÑALES");
  Serial.println("=================================");
  Serial.println("Conecta el generador a GPIO34");
  Serial.println("Configura: 1kHz, 2Vpp, offset 1.65V");
  Serial.println("---------------------------------");
}

void loop() {
  // 1. MUESTREO RÁPIDO (para capturar la forma de onda)
  // Leer ADC lo más rápido posible
  samples[sampleIndex] = analogRead(PIN_ADC);
  sampleIndex = (sampleIndex + 1) % NUM_SAMPLES;
  
  // 2. MOSTRAR DATOS EN SERIAL PLOTTER (cada cierto tiempo)
  unsigned long now = millis();
  if (now - lastPrint >= PRINT_INTERVAL) {
    lastPrint = now;
    
    // Enviar TODOS los samples acumulados para visualización
    for (int i = 0; i < NUM_SAMPLES; i++) {
      Serial.print(samples[i]);
      if (i < NUM_SAMPLES - 1) Serial.print(",");
    }
    Serial.println();
  }
  
  // Pequeña pausa para controlar velocidad
  delayMicroseconds(10);
}