@echo off
if [%1]==[justcompile] goto :justcompile

echo Generating Pals
..\..\utils\mkts.exe mode=pals pals=..\gfx\palts.png out=work\palbg1.h label=palts1 silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\palss.png out=work\palfg1.h label=palss1 silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\palts_alien.png out=work\palbg5.h label=palts_alien silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\palss_alien.png out=work\palfg5.h label=palss_alien silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\palreds.png out=work\palreds.h label=pal_reds silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\palending.png out=work\palending.h label=palending silent aseprite

copy /b work\palbg1.h + work\palfg1.h + work\palbg5.h + work\palfg5.h + work\palending.h assets\palettes.h > nul

echo Exporting chr
cd ..\gfx
echo bank 0 (tileset)
..\..\utils\mkts.exe mode=scripted in=cut_tiles.spt out=tschr.bin silent
..\..\utils\fillto.exe tschr.bin 4096
echo bank 1 (spriteset)
..\..\utils\mkts.exe mode=scripted in=cut_sprites.spt out=sschr.bin silent
..\..\utils\fillto.exe sschr.bin 4096
echo Juntando pichas
copy /b tschr.bin + sschr.bin ..\dev-a\tileset.chr > nul
del tschr.bin > nul
del sschr.bin > nul

echo Exporting enems
cd ..\enems
..\..\utils\eneexp3c.exe level0.ene ..\dev-a\assets\enems0.h 0 1
..\..\utils\eneexp3c.exe level1.ene ..\dev-a\assets\enems1.h 1 1
..\..\utils\eneexp3c.exe level2.ene ..\dev-a\assets\enems2.h 2 1

echo Making map 
cd ..\map
..\..\utils\rle53map.exe in=level0.map out=..\dev-a\assets\map0.h size=8,1 prefix=0 scrsizes fixmappy
..\..\utils\rle53map.exe in=level1.map out=..\dev-a\assets\map1.h size=6,2 prefix=1 scrsizes fixmappy
..\..\utils\rle53map.exe in=level2.map out=..\dev-a\assets\map2.h size=4,9 tlock=15 prefix=2 scrsizes fixmappy

echo Making texts
cd ..\dev-a
rem cd ..\texts
rem ..\..\utils\texts2array.exe dialogue.txt ..\dev-a\assets\texts.h texts0 19
..\..\utils\diacom.exe ..\texts\dialogue-a.txt assets\dialogue.h 21 95
..\..\utils\diacom.exe ..\texts\dialogue-a_es.txt assets\dialogue_es.h 21 95

cd ..\dev-a

rem ..\..\utils\msc4nes.exe in=..\script\journey.spt out=..\dev-a\engine\mscnes.h maxpants=30 mapadjust=1

:justcompile

cc65 -Oi game.c --add-source
ca65 crt0.s -o crt0.o
ca65 game.s
ld65 -v -C nes.cfg -o journey.nes crt0.o game.o runtime.lib -Ln labels.txt

cc65 -Oi game.c --add-source -D GNROM
ca65 crt0-gnrom.s -o crt0.o
ca65 game.s
ld65 -v -C nes.cfg -o ..\gnrom\journey-gnrom-rom0.nes crt0.o game.o runtime.lib -Ln labels.txt

del game.s
del game.o
del crt0.o
