#include <Wire.h>
#include <Arduino.h>
#include <SHTSensor.h>

SHTSensor sht;
// Para usar un sensor especifico en vez de probar el bus use este comando:
// SHTSensor sht(SHTSensor::SHT3X);

void setup() {

  Wire.begin();
  Serial.begin(115200);
  delay(100); // Retardo para permitir que el puerto serie se ajuste

  if (sht.init()) {
      Serial.print("init(): Exitoso\n");
  } else {
      Serial.print("init(): Fallido\n");
  }
  sht.setAccuracy(SHTSensor::SHT_ACCURACY_MEDIUM); // only supported by SHT3x

}

void loop() {
  
  if (sht.readSample()) {
      Serial.print("SHT:\n");
      Serial.print("  RH: ");
      Serial.print(sht.getHumidity(), 2);
      Serial.print("\n");
      Serial.print("  T:  ");
      Serial.print(sht.getTemperature(), 2);
      Serial.print("\n");
  } else {
      Serial.print("Error en readSample()\n");
  }

  delay(1000);
}