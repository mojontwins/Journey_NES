@echo off
..\..\utils\nsf2data sounds.nsf -ca65 -pal
..\..\utils\text2data music.txt -ca65
copy *.s ..\dev-a > nul
copy *.s ..\dev-b > nul
echo DONE!
