int switchPin = 15;
int ledPin = 26;
int val = 0;
boolean toggle = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(7, INPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(7 == HIGH){
    toggle = !toggle;
    digitalWrite(3, toggle);
    Serial.println(toggle);
  }
  Serial.println(val);
  delay(1000);
}
