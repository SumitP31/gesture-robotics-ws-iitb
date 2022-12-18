const int PROXPIN = A0;
const int VCC = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(VCC, OUTPUT);
  digitalWrite(VCC, HIGH);

  pinMode(PROXPIN, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(PROXPIN));
  Serial.println(digitalRead(PROXPIN));
}
