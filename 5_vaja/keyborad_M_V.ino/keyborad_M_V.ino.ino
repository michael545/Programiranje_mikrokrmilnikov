#define ENC_A 2
#define ENC_B 3
#define LED_PIN 13
#define TIPKA_PIN 8

volatile int counter = 0;
char TEKST[100] = ""; 
char *k_TEKST = TEKST;

void setup() {
  
  pinMode(ENC_A, INPUT_PULLUP); //obe vedno logical high
  pinMode(ENC_B, INPUT_PULLUP);
  pinMode(TIPKA_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT); 
  attachInterrupt(digitalPinToInterrupt(ENC_A), read_encoder, CHANGE); //kadarkoli vidis spremembo na ENCA, ENCB, klici funkcijo read encoder
  attachInterrupt(digitalPinToInterrupt(ENC_B), read_encoder, CHANGE);

  Serial.begin(9600);
}

void loop() {
  static int lastCounter = 0;
  static int ptr = k_TEKST;

  if(ptr != k_TEKST){
    Serial.print("Tekst:  ");
    Serial.println(TEKST);
    ptr = k_TEKST;
  }

  
  vstaviZnak(vrniZnak(counter));
  // ce se count spremeni, ga izpisi in updataj
  if(counter != lastCounter){
    Serial.println(vrniZnak(counter));
//    Serial.println();
//    Serial.print("Tekst:  ");
//    Serial.println(TEKST);
//    Serial.println();
//    
    lastCounter = counter;
  }
}

void read_encoder() {
  // Encoder interrupt za oba pina se klice ista funkcija glej setup 
 
  static uint8_t old_AB = 3;  // ker je na startupu 0b 0000 0011 A in B sta high, encoder se ne premika 
  static int8_t encval = 0;   // Encoder value  
  static const int8_t enc_states[]  = {0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0}; // Lookup table

  old_AB <<=2;  // Remember previous state

  if (digitalRead(ENC_A)) old_AB |= 0x02; // dodaj trenutno stanje za pin A
  if (digitalRead(ENC_B)) old_AB |= 0x01; // dodaj trenutno stanje za pin B
  
  encval += enc_states[( old_AB & 0x0f )];

  // Update counter ce se je zavrtel vsaj za 4 korake
  if( encval > 3 ) {       
    int changevalue = 1;

    counter = counter + changevalue;             
    encval = 0;
  }
  else if( encval < -3 ) {        // updataj counter ce se je zavrtel vsaj za 4 korake nazaj
    int changevalue = -1;
    counter = counter + changevalue;              
    encval = 0;
  }
} 


// VRNI ZNAK

char vrniZnak(int pozicija){  
  if(pozicija >= 24 || pozicija <= -50) counter = -1;
//  if(pozicija <= 30) counter = 0;
  
  return 'a' + pozicija;
  
}


//VSTAVI ZNAK
void vstaviZnak(char znak){
  
  
  if(!digitalRead(TIPKA_PIN)){
    delay(200);
    *k_TEKST = znak;
    k_TEKST++;
    return;
     
  }
}
