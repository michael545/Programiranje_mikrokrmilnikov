#define LED_PIN 13
#define DT_PIN 2
#define CLK_PIN 3
#define TIPKA_PIN 8

bool isOn = 0;


void setup() {
  pinMode(LED_PIN, OUTPUT); 
  pinMode(TIPKA_PIN, INPUT); // 8 input
  pinMode(CLK_PIN, INPUT);
  pinMode(DT_PIN, INPUT);
  
  digitalWrite(LED_PIN, LOW);
  
  Serial.begin(9600);
}


void loop() {
  static int staro  = HIGH;
  static int led = HIGH;
  int novo;

  digitalWrite(LED_PIN, led);
  novo = digitalRead(TIPKA_PIN);
  Serial.println(novo);
  if(novo != staro){
    staro = novo;
     if(novo == LOW){
      if (led == LOW){
        led = HIGH;
      }
      else{
        led = LOW;
      }
     }
     delay(20);
  }
  
}
  
