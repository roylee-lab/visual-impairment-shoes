int trig = 2; //set port
int echo = 3; //set port
int speakerPin = 13;
int sound = 330;
void setup() {
  pinMode(speakerPin, OUTPUT);
  pinMode(trig, OUTPUT); 
  pinMode(echo, INPUT);
  Serial.begin(9600);
}
int i = 0;
float arr[4] = {0.0,0.0,0.0,0.0}; //arr 배열 선언
void loop() {
  i ++;
  float length1, distance1;
  digitalWrite(trig, LOW);
  delay(2);
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  length1 = pulseIn(echo, HIGH);
  distance1 = ((float)(340 * length1) / 10000) / 2;
  arr[i%4] = distance1; //arr 배열에 순서대로 장애물까지의 거리 저장
  bool check = true; //참, 거짓을 판단하는 bool check에 참 저장
  for (int i = 0; i < 4; i ++) {
      if (arr[i] > 100.0) {
          check = false; //arr의 값중 한가지라도 100보다 크다면 check을 거짓으로 저장
      }
  }
  if (check == true) { //check이 참이면 실행, 즉 arr의 값중 한가지라도 100보다 크면 실행하지 않음
    tone(speakerPin, sound);
    delay(100);
    noTone(speakerPin);
    delay(distance1/2);
  }
  for (int i = 0; i < 4; i ++) {
    Serial.print(arr[i]); 
    Serial.print("     ");
  }
  Serial.println("");
  delay(10);
}