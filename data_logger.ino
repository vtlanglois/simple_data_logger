// analog input pins
const int lightPin = A0;  // the analog input pin for the phototransistor
const int tempPin = A1;   // the analog input pin for the temperature sensor

int lightSensorLow = 1023;
int lightSensorHigh = 0;

const float referenceVoltage = 5.0;  // Reference voltage for the Arduino (in volts)

const int frequency = 1000;            // data collection frequencey in ~x milliseconds.

float temperature;  // the recorded temperature
int light;        // the recorded light level
float voltage;      // the voltage from a sensor (phototransistor or temperature sensor)
int sensorValue;    // the value from a sensor (phototransistor or temperature sensor)


void setup() {
  // open serial communication
  Serial.begin(9600);
  // set up pins
  // pinMode(lightPin, INPUT);
  // pinMode(tempPin, INPUT);

  // setup the light sensor analog values
  while (millis() < 10000) {
    sensorValue = analogRead(lightPin);
    if(sensorValue > lightSensorHigh) {
      lightSensorHigh = sensorValue;
    } 
    if (sensorValue < lightSensorLow) {
      lightSensorLow = sensorValue;
    }
  }

  Serial.print("temp,");
  Serial.println("light");

}

void loop() {
  // get temperature data
  sensorValue = analogRead(tempPin);
  // Serial.print("TEMP: sensor value: ");
  // Serial.print(sensorValue);
  // convert the ADC reasing to voltage
  voltage = (sensorValue / 1023.0) * 5.0;
  // Serial.print(", Voltage: ");
  // Serial.print(voltage);
  // convert the voltage to temperature in degrees Celcius
  temperature = (voltage - .5) * 100;
  // Serial.print(", Temp: ");
  // Serial.println(temperature);

  sensorValue = analogRead(lightPin);
  // Serial.print("LIGHT: sensor value: ");
  // Serial.print(sensorValue);
  light = constrain(map(sensorValue, lightSensorLow, lightSensorHigh, 0, 1000), 0, 1000);
  // Serial.print(", light in lux: ");
  // Serial.println(light);

  // Serial.print("LIGHT RANGE: ");
  // Serial.print(lightSensorLow);
  // Serial.print(", ");
  // Serial.print(lightSensorHigh);

  Serial.print(temperature);
  Serial.print(",");
  Serial.println(light);

  delay(frequency);
}
