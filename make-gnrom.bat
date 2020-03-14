@echo off
echo Building ROM 0
cd dev-a
call compile.bat > nul
cd ..
echo Building ROM 1
cd dev-b
call compile.bat > nul
cd ..
echo Assembling . . .
cd gnrom
xtrctbin.exe journey-gnrom-rom0.nes prg0.bin 16 32768 
xtrctbin.exe journey-gnrom-rom1.nes prg1.bin 16 32768 
copy ..\dev-b\tileset.chr chr0.bin > nul
bldgnrom.exe ..\journey-gnrom.nes vert 2 1
cd ..
echo DONE!
