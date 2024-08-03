#include <wire.h>
#include <Adafruit_ADS1015.h>

const float FACTOR = 30;          // Calibration factor for current sensor
const float MULTIPLIER = 0.0625F; // ADC voltage step multiplier

void setup()
{
  Serial.begin(9600);
  ads.setGain(GAIN_TWO);
  ads.begin();
}

float getCurrentRMS()
{
  float adc = ads.readADC_Differential_0_1();
  float current, sum = 0;
  long startTime = millis();  
  int count = 0;

  while (millis() - startTime < 1000)
  {                                        
    voltage = adc * MULTIPLIER;            
    current = (voltage * FACTOR) / 1000.0;
    sum += sq(current);                    // Sum of squares
    count++;
  }

  rmscurrent = sqrt(sum / count); // Calculate RMS current
  return rmscurrent;
}

void loop()
{
  float currentRMS = getCurrentRMS(); 

  char telemetry[128];
  snprintf(telemetry, sizeof(telemetry), "{\"Irms\":%.3f}", currentRMS);
  MQTT_telemetry(telemetry);
  delay(1000);
}
