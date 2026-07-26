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

  // TODO:
  // Make state machine to show how instructions received translate to what motor commands
  // Motor commmands: Forward, Reverse, Parked, Left, and Right
  // Create if-else block from state machine

  // Check for data in BL module
  if (BTSerial.available() > 0) {
    // Print received instruction
    String receivedInstr = BTSerial.readStringUntil('\n');
    receivedInstr.trim(); 
    Serial.print("Received string: ");
    Serial.println(receivedInstr);

    if (receivedInstr == "FORWARD") {
      // Forward
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      delay(1000);
      Serial.println("Forward");
    }

    else if (receivedInstr == "REVERSE") {
      // Reverse
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delay(1000);
      Serial.println("Reverse");
    }

    else if (receivedInstr == "LEFT") {
      // Left turn (Motor A Clkwise)
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, HIGH);
      delay(1000);
      Serial.println("Left turn");
    }

    else if (receivedInstr == "RIGHT") {
      // Right turn (Motor B Clkwise)
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      delay(1000);
      Serial.println("Right turn");
    }

  } else{
      // Parked
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      delay(1000);
      Serial.println("Parked");
    }
}