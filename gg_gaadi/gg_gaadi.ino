#define GND1 9

#define VCC1 13
#define VCC2 11

#define OUT1 12
#define OUT2 10

#define W1D1 4
#define W1D2 5

#define W2D1 6
#define W2D2 7

void setup() {
  pinMode(VCC1, OUTPUT);
  pinMode(VCC2, OUTPUT);
  pinMode(GND1, OUTPUT);
  pinMode(OUT1, INPUT);
  pinMode(OUT2, INPUT);
  digitalWrite(VCC1, HIGH);
  digitalWrite(VCC2, HIGH);
  digitalWrite(GND1, LOW);
  Serial.begin(9600);
}

void rotateRWheel(int direction) {
  digitalWrite(W1D1, max(-direction, 0));
  digitalWrite(W1D2, max(direction, 0));
}

void rotateLWheel(int direction) {
  digitalWrite(W2D1, max(direction, 0));
  digitalWrite(W2D2, max(-direction, 0));
}

bool forwardL = true, forwardR = true;
bool ir1_0 = digitalRead(OUT1), ir2_0 = digitalRead(OUT2);

void loop() {
  bool ir1 = digitalRead(OUT1), ir2 = digitalRead(OUT2);

  if (ir1) {
    rotateLWheel(0);

    if (ir1 != ir1_0) {
      forwardL = !forwardL;
    }
  } else {
    if (forwardL) {
      rotateLWheel(1);
    } else {
      rotateLWheel(-1);
    }
  }

  if (ir2) {
    rotateRWheel(0);

    if (ir2 != ir2_0) {
      forwardR = !forwardR;
    }
  } else {
    if (forwardR) {
      rotateRWheel(1);
    } else {
      rotateRWheel(-1);
    }
  }
  // rotateLWheel(1);
  // rotateRWheel(1);


  // Serial.println("L =" + forwardL? "1" : "0");
  // Serial.println("R =" + forwardR? "1" : "0");

  // Serial.println((int) ir1);
  // Serial.println((int) ir2);
  // Seria.println();
}
