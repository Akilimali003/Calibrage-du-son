qint sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;
//LED pin
const int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

//  calibrate duration of the first five seconds
while(millis() < 5000){
  sensorValue = analogRead(A0);

  //  record the maximum sensor value
  if (sensorValue > sensorHigh){
    sensorHigh = sensorValue;
  }

  //record the minimum sensor value
  if (sensorValue < sensorLow){
    sensorLow = sensorValue;
  }
}

//signal the end of calibration period
digitalWrite(ledPin, LOW);
}

void loop() {
  // read the input from A0
  sensorValue = analogRead(A0);
  
// map the sensor values to a wide range of pitches
// Adjust the values below to conform the maximum and the 
//numbers you get from your sensor
int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);

//play the tone
tone(8, pitch, 20);

//wait for a moment
delay(10);
}
