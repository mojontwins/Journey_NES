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
#include "assets/enems3.h"
#include "assets/map3.h"
#include "assets/enems4.h"
#include "assets/map4.h"
#include "assets/enems5.h"
#include "assets/map5.h"
#include "assets/enems6.h"
#include "assets/map6.h"
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
#include "assets/hud_rle.h"

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
#include "engine/particles.h"
#include "engine/random_connection.h"
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

// Functions

void main (void) {

#ifndef STANDALONE
	//pal_col(0,0);pal_bright(4);while (1)ppu_wait_nmi ();
	if (COMM_GAME_SIGNATURE == 0x66 && COMM_CHECKSUM == 0xff) {
		//COMM_GAME_SIGNATURE = 0; COMM_CHECKSUM = 1;
		COMM_POOL[0xe] = 0; COMM_POOL[0xf] = 1;
	} else 
#ifdef GNROM
	{
		COMM_GAME_SELECT = 0x00; COMM_REG = 0x00; 
		__asm__ ("jmp _change_rom");	
	}
#else
	m11_handle_reset ();		// If bad checksum, this jumps to PRG 0 / CHR 0 (main menu)
#endif
#endif	

	bank_bg (0);
	bank_spr (1);
			
	ticks = ppu_system () ? 60 : 50;
	halfticks = ticks >> 1;

	oam_size (0);
	pal_bright (0);

	scroll (0, SCROLL_Y);

	// CUSTOM {
	pal_cycle [0] = 0x19;
	pal_cycle [1] = 0x29;
	pal_cycle [2] = 0x28;
	// } END_OF_CUSTOM
	
	// Run the game here.

	while (1) {
#ifndef STANDALONE	
		level = COMM_STATS_LEVEL - FIRST_LEVEL;
		plife = COMM_STATS_LIVES;
#else
		level = 3;
		plife = LIFE_INI;
#endif	

		hud_draw ();
		game_init ();
		game_loop ();

		// Todo: Back to main rom (full integration).

		COMM_STATS_LEVEL = level + FIRST_LEVEL;
		
		if (pkilled) {
			COMM_STATS_STATUS = GAME_STATUS_GAME_OVER;
		} else {
			rdb = 0xfd; game_event ();
			COMM_STATS_STATUS = GAME_STATUS_WIN_LEVEL;
			COMM_STATS_LIVES = plife;
		}
		m11_switch_raw (1);
	}

}
