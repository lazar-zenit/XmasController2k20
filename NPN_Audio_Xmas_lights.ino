


int brightness = 0;
int fadeAmount = 5;
int btn1Counter = 0;
int buttonState = 0;

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  buttonState=digitalRead(2);
  if (buttonState==HIGH){
    btn1Counter++; 
    delay(500);
  }
  Serial.println(btn1Counter);
  if (btn1Counter == 0){
      analogWrite(9, 255);
      analogWrite(10, 255);
   }
  if (btn1Counter == 1){
      FadeSlow();
   }
  if (btn1Counter == 2){
      FadeMedium();
   }
  if (btn1Counter==3){
      FadeFast();
   }
   if (btn1Counter==4){
    PartyMode();
   }
   if (btn1Counter==5){
    Audio();
   }
   if (btn1Counter==6){
    btn1Counter=0;
   }
  
  
}
void Audio(){
  int audio_in=analogRead(A0);
  int audio_in_map=map(audio_in, 0 ,255, 0, 255); 
  analogWrite(9, audio_in_map);
  analogWrite(10, audio_in_map);
  }

void PartyMode(){
   analogWrite(9, brightness);
   analogWrite(10, brightness);
   brightness = brightness + fadeAmount;
   if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount ;}
  delay(1);}

void FadeSlow(){
   analogWrite(9, brightness);
   analogWrite(10, brightness);
   brightness = brightness + fadeAmount;
   if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount ;}
  delay(65);}
  
void FadeMedium(){
   analogWrite(9, brightness);
   analogWrite(10, brightness);
   brightness = brightness + fadeAmount;
   if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount ;}
  delay(25);}

void FadeFast(){
   analogWrite(9, brightness);
   analogWrite(10, brightness);
   brightness = brightness + fadeAmount;
   if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount ;}
  delay(10);}
