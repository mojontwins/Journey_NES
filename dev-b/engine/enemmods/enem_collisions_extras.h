#if ((defined (ENABLE_PRECALC_FANTY) || defined (ENABLE_PRECALC_HOMING_FANTY)) && defined (FANTY_COLLIDES)) || defined (ENABLE_VIRAS)

void enem_fanty_collide_x (void) {
	if (_en_mx) {
		rdx = _en_x;
		cx1 = cx2 = _en_mx < 0 ? ((_en_x + 4) >> 4) : ((_en_x + 11) >> 4);
		cy1 = (_en_y + 4) >> 4; cy2 = (_en_y + 11) >> 4;
		cm_two_points ();
		if ((at1 & FLOOR_BITS) || (at2 & FLOOR_BITS)) { 
			//if (_en_state == FANTY_ST_PURSUING)
			_en_mx = -_en_mx; 
			_en_x = rdx; 
		}
	}
}

void enem_fanty_collide_y (void) {
	if (_en_my) {
		cy1 = cy2 = _en_my < 0 ? ((_en_y + 4) >> 4) : ((_en_y + 11) >> 4);
		cx1 = (_en_x + 4) >> 4; cx2 = (_en_x + 11) >> 4;
		cm_two_points ();
		if ((at1 & FLOOR_BITS) || (at2 & FLOOR_BITS)) { 
			//if (_en_state == FANTY_ST_PURSUING) {
				if (_en_my > 0) _en_my = FANTY_INCS_MAX;
				else _en_my = -FANTY_INCS_MAX;
			//}
			_en_y = rdy; 
		}
	}
}

#endif
