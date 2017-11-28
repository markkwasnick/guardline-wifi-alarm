int boardLed = D7;
int triggerPort = D0;
int waitOnSignalSec = 1; // configure me to however many seconds to wait until next loop

bool tripped = false;

void setup() {
  // Board LED is an output, the trigger port is where we detect signal from receiver
  pinMode(boardLed, OUTPUT);
  pinMode(triggerPort, INPUT);
}

void loop() {
  // We are usually high, so if we are low then TRIGGERED
  tripped = (LOW == digitalRead(triggerPort));

  if (tripped) {
    // Not needed, just showing that tripped should go to false for next iteration (should, based on this use case)
    tripped = false;
    
    // Turn on the board LED
    digitalWrite(boardLed, HIGH);
    
    // Publish SENSOR_TRIGGERED event with ttl 60 seconds and the datetime string (you can change this payload)
    Particle.publish("SENSOR_TRIGGERED", Time.timeStr().c_str(), 60, PRIVATE);
    
    // Wait for a bit after we fire
    delay(waitOnSignalSec * 1000);
  } else {
    // read: board LED is OFF
    digitalWrite(boardLed, LOW);
  }
}
