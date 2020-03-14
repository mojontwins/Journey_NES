// Hacky random exit engine!
// Needs a number of rooms which is a power of two.

#define ENTRY_LEFT 		0
#define ENTRY_TOP 		1
#define ENTRY_RIGHT 	2
#define ENTRY_BOTTOM 	3

void random_connection (void) {
	rda = n_pant;

	if (entry == rdb) n_pant = prev_pant; else do {
		// n_pant = ++ frame_counter & 0x0f; 
		n_pant = room_shuffle [(seq ++) & 0xf];
		//if (seq > 15) seq = 0;
	} while (n_pant == rda);

	prev_pant = rda;

	// Hakish, but works. flips entry left<->right, top<->bottom
	entry = rdb + 2; if (entry > 3) entry -= 4;
}
