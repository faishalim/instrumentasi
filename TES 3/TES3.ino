//INPUT ANALOG
int ldr = A2;
int berat = A1;
int suhu = A0;
//OUTPUT
int led1 = 7;
int led2 = 8;
int led3 = 9;

int hasilldr = 0;
int hasilberat = 0;
int hasilsuhu = 0;

void setup() {
  Serial.begin(9600);
  //INPUT
  pinMode(ldr,INPUT);
  pinMode(berat, INPUT);
  pinMode(suhu, INPUT);

  //OUTPUT
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  //Membaca output masing-masing rangkaian
  //sensor suhu
  hasilsuhu = analogRead(suhu);
  //loadcell
  hasilberat = analogRead(berat);
  //LDR
  hasilldr = analogRead (ldr);

  //Mengubah hasil bacaan sensor ke bentuk tegangan 0 Volt - 5 Volt 
  float suhuv = hasilsuhu * (5.0 /1023.0);
  float beratv = hasilberat * (5.0 /1023.0);
  float ldrv = hasilldr * (5.0 /1023.0);

  //Benchmark
  float suhumid = 2.53;
  float ldrmid = 0.71;
  float beratmid = 4.8; 

  //Kondisi 1
  if(ldrv > ldrmid & beratv < beratmid & suhuv < suhumid){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  }

  //Kondisi 2
  else if(ldrv > ldrmid & beratv < beratmid & suhuv > suhumid){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  }

  //Kondisi 3
  else if(ldrv > ldrmid & beratv > beratmid & suhuv < suhumid){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }

  //Kondisi 4
  else if(ldrv > ldrmid & beratv > beratmid & suhuv > suhumid){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
  }

  //Kondisi 5
      else if(ldrv < ldrmid & beratv < beratmid & suhuv < suhumid){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }    

  //Kondisi 6
  else if(ldrv < ldrmid & beratv < beratmid & suhuv > suhumid){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }    

  //Kondisi 7
  else if(ldrv < ldrmid & beratv > beratmid & suhuv < suhumid){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }    

  //Kondisi 8
  else if(ldrv < ldrmid & beratv > beratmid & suhuv > suhumid){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
  }
  
}
