#include <EEPROM.h>

const int poll_3 = 13;
const int poll_2 = 12;

int readIntFromEEPROM(int address)
{
  return (EEPROM.read(address) << 8) + EEPROM.read(address + 1);
}

void setup()
{
  Serial.begin(115200);
  EEPROM.begin(512);
  pinMode(poll_3, INPUT_PULLUP);
}

void loop() 
{
  int a = digitalRead(poll_3);
  int b = digitalRead(poll_2);
  if(a==0)
  {
    int cpm = readIntFromEEPROM(300);
    int bjp = readIntFromEEPROM(200);
    int tmc = readIntFromEEPROM(100);
    Serial.print("CPI(M): ");
    Serial.println(cpm);
    Serial.print("BJP: ");
    Serial.println(bjp);
    Serial.print("TMC: ");
    Serial.println(tmc);
    delay(2000);
  }
  if(b==0)
  {
    EEPROM.write(100, 0);
    EEPROM.write(101, 0);
    EEPROM.write(200, 0);
    EEPROM.write(201, 0);
    EEPROM.write(300, 0);
    EEPROM.write(301, 0);
    EEPROM.commit();
  }
}
