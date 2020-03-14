
void do_menu (void) {
	// Write wee values to the pool so checksums are better.
	for (gpit = 1; gpit < 15; gpit ++) COMM_POOL [gpit] = gpit;

	// Now do the menu. First of all switch CHR3 in, combination 0
	m11_change_raw (0);

	pal_bg (palmenu);
	pal_spr (palmenu);

	vram_adr (NAMETABLE_A);
	vram_unrle (menu_frame_rle);

	p_s (5, 4, "LOS CUENTOS ASOMBROSOS//   DE");
	p_s (4, 14, "LAS AVENTURAS DE CHERIL/EN LA CUEVA CAVE//EL SGT. HELMET CONTRA/EL TERRIBLE COMMANDOW//PDT6 EN: VIAJE AL CENTRO/DEL ALIEN MISTERIOSOW");
	p_s (3, 26, "@ 2017 BY THE MOJON TWINS");

	ppu_on_all ();
	fade_in ();

	menu_item = 0;

	while (1) {
		pad_read (); 

		if (pad_this_frame & (PAD_START|PAD_A)) {
			sfx_play (SFX_START, 0);
			delay (30);
			break;
		}

		if (pad_this_frame & PAD_UP) {
			menu_item = menu_item > 0 ? menu_item - 1 : 2;
			sfx_play (SFX_TU, 0);
		}

		if (pad_this_frame & (PAD_DOWN|PAD_SELECT)) {
			menu_item = menu_item < 2 ? menu_item + 1 : 0;
			sfx_play (SFX_TU, 0);
		}

		oam_hide_rest (
			oam_meta_spr (
				16, 112+(menu_item << 4)+(menu_item << 3),
				0,
				spr_menu
			)
		);
		ppu_wait_nmi ();
	}

	exit_cleanly ();

	// Finally jump roms. Menu result on menu_item.
	// 0 -> Cave, switch to combination 2
	// 1 -> Commandow, switch to combination 3
	// 2 -> Journey (this)
	if (menu_item != 2) {
		rda = 0; for (gpit = 1; gpit < 15; gpit ++) rda += COMM_POOL [gpit];
		COMM_CHECKSUM = rda;
		
		m11_switch_raw (menu_item + 2);
	}

	// If we are here is 'cause we want to play Journey!
	
	// Page in PRG0, CHR1 (combination 1)
	m11_change_raw (1);
}
