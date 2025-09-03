int a = 0;
int b = 0;
int c = 0;
int d= 0;
int e= 0;
int f= 0;
int g= 0;
int h= 0;
int i= 0;
int j= 0;
int k= 0;
int l= 0;

int A = 0;
int B = 0;
int C = 0;
int D= 0;
int E= 0;
int F= 0;
int G= 0;
int H= 0;
int I= 0;
int J= 0;
int K= 0;
int L= 0;

const int capt1 = 2;  
const int capt2 = 3;
const int capt3 = 4;
const int capt4 = 5;
const int capt5 = 6;
const int capt6 = 7;
const int capt7 = 8;
const int capt8 = 9;
const int capt9 = 10;
const int capt10 = 11;
const int capt11 = 12;
const int capt12 = 13;

int capt1State = 0;
int capt2State = 0;  
int capt3State = 0; 
int capt4State = 0;
int capt5State = 0;  
int capt6State = 0; 
int capt7State = 0;
int capt8State = 0;  
int capt9State = 0; 
int capt10State = 0;
int capt11State = 0;
int capt12State = 0;

unsigned long myTime;
unsigned long prevTime;

int tdelay = 10;

void setup() {
  Serial.begin(9600);
  pinMode(capt1, INPUT);
  pinMode(capt2, INPUT);
  pinMode(capt3, INPUT);
  pinMode(capt4, INPUT);
  pinMode(capt5, INPUT);
  pinMode(capt6, INPUT);
  pinMode(capt7, INPUT);
  pinMode(capt8, INPUT);
  pinMode(capt9, INPUT);
  pinMode(capt10, INPUT);
  pinMode(capt11, INPUT);
  pinMode(capt12, INPUT);
  
  myTime = millis ();
  prevTime = myTime;
}

void loop() {
  // read the state of the pushbutton value:
  capt1State = digitalRead(capt1);
  capt2State = digitalRead(capt2);
  capt3State = digitalRead(capt3);
  capt4State = digitalRead(capt4);
  capt5State = digitalRead(capt5);
  capt6State = digitalRead(capt6);
  capt7State = digitalRead(capt7);
  capt8State = digitalRead(capt8);
  capt9State = digitalRead(capt9);
  capt10State = digitalRead(capt10);
  capt11State = digitalRead(capt11);
  capt12State = digitalRead(capt12);

  myTime = millis();

  if (myTime - prevTime >= 1200){
    prevTime = myTime ;

   Serial.print(A);
    Serial.print(" ");
    Serial.print(B);
    Serial.print(" ");
    Serial.print(C);
    Serial.print(" ");
    Serial.print(D);
    Serial.print(" ");
    Serial.print(E);
    Serial.print(" ");
    Serial.print(F);
    Serial.print(" ");
    Serial.print(G);
    Serial.print(" ");
    Serial.print(H);
    Serial.print(" ");
    Serial.print(I);
    Serial.print(" ");
    Serial.print(J);
    Serial.print(" ");
    Serial.print(K);

    Serial.print(" ");
    Serial.print(L);

    Serial.println("");
  }
  // CAPTEUR 1
  if (capt1State == HIGH) {
    a += 1;
    delay(tdelay);
    }
  else {
   // Serial.println("Rien de détecté");
  }
  if (capt1State == LOW && a != 0){
    a = 0;
    A+=1;
    
  }


//CAPTEUR 2
  if (capt2State == HIGH) {
    b += 1;
    delay(tdelay);
    }
  else {
   // Serial.println("Rien de détecté");
  }
  if (capt2State == LOW && b != 0){
    b = 0;
    B+=1;
    
  }



//CAPTEUR 3
  if (capt3State == HIGH) {
    c += 1;
    delay(tdelay);
    }
  else {
   // Serial.println("Rien de détecté");
  }
  if (capt3State == LOW && c != 0){
    c = 0;
    C+=1;
    
  }


//CAPTEUR 4
  if (capt4State == HIGH) {
    d += 1;
    delay(tdelay);
    }
  else {
   // Serial.println("Rien de détecté");
  }
  if (capt4State == LOW && d != 0){
    d = 0;
    D+=1;
   
  }
  

  //CAPTEUR 5
  if (capt5State == HIGH) {
    e += 1;
    delay(tdelay);
    }
  else {
   // Serial.println("Rien de détecté");
  }
  if (capt5State == LOW && e != 0){
    e = 0;
    E+=1;
   
  }


  //CAPTEUR 6
  if (capt6State == HIGH) {
    f += 1;
    delay(tdelay);
    }
  else {
   // Serial.println("Rien de détecté");
  }
  if (capt6State == LOW && f != 0){
    f = 0;
    F+=1;
 
  }


  //CAPTEUR 7
  if (capt7State == HIGH) {
    g += 1;
    delay(tdelay);
    }
  else {
   // Serial.println("Rien de détecté");
  }
  if (capt7State == LOW && g != 0){
    g = 0;
    G+=1;
   
  }


  //CAPTEUR 8
  if (capt8State == HIGH) {
    h += 1;
    delay(tdelay);
    }
  else {
   // Serial.println("Rien de détecté");
  }
  if (capt8State == LOW && h != 0){
    h = 0;
    H+=1;
  
  }


  //CAPTEUR 9
  if (capt9State == HIGH) {
    i += 1;
    delay(tdelay);
    }
  else {
   // Serial.println("Rien de détecté");
  }
  if (capt9State == LOW && i != 0){
    i = 0;
    I+=1;
   
  }


  //CAPTEUR 10
  if (capt10State == HIGH) {
    j += 1;
    delay(tdelay);
    }
  else {
   // Serial.println("Rien de détecté");
  }
  if (capt10State == LOW && j != 0){
    j = 0;
    J+=1;
  
  }


  //CAPTEUR 11
  if (capt11State == HIGH) {
    k += 1;
    delay(tdelay);
    }
  else {
   // Serial.println("Rien de détecté");
  }
  if (capt11State == LOW && k != 0){
    k = 0;
    K+=1;

  }

  //CAPTEUR 12
  if (capt12State == HIGH) {
    l += 1;
    delay(tdelay);
    }
  else {
   // Serial.println("Rien de détecté");
  }
  if (capt12State == LOW && l != 0){
    l = 0;
    L+=1;
    
  }
  }
