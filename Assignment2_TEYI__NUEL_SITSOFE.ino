int segmentPins[] = {2, 3, 4, 5, 6, 7, 9};
int numSegments = 7;
int buzzerPin = 8;

byte digits[10][7] = {
// a  b  c  d  e  f  g
  {1, 1, 1, 1, 1, 1, 0}, //0
  {0, 1, 1, 0, 0, 0, 0}, //1
  {1, 1, 0, 1, 1, 0, 1}, //2
  {1, 1, 1, 1, 0, 0, 1}, //3
  {0, 1, 1, 0, 0, 1, 1}, //4
  {1, 0, 1, 1, 0, 1, 1}, //5
  {1, 0, 1, 1, 1, 1, 1}, //6
  {1, 1, 1, 0, 0, 0, 0}, //7
  {1, 1, 1, 1, 1, 1, 1}, //8
  {1, 1, 1, 1, 0, 1, 1}, //9
};
void showDigit(int n) {
  if (n < 0 || n > 9)
  return;
  for (int i = 0; i < numSegments; i++){
    digitalWrite(segmentPins[i], digits[n][i]);
  }
}

void setup() {
      Serial.begin(9600);
    pinMode(buzzerPin, OUTPUT);

    for (int i = 0; i < numSegments; i++){
      pinMode(segmentPins[i], OUTPUT);
    }
  Serial.println("===Trigger Countdown Beeps....===");

  int count = 9;
  while (count >= 1){
    Serial.print("Counting: ");
    Serial.println(count);

    showDigit(count);

    tone(buzzerPin, 300, 500);
    delay(1000);
    count = count - 1;
  }
  showDigit(0);
  tone(buzzerPin, 550, 1000);

  Serial.println("===Countdown Completed Successfully===");
}



void loop() {
  // put your main code here, to run repeatedly:

}
