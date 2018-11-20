#define LED_PIN 5
#define BUTTON_PIN 4
#define BLINK_RATE 500

bool ledState = false;
int buttonState = 0;
int t = 0;
int tStamp = 0;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);
    ledState = false;
}

void loop() {
  t = millis();
  buttonState = digitalRead(BUTTON_PIN);

  if(buttState == LOW) {
    if(tStamp <= t){
      tStamp = t + BLINK_RATE;

      if(ledState){
        digitalWrite(LED_PIN, LOW);
        ledState = false;
      } else {
        digitalWrite(LED_PIN, HIGH);
        ledState = true;
      }
    }
  } else {
    digitalWrite(LED_PIN, LOW);
    ledState = false;
    tStamp = t;
  }
}
