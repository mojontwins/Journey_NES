// heart.h, a simple particle
// v2.0.Journey, customized to be bubbles which only
// exist on tiles with the water bit set.

// To save RAM, I've removed particles_l as it won't be used.
// So this is almost a full rewrite.

// I love when this happens ...

/*
void heart_create (void) {
	bi = MAX_HEARTS; while (bi --) if (!particles_l [bi]) {
		particles_l [bi] = halfticks + (rand8 () & 0xf); particles_x [bi] = en_x [gpit] + 4; particles_y [bi] = en_y [gpit] - 4;
		break;
	}
}

void particles_move (void) {
	bi = MAX_HEARTS; while (bi --) if (particles_l [bi]) {
		particles_l [bi] --; particles_y [bi] -= (1 + (rand8 () & 1)); particles_x [bi] += ((rand8 () & 1) << 1) - 1;
		if (particles_y [bi] < 16) particles_l [bi] = 0;
		
		oam_index = oam_spr (particles_x [bi], particles_y [bi] + SPRITE_ADJUST, 2, 0, oam_index);
	}
}

void particles_init (void) {
	bi = MAX_HEARTS; while (bi --) particles_l [bi] = 0;
}
*/

void particles_init (void) {
	bi = MAX_PARTICLES; while (bi --) particles_t [bi] = 0;
}

void particles_create (void) {
	if (pry < 8) return;

	bi = MAX_PARTICLES; while (bi --) if (particles_t [bi] == 0) {
		particles_x [bi] = rdx; particles_y [bi] = rdy;
		particles_t [bi] = rda;
		break;
	}
}

void particles_move (void) {
	bi = MAX_PARTICLES; while (bi --) if (particles_t [bi]) {
		rdc = scr_attr [(particles_x [bi]>>4)|((particles_y [bi] & 0xf0)-16)];
		switch (particles_t [bi]) {
			case 1:
				if (half_life) { particles_y [bi] -= (1 + (rand8 () & 1)); particles_x [bi] += ((rand8 () & 1) << 1) - 1; }
				rda = 6 | (bi & 1);
				rdb = !(rdc & WATER_BIT);
				break;
			case 2:
				particles_y [bi] -= 2;
				rda = 8;
				rdb = rdc & 13;
				break;
		}
		if (particles_y [bi] < 16 || rdb) { particles_t [bi] = 0; break; }

		if ((bi & 1) == half_life) oam_index = oam_spr (particles_x [bi], particles_y [bi] + SPRITE_ADJUST, rda, 2, oam_index);
	}
}
