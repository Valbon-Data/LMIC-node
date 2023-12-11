/*******************************************************************************
 *
 *  Simplified LMIC-node main application file.
 *
 ******************************************************************************/

#include "LMIC-node.h"

const uint8_t payloadBufferLength = 4;
uint8_t payloadBuffer[payloadBufferLength];
static osjob_t doWorkJob;
uint32_t doWorkIntervalSeconds = DO_WORK_INTERVAL_SECONDS;

#ifdef OTAA_ACTIVATION
    static const u1_t PROGMEM DEVEUI[8]  = { OTAA_DEVEUI } ;
    static const u1_t PROGMEM APPEUI[8]  = { OTAA_APPEUI };
    static const u1_t PROGMEM APPKEY[16] = { OTAA_APPKEY };
    // Below callbacks are used by LMIC for reading above values.
    void os_getDevEui (u1_t* buf) { memcpy_P(buf, DEVEUI, 8); }
    void os_getArtEui (u1_t* buf) { memcpy_P(buf, APPEUI, 8); }
    void os_getDevKey (u1_t* buf) { memcpy_P(buf, APPKEY, 16); }  
#endif

void setup() 
{

    initDisplay();
    // #ifdef USE_DISPLAY 
    //     initDisplay();
    // #endif

    display.print("Hello World!");
}

void loop() {
    os_runloop_once();
}
