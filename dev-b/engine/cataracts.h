// MT MK2 NES v0.85 - Snotty Mucosity version.
// Copyleft 2017 by The Mojon Twins

// Cataracts. Not very much related, but I felt like displaying
// my love for Final Fantasy XII.

// Cataracts use the same memory structures as estrujators.
// Right away there's no distinction, so you *can't* place 
// estrujators and cataracts in the same screen, which may
// be good as you don't want update_list to go haywire!

void cataracts_add (void) {
#ifdef CATARACTS_CREATE_FROM_MAP
	est_x [est_idx] = rdx >> 1;
	est_y [est_idx] = (rdy - TOP_ADJUST) >> 1;
#else
	est_x [est_idx] = CATARACTS_X;
	est_y [est_idx] = CATARACTS_Y;
#endif
	est_ct [est_idx] = CATARACTS_IDLE_TIME - (est_idx<<6);
	est_state [est_idx ++] = 0;
}

void cataracts_do (void) {
	est_n_acts = 1;
	gpit = est_idx; while (gpit --) {
		_est_ct = est_ct [gpit];
		_est_state = est_state [gpit];
		_est_x = est_x [gpit];
		_est_y = est_y [gpit];

		switch (_est_state) {
			case 0:
				// Idling, out
			case 2:				
				// Idling, in
				if (_est_ct) _est_ct --; else _est_state ++;	
				break;
			case 1: 
				// Entering
			case 3:
				// Exiting

				// Paint
				if (_est_state == 1) {
					rda = CATARACTS_PATTERN;
					rdb = c_behs [CATARACTS_TILE];
				} else {
					rda = CATARACTS_DELETE_PATTERN;
					rdb = 0;
				}

				gp_addr = NAMETABLE_A + (((_est_y << 1) + _est_ct + TOP_ADJUST) << 5) + (_est_x << 1);
				*ul ++ = MSB (gp_addr) | NT_UPD_HORZ;
				*ul ++ = LSB (gp_addr);
				*ul ++ = 8;
				*ul ++ = rda;
				*ul ++ = rda;
				*ul ++ = rda;
				*ul ++ = rda;
				*ul ++ = rda;
				*ul ++ = rda;
				*ul ++ = rda;
				*ul ++ = rda;

				// On _est_ct even, modify screen attributes
				if (_est_ct & 1) {
					rdc = ((_est_y + (_est_ct >> 1)) << 4) | _est_x;
					scr_attr [rdc ++] = rdb;
					scr_attr [rdc ++] = rdb;
					scr_attr [rdc ++] = rdb;
					scr_attr [rdc] = rdb;
				}

				if (half_life) {
					_est_ct ++; if (_est_ct == (CATARACTS_HEIGHT<<1)) {
						_est_ct = CATARACTS_IDLE_TIME;
						_est_state = (_est_state == 1 ? 2 : 0);
					}
				}
				break;
		}

		est_ct [gpit] = _est_ct;
		est_state [gpit] = _est_state;
		est_x [gpit] = _est_x;
		est_y [gpit] = _est_y;				
	}
}
