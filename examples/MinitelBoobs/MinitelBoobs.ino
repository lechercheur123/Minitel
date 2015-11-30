/**
 * Minitel library for Arduino (v0.1) / May 2013
 * http://github.com/01010101/Minitel
 *
 * By Jerome Saint-Clair aka 01010101
 * http://saint-clair.net
 * 
 * For the Graffiti Research Lab France
 * http://graffitiresearchlab.fr
 * 
 * Based on works by the Tetalab (Fabrice, Renaud, PG & Phil)
 * http://tetalab.org
 */
 
#include <SoftwareSerial.h>
#include <Minitel.h>

Minitel m;

byte c[]={127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,48,111,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,125,50,111,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,125,50,111,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,125,50,111,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,116,43,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,117,50,111,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,116,35,111,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,125,112,43,111,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,125,112,107,127,63,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,106,127,53,127,127,127,127,127,127,127,127,127,127,127,59,111,127,127,127,127,127,127,32,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,53,122,127,117,107,127,127,127,127,127,127,127,127,109,127,127,106,127,127,127,127,127,127,96,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,101,127,127,127,58,127,127,127,127,127,127,127,127,42,47,97,126,127,127,127,127,127,55,106,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,63,122,127,127,127,117,111,127,127,127,127,127,127,127,127,126,127,127,127,127,127,127,127,101,42,127,127,127,127,127,127,127,127,127,127,127,127,127,127,63,120,127,127,127,127,127,50,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,55,122,117,43,127,127,127,127,127,127,127,127,127,127,127,127,63,120,127,127,127,127,127,127,127,50,111,127,127,127,127,127,127,127,127,127,127,127,127,63,120,127,127,117,43,127,127,127,127,127,127,127,127,127,63,103,126,127,127,127,127,127,127,127,127,127,118,47,127,127,127,127,127,127,127,127,127,127,103,126,127,127,127,127,125,118,59,47,47,47,47,47,111,115,124,127,127,127,127,127,127,127,127,127,127,127,127,125,114,47,127,127,127,127,127,63,111,120,127,127,127,127,127,127,127,127,127,127,124,124,126,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,124,116,115,115,124,126,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127};


void setup() {
}

void loop() {
  m.graphicMode();
  m.clearScreen();
  
  for (int i=0; i< sizeof(c); i++) {
    m.textByte(c[i]);
  }
  delay(10000);
} 
