//if ((frame_counter & 31) == 0) {
	gpit = pal_cycle [2]; 
	pal_cycle [2] = pal_cycle [1]; 
	pal_cycle [1] = pal_cycle [0]; 
	pal_cycle [0] = gpit; 
	pal_col (9, pal_cycle [0]);
	pal_col (10, pal_cycle [1]);
	pal_col (11, pal_cycle [2]);
//}
