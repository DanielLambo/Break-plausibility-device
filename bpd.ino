const int pot1Pin = A0;   // Analog input pin for potentiometer 1
const int pot2Pin = A1;   // Analog input pin for potentiometer 2
const int relayPin = 5;   // Digital output pin for the relay

int pot1Value;            // Store the value of potentiometer 1
int pot2Value;            // Store the value of potentiometer 2

void setup() {
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Read the values from the potentiometers
  pot1Value = analogRead(pot1Pin);
  pot2Value = analogRead(pot2Pin);

  // Calculate the voltage across the potentiometers
  float voltage1 = (pot1Value / 1023.0) * 5.0;
  float voltage2 = (pot2Value / 1023.0) * 5.0;

  // Check if both potentiometers provide enough resistance
  if (voltage1 > 0.5 && voltage2 > 0.5) {
    // Wait for 1 second
    delay(1000);

    // Read the values again after 1 second
    pot1Value = analogRead(pot1Pin);
    pot2Value = analogRead(pot2Pin);

    // Calculate the voltage across the potentiometers again
    voltage1 = (pot1Value / 1023.0) * 5.0;
    voltage2 = (pot2Value / 1023.0) * 5.0;
  }
    // Check if both potentiometers are still in the desired state
    if (voltage1 > 0.5 && voltage2 > 0.5)
    { 
      // Turn off the relay
      digitalWrite(relayPin, HIGH);
      // Print a message to the serial monitor
      Serial.println("Relay turned on.");
    }
    else if(voltage1 < 0.5 || voltage2 < 0.5)
    {
      digitalWrite(relayPin, LOW);
      Serial.println("Relay turned off.");

    }

  // Print the voltage values to the serial monitor
  Serial.print("Brake sensor 1 Voltage: ");
  Serial.print(voltage1);
  Serial.print("V, Throttle position sensor 2 Voltage: ");
  Serial.print(voltage2);
  Serial.println("V");

  // Add a delay to prevent rapid serial prints
  delay(1000);
}
