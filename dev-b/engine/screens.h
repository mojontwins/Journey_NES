// MT MK2 NES v0.85 - Snotty Mucosity version.
// Copyleft 2017 by The Mojon Twins

// Code for fixed screens

void enter_screen (const unsigned char *pal, void (*func) (void)) {
	//scroll (0, 472);
	
	cls ();
	
	pal_bg (pal);
	(*func) ();
	
	ppu_on_all ();
	fade_in ();
}

void exit_cleanly (void) {
	//set_vram_update (0);
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

/*
void screen_title (void) {
	// vram_adr (NAMETABLE_A);
	// vram_unrle (title_rle);
}
*/

/*
void screen_game_over (void) {
}

void screen_game_ending (void) {
}
*/

void screen_event (void) {
	cls ();
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

		/*
		case 0xfe:
			// Game over
			break;
		*/

		/*
		case 0xff:
			// Ending
			vram_adr (NAMETABLE_A);
			vram_unrle (ending_rle);
			break;
		*/
	}
}
