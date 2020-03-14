// MT MK2 NES v0.85 - Snotty Mucosity version.
// Copyleft 2017 by The Mojon Twins

// Metaspritesets (in nice arrays)

#include "assets/spritedata.h"

// Of course, you have to somewhat customize this for every game and make it fit.

// Rock the Kashbah
const unsigned char * const spr_enems_0 [] = {
	ssen_1_00_a, ssen_1_01_a, ssen_1_00_b, ssen_1_01_b, 
	ssen_1_02_a, ssen_1_03_a, ssen_1_02_b, ssen_1_03_b, 
	ssen_1_04_a, ssen_1_05_a, ssen_1_04_b, ssen_1_05_b, 
	ssmp_00, ssmp_01, ssmp_00, ssmp_01,
	ssen_1_06_a, ssen_1_07_a, ssen_1_06_b, ssen_1_07_b, 
	ssen_1_08_a, ssen_1_09_a, ssen_1_08_b, ssen_1_09_b, 
	ssen_2_00, ssen_2_01, ssen_2_00, ssen_2_01,

	// 28
	ssvira_00, ssvira_01, ssvira_02, ssvira_03, ssvira_04, ssvira_05
};

// RIGHT, LEFT x IDLE, W1 W2 W3 W4, UP, DOWN
const unsigned char * const spr_player_0 [] = {
	sspl_00_a, 
	sspl_01_a, sspl_02_a, sspl_03_a, sspl_04_a, 
	sspl_05_a, sspl_06_a, 
	sspl_07_a, sspl_08_a, 
	sspl_09_a, sspl_0A_a, sspl_0B_a, sspl_0A_a,   // RIGHT

	sspl_00_b, 
	sspl_01_b, sspl_02_b, sspl_03_b, sspl_04_b, 
	sspl_05_b, sspl_06_b, 
	sspl_07_b, sspl_08_b, 
	sspl_09_b, sspl_0A_b, sspl_0B_b, sspl_0A_b,   // LEFT

	// Reborde
	ssrb_00_a, 
	ssrb_01_a, ssrb_02_a, ssrb_03_a, ssrb_04_a, 
	ssrb_05_a, ssrb_06_a, 
	ssrb_07_a, ssrb_08_a, 
	ssrb_09_a, ssrb_0A_a, ssrb_0B_a,ssrb_0A_a,   // RIGHT

	ssrb_00_b, 
	ssrb_01_b, ssrb_02_b, ssrb_03_b, ssrb_04_b, 
	ssrb_05_b, ssrb_06_b, 
	ssrb_07_b, ssrb_08_b, 
	ssrb_09_b, ssrb_0A_b, ssrb_0B_b, ssrb_0A_b   // LEFT
};

// Items 
const unsigned char * const spr_items [] = {
//     object   key      refill   relay
	0, ssit_00, ssit_01, ssit_02, ssit_04
};

// FUCK

const unsigned char sprplempty [] = {
	-4, -8, 0, 0, 4, -8, 0, 0, 
	-4, 0, 0, 0, 4, 0, 0, 0, 
	-4, 8, 0, 0, 4, 8, 0, 0, 
	0x80
};

// CUSTOM {
const unsigned char * const spr_cuts [] = {
	sscuts_00, sscuts_01
};
// } END_OF_CUSTOM
