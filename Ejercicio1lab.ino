/**
 * Laboratorio IoT - Prueba ADC con Potenciómetro
 * Con verificación de configuración de placa
 */

#ifdef ESP32
  #include <esp32-hal-adc.h>
  #define PIN_POTENCIOMETRO 15
#else
  #error "Este código SOLO funciona en ESP32. Por favor selecciona una placa ESP32 (Tools > Board > ESP32 Arduino)"
#endif

void setup() {
  Serial.begin(115200);
  delay(1000); // Esperar a que el serial se inicie
  
  Serial.println("\n\n=================================");
  Serial.println("VERIFICACIÓN DE CONFIGURACIÓN");
  Serial.println("=================================");
  
  // Verificar que estamos en ESP32
  #ifdef ESP32
    Serial.println("Placa correcta: ESP32 detectado");
  #else
    Serial.println("ERROR: No es una placa ESP32");
    Serial.println("Ve a Herramientas > Placa > ESP32 Arduino y selecciona tu modelo");
    while(1); // Detener ejecución
  #endif
  
  // Verificar configuración del ADC
  analogReadResolution(12);
  analogSetAttenuation(ADC_11db);
  
  Serial.println("ADC configurado: 12 bits, 0-3.3V");
  Serial.println("---------------------------------");
  Serial.println("Conecta el potenciómetro al GPIO34");
  Serial.println("Gira el potenciómetro para ver los valores");
  Serial.println("=================================\n");
}

void loop() {
  int valorAdc = analogRead(PIN_POTENCIOMETRO);
  float voltaje = (valorAdc * 3.3) / 4095.0;
  
  // Formato para Serial Plotter (solo número)
  Serial.println(valorAdc);
  
  // También mostrar cada 500ms en formato texto
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint > 500) {
    lastPrint = millis();
    Serial.print("📊 ADC: ");
    Serial.print(valorAdc);
    Serial.print(" | Voltaje: ");
    Serial.print(voltaje, 2);
    Serial.println("V");
  }
  
  delay(10); // Pequeña pausa
}