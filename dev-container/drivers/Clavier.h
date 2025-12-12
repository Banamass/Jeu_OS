#ifndef CLAVIER_H
#define CLAVIER_H

#include "../drivers/Ecran.h"
#include "../hal/fonctionsES.h"
/**
 * @file Clavier.h
 * @class Clavier
 * @brief Permet la récupération des caractères saisis au clavier.
 */

namespace AZERTY {
	enum scancodes {
		K_ESC = 1,
		K_1, K_2, K_3, K_4, K_5, K_6, K_7, K_8, K_9, K_0, K_OEM_4, K_OEM_PLUS, K_BACK, K_TAB,
		K_A, K_Z, K_E, K_R, K_T, K_Y, K_U, K_I, K_O, K_P, K_OEM_6, K_OEM_1, K_RETURN, K_LCONTROL, K_Q, K_S,
		K_D, K_F, K_G, K_H, K_J, K_K, K_L, K_M, K_OEM_3, K_OEM_7, K_LSHIFT, K_OEM_5, K_W, K_X, K_C, K_V,
		K_B, K_N, K_OEM_COMMA, K_OEM_PERIOD, K_OEM_2, K_OEM_8, K_RSHIFT, K_MULTIPLY, K_LALT, K_SPACE, K_CAPITAL, K_F1, K_F2, K_F3, K_F4, K_F5,
		K_F6, K_F7, K_F8, K_F9, K_F10, K_NUMLOCK, K_SCROLL, K_KP_7, K_KP_8, K_KP_9, K_KP_MINUS, K_KP_4, K_KP_5, K_KP_6, K_KP_PLUS, K_KP_1,
		K_KP_2, K_KP_3, K_KP_0, K_KP_DOT,
		K_F11 = 0x57,
		K_F12
	};
	
} // namespace AZERTY

namespace QWERTY {
	enum scancodes {
		K_ESC = 1,
		K_1, K_2, K_3, K_4, K_5, K_6, K_7, K_8, K_9, K_0, K_OEM_MINUS, K_OEM_PLUS, K_BACK, K_TAB,
		K_Q, K_W, K_E, K_R, K_T, K_Y, K_U, K_I, K_O, K_P, K_OEM_4, K_OEM_6, K_RETURN, K_LCONTROL, K_A, K_S,
		K_D, K_F, K_G, K_H, K_J, K_K, K_L, K_OEM_1, K_OEM_7, K_OEM_3, K_LSHIFT, K_OEM_5, K_Z, K_X, K_C, K_V,
		K_B, K_N, K_M, K_OEM_COMMA, K_OEM_PERIOD, K_OEM_2, K_RSHIFT, K_MULTIPLY, K_LALT, K_SPACE, K_CAPITAL, K_F1, K_F2, K_F3, K_F4, K_F5,
		K_F6, K_F7, K_F8, K_F9, K_F10, K_NUMLOCK, K_SCROLL, K_KP_7, K_KP_8, K_KP_9, K_KP_MINUS, K_KP_4, K_KP_5, K_KP_6, K_KP_PLUS, K_KP_1,
		K_KP_2, K_KP_3, K_KP_0, K_KP_DOT,
		K_F11 = 0x57,
		K_F12
	};
}

class Clavier {
public:
	/***
	 * Recupere le premier caractere tape.
	 ***/
	char getchar();
	/***
	 * Recupere tous les caracteres tapes.
	 ***/
	char* getString();
	/***
	 * Verifie s'il y a au moins un caractere qui a ete tape.
	 ***/
	bool testChar();

	void set_leds(void);

	bool is_pressed(ui8_t s);
	bool is_pressed_then_deleted(ui8_t s);
};

#endif
