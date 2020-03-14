// MT MK2 NES v0.8b
// Copyleft 2017 by The Mojon Twins

// Levelset
// Coment whichever doesn't apply

const unsigned char * const l_ts_pals [] = { ts3_pals, ts4_pals, ts5_pals, ts3_pals };
const unsigned char * const l_ts_tmaps [] = { ts3_tmaps, ts4_tmaps, ts5_tmaps, ts3_tmaps };
const unsigned char * const l_behs [] = { behs3, behs4, behs5, behs3 };
const unsigned char * const * const l_map [] = { map_3, map_4, map_5, map_6 };
//const unsigned char * const * const l_decos [] = { map_3_decos, map_3_decos, map_3_decos };
#ifdef ENEMS_FORMAT_UNPACKED
const unsigned char * const l_enems [] = { enems_3, enems_4, enems_5, enems_6 } ;
#else
const unsigned char * const * const l_enems [] =  { enems_3, enems_4, enems_5, enems_6 } ;
#endif
const unsigned char * const l_hotspots [] = { hotspots_3, hotspots_4, hotspots_5, hotspots_6 };
const unsigned char * const l_locks [] = { map_3_locks, 0, 0, 0 };
const unsigned char * const l_pal_bgs [] = { palts3, palts4, palts5, palts3 };
const unsigned char * const l_pal_fgs [] = { palss1, palss1, palss1, palss1 };
// const unsigned char * const t_pal_bgs [] = { palts0, palts0 };
// const unsigned char * const t_pal_fgs [] = { palss0, palss0 };
const unsigned char l_max_hotspots_type_1 [] = { MAX_HOTSPOTS_3_TYPE_1, MAX_HOTSPOTS_4_TYPE_1, MAX_HOTSPOTS_5_TYPE_1, 0 };
/*const unsigned char l_max_killable_enems [] = { 
	MAX_enems_3_TYPE_10,
	MAX_enems_3_TYPE_10 + MAX_enems_3_TYPE_30,
	MAX_enems_3_TYPE_10 + MAX_enems_3_TYPE_30,
	MAX_enems_3_TYPE_10 + MAX_enems_3_TYPE_30,
};*/
const unsigned char l_map_w [] = { 6, 4, 4, 1 };
// const unsigned char l_plife [] = { 5, 5, 5, 5 };
const unsigned char l_scr_ini [] = { 6, 0, 19, 2 };
const unsigned char player_ini_x [] = { 2, 12, 12, 7 };
const unsigned char player_ini_y [] = { 4, 3, 10, 9 };
//const unsigned char * const * const l_spr_enems [] = { spr_enems_3, spr_enems_3, spr_enems_3 }; 
// const unsigned char * const * const l_spr_player [] = { spr_player_0, spr_player_0, spr_player_0 };
const unsigned char level_musics [] = { MUSIC_INGAME_C, MUSIC_INGAME_A, MUSIC_INGAME_B, MUSIC_BOSS };
