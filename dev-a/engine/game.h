// MT MK2 NES v0.85 - Snotty Mucosity version.
// Copyleft 2017 by The Mojon Twins

// Game loop & shit

#ifdef SCRIPTING_ON
void game_run_fire_script (void) {
	run_script (2 * MAX_PANTS + 2);		// Press fire in any room.
	run_script (n_pant + n_pant + 1);		// Press fire in current room.
}
#endif

void game_init (void) {
	// This makes my life easier
	// gp_gen = scr_attr + 192; gpit = 16; while (gpit --) *gp_gen = 0;
	// Deprecating this...

	// Multiple level support (pseudo custom)
	// Some things are hardcoded for some games.

	c_ts_pals = l_ts_pals [level];
	c_ts_tmaps = l_ts_tmaps [level];
	c_behs = l_behs [level];
	c_map = l_map [level];
	//c_decos = l_decos [level];
	c_enems = l_enems [level];
	c_hotspots = l_hotspots [level];
	c_locks = l_locks [level];
	max_hotspots_type_1 = l_max_hotspots_type_1 [level];
	spr_enems = spr_enems_0; // l_spr_enems [level];
	spr_player = spr_player_0; // l_spr_player [level];

	// Scalar types dealt with together
	// This produces better code.
	map_w = l_map_w [level];
	n_pant = l_scr_ini [level];

	pal_bg (l_pal_bgs [level]);
	pal_spr (l_pal_fgs [level]);

	// c_pal_bg = l_pal_bgs [level];

#if defined(ENEMIES_CAN_DIE) && defined(PERSISTENT_DEATHS)
	enems_persistent_deaths_init ();
#endif	

#ifdef PERSISTENT_ENEMIES
	persistent_enems_load ();
#endif

#ifdef HOTSPOT_TYPE_KEY
	bolts_load ();
#endif

	player_init ();

#ifndef DISABLE_HOTSPOTS	
	hotspots_ini ();
#endif	

	// Scripting / flags stuff

#ifdef COUNT_KILLED_ON_FLAG
	flags [COUNT_KILLED_ON_FLAG] = 0;
#endif

#ifdef ONLY_ONE_OBJECT_FLAG
	flags [ONLY_ONE_OBJECT_FLAG] = 0;
#endif

#ifdef PLAYER_INV_FLAG
	flags [PLAYER_INV_FLAG] = 0;
#endif

#ifdef SCRIPTING_ON
	// Script init
	script_pool = level_scripts [level];
#endif

	// Game values (lifes, etc)

	// plife = LIFE_INI /*l_plife [level]*/; 
	oplife = 0xff;
	pobjs = 0; opobjs = 0xff;
	pbodycount = 0; opbodycount = 0xff;
	pkeys = 0; opkeys = 0xff;
	//pammo = AMMO_MAX; opammo = 0x0ff;

	// CUSTOM {
	do_initial_dialogue = 1;
	mission_done = (level == 0);	// Unreadable tomorrow.
	// END_OF_CUSTOM

	// The almighty debug line!

	//n_pant = 7; pobjs = 4; pkeys = 5;
}

void game_prepare_screen (void) {
	no_ct = 0;
	update_list [0] = NT_UPD_EOF;
	ppu_wait_nmi ();

	if (first_time) first_time = 0; else fade_out ();
	ppu_off ();

#ifdef ENABLE_SPRINGS
	springs_idx = 0;
#endif

#ifdef ENABLE_PROPELLERS
	propellers_idx = 0;
#endif

#if defined (ENABLE_ESTRUJATORS) || defined (ENABLE_CATARACTS)
	est_ini_delay = est_idx = 0;
#endif	

#ifdef ENABLE_CATARACTS
	cataracts_on = 0;
#endif

	draw_scr ();

#ifdef ENABLE_FUMETTOS
	fumettos_init ();
#endif

#ifdef HOTSPOT_TYPE_KEY
	bolts_update_screen ();
#endif

#ifdef ENABLE_PUAS
	puas_init ();
#endif	

#ifdef PLAYER_CAN_FIRE	
	bullets_ini ();
#endif

#ifdef SHOOTING_DRAINS	
	flower_ini ();
#endif

#ifdef PERSISTENT_ENEMIES
	persistent_update ();
#endif	

#ifdef BREAKABLE_WALLS
	breakable_init ();
#endif

	enems_load ();

#ifndef DISABLE_HOTSPOTS	
	hotspots_load ();
#endif

#ifdef SHOOTING_DRAINS		
	pgauge = 30; bullets_draw_gauge_offline ();
#endif

#ifdef ENABLE_COCOS	
	simplecoco_init ();
#endif

#ifdef ENABLE_FABOLEES
	fabolee_init ();
#endif

	show_attributes ();

	ppu_on_all ();

	oam_index = 44;
	prx = px >> FIX_BITS; pry = py >> FIX_BITS;
	player_render ();

// CUSTOM {
	player_border ();
// } END_OF_CUSTOM

#ifndef DISABLE_HOTSPOTS	
	hotspots_do ();
#endif	

	enems_do ();

	oam_hide_rest (oam_index);
	ul = update_list; 
	hud_update (); 
	close_update_cycle ();

#ifdef ENABLE_CONTAINERS
	c_idx = 0;
#endif

#ifdef SCRIPTING_ON
	run_script (2 * MAX_PANTS + 1);		// Entering any script
	run_script (n_pant + n_pant);			// Entering this room script
#endif

#ifdef ENABLE_HOLES
	player_register_safe_spot ();
#endif

	// CUSTOM {
	hearts_init ();
	// } END_OF_CUSTOM	

	fade_in ();

	// CUSTOM {
	if (do_initial_dialogue) {
		rda = level; run_talk_script ();
		do_initial_dialogue = 0;
	}
	relay_not_activated_yet = 1;
	// END_OF_CUSTOM
}

void game_loop (void) {
	half_life = 0;
	first_time = 1;
	on_pant = 99;

	// scroll (0, SCROLL_Y);
	// reset_attributes ();
	// gpit = 8; while (gpit --) attr_table [gpit] = 0x55;
	
	ppu_on_all ();

	music_play (level_musics [level]);
	// CUSTOM {
	music_pause (1);
	// } END_OF_CUSTOM

	set_vram_update (update_list);
	do_game = 1;
	pwashit = 0; 
	pcharacter = 0;

	// Entering Game
#ifdef SCRIPTING_ON
#ifdef CLEAR_FLAGS
	msc_clear_flags ();
#endif
	script_result = 0;
	// Entering game script
	run_script (2 * MAX_PANTS);
#endif

	paused = 0; update_list [0] = NT_UPD_EOF;

	while (do_game) {

		//*((unsigned char*)0x2001) = 0x1e;
		ppu_wait_frame ();
		//*((unsigned char*)0x2001) = 0x1f;

		half_life = 1 - half_life;		// Main flip-flop
		frame_counter ++;				// Increase frame counter
		//if (ticker) ticker --; else ticker = ticks;
	
		pad_read ();		

		if (pwashit) player_hit ();

		// Press Fire At
#ifdef SCRIPTING_ON
		if (f_zone_ac) {
			if (pry >= fzy1 && pry <= fzy2)
				if (prx >= fzx1 && prx <= fzx2)
					game_run_fire_script ();
		}
#endif

		if (pad_this_frame & PAD_START) {
			paused = !paused;
			if (paused) pal_bright (3); else pal_bright (4);
			music_pause (paused);
			sfx_play (0, SC_LEVEL);
		}

		if (pkilled 
			|| (pobjs == max_hotspots_type_1 && mission_done)
			|| ((pad0 & (PAD_SELECT | PAD_B)) == (PAD_SELECT | PAD_B))
		) do_game = 0;
			
		#include "engine/mainloop/flick_screen.h"

		/*
		if (pkilled 
#ifdef SCRIPTING_ON			
			|| script_result == 1
#endif			
		) do_game = 0;
		*/

		/*
		if (pkilled 
			|| pbodycount == l_max_killable_enems [level]
		) do_game = 0;
		*/

		if (!paused) {
			ul = update_list;				// Reset pointer to update list
			oam_index = 44;					// Reset OAM index; skip sprite #0 & player
		
			pgotten = pgtmx = pgtmy = 0;

#ifdef ENABLE_PUAS
			puas_do ();
#endif
#ifdef PLAYER_CAN_FIRE
			bullets_do ();
#endif
#ifndef DISABLE_HOTSPOTS		
			hotspots_do ();
#endif		
#ifdef ENABLE_FABOLEES
			fabolee_do ();
#endif

			enems_do ();
		
#ifdef ENABLE_COCOS		
			simplecoco_do ();
#endif		
#ifdef SHOOTING_DRAINS			
			flower_do ();
#endif
#ifdef BREAKABLE_WALLS
			breakable_do ();
#endif		

			// If both active, cataracts and estrujators are exclusive
#ifdef ENABLE_CATARACTS
			if (cataracts_on) cataracts_do ();
#ifdef ENABLE_ESTRUJATORS
			else
#endif
#endif
#ifdef ENABLE_ESTRUJATORS
			estrujators_do ();
#endif

			player_move ();	
			if (n_pant == on_pant) player_render ();
			//if (pwashit) player_hit ();

			// CUSTOM {
			if (hrt && half_life && (hrt != 4 || pobjs == max_hotspots_type_1)) oam_index = oam_meta_spr (hrx, hry + SPRITE_ADJUST, oam_index, ssit_03);
			player_border ();
			hearts_move ();
			if (pwater && 0 == (frame_counter & 0x3f)) hearts_create ();
			// } END_OF_CUSTOM

#ifdef ENABLE_FUMETTOS
			fumettos_do ();
#endif
#ifdef ENABLE_CONTAINERS
			containers_draw ();
#endif
#ifdef ENABLE_SPRINGS
			if (springs_idx) springs_do ();
#endif
#ifdef ENABLE_PROPELLERS
			if (propellers_idx) propellers_do ();
#endif
			hud_update ();
		
			oam_hide_rest (oam_index);
			*ul = NT_UPD_EOF;
		}
	}

	// CUSTOM {
	if (!pkilled) {
		rda = MAX_LEVELS + level;
		run_talk_script (); 
	}
	// } END_OF_CUSTOM

	set_vram_update (0);
	exit_cleanly ();
}

void game_title (void) {
	enter_screen (palts1, screen_title);
	music_play (MUSIC_TITLE);
	
	while (1) {
		pad_read ();
		
		if (pad_this_frame & PAD_START) {
			COMM_STATS_INITIAL_PLIFE = LIFE_INI;
			level = 0;
			break;
		} 

		if ((pad_this_frame & PAD_SELECT) && !first_game) {
			break;
		}
		
		ppu_wait_nmi ();
	}

	music_stop ();
	sfx_play (SFX_START, SC_LEVEL);
	delay (ticks);

	exit_cleanly ();
}

/*
void game_over (void) {
	enter_screen (t_pal_bgs [level], screen_game_over);
	music_play (MUSIC_EVENT);
	do_screen (10);
}
*/
// 140,100
void game_ending (void) {
	enter_screen (palending, 0);
	pal_spr (palss1);

	set_vram_update (update_list);
	rda = MAX_LEVELS + MAX_LEVELS + 1;
	level = 0; gpit = 192; while (gpit --) scr_buff [gpit] = 0;
	run_talk_script (); 
	set_vram_update (0);

	exit_cleanly ();

	rdb = 0xff;
	enter_screen (palending, screen_event);
	music_play (MUSIC_ENDING);

	delay (120);
	sfx_play (SFX_THUNDER, SC_LEVEL);

	rda = 180; rdx = 136; rdy = 96; rdc = 0;
	frame_counter = 0;

	while (1) {	
		pad_read (); if (pad_this_frame & PAD_START) break;

		oam_index = 4;
		frame_counter ++;

		if (rda) {
			rda --; rdb = rda & 0xf;
			oam_index = oam_meta_spr (
				132 + jitter_big [rdb], 92 + jitter_big [15 - rdb],
				oam_index,
				ssit_05
			);
			if (rda == 90) rdc = 1;
		}

		if (rdx < 248 && rdc) {
			if ((frame_counter & 0x7) == 0) rdx ++;
			if ((frame_counter & 0xf) == 0) rdy --;
			oam_index = oam_spr (rdx, rdy, 9, 0x20, oam_index);
		}

		oam_hide_rest (oam_index);
		ppu_wait_nmi ();
	}

	first_game = 1;
	exit_cleanly ();
}

void game_event (void) {
	enter_screen (palts1, screen_event);
	do_screen (5);
}
