// Reconstructed 2026-10-23. New pin map; not the lost original firmware.
#include <Arduino.h>
#if defined(ESP32)
const int SENSOR=34, INPUT_A=27, INPUT_B=14, OUT=26, AUX=25;
const int ADC_MAXIMUM=4095;
#else
const int SENSOR=A0, INPUT_A=2, INPUT_B=3, OUT=8, AUX=9;
const int ADC_MAXIMUM=1023;
#endif
// OUT/AUX drive a transistor/module input, never an inductive load directly.
// Default OFF = LOW. Use a compatible active-HIGH driver for this reconstruction.

unsigned long last=0,highSince=0;bool tracking=false,alarmActive=false;
const unsigned long WARMUP_MS=60000; // Bench demo only: follow exact module conditioning requirements.
void setup(){Serial.begin(115200);pinMode(OUT,OUTPUT);pinMode(AUX,OUTPUT);digitalWrite(OUT,LOW);digitalWrite(AUX,LOW);}
void loop(){unsigned long now=millis();if(now-last<100)return;last=now;
 int raw=analogRead(SENSOR);bool fault=raw<=3||raw>=ADC_MAXIMUM-3;
 if(now<WARMUP_MS||fault){alarmActive=false;tracking=false;}
 else if(raw>=ADC_MAXIMUM*6/10){if(!tracking){highSince=now;tracking=true;}if(now-highSince>=2000)alarmActive=true;}
 else if(raw<=ADC_MAXIMUM*4/10){alarmActive=false;tracking=false;}else tracking=false;
 digitalWrite(OUT,alarmActive?HIGH:LOW);digitalWrite(AUX,fault?HIGH:LOW);
 Serial.print(raw);Serial.print(',');Serial.print(alarmActive);Serial.print(',');Serial.println(fault);
}
