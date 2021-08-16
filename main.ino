
#pragma GCC push_options
#pragma GCC optimize ("Os")
#include <SPI.h> // Required by MAX31865_RTD1
#include <Adafruit_MAX31865.h>
#include <SerialTerminal.h>


Adafruit_MAX31865 MAX31865_RTD1 = Adafruit_MAX31865 (10);
Adafruit_MAX31865 MAX31865_RTD2 = Adafruit_MAX31865 (9);
Adafruit_MAX31865 MAX31865_RTD3 = Adafruit_MAX31865 (8);
SerialTerminal VT1 = SerialTerminal ();
#define RREF 430.0
#define RNOMINAL 100.0

void peripheral_setup () {
Serial.begin (9600);

MAX31865_RTD1.begin(MAX31865_4WIRE); // set to 2WIRE or 4WIRE as necessary
MAX31865_RTD2.begin(MAX31865_4WIRE); // set to 2WIRE or 4WIRE as necessary
MAX31865_RTD3.begin(MAX31865_4WIRE); // set to 2WIRE or 4WIRE as necessary

}

void peripheral_loop() {

}
// Flowchart Variables
float a;
float b;
float c;
float ratio_a;
float ratio_b;
float ratio_c;
float rtd_a;
float rtd_b;
float rtd_c;

// Flowchart Routines

void chart_SETUP() {

}

void chart_LOOP() {
  
rtd_a = MAX31865_RTD1.readRTD();
Serial.print("RTD 1 value: "); Serial.println(rtd_a);
ratio_a = rtd_a;
ratio_a /= 32768;
Serial.print("Ratio RT_1 = "); Serial.println(ratio_a,8);
Serial.print("Resistance RT_1 = "); Serial.println(RREF*ratio_a,3); Serial.print(" Ohms");
Serial.print("Temperature RT_1 = "); Serial.println(MAX31865_RTD1.temperature(RNOMINAL, RREF));Serial.print("°C\r");
delay (500);


rtd_b = MAX31865_RTD2.readRTD();
Serial.print("RTD 2 value: "); Serial.println(rtd_b);
ratio_b = rtd_b;
ratio_b /= 32768;
Serial.print("Ratio RT_2 = "); Serial.println(ratio_b,8);
Serial.print("Resistance  RT_2 = "); Serial.println(RREF*ratio_b,8); Serial.print(" Ohms");
Serial.print("Temperature RT_2 = "); Serial.println(MAX31865_RTD2.temperature(RNOMINAL, RREF)); Serial.print("°C\r");
delay (500);


rtd_c = MAX31865_RTD3.readRTD();
Serial.print("RTD 3 value: "); Serial.println(rtd_c);
ratio_c = rtd_c;
ratio_c /= 32768;
Serial.print("Ratio RT_3= "); Serial.println(ratio_c,8);
Serial.print("Resistance RT_3 = "); Serial.println(RREF*ratio_c,8); Serial.println(" Ohms");
Serial.print("Temperature RT_3 = "); Serial.println(MAX31865_RTD3.temperature(RNOMINAL, RREF));Serial.println("°C\r");
delay (500);

}



void setup () { peripheral_setup(); chart_SETUP(); }
void loop () { peripheral_loop(); chart_LOOP(); }
