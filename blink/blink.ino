int led=5;
int butt=4;
int buttState=0;
int ledState=0;
int t=0;
int tStamp=0;
int rate=500;

void setup() {
    pinMode(led, OUTPUT);
    pinMode(butt,INPUT);
    ledState=false;
}

void loop() {
  t=millis();
  buttState=digitalRead(butt);
  
  if(buttState==LOW) {
    if(tStamp<=t){
      tStamp=t+rate ;
      
      if(ledState){
        digitalWrite(led,LOW);
        ledState=false;
      }else{
        digitalWrite(led,HIGH);
        ledState=true;
      }
    }
    
    
    
    /*
    digitalWrite(led,HIGH);
    delay(1000);
    digitalWrite(led,LOW);
    delay(1000);
    */
  }else{
    digitalWrite(led,LOW);
    ledState=false;
    tStamp=t;
  }
}
