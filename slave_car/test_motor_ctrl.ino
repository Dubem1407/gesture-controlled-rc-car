int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;
int ENA = 9;  // PWM pin for Motor A (Right Motor)
int ENB = 10; // PWM pin for Motor B (Left Motor)

// Speed (PWM) values from 0-255
int speedA = 230; // Reduce if drifts left
int speedB = 250; // Reduce if drifts right

void setup() {
  // Set pin dir
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println("Loop Start"); 

  // Set motor speeds
  analogWrite(ENA, speedA);
  analogWrite(ENB, speedB);

  // Forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(2000);
  Serial.println("Forward");

  // Brake
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  delay(500);

  // TODO:
  // Make state machine to show how instructions received translate to what motor commands
  // Motor commmands: Forward, Reverse, Parked, Left, and Right
  // Create switch case block from state machine
}