#define W1D1 4
#define W1D2 5

#define  IR_VCC 13
#define IR_OUT 12

void setup() {
  // put your setup code here, to run once:
  pinMode(W1D1, OUTPUT);
  pinMode(W1D2, OUTPUT);
  

  pinMode(IR_VCC, OUTPUT);
  digitalWrite(IR_VCC, HIGH);

  pinMode(IR_OUT, INPUT);

  // pinMode(MC, OUTPUT);
}

void rotateRWheel(int direction) {
  digitalWrite(W1D1, max(-direction, 0));
  digitalWrite(W1D2, max(direction, 0));
}

bool rotateForward = true, ir0 = digitalRead(IR_OUT);

void loop() {
  // put your main code here, to run repeatedly:
  bool ir = digitalRead(IR_OUT);

  if (ir) {
    rotateRWheel(0);

    if (ir != ir0) {
      rotateForward = !rotateForward;
    }
  } else {
    if (rotateForward) {
      rotateRWheel(1);
    } else {
      rotateRWheel(-1);
    }
  }
}
