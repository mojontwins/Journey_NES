// MT MK2 NES v0.85 - Snotty Mucosity version.
// Copyleft 2017 by The Mojon Twins

// Tile behaviours

// | 1 evil
// | 2 water
// | 4 platform
// | 8 obstacle
// | 16 slippery

// Special : 10 (key lock)

const unsigned char behs3 [] = {
	0, 0, 0, 0, 0, 2, 2, 1,
	8, 8, 8, 8, 8, 8, 8,10,
	0, 0, 0, 0, 0, 2, 2, 1,
	0, 8,33, 1, 1, 4, 4, 4
};

const unsigned char behs4 [] = {
	0, 0, 0, 0, 0, 0, 4, 4,
	4, 1, 8, 8, 8, 8, 8, 8, 
	1, 0, 0, 0, 0, 0, 0, 0,
	8, 4, 8, 8, 8, 8, 8, 8
};

const unsigned char behs5 [] = {
	0, 0, 0, 0, 8, 2, 2, 1,
	8, 8, 8, 8, 8, 8, 8, 0,
	0, 0, 0, 0, 8, 2, 2, 1,
	8, 8, 8, 1, 1, 4, 4, 4
};
