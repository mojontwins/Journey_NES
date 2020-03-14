// MT MK2 NES v0.85 - Snotty Mucosity version.
// Copyleft 2017 by The Mojon Twins

// Hud. Of course, this has to be customized for each game
/*
void p_t1 (unsigned char x, unsigned char y, unsigned char n) {
	gp_addr = NAMETABLE_A + (y << 5) + x;
	*ul ++ = MSB (gp_addr);
	*ul ++ = LSB (gp_addr);
	*ul ++ = DIGIT (n);
}
*/
void hud_update (void) {
	if (plife != oplife) p_t2 (6, 2, plife);
	if (pobjs != opobjs) p_t2 (18, 2, max_hotspots_type_1 - pobjs);
	if (pkeys != opkeys) p_t2 (29, 2, pkeys);
	opobjs = pobjs;
	opkeys = pkeys;
	oplife = plife;
}

void hud_draw (void) {
	vram_adr (NAMETABLE_A);
	vram_unrle (hud_rle);
	p_s (1, 2, "LIFE:00__OBJECTS:00__CUTTER:00");	
}
