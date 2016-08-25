/*
 * 
 * 미림 기기들 제어를 위한 적외선 제어장치 소스. 
 * IRremote: IRsendRawDemo를 기반으로 하여 WIFI를 연결, 발전시킬 계획임.
 * Version 0.1 2016.08.25(목) 시작 ~ 
 * IR LED가 3번핀에 연결되어 있어야 함
 * 
 */


#include <IRremote.h>

IRsend irsend;

void setup()
{
    pinMode(13, OUTPUT);
}

void loop() {
  int khz = 38; // 38kHz carrier frequency for the NEC protocol
  // send beam alram
      digitalWrite(13, HIGH);  
  // for EPSON Projector
    unsigned int irSignal[] = {2300,550, 550,550, 1200,550, 550,600, 550,1150, 550,1150, 600,550, 600,550, 550,600, 550,550, 600,550, 600,550, 600,550, 600,550, 550};
  // for SAMSUNG TV
    //unsigned int irSignal[] = {4400,4400, 550,1650, 550,1650, 600,1600, 600,550, 550,550, 550,550, 550,500, 600,550, 550,1650, 550,1650, 550,1650, 600,500, 600,500, 600,500, 600,500, 600,500, 600,550, 550,1650, 550,550, 550,550, 550,550, 550,550, 600,550, 550,500, 600,1600, 600,500, 600,1650, 550,1650, 550,1650, 550,1650, 600,1600, 600,1600, 600};
    
    irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.  
    delay(40);
    digitalWrite(13, LOW);
  delay(2000); //In this example, the signal will be repeated every 5 seconds, approximately.
}
