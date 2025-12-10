#include "Clavier.h"

extern bool modifBuf;
extern char buf[256];
extern int posBuf;
extern bool key_pressed[126];

bool Clavier::testChar() {//Retourne vrai si un caract�re a �t� saisi au clavier
	return modifBuf;
}

char Clavier::getchar(){
	while(!modifBuf);
	modifBuf = false;
	posBuf = 0;
	return buf[0];
}

char* Clavier::getString(){
	while(!modifBuf);
	modifBuf = false;
	posBuf = 0;
	return buf;
}

void Clavier::set_leds(void) {
	ecrireOctet(0x60, 0xED);
}

bool Clavier::is_pressed(ui8_t sc) { 
	return key_pressed[sc];
}

bool Clavier::is_pressed_then_deleted(ui8_t sc) { 
	bool pressed = key_pressed[sc];
	key_pressed[sc] = false;
	return pressed;
}
