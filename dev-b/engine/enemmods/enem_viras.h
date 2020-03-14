// Viras!

// Basicly a short-sighted homing fanty with an extra state: reset.
// Reset is like the retreating state but Viras will flicker, won't hit,
// and won't interrupt the state until it reaches its destination.

// Needs FANTY_INCS_MAX and fanty_incs
// Needs FANTY_RETREAT_INCS_MAX and fanty_retreat_incs
// Needs mod6

	// States are:
	// FANTY_ST_IDLE 0 - stays idle. 
	// FANTY_ST_PURSUING 1 - pursues player.
	// FANTY_ST_RETREATING 2 - retreats to original position.

	// IDLE -> PURSUING if player_in_range
	// PURSUING -> RETREATING if !player_in_range
	// RETREATING -> IDLE if x = x1 && y = y1

	rdb = (DELTA (prx, _en_x) < VIRAS_SIGHT_DISTANCE && DELTA (pry, _en_y) < VIRAS_SIGHT_DISTANCE);
	rdx = _en_x; 
	rdy = _en_y; 

	switch (_en_state) {
		case FANTY_ST_IDLE:
			if (rdb) {
				_en_state = FANTY_ST_PURSUING;
				_en_mx = 0;	_en_my = 0;
			}
			break;

		case FANTY_ST_PURSUING:
			if (!rdb) {
				_en_state = FANTY_ST_RETREATING;
				_en_mx = 0;	_en_my = 0;
			} else {
				// Accelerate X
				if (prx > _en_x) {
					_en_mx ++; if (_en_mx >= FANTY_INCS_MAX - 1) _en_mx = FANTY_INCS_MAX - 1;
				} else if (prx < _en_x) {
					_en_mx --; if (_en_mx <= -(FANTY_INCS_MAX - 1)) _en_mx = - (FANTY_INCS_MAX - 1);
				}

				// Move X
				if (rand8 () & 0xf) _en_x += ADD_SIGN (_en_mx, fanty_incs [ABS (_en_mx)]);
				
				// Collide X
				if ((_en_x < 8 && _en_mx < 0) || (_en_x > 232 && _en_mx > 0)) _en_mx = -_en_mx; 
				enem_fanty_collide_x ();

				// Accelerate Y
				if (pry > _en_y) {
					_en_my ++; if (_en_my >= FANTY_INCS_MAX - 1) _en_my = FANTY_INCS_MAX - 1;
				} else if (pry < _en_y) {
					_en_my --; if (_en_my <= -(FANTY_INCS_MAX - 1)) _en_my = - (FANTY_INCS_MAX - 1);
				}

				// Move Y
				if (rand8 () & 0xf) _en_y += ADD_SIGN (_en_my, fanty_incs [ABS (_en_my)]);

				// Collide Y
				if ((_en_y < 8 && _en_my < 0) || (_en_y > 232 && _en_my > 0)) _en_my = -_en_my;
				enem_fanty_collide_y ();

			}
			break;

		case FANTY_ST_RETREATING:
			if (rdb) {
				_en_state = FANTY_ST_PURSUING;
				_en_mx = 0; _en_my = 0;
				break;
			} 
		case FANTY_ST_RESET:
			/*
			_en_mx = (_en_mx + 1) & 3; rds = _en_state == FANTY_ST_RESET ? 1 : fanty_retreat_incs [_en_mx];
			if (_en_x != _en_x1) { _en_x += (_en_x > _en_x1 ? -rds : rds); enem_fanty_collide_x (); }
			if (_en_y != _en_y1) { _en_y += (_en_y > _en_y1 ? -rds : rds); enem_fanty_collide_y (); }
			if (_en_x == _en_x1 && _en_y == _en_y1)	_en_state = FANTY_ST_IDLE;
			*/

			if (_en_state == FANTY_ST_RESET || (half_life & 3) == 0) {
				if (_en_x > _en_x1) _en_mx = -1; else if (_en_x < _en_x1) _en_mx = 1; else _en_mx = 0; _en_x += _en_mx; enem_fanty_collide_x ();
				if (_en_y > _en_y1) _en_my = -1; else if (_en_y < _en_y1) _en_my = 1; else _en_my = 0; _en_y += _en_my; enem_fanty_collide_y ();
				if (_en_x == _en_x1 && _en_y == _en_y1)	_en_state = FANTY_ST_IDLE;
			}

			break;
	}

	// Collision with cataract
	if ((scr_attr [((_en_y - 7) & 0xf0) | ((_en_x + 7) >> 4)] & 1)
		&& _en_state != FANTY_ST_RESET) {
		//enems_drain ();
		_en_state = FANTY_ST_RESET;
		lightning = 16;
		sfx_play (SFX_ENEMY_HIT, SC_ENEMS);
		enems_drain (); 
		en_washit [gpit] = 30;

		// Dead?
		// CUSTOM {
		if (rdt == 0) {
			set_map_tile (2, 0, 0);
			set_map_tile (3, 0, 0);
			sfx_play (SFX_GET_ITEM, SC_PLAYER);
		}
		// } END_OF_CUSTOM
	}

	spr_id = (_en_state != FANTY_ST_RESET || half_life) ? VIRAS_CELL_BASE + mod6 [frame_counter >> 3] : 0xff;
