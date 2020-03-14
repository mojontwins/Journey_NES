// MT MK2 NES v0.85 - Snotty Mucosity version.
// Copyleft 2017 by The Mojon Twins

// Code for fixed screens

void enter_screen (const unsigned char *pal, void (*func) (void)) {
	//scroll (0, 472);
	cls ();
	
	pal_bg (pal);
	if (func) (*func) ();
	
	ppu_on_all ();
	fade_in ();
}

void exit_cleanly (void) {
	oam_hide_rest (0);
	music_stop ();
	fade_out ();
	ppu_off ();	
}

void wait_time_or_input (void) {
	rda = (pad_poll (0) != 0);
	while (game_time) {
		ticker ++; if (ticker == ticks) {
			ticker = 0;
			game_time --;
		}

		if (pad_poll (0)) {
			if (!rda) break;
		} else {
			rda = 0;
		}

		ppu_wait_nmi ();
	}
}

void do_screen (unsigned char seconds) {
	game_time = seconds; ticker = 0;
	wait_time_or_input ();
	exit_cleanly ();
}

void screen_title (void) {
	vram_adr (NAMETABLE_A);
	vram_unrle (title_rle);
	p_s (10, 4, "MOJON_TWINS'");
	if (first_game) {
#ifdef LANG_ES
		p_s (10, 24, "PULSA_START!");
#else
		p_s (10, 24, "PRESS_START!");
#endif		
	} else {
#ifdef LANG_ES		
		p_s (3, 23, "PULSA_[START]__Y_REINICIA");
		p_s (3, 25, "PULSA_[SELECT]_Y_CONTINUA");
#else
		p_s (3, 23, "PRESS_[START]__TO_BEGIN");
		p_s (3, 25, "PRESS_[SELECT]_TO_CONTINUE");
#endif		
	}
}

/*
void screen_game_over (void) {
}

void screen_game_ending (void) {
}
*/

void screen_event (void) {
	switch (rdb) {
		/*
		case 0xfc:
			// Cutscene
			//vram_adr (NAMETABLE_A);
			//vram_unrle (event_rle);
			break;
		*/

		case 0xfd:
			// Stage clear
#ifdef LANG_ES
			p_s (8, 15, "FASE_COMPLETADA!");
#else		
			p_s (10, 15, "STAGE_CLEAR!");
#endif
			break;

		case 0xfe:
			// Game over
			p_s (11, 15, "GAME_OVER!");
			break;

		case 0xff:
			// Ending
			vram_adr (NAMETABLE_A);
			vram_unrle (ending_rle);
			break;
	}
}
