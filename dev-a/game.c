// MT MK2 NES v0.85 - Snotty Mucosity version.
// Copyleft 2017 by The Mojon Twins

//#define STANDALONE	// Comment when assembling to main ROM.

// Shiru's

#include "neslib.h"

// Some needed stuff...

#include "definitions.h"

// Main const includes

#include "assets/palettes.h"
#include "assets/precalcs.h"
#include "assets/enems0.h"
#include "assets/map0.h"
#include "assets/enems1.h"
#include "assets/map1.h"
#include "assets/enems2.h"
#include "assets/map2.h"
//#include "assets/enems3.h"
//#include "assets/map3.h"
#include "assets/tiledata.h"
#include "assets/metasprites.h"
#include "assets/behs.h"
#include "assets/levelset.h"
// #include "assets/texts.h"
// #include "assets/script_texts.h"
// #include "assets/talk_scripts.h"
#ifdef LANG_ES
#include "assets/dialogue_es.h"
#else
#include "assets/dialogue.h"
#endif
#include "assets/title_rle.h"
#include "assets/hud_rle.h"
#include "assets/ending_rle.h"

/*
#include "assets/spritedata_menu.h"
#include "assets/menu-frame_rle.h"
*/

// Some variables

#pragma bss-name (push,"ZEROPAGE")
#pragma data-name(push,"ZEROPAGE")

#include "ram/zp.h"

#pragma bss-name (push,"BSS")
#pragma data-name(push,"BSS")

#include "ram/bss.h"

// Engine functions

#include "someprotos.h"
#include "engine/printer.h"
#include "engine/screens.h"
#include "engine/general.h"
#ifdef ENABLE_SPRINGS
#include "engine/spring.h"
#endif
#ifdef ENABLE_PROPELLERS
#include "engine/propellers.h"
#endif
#ifdef ENABLE_ESTRUJATORS
#include "engine/estrujators.h"
#endif
#ifdef ENABLE_CATARACTS
#include "engine/cataracts.h"
#endif
#ifdef SCRIPTING_ON
#ifdef ENABLE_EXTERN_CODE
#include "engine/extern.h"
#endif
#include "engine/mscnes.h"
#endif
#ifdef SHOOTING_DRAINS
#include "engine/flower.h"
#endif
#ifdef BREAKABLE_WALLS
#include "engine/breakable.h"
#endif
#ifdef PLAYER_CAN_FIRE
#include "engine/bullets.h"
#endif
#ifndef DISABLE_HOTSPOTS
#include "engine/hotspots.h"
#endif
#ifdef HOTSPOT_TYPE_KEY
#include "engine/bolts.h"
#endif
#ifdef ENABLE_FUMETTOS
#include "engine/fumettos.h"
#endif
#ifdef ENABLE_PUAS
#include "engine/puas.h"
#endif
// CUSTOM {
#include "engine/heart.h"
// } END_OF_CUSTOM
#include "engine/hud.h"
#ifdef ENABLE_CONTAINERS
#include "engine/containers.h"
#endif
#ifdef ENABLE_FABOLEES
#include "engine/fabolee_int.h"
#endif
#include "engine/player.h"
#ifdef ENABLE_COCOS
#include "engine/simplecoco.h"
#endif
#include "engine/enems.h"
#include "engine/mapper11.h"
#include "engine/talkbox.h"
#include "engine/game.h"

#ifndef STANDALONE
/*#include "menustuff.h"*/
#endif

// Functions

#ifndef STANDALONE
void autosave_game (void) {
	COMM_STATS_INITIAL_PLIFE = plife;
}

void jump_roms (void) {
	COMM_STATS_LEVEL = level;
	COMM_STATS_LIVES = plife;
	COMM_GAME_SIGNATURE = 0x66;
	COMM_CHECKSUM = 0xff;
	m11_switch_raw (2);
}
#endif

void main (void) {

	bank_bg (0);
	bank_spr (1);
			
	ticks = ppu_system () ? 60 : 50;
	halfticks = ticks >> 1;

	oam_size (0);
	pal_bright (0);

	scroll (0, SCROLL_Y);

#ifndef STANDALONE
	// First check for game status
	if (COMM_GAME_SIGNATURE == 0x66 && COMM_CHECKSUM == 0xff) {
		COMM_GAME_SIGNATURE = 0; COMM_CHECKSUM = 1;
		//COMM_POOL[0xe] = 0; COMM_POOL[0xf] = 1;
		plife = COMM_STATS_LIVES;
		level = COMM_STATS_LEVEL;
		if (COMM_STATS_STATUS == GAME_STATUS_GAME_OVER) goto game_over;
		if (COMM_STATS_STATUS == GAME_STATUS_WIN_LEVEL) goto game_new_level;
	}
#ifndef GNROM
	m11_handle_reset ();		// If bad checksum, this jumps to PRG 0 / CHR 0 (main menu)
#endif
#endif

	first_game = 1;

	// Run the game here.
	while (1) {
		// level & initial_plife are set here:
		game_title ();	
		first_game = 0;

		//rdb = 0xfc; game_event ();

		plife = COMM_STATS_INITIAL_PLIFE;
		win_game = 0;

		while (1) {
#ifndef STANDALONE			
			autosave_game ();
#endif			

			if (level < 3) {
				hud_draw ();
				game_init ();
				game_loop ();
			} else {
#ifndef STANDALONE				
				jump_roms (); 
#else
				win_game = 1; break;
#endif				
			}
			
			if (pkilled) break;

			rdb = 0xfd; game_event ();
			
#ifndef STANDALONE			
game_new_level:
#endif
			level ++;
			plife ++;
			delay (10);

#ifndef STANDALONE	
			if (level == 7) {
				win_game = 1;
				break;
			}
#endif
			
		}
#ifndef STANDALONE
game_over:
#endif
		if (win_game) {
			game_ending ();
		} else {
			rdb = 0xfe; game_event ();
		}
	}
}
