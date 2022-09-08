byte Reception_Trame[5];

int i = 0;

//Request what ECU is it
byte ECU_request[] = {0x25, 0x3E, 0x77, 0x68, 0x21, 0x0D}; //bit de parité à refaire

//Request identification
byte ID_request[] = {0x25, 0x3F, 0x69, 0x64, 0x32, 0x0D}; //bit de parité à 

//Request identification with wrong parity
byte Fake_ID[] = {0x25, 0x3F, 0x69, 0x64, 0x10, 0x0D}; //bit de parité à 

//Send fake data
byte Fake[] = {0x25, 0x57, 0x69, 0x64, 0x10, 0x0D}; //bit de parité à 


//Parity Byte Error
byte Parity_error[] = {0x25, 0xFE, 0x50, 0x42, 0xEC, 0x0D};

int info;

bool enable = true;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial3.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(2) == true){
    Serial3.write(ECU_request, sizeof(ECU_request));
    Serial.println("ECU Request");
    delay(1000);
  }

  if(digitalRead(3) == true){
    Serial3.write(ID_request, sizeof(ID_request));
    delay(1000);
  }
  
  if(digitalRead(4) == true){
    Serial3.write(Fake_ID, sizeof(Fake_ID));
    delay(1000);
  }

  if(digitalRead(5) == true){
    Serial3.write(Fake, sizeof(Fake));
    delay(1000);
  }

  if(Serial3.available()>0)
  {
    info = Serial3.read();
    Serial.print(info, HEX);
    i += 1;
  }
  if (i==6)
  {
    Serial.println("");
    i = 0;
  }
}
