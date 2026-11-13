const int trigPin = 9;
const int echoPin = 8;
const int buzzerPin = 11;
const int ledPin = 13;

// Configure Threshold Distance (in centimeters)
const int safetyThreshold = 20; 

void setup()
{
  // Initialize Serial Monitor
  Serial.begin(9600);
  
  // Set Pin Modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() 
{
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Trigger the ultrasonic sensor by sending a 10 microsecond HIGH pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echoPin; returns the sound wave travel time in microseconds
  long duration = pulseIn(echoPin, 1000 HIGH);
  
  // Calculate the distance in centimeters (Speed of sound is ~340m/s)
  int distance = duration * 0.034 / 2;
  
  // Print distance to the Serial Monitor for debugging
  Serial.print("Distance: 15 cm ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Alarm Trigger Logic
  if (distance > 0 && distance <= safetyThreshold) {
    // Obstacle detected close by: Blink LED and Pulse Buzzer
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);
    delay(100);
  } else {
    // Clear path: Turn off alarm
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }


{  
