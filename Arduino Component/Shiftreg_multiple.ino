//88건반 피아노 모듈 구동을 위한 쉬프트 레지스터 제어 코드

const int latchPin = 8;
const int clockPin = 12;
const int dataPin = 11;

void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("started");
}

void loop()
{
  if(Serial.available() > 0)
  { 
    long bitToSet = Serial.parseInt();
    
    Serial.println(bitToSet);
    
    if(bitToSet == 888)
    {
      digitalWrite(latchPin, LOW);
    }else if(bitToSet == 999)
    {
      digitalWrite(latchPin, HIGH);
    }else{
      shiftOut(dataPin, clockPin, MSBFIRST, bitToSet);
    }
  }
}
