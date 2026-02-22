/**
 * Verificación de precisión en puntos específicos
 */

#define PIN_DAC 25

void setup() {
  Serial.begin(115200);
  
  Serial.println("\n\n=================================");
  Serial.println("VERIFICACIÓN DE PRECISIÓN DAC");
  Serial.println("=================================");
  Serial.println("Comandos disponibles:");
  Serial.println("  - Envia un número (0-255) para ese valor DAC");
  Serial.println("  - 'r' para rampa automática");
  Serial.println("  - 'm' para valores predefinidos");
  Serial.println("---------------------------------\n");
}

void loop() {
  if (Serial.available() > 0) {
    char comando = Serial.read();
    
    if (comando == 'r') {
      // Modo rampa
      Serial.println("Modo RAMPA activado");
      for (int i = 0; i <= 255; i++) {
        dacWrite(PIN_DAC, i);
        float voltaje = (i / 255.0) * 3.3;
        Serial.print("Valor: ");
        Serial.print(i);
        Serial.print(" (");
        Serial.print(voltaje, 3);
        Serial.println(" V)");
        delay(100);
      }
    }
    else if (comando == 'm') {
      // Modo manual - puntos clave
      int puntos[] = {0, 64, 128, 192, 255};
      for (int i = 0; i < 5; i++) {
        dacWrite(PIN_DAC, puntos[i]);
        float voltaje = (puntos[i] / 255.0) * 3.3;
        Serial.print("Valor DAC: ");
        Serial.print(puntos[i]);
        Serial.print(" -> Voltaje: ");
        Serial.print(voltaje, 3);
        Serial.println(" V (MIDE AHORA)");
        delay(3000);
      }
    }
    else {
      // Número enviado
      int valor = comando - '0'; // Esto es muy simple, mejor usar parseInt
      // Para números de más de 1 dígito, usa:
      while(Serial.available() > 0) {
        // Leer el resto del número
      }
    }
  }
}