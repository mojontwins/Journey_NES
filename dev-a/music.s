;this file for FamiTone2 library generated by text2data tool

music_music_data:
	.byte 6
	.word @instruments
	.word @samples-3
	.word @song0ch0,@song0ch1,@song0ch2,@song0ch3,@song0ch4,307,256
	.word @song1ch0,@song1ch1,@song1ch2,@song1ch3,@song1ch4,307,256
	.word @song2ch0,@song2ch1,@song2ch2,@song2ch3,@song2ch4,307,256
	.word @song3ch0,@song3ch1,@song3ch2,@song3ch3,@song3ch4,307,256
	.word @song4ch0,@song4ch1,@song4ch2,@song4ch3,@song4ch4,307,256
	.word @song5ch0,@song5ch1,@song5ch2,@song5ch3,@song5ch4,307,256

@instruments:
	.byte $30 ;instrument $00
	.word @env1,@env0,@env0
	.byte $00
	.byte $30 ;instrument $04
	.word @env3,@env8,@env0
	.byte $00
	.byte $30 ;instrument $05
	.word @env7,@env0,@env0
	.byte $00
	.byte $30 ;instrument $06
	.word @env5,@env0,@env0
	.byte $00
	.byte $30 ;instrument $0b
	.word @env2,@env8,@env0
	.byte $00
	.byte $30 ;instrument $0c
	.word @env6,@env0,@env0
	.byte $00
	.byte $30 ;instrument $0d
	.word @env4,@env0,@env0
	.byte $00

@samples:
@env0:
	.byte $c0,$00,$00
@env1:
	.byte $cc,$00,$00
@env2:
	.byte $cd,$cb,$c9,$c8,$c5,$c3,$c1,$c0,$00,$07
@env3:
	.byte $cf,$cd,$cb,$c9,$c7,$c5,$c3,$c1,$c0,$00,$08
@env4:
	.byte $c7,$c2,$c0,$00,$02
@env5:
	.byte $ca,$c5,$c3,$c2,$c0,$00,$04
@env6:
	.byte $cc,$ca,$c8,$c6,$c4,$c3,$c2,$c1,$c0,$00,$08
@env7:
	.byte $cd,$cc,$ca,$c9,$c7,$c6,$c5,$c3,$c0,$00,$08
@env8:
	.byte $c7,$c3,$c0,$bd,$00,$02


@song0ch0:
	.byte $fb,$06
@song0ch0loop:
@ref0:
	.byte $f9,$85
@ref1:
	.byte $f9,$85
@ref2:
	.byte $f9,$85
@ref3:
	.byte $f9,$85
@ref4:
	.byte $f9,$85
	.byte $fd
	.word @song0ch0loop

@song0ch1:
@song0ch1loop:
@ref5:
	.byte $f9,$85
@ref6:
	.byte $f9,$85
@ref7:
	.byte $f9,$85
@ref8:
	.byte $f9,$85
@ref9:
	.byte $f9,$85
	.byte $fd
	.word @song0ch1loop

@song0ch2:
@song0ch2loop:
@ref10:
	.byte $80,$33,$39,$3f,$39,$33,$39,$3f,$39,$31,$3b,$41,$3b,$31,$3b,$41
	.byte $3b,$33,$39,$3f,$39,$33,$39,$3f,$39,$31,$3b,$41,$3b,$31,$3b,$41
	.byte $3a,$81
@ref11:
	.byte $4b,$39,$3f,$39,$33,$39,$3f,$4a,$4c,$49,$3b,$41,$3b,$31,$3b,$41
	.byte $3b,$4b,$39,$3f,$39,$33,$39,$3f,$48,$4a,$53,$3b,$41,$3b,$31,$3b
	.byte $41,$3a,$81
@ref12:
	.byte $4b,$39,$3f,$39,$33,$39,$3f,$4a,$4c,$49,$3b,$41,$3b,$31,$3b,$41
	.byte $44,$40,$45,$39,$3f,$39,$33,$39,$3f,$48,$44,$3b,$3b,$41,$3b,$31
	.byte $3b,$41,$3a,$81
	.byte $ff,$23
	.word @ref11
	.byte $ff,$24
	.word @ref12
	.byte $fd
	.word @song0ch2loop

@song0ch3:
@song0ch3loop:
@ref15:
	.byte $f9,$85
@ref16:
	.byte $f9,$85
@ref17:
	.byte $f9,$85
@ref18:
	.byte $f9,$85
@ref19:
	.byte $f9,$85
	.byte $fd
	.word @song0ch3loop

@song0ch4:
@song0ch4loop:
@ref20:
	.byte $f9,$85
@ref21:
	.byte $f9,$85
@ref22:
	.byte $f9,$85
@ref23:
	.byte $f9,$85
@ref24:
	.byte $f9,$85
	.byte $fd
	.word @song0ch4loop


@song1ch0:
	.byte $fb,$06
@song1ch0loop:
@ref25:
	.byte $bf
@ref26:
	.byte $bf
@ref27:
	.byte $bf
@ref28:
	.byte $bf
@ref29:
	.byte $bf
@ref30:
	.byte $bf
@ref31:
	.byte $bf
@ref32:
	.byte $bf
	.byte $fd
	.word @song1ch0loop

@song1ch1:
@song1ch1loop:
@ref33:
	.byte $bf
@ref34:
	.byte $bf
@ref35:
	.byte $bf
@ref36:
	.byte $bf
@ref37:
	.byte $bf
@ref38:
	.byte $bf
@ref39:
	.byte $bf
@ref40:
	.byte $bf
	.byte $fd
	.word @song1ch1loop

@song1ch2:
@song1ch2loop:
@ref41:
	.byte $80,$4a,$01,$01,$00,$52,$00,$56,$00,$5a,$00,$5e,$01,$01,$00,$52
	.byte $00,$4e,$01,$01,$00,$4a,$00,$4e,$00,$56,$00
@ref42:
	.byte $52,$01,$01,$00,$52,$00,$4e,$00,$4a,$00,$5a,$00,$56,$00,$52,$01
	.byte $01,$01,$01,$01,$00,$4a,$00,$4e,$00
@ref43:
	.byte $4a,$01,$01,$01,$01,$00,$4a,$00,$4e,$00,$52,$00,$56,$01,$01,$01
	.byte $01,$00,$4a,$00,$54,$00,$52,$00
@ref44:
	.byte $56,$00,$5a,$00,$5e,$01,$01,$00,$4a,$00,$5a,$00,$56,$00,$5a,$01
	.byte $01,$00,$4e,$00,$4a,$01,$00,$4e,$01,$00
@ref45:
	.byte $4a,$01,$01,$01,$01,$00,$52,$00,$4e,$01,$00,$56,$01,$01,$01,$01
	.byte $00,$5a,$00,$56,$01,$00
@ref46:
	.byte $5e,$01,$01,$01,$01,$00,$62,$00,$5e,$00,$5a,$00,$56,$00,$52,$00
	.byte $4e,$00,$4a,$00,$56,$00,$5a,$00,$62,$00,$66,$00
@ref47:
	.byte $4a,$01,$01,$01,$01,$00,$52,$00,$4e,$00,$56,$00,$5a,$01,$01,$01
	.byte $01,$00,$5e,$00,$62,$00,$66,$00
@ref48:
	.byte $6a,$01,$01,$01,$01,$00,$5e,$00,$62,$00,$5a,$00,$66,$00,$56,$00
	.byte $6a,$01,$01,$00,$52,$00,$4e,$00,$4a,$00
	.byte $fd
	.word @song1ch2loop

@song1ch3:
@song1ch3loop:
@ref49:
	.byte $84,$21,$21,$82,$0f,$84,$21,$21,$21,$82,$0f,$84,$21,$21,$21,$82
	.byte $0f,$84,$21,$21,$21,$82,$0f,$84,$20,$81
@ref50:
	.byte $21,$21,$82,$0f,$84,$21,$21,$21,$82,$0f,$84,$21,$21,$21,$82,$0f
	.byte $84,$21,$21,$21,$82,$0f,$84,$20,$81
	.byte $ff,$11
	.word @ref50
	.byte $ff,$11
	.word @ref50
	.byte $ff,$11
	.word @ref50
	.byte $ff,$11
	.word @ref50
	.byte $ff,$11
	.word @ref50
	.byte $ff,$11
	.word @ref50
	.byte $fd
	.word @song1ch3loop

@song1ch4:
@song1ch4loop:
@ref57:
	.byte $bf
@ref58:
	.byte $bf
@ref59:
	.byte $bf
@ref60:
	.byte $bf
@ref61:
	.byte $bf
@ref62:
	.byte $bf
@ref63:
	.byte $bf
@ref64:
	.byte $bf
	.byte $fd
	.word @song1ch4loop


@song2ch0:
	.byte $fb,$06
@song2ch0loop:
@ref65:
	.byte $f9,$85
@ref66:
	.byte $f9,$85
@ref67:
	.byte $f9,$85
@ref68:
	.byte $f9,$85
@ref69:
	.byte $f9,$85
@ref70:
	.byte $f9,$85
@ref71:
	.byte $f9,$85
@ref72:
	.byte $f9,$85
@ref73:
	.byte $f9,$85
@ref74:
	.byte $f9,$85
@ref75:
	.byte $f9,$85
@ref76:
	.byte $f9,$85
	.byte $fd
	.word @song2ch0loop

@song2ch1:
@song2ch1loop:
@ref77:
	.byte $f9,$85
@ref78:
	.byte $f9,$85
@ref79:
	.byte $f9,$85
@ref80:
	.byte $f9,$85
@ref81:
	.byte $f9,$85
@ref82:
	.byte $f9,$85
@ref83:
	.byte $f9,$85
@ref84:
	.byte $f9,$85
@ref85:
	.byte $f9,$85
@ref86:
	.byte $f9,$85
@ref87:
	.byte $f9,$85
@ref88:
	.byte $f9,$85
	.byte $fd
	.word @song2ch1loop

@song2ch2:
@song2ch2loop:
@ref89:
	.byte $80,$52,$83,$00,$60,$8b,$00,$5c,$58,$56,$5c,$58,$83,$00,$52,$8b
	.byte $00,$4e,$85,$4a,$83,$00,$62,$89,$01,$60,$5c,$58,$60,$5c,$99,$00
	.byte $81
@ref90:
	.byte $52,$83,$00,$60,$89,$01,$5c,$58,$56,$5c,$58,$83,$00,$52,$89,$01
	.byte $4e,$83,$00,$4b,$01,$4b,$01,$4e,$00,$4f,$01,$52,$99,$00,$85
@ref91:
	.byte $52,$83,$00,$60,$8b,$00,$5c,$58,$56,$5c,$58,$83,$00,$52,$8b,$00
	.byte $4e,$85,$4a,$83,$00,$62,$89,$01,$60,$5c,$58,$60,$5c,$99,$00,$81
	.byte $ff,$1f
	.word @ref90
@ref93:
	.byte $56,$89,$01,$56,$83,$00,$5c,$83,$00,$59,$57,$59,$5d,$60,$89,$01
	.byte $62,$85,$01,$63,$60,$85,$5c,$85,$60,$9d
@ref94:
	.byte $56,$85,$01,$57,$58,$83,$00,$5c,$85,$58,$83,$00,$56,$83,$00,$52
	.byte $89,$01,$4a,$87,$00,$56,$87,$00,$5c,$83,$00,$60,$91,$62,$00,$60
	.byte $83,$00
	.byte $ff,$20
	.word @ref91
	.byte $ff,$1f
	.word @ref90
	.byte $ff,$20
	.word @ref91
	.byte $ff,$1f
	.word @ref90
@ref99:
	.byte $56,$87,$00,$53,$4e,$83,$00,$5c,$83,$00,$60,$87,$00,$5d,$58,$83
	.byte $00,$60,$83,$00,$62,$83,$00,$60,$83,$00,$5c,$83,$00,$62,$83,$00
	.byte $60,$99,$00,$81
@ref100:
	.byte $62,$00,$62,$62,$66,$00,$62,$00,$60,$83,$00,$58,$85,$56,$00,$56
	.byte $56,$58,$00,$5c,$00,$58,$83,$00,$53,$4f,$62,$95,$4b,$63,$60,$95
	.byte $48,$85
	.byte $fd
	.word @song2ch2loop

@song2ch3:
@song2ch3loop:
@ref101:
	.byte $8a,$21,$8c,$16,$16,$88,$0f,$8c,$16,$16,$8a,$21,$8c,$16,$16,$88
	.byte $0f,$8c,$16,$16,$8a,$21,$8c,$16,$16,$88,$0f,$8c,$16,$16,$8a,$21
	.byte $88,$0f,$0f,$8c,$16,$16,$8a,$21,$8c,$16,$16,$88,$0f,$8c,$16,$16
	.byte $8a,$21,$8c,$16,$16,$88,$0f,$8c,$16,$16,$8a,$21,$8c,$16,$16,$88
	.byte $0f,$8c,$16,$16,$8a,$21,$88,$0f,$0f,$0e,$0e
	.byte $ff,$2e
	.word @ref101
	.byte $ff,$2e
	.word @ref101
	.byte $ff,$2e
	.word @ref101
	.byte $ff,$2e
	.word @ref101
	.byte $ff,$2e
	.word @ref101
	.byte $ff,$2e
	.word @ref101
	.byte $ff,$2e
	.word @ref101
	.byte $ff,$2e
	.word @ref101
	.byte $ff,$2e
	.word @ref101
	.byte $ff,$2e
	.word @ref101
	.byte $ff,$2e
	.word @ref101
	.byte $fd
	.word @song2ch3loop

@song2ch4:
@song2ch4loop:
@ref113:
	.byte $f9,$85
@ref114:
	.byte $f9,$85
@ref115:
	.byte $f9,$85
@ref116:
	.byte $f9,$85
@ref117:
	.byte $f9,$85
@ref118:
	.byte $f9,$85
@ref119:
	.byte $f9,$85
@ref120:
	.byte $f9,$85
@ref121:
	.byte $f9,$85
@ref122:
	.byte $f9,$85
@ref123:
	.byte $f9,$85
@ref124:
	.byte $f9,$85
	.byte $fd
	.word @song2ch4loop


@song3ch0:
	.byte $fb,$06
@song3ch0loop:
@ref125:
	.byte $f9,$85
@ref126:
	.byte $f9,$85
@ref127:
	.byte $f9,$85
@ref128:
	.byte $f9,$85
@ref129:
	.byte $f9,$85
@ref130:
	.byte $f9,$85
@ref131:
	.byte $f9,$85
@ref132:
	.byte $f9,$85
@ref133:
	.byte $f9,$85
@ref134:
	.byte $f9,$85
@ref135:
	.byte $f9,$85
@ref136:
	.byte $f9,$85
@ref137:
	.byte $f9,$85
	.byte $fd
	.word @song3ch0loop

@song3ch1:
@song3ch1loop:
@ref138:
	.byte $f9,$85
@ref139:
	.byte $f9,$85
@ref140:
	.byte $f9,$85
@ref141:
	.byte $f9,$85
@ref142:
	.byte $f9,$85
@ref143:
	.byte $f9,$85
@ref144:
	.byte $f9,$85
@ref145:
	.byte $f9,$85
@ref146:
	.byte $f9,$85
@ref147:
	.byte $f9,$85
@ref148:
	.byte $f9,$85
@ref149:
	.byte $f9,$85
@ref150:
	.byte $f9,$85
	.byte $fd
	.word @song3ch1loop

@song3ch2:
@song3ch2loop:
@ref151:
	.byte $00,$f9,$83
@ref152:
	.byte $80,$52,$85,$01,$48,$85,$56,$00,$57,$59,$56,$85,$01,$4e,$85,$01
	.byte $49,$01,$58,$85,$01,$4e,$00,$5d,$01,$5d,$61,$5c,$89,$01,$59,$57
	.byte $53,$4e,$81
@ref153:
	.byte $52,$85,$01,$48,$85,$01,$59,$01,$56,$85,$01,$5d,$57,$01,$4f,$01
	.byte $48,$85,$01,$56,$83,$00,$57,$58,$85,$56,$91,$5d,$53,$4e,$81
@ref154:
	.byte $52,$85,$01,$48,$85,$56,$00,$57,$59,$56,$85,$01,$4e,$85,$01,$49
	.byte $01,$58,$85,$01,$4e,$00,$5d,$01,$5d,$61,$5c,$89,$01,$59,$57,$53
	.byte $4e,$81
@ref155:
	.byte $52,$85,$01,$48,$85,$01,$59,$01,$56,$85,$01,$5d,$57,$01,$4f,$01
	.byte $48,$85,$01,$56,$83,$00,$57,$58,$85,$5c,$91,$5d,$61,$5c,$81
@ref156:
	.byte $58,$8d,$01,$41,$49,$59,$5c,$8d,$01,$61,$5d,$57,$58,$83,$40,$4e
	.byte $83,$36,$48,$83,$36,$40,$83,$36,$5c,$91,$59,$61,$5c,$81
@ref157:
	.byte $60,$8d,$01,$61,$63,$66,$00,$66,$85,$5c,$85,$56,$85,$66,$85,$6a
	.byte $85,$60,$85,$58,$85,$6a,$85,$66,$9d
@ref158:
	.byte $60,$8d,$01,$61,$63,$61,$5c,$85,$56,$85,$4e,$85,$5c,$85,$58,$85
	.byte $52,$85,$48,$85,$58,$85,$56,$9d
	.byte $ff,$22
	.word @ref154
	.byte $ff,$1f
	.word @ref153
	.byte $ff,$22
	.word @ref154
	.byte $ff,$1f
	.word @ref155
@ref163:
	.byte $3a,$b1,$3b,$52,$00,$53,$84,$3a,$bd
	.byte $fd
	.word @song3ch2loop

@song3ch3:
@song3ch3loop:
@ref164:
	.byte $84,$20,$89,$20,$85,$82,$13,$0f,$0b,$84,$20,$89,$20,$85,$82,$13
	.byte $0f,$0b,$84,$20,$89,$20,$85,$82,$13,$0f,$0b,$84,$20,$89,$20,$85
	.byte $82,$13,$0f,$0a,$81
	.byte $ff,$1d
	.word @ref164
	.byte $ff,$1d
	.word @ref164
@ref167:
	.byte $84,$21,$86,$16,$12,$82,$0b,$16,$84,$0a,$21,$86,$16,$12,$82,$0b
	.byte $16,$84,$0a,$21,$86,$16,$12,$82,$0b,$16,$84,$0a,$21,$86,$16,$12
	.byte $82,$0b,$16,$84,$0a,$21,$86,$16,$12,$82,$0b,$16,$84,$0a,$21,$86
	.byte $16,$12,$82,$0b,$16,$84,$0a,$20,$89,$20,$85,$82,$13,$0f,$0a,$81
	.byte $ff,$2c
	.word @ref167
	.byte $ff,$1d
	.word @ref164
	.byte $ff,$2c
	.word @ref167
	.byte $ff,$2c
	.word @ref167
	.byte $ff,$2c
	.word @ref167
	.byte $ff,$2c
	.word @ref167
	.byte $ff,$2c
	.word @ref167
	.byte $ff,$2c
	.word @ref167
	.byte $ff,$1d
	.word @ref164
	.byte $fd
	.word @song3ch3loop

@song3ch4:
@song3ch4loop:
@ref177:
	.byte $f9,$85
@ref178:
	.byte $f9,$85
@ref179:
	.byte $f9,$85
@ref180:
	.byte $f9,$85
@ref181:
	.byte $f9,$85
@ref182:
	.byte $f9,$85
@ref183:
	.byte $f9,$85
@ref184:
	.byte $f9,$85
@ref185:
	.byte $f9,$85
@ref186:
	.byte $f9,$85
@ref187:
	.byte $f9,$85
@ref188:
	.byte $f9,$85
@ref189:
	.byte $f9,$85
	.byte $fd
	.word @song3ch4loop


@song4ch0:
	.byte $fb,$06
@song4ch0loop:
@ref190:
	.byte $bf
@ref191:
	.byte $bf
@ref192:
	.byte $bf
@ref193:
	.byte $bf
@ref194:
	.byte $bf
@ref195:
	.byte $bf
@ref196:
	.byte $bf
@ref197:
	.byte $bf
@ref198:
	.byte $bf
@ref199:
	.byte $bf
@ref200:
	.byte $bf
@ref201:
	.byte $bf
@ref202:
	.byte $bf
@ref203:
	.byte $bf
@ref204:
	.byte $bf
@ref205:
	.byte $bf
@ref206:
	.byte $bf
@ref207:
	.byte $bf
@ref208:
	.byte $bf
@ref209:
	.byte $bf
@ref210:
	.byte $bf
@ref211:
	.byte $bf
@ref212:
	.byte $bf
@ref213:
	.byte $bf
	.byte $fd
	.word @song4ch0loop

@song4ch1:
@song4ch1loop:
@ref214:
	.byte $bf
@ref215:
	.byte $bf
@ref216:
	.byte $bf
@ref217:
	.byte $bf
@ref218:
	.byte $bf
@ref219:
	.byte $bf
@ref220:
	.byte $bf
@ref221:
	.byte $bf
@ref222:
	.byte $bf
@ref223:
	.byte $bf
@ref224:
	.byte $bf
@ref225:
	.byte $bf
@ref226:
	.byte $bf
@ref227:
	.byte $bf
@ref228:
	.byte $bf
@ref229:
	.byte $bf
@ref230:
	.byte $bf
@ref231:
	.byte $bf
@ref232:
	.byte $bf
@ref233:
	.byte $bf
@ref234:
	.byte $bf
@ref235:
	.byte $bf
@ref236:
	.byte $bf
@ref237:
	.byte $bf
	.byte $fd
	.word @song4ch1loop

@song4ch2:
@song4ch2loop:
@ref238:
	.byte $80,$4a,$85,$01,$51,$58,$85,$00,$85,$4a,$00,$4a,$00,$4b,$5b,$59
	.byte $01,$55,$50,$00
@ref239:
	.byte $54,$85,$01,$51,$4f,$01,$59,$5b,$59,$01,$55,$01,$51,$01,$4f,$00
	.byte $81
@ref240:
	.byte $4a,$85,$01,$51,$58,$85,$00,$85,$4a,$00,$4a,$00,$4b,$5b,$59,$01
	.byte $54,$00,$50,$00
@ref241:
	.byte $54,$85,$01,$51,$4f,$01,$51,$4f,$4a,$91,$40,$00,$40,$00,$40,$00
@ref242:
	.byte $4a,$85,$01,$51,$58,$85,$00,$85,$4a,$00,$4a,$00,$4b,$5b,$59,$01
	.byte $55,$50,$00
	.byte $ff,$11
	.word @ref239
	.byte $ff,$14
	.word @ref240
@ref245:
	.byte $54,$85,$01,$51,$4f,$01,$51,$4f,$4a,$99,$4a,$81
@ref246:
	.byte $4e,$85,$01,$4e,$00,$4f,$01,$4f,$55,$51,$01,$4f,$01,$4b,$01,$4a
	.byte $46,$42,$40
@ref247:
	.byte $3d,$01,$5a,$89,$01,$59,$55,$58,$95,$01,$4a,$81
@ref248:
	.byte $4e,$85,$01,$51,$54,$85,$51,$4f,$51,$01,$55,$01,$59,$01,$4f,$4a
	.byte $81
@ref249:
	.byte $4e,$91,$01,$51,$4f,$4a,$91,$40,$00,$40,$00,$40,$00
	.byte $ff,$13
	.word @ref242
	.byte $ff,$11
	.word @ref239
	.byte $ff,$14
	.word @ref240
	.byte $ff,$10
	.word @ref241
	.byte $ff,$13
	.word @ref242
	.byte $ff,$11
	.word @ref239
	.byte $ff,$14
	.word @ref240
	.byte $ff,$0c
	.word @ref245
@ref258:
	.byte $54,$85,$01,$55,$59,$01,$5b,$01,$5a,$85,$01,$58,$00,$58,$89,$00
	.byte $81
@ref259:
	.byte $54,$85,$01,$55,$59,$01,$5b,$01,$58,$9d
@ref260:
	.byte $54,$85,$01,$55,$59,$01,$5a,$85,$59,$01,$5b,$01,$5e,$89,$00,$81
@ref261:
	.byte $62,$00,$5f,$01,$5b,$59,$01,$55,$01,$50,$91,$5e,$62,$5e,$00,$40
	.byte $81
	.byte $fd
	.word @song4ch2loop

@song4ch3:
@song4ch3loop:
@ref262:
	.byte $84,$20,$89,$21,$82,$16,$8d,$13,$12,$85,$84,$21,$82,$12,$85,$86
	.byte $17,$16,$81
@ref263:
	.byte $84,$21,$86,$16,$16,$82,$17,$86,$16,$16,$84,$21,$86,$16,$16,$82
	.byte $17,$86,$16,$16,$84,$21,$86,$17,$84,$21,$86,$17,$84,$21,$86,$17
	.byte $82,$17,$16,$16
@ref264:
	.byte $84,$21,$86,$16,$16,$82,$17,$86,$16,$16,$84,$21,$86,$16,$16,$82
	.byte $17,$86,$16,$16,$84,$21,$86,$16,$16,$82,$17,$86,$16,$16,$84,$21
	.byte $86,$16,$16,$82,$17,$86,$16,$16
	.byte $ff,$15
	.word @ref263
	.byte $ff,$18
	.word @ref264
	.byte $ff,$15
	.word @ref263
	.byte $ff,$18
	.word @ref264
	.byte $ff,$15
	.word @ref263
	.byte $ff,$18
	.word @ref264
	.byte $ff,$15
	.word @ref263
	.byte $ff,$18
	.word @ref264
	.byte $ff,$15
	.word @ref263
	.byte $ff,$0e
	.word @ref262
	.byte $ff,$15
	.word @ref263
	.byte $ff,$18
	.word @ref264
	.byte $ff,$15
	.word @ref263
	.byte $ff,$18
	.word @ref264
	.byte $ff,$15
	.word @ref263
	.byte $ff,$18
	.word @ref264
	.byte $ff,$15
	.word @ref263
	.byte $ff,$18
	.word @ref264
	.byte $ff,$15
	.word @ref263
	.byte $ff,$18
	.word @ref264
	.byte $ff,$15
	.word @ref263
	.byte $fd
	.word @song4ch3loop

@song4ch4:
@song4ch4loop:
@ref286:
	.byte $bf
@ref287:
	.byte $bf
@ref288:
	.byte $bf
@ref289:
	.byte $bf
@ref290:
	.byte $bf
@ref291:
	.byte $bf
@ref292:
	.byte $bf
@ref293:
	.byte $bf
@ref294:
	.byte $bf
@ref295:
	.byte $bf
@ref296:
	.byte $bf
@ref297:
	.byte $bf
@ref298:
	.byte $bf
@ref299:
	.byte $bf
@ref300:
	.byte $bf
@ref301:
	.byte $bf
@ref302:
	.byte $bf
@ref303:
	.byte $bf
@ref304:
	.byte $bf
@ref305:
	.byte $bf
@ref306:
	.byte $bf
@ref307:
	.byte $bf
@ref308:
	.byte $bf
@ref309:
	.byte $bf
	.byte $fd
	.word @song4ch4loop


@song5ch0:
	.byte $fb,$06
@song5ch0loop:
@ref310:
	.byte $bf
@ref311:
	.byte $bf
@ref312:
	.byte $bf
@ref313:
	.byte $bf
@ref314:
	.byte $bf
@ref315:
	.byte $bf
@ref316:
	.byte $bf
@ref317:
	.byte $bf
@ref318:
	.byte $bf
@ref319:
	.byte $bf
@ref320:
	.byte $bf
@ref321:
	.byte $bf
@ref322:
	.byte $bf
@ref323:
	.byte $bf
	.byte $fd
	.word @song5ch0loop

@song5ch1:
@song5ch1loop:
@ref324:
	.byte $bf
@ref325:
	.byte $bf
@ref326:
	.byte $bf
@ref327:
	.byte $bf
@ref328:
	.byte $bf
@ref329:
	.byte $bf
@ref330:
	.byte $bf
@ref331:
	.byte $bf
@ref332:
	.byte $bf
@ref333:
	.byte $bf
@ref334:
	.byte $bf
@ref335:
	.byte $bf
@ref336:
	.byte $bf
@ref337:
	.byte $bf
	.byte $fd
	.word @song5ch1loop

@song5ch2:
@song5ch2loop:
@ref338:
	.byte $80,$59,$00,$52,$58,$ad,$00,$85
@ref339:
	.byte $59,$00,$52,$5c,$b5
@ref340:
	.byte $5d,$62,$00,$63,$5c,$00,$66,$00,$66,$00,$67,$01,$5d,$62,$00,$63
	.byte $5c,$00,$66,$00,$66,$00,$67,$00,$81
@ref341:
	.byte $63,$66,$00,$67,$63,$6b,$01,$67,$01,$62,$9d
@ref342:
	.byte $59,$00,$52,$58,$ad,$00,$85
	.byte $ff,$05
	.word @ref339
	.byte $ff,$19
	.word @ref340
	.byte $ff,$0b
	.word @ref341
@ref346:
	.byte $5c,$85,$01,$5d,$63,$01,$63,$01,$66,$00,$62,$00,$60,$00,$62,$00
	.byte $66,$89,$00,$81
@ref347:
	.byte $5c,$85,$01,$5d,$63,$01,$63,$01,$67,$01,$67,$01,$66,$85,$00,$85
@ref348:
	.byte $58,$89,$01,$6a,$89,$01,$6a,$00,$66,$00,$62,$00,$66,$00,$6a,$89
	.byte $00,$81
@ref349:
	.byte $66,$89,$01,$66,$85,$01,$67,$62,$99,$00,$81
	.byte $ff,$19
	.word @ref340
	.byte $ff,$0b
	.word @ref341
	.byte $fd
	.word @song5ch2loop

@song5ch3:
@song5ch3loop:
@ref352:
	.byte $86,$13,$16,$12,$13,$16,$12,$13,$16,$12,$13,$16,$12,$13,$16,$12
	.byte $13,$16,$12,$13,$16,$12,$13,$16,$12
@ref353:
	.byte $13,$16,$12,$13,$16,$12,$13,$16,$12,$13,$16,$12,$13,$16,$12,$13
	.byte $16,$12,$13,$16,$12,$12,$12,$16,$12
@ref354:
	.byte $84,$21,$86,$19,$82,$19,$84,$21,$82,$17,$19,$1c,$85,$84,$21,$86
	.byte $19,$82,$19,$84,$21,$82,$17,$19,$1c,$85
@ref355:
	.byte $84,$21,$86,$19,$82,$19,$84,$21,$82,$16,$85,$18,$85,$84,$21,$21
	.byte $82,$19,$84,$21,$21,$82,$19,$1d,$1c,$1c
@ref356:
	.byte $84,$21,$86,$19,$82,$19,$84,$21,$21,$86,$19,$82,$1d,$86,$19,$84
	.byte $21,$21,$82,$19,$84,$21,$21,$82,$19,$1d,$1c,$1c
@ref357:
	.byte $84,$21,$86,$19,$82,$19,$84,$21,$21,$86,$19,$82,$1d,$86,$19,$84
	.byte $21,$21,$82,$18,$18,$84,$21,$21,$82,$19,$1d,$1c,$1c
	.byte $ff,$10
	.word @ref354
	.byte $ff,$11
	.word @ref355
	.byte $ff,$11
	.word @ref356
@ref361:
	.byte $84,$21,$86,$19,$82,$19,$84,$21,$21,$86,$19,$82,$1d,$86,$19,$82
	.byte $16,$85,$18,$85,$18,$85,$1d,$1c,$1c
@ref362:
	.byte $84,$21,$86,$19,$82,$19,$86,$19,$84,$21,$86,$19,$82,$1d,$86,$19
	.byte $84,$21,$21,$82,$19,$84,$21,$21,$82,$19,$1d,$1c,$1c
@ref363:
	.byte $84,$21,$86,$19,$82,$19,$86,$19,$84,$21,$21,$82,$1d,$86,$19,$84
	.byte $21,$21,$82,$19,$19,$84,$21,$82,$19,$1d,$1c,$1c
	.byte $ff,$10
	.word @ref354
	.byte $ff,$11
	.word @ref355
	.byte $fd
	.word @song5ch3loop

@song5ch4:
@song5ch4loop:
@ref366:
	.byte $bf
@ref367:
	.byte $bf
@ref368:
	.byte $bf
@ref369:
	.byte $bf
@ref370:
	.byte $bf
@ref371:
	.byte $bf
@ref372:
	.byte $bf
@ref373:
	.byte $bf
@ref374:
	.byte $bf
@ref375:
	.byte $bf
@ref376:
	.byte $bf
@ref377:
	.byte $bf
@ref378:
	.byte $bf
@ref379:
	.byte $bf
	.byte $fd
	.word @song5ch4loop
