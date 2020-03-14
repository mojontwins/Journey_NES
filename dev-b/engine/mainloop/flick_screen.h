	// Change screen
	// This version is heavily customized for this game

	if (prx == 4 && pvx < 0) {
		px = 244 << FIX_BITS;

		if (custom_on_off & FLAG_RANDOM_CONNECTION) {
			rdb = ENTRY_LEFT; random_connection ();
		} else {
			n_pant --;
		}

	} else if (prx == 244 && pvx > 0) {
		px = 8<<FIX_BITS;

		if (custom_on_off & FLAG_RANDOM_CONNECTION) {
			rdb = ENTRY_RIGHT; random_connection ();
		} else {
			n_pant ++;
		}
	} else if (pry == 0 && pvy < 0) {
		py = 192<<FIX_BITS;

		if (custom_on_off & FLAG_RANDOM_CONNECTION) {
			rdb = ENTRY_TOP; random_connection ();
		} else {
			n_pant -= map_w;
		}

		if (pwater) pvy = -PLAYER_VY_FLICK_TOP_SWIMMING; else { 
			pvy = -PLAYER_VY_FLICK_TOP; pj = 0; 
		}

		flicked = 1;
	} else if (pry >= 192 && pvy > 0) {
		if (custom_on_off & FLAG_RANDOM_CONNECTION) {
			rdb = ENTRY_BOTTOM; random_connection ();
		} else {
			n_pant += map_w;
		}
		py = 0;
	}

	if (on_pant != n_pant && do_game) {
		prx = px >> FIX_BITS;
		pry = py >> FIX_BITS;
		game_prepare_screen ();
		on_pant = n_pant;
	} 
