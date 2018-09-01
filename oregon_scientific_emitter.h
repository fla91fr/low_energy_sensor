#ifndef __OREGON_SCIENTIFIC_EMITTER_H__
#define __OREGON_SCIENTIFIC_EMITTER_H__

#include <Arduino.h>
#include "configuration.h"

// Data Transmission Pin (RF 433)
// PB4 == Pin 3 on ATtiny85
#define SEND_HIGH()    (PORTB |=  (1 << PORTB4))
#define SEND_LOW()     (PORTB &= ~(1 << PORTB4))

#ifndef MODE
#define MODE 2
#endif

#if MODE == 0
#define MESSAGE_BUF_LEN   8
#elif MODE == 1
#define MESSAGE_BUF_LEN   9
#else
#define MESSAGE_BUF_LEN  11
#endif

// Buffer for Oregon message
extern byte OregonMessageBuffer[MESSAGE_BUF_LEN];

const unsigned long TIME = 512;
const unsigned long TWOTIME = TIME*2;

void oregon_init();
void oregon_set_battery_level(byte level, byte* data = OregonMessageBuffer);
void oregon_set_temperature(float temp, byte* data = OregonMessageBuffer);
void oregon_set_humidity(byte hum, byte* data = OregonMessageBuffer);
void oregon_set_pressure(float pres, byte *data = OregonMessageBuffer);
void oregon_send_message(byte* data = OregonMessageBuffer, byte size = MESSAGE_BUF_LEN);

#endif
