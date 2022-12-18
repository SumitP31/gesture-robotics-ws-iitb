#define IR_L 8
#define IR_R 4
#define JUGAAD_PIN 12

void setup() {
  pinMode(JUGAAD_PIN, OUTPUT);
  pinMode(IR_L, INPUT);
  pinMode(IR_R, INPUT);
  digitalWrite(JUGAAD_PIN, HIGH);
  Serial.begin(9600);
}

bool leftClose = false, rightClose = false;
bool v0 = false;

void loop() {
  bool v1 = digitalRead(IR_L) ^ digitalRead(IR_R);
  if (v0 != v1) Serial.println(v1);
  v0 = v1;
}
