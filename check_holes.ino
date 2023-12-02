int trig = 2; //set port
int echo = 3; //set port
int speakerPin = 13;
int sound = 700;

void setup() {
  pinMode(speakerPin, OUTPUT);
  pinMode(trig, OUTPUT); 
  pinMode(echo, INPUT);
  Serial.begin(9600);
}
void siren() {
  for (int i = 0; i < 801; i ++ ) {
     tone(speakerPin, sound + i);
  }
   for (int i = 0; i < 801; i ++) { 
     tone(speakerPin, sound + 800 - i); 
  }
  return;
}
void loop() {
  float length1, distance1;
  digitalWrite(trig, LOW);
  delay(2);
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  length1 = pulseIn(echo, HIGH);
  

  distance1 = ((float)(340 * length1) / 10000) / 2;
  if(distance1 < 25) {
    noTone(speakerPin);
  }
  if(distance1 >= 25) {
    siren();
  }
  Serial.println(distance1); 
  delay(10);
}