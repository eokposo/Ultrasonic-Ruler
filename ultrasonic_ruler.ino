#include <LiquidCrystal.h> // Use angle brackets for including libraries

LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)

const int trigPin = 9;
const int echoPin = 10;
long duration;
int distanceCm, distanceInch;

void setup() {
  lcd.begin(16, 2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
  pinMode(trigPin, OUTPUT); // Set TRIG pin as output
  pinMode(echoPin, INPUT);  // Set ECHO pin as input
}

void loop() {
  // Send a pulse from the TRIG pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the ECHO pin and calculate the duration
  duration = pulseIn(echoPin, HIGH);

  // Convert duration to distances
  distanceCm = duration * 0.034 / 2;   // Convert to centimeters
  distanceInch = duration * 0.0133 / 2; // Convert to inches

  // Display the distance in centimeters on the first row
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distanceCm);
  lcd.print(" cm");

  // Display the distance in inches on the second row
  lcd.setCursor(0, 1);
  lcd.print("Distance: ");
  lcd.print(distanceInch);
  lcd.print(" inch");

  delay(500); // Wait for 0.5 seconds before next measurement
}
