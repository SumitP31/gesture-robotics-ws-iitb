
int data = 0;

void setup() {
  pinMode(LED_BUILTIN,OUTPUT);  
  digitalWrite(LED_BUILTIN,LOW);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  if (Serial.available()>0){
    data = Serial.read();
    if(data=='0')
    {
      digitalWrite(LED_BUILTIN,LOW);
      Serial.println("LED:OFF");
      
    }
   else if(data =='69')
   {
      digitalWrite(LED_BUILTIN,HIGH);
      Serial.println("LED:chal nikal");
      
    }
    }
  // put your main code here, to run repeatedly:

}
