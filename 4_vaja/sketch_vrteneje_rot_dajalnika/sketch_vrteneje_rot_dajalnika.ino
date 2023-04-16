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
  static int stanje_DT = LOW;
  static int stanje_CLK = LOW; 

  stanje_DT = digitalRead(DT_PIN)
  stanje_CLK  = digitalRead(CLK_PIN)

  if(stanje_CLK == HIGH && stanje_DT == LOW){
    Serial.println("rotacijski dajalnik se vrti v desno");
    
  }
  if (stanje_CLK == HIGH && stanje_DT == HIGH){
    Serial.println("rotacijski dajalnik se ne vrti");
    
  }

  delay(100);
  
}
