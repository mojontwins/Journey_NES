@echo off
if [%1]==[justcompile] goto :justcompile

echo Generating Pals
..\..\utils\mkts.exe mode=pals pals=..\gfx\palts.png out=work\palbg1.h label=palts1 silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\palts3.png out=work\palbg3.h label=palts3 silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\palts4.png out=work\palbg4.h label=palts4 silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\palts5.png out=work\palbg5.h label=palts5 silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\palss.png out=work\palfg1.h label=palss1 silent aseprite
..\..\utils\mkts.exe mode=pals pals=..\gfx\pallightning.png out=work\pallightning.h label=pallightning silent aseprite

copy /b work\palbg1.h + work\palbg3.h + work\palbg4.h + work\palbg5.h + work\palfg1.h + work\pallightning.h assets\palettes.h > nul

echo Exporting chr
cd ..\gfx
echo bank 0 (tileset)
..\..\utils\mkts.exe mode=scripted in=cut_tiles.spt out=tschr.bin silent
..\..\utils\fillto.exe tschr.bin 4096
echo bank 1 (spriteset)
..\..\utils\mkts.exe mode=scripted in=cut_sprites.spt out=sschr.bin silent
..\..\utils\fillto.exe sschr.bin 4096
echo Juntando pichas
copy /b tschr.bin + sschr.bin ..\dev-b\tileset.chr > nul
del tschr.bin > nul
del sschr.bin > nul

echo Exporting enems
cd ..\enems
..\..\utils\eneexp3c.exe level3.ene ..\dev-b\assets\enems3.h 3 1
..\..\utils\eneexp3c.exe level4.ene ..\dev-b\assets\enems4.h 4 1
..\..\utils\eneexp3c.exe level5.ene ..\dev-b\assets\enems5.h 5 1
..\..\utils\eneexp3c.exe level6.ene ..\dev-b\assets\enems6.h 6 1

echo Making map 
cd ..\map
..\..\utils\rle53map.exe in=level3.map out=..\dev-b\assets\map3.h size=6,3 tlock=15 prefix=3 scrsizes fixmappy
..\..\utils\rle53map.exe in=level4.map out=..\dev-b\assets\map4.h size=4,4 prefix=4 scrsizes fixmappy
..\..\utils\rle53map.exe in=level5.map out=..\dev-b\assets\map5.h size=4,5 prefix=5 scrsizes fixmappy
..\..\utils\rle53map.exe in=level6.map out=..\dev-b\assets\map6.h size=1,3 prefix=6 scrsizes fixmappy

echo Making texts
cd ..\dev-b
rem cd ..\texts
rem ..\..\utils\texts2array.exe dialogue.txt ..\dev-b\assets\texts.h texts0 19
..\..\utils\diacom.exe ..\texts\dialogue-b.txt assets\dialogue.h 21

cd ..\dev-b

rem ..\..\utils\msc4nes.exe in=..\script\journey.spt out=..\dev-b\engine\mscnes.h maxpants=30 mapadjust=1

:justcompile

cc65 -Oi game.c --add-source
ca65 crt0.s -o crt0.o
ca65 game.s
ld65 -v -C nes.cfg -o journey.nes crt0.o game.o runtime.lib -Ln labels.txt

cc65 -Oi game.c --add-source -D GNROM
ca65 crt0-gnrom.s -o crt0.o
ca65 game.s
ld65 -v -C nes.cfg -o ..\gnrom\journey-gnrom-rom1.nes crt0.o game.o runtime.lib -Ln labels.txt

del game.s
del game.o
del crt0.o
