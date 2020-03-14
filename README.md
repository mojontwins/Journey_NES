# Journey_NES

Journey to the Centre of the Alien (NES)

To build use `make_gnrom.bat` with cc65 2.17 (min) in the PATH

## Diario

20170313
========

Voy a programar el compresor RLE3.5 orientado a pantallas, separar Journey de la ROM de Napia, y recomprimir todos los mapas con el nuevo formato a ver qué tal resulta (al menos de esos juegos).

~~

He separado por fin Journey de la rom de Tontis (además de recomprimir los mapas en el nuevo formato), resultando en un montón de sitio en ambas ROMs. Journey está preparado además para llevar varios niveles. La idea es expandir este juego y convertirno en una pequeña aventura chuli, rehaciendo algunos gráficos y añadiendo un par de fases o tres más.

20170421
========

Me cago en mi vida. Venía justo a apuntar unas ideas para Journey to the Centre of the Nose:

- Juego lineal, pero de forma cool: Tras cada fase se vuelve a una especie de pantalla hub para ir a la siguiente fase. Cada vez que consigues una nueva habilidad puedes acceder a una fase que no podías antes.
- Las habilidades son sobre salto y glide, y se obtienen al terminar las fases 1 y 2. La fase 2 se correspondería con la que hay hecha.
- Añadir cuadros de texto sencillos con la comandante dándote instrucciones.

Sin embargo tenía por ahí apuntadas cosas muy chulas:

- Fase jelly, sumergida en mocos verdes ¿controles ninjajar de nadal?
- Propellers / Gyrosaws / Steady shooters.

Lo de la fase jelly es ace, pero lo suyo sería que pudiese cambiarse de jelly a plataformas en medio de la fase. Vamos a diseñar una cosa:

- Si "punto central" & BIT_JELLY -> modo jelly.
- Si modo jelly y !("punto central" & BIT_JELLY) -> salta (para salir fácilmente del agua).
- Si modo jelly: 
  - te hundes despacio.
  - botón de salto para nadal, puedo parchear la forma de la que actúa el salto en las arenas movedizas.

Joder, el puto jelly es como las arenas movedizas, ¿no? Tengo que pensar en las posibles diferencias.

Lo que sí tendré que hacer será empezar portando los tiestos a la versión más moderna de MK2 XDDDD

Mira, voy preparando las cosas, pero no lo empiezo hasta que deje Cave, Yun y Babushka finiquitados.

20170422
========

Joder, no paro de liarme. Quiero meterle más mandanga al Journey. Y juro que es lo último que hago. Bueno, lo de que quiero hacerlo lo llevo diciendo desde ayer. Pero es que ya he empezado... Y eso que aún tengo que probar bien Yun, Cave (este menos) y Perils (Babushka).

Pero bueno.

Voy a implementar el tipo de nadal de Super Mario Bros, en el que te hundes lentamente pero pulsando mucho salto empiezas a ascender. No es exactamente igual que el tema de las arenas movedizas, pero compartirá código. El botón de salto simplemente añadirá una -VY, y no podrá dejarse pulsado. En las arenas movedizas el salto se hace entero pero se detiene. Aquí será diferente. además, haré lo que dije de que si "no se detecta agua" pero "se detectó agua la vez anterior" se produzca un impulso vertical hacia arriba.

Haré mapitas pequeños y al final la morterá grande original.

Pero lo primero que tendré que hacer será portar esto a la versión más reciente de MK2. Toca montar sober Perils (Babushka) y subir el número de versión.

Pero hoy ya no. Día improductivo a full. Pero tengo un tileset chulo y he hecho la animación de nadar.

~~

Antes de irme voy a hacer inventario de customs:

- Metasprites (save assets\metasprites.h)
- Hud (save engine\hud.h)
- Player sprite id.
- Fumettos on

Es bastante estándar. Enemigos persistentes, doble salto, step on enemies con culo sin matar, llaves y objetos, recargas. Será fácil de montar sobre el esqueleto cotejando definitions.h

Voy a mover dev a dev-orig, y a copiar el dev de perils en la carpeta de journey para mañana empezar a transformar.

~~

Ok, arogas entregagas. Journey portado a la versión más reciente de MK2, listo para recibir las novedades. 

```c
    #define ENABLE_WATER                    
    #define WATER_BIT                   
```

~~

Novedades funcionando ^:*)

20170424
========

Voy a meterle unas burbujitas, espero que no liándola mucho. Son como los corazones de Cheril Begins, pero levemente más complejos, porque tienen que detectar colisión (vaya, tienen que dejar de existir si el BIT de agua no está activado en el tile en el que entran).

~~

Hecho.

~~

En un ratito voy a diseñar el sistema de diálogos. Cada diálogo será un script que contendrá varias lineas. Cada linea estará compuesta por quién la dice y un texto. Los saltos de linea en el texto llevan % y están ajustados por el conversor.

```c 
    const unsigned char dialogue_00 [] = {
        0, 0,   // Character, text string
        0, 1,
        1, 2,
        1, 3,
        0, 4,
        1, 5,
        0xff    // end 
        er!
    };  

    ...

    const unsigned char * const dialogues [] = {
        dialogue_00, dialogue_01, dialogue_02, ...
    };

    const unsigned char text_00 [] = "HEY, COMMANDER, WHAT'S%GOING ON?!";
    const unsigned char text_01 [] = "ALL I GET IS STATIC NOISE!%CAN YOU FIX THAT?";
    ...

    const unsigned char * const texts [] = {
        text_00, text_01, ...
    };
```

Lo suyo es meter un txt codificado, rollo ristras de lineas ID|TEXTO terminadas por `<END>` y que genere el código de arriba automágicamente.

Vamos al lío.

~~

Todo guay. Ahora lo que tengo que ver es como enganchar sin tener que usar el scripting.

Quiero tener una charla al principio y al final de cada nivel, más cosas intermedias que puedan pegar. Para empezar, pongamos que tenemos una charla al principio y al final de cada nivel.

Podemos hacer que dialogue `[level]` sea al principio de cada nivel y dialogue `[MAX_LEVELS + level]` la del final. Hasta ahora nunca he definido `MAX_LEVELS`...

La forma de enganchar la del inicio del nivel, para que salga con la primera pantalla puesta, es tener un booleano. Para enganchar la del final, se hace en la detección de final de fase antes de salir de `game_loop`.

~~

Enganchado

20170425
========

Debería pensar en hacer que el compilador de diálogos pudiera reaprovechar cadenas. En realidad es un poco tontis porque tampoco es que fuese a ahorrar mucho (no creo que haya muchas cadenas repetidas), pero siempre mola ahorrar, y trabajar estúpidamente para salvar 10 bytes es mi segundo nombre.

Por otro lado lo escribo ya: he decidido no escatimar en diálogos y features, así que si tengo que ocupar con este juego las dos PRG ROM que quedan además de las suya propia no se me va a caer ningún anillo. Aún queda sitio para meter más gráficos si los necesito. Quiero meter lenguas que usen el código de los estrujadores, y meter a lo mejor variaciones como estrujadores desde abajo o estrujadores-chac-chac, pero tendría que ver como codificar todos los tipos. Los estrujadores ocupan bastante código.

Por lo pronto me centraré en completar la fase 2, donde hay que nadar más. Voy a meter los diálogos iniciales.

~~

Lo que sí voy a meter es poder poner comentarios y que se salte las lineas en blanco.

~~

Ok, todo hecho e introducido. Con sonidito de letras :) El flow entre fases funciona genial. Ahora tengo que terminar la fase 2 y retocar a saco la 3 para hacerla mejor (tiene demasiado cambio mierder entre pantallas!). Luego veré por donde tiramos. Probablemente añadiré más música a la ROM y pasaré a la siguiente. Quiero esas lenguas estrujadoras :D

~~

El exportador de enemigos compactados no lo hace bien si hay "huecos" en los enemigos de la habitación. Seguramente porque lo he hecho en plan cutre. Lo arreglaré.

No parece haber nada raro en los datos convertidos. ¿Podría ser la transición entre pantalla con N enemigos -> pantalla con N-1 enemigos, combinado con los enemigos persistentes? Lo investigaré.

Gur. Tengo que reproducirlo y ver para que me de más pistas. Pero eso luego.

20170426
========

Mientras retraso el momento de ponerme a buscar fantasmas (y eso que ayer estuve un buen rato) pienso en cosas que voy a meter en la siguiente ROM:

- Estrujators. Ver cómo definirlos hacia arriba también.
- Torrentes de ácido que bajan cayendo como un estrujator, se tiran un rato ahi dale fran, y luego desaparecen.
- Timed propellers. Los propellers estarán encendidos o apagados de forma alternativa durante períodos fijos.
- Sprite de adorno al propeller, como en Limite de Yun.
- ¿Enemigos que se te pegan y te hacen moverte a la mitad de velocidad? Esto podría molar.

Voy a programar a ciegas un rato. Total, más no puedo hacer. Extiendo los propellers.

Hm - lo de los propellers on/off no es tan fácil porque están modificando las durezas de la pantalla. ¿no será mucha tela tenerlos dinámicos? Siempre se puede probar...

Vaya bloat, necesita muchos más arrays para funcionar.

Bueno, en la siguiente ROM habrá más RAM libre porque hacer fases de 36 pantallas solo por un puto pasillo como que never again.

~~

Los propellers "ON_OFF" necesitan más parámetros que definir:

- `PROPELLERS_MAX_CTR`
- `PROPELLERS_INI_CTR`

Lo he dejado así para poder poner expresiones complejas si queremos y hacer que no vayan todos sincronizados, porque tenerlos todos sincronizados podría ser un pequeño overkill.

Por ejemplo, puedo probar:
 
```c
    #define PROPELLERS_MAX_CTR 63
    #define PROPELLERS_INI_CTR ((rand8()&7)<<3)
```

Puedo ahorrarme un array sin MAX_CTR es fijo. Listo, nuevo define. Buf, qué feo se pone todo.

~~ 

Otras cosas que tuve ayer ideas:

- Una fase en las que todas las pantallas esten conectadas por todos los lados y que cada vez que cambias de pantalla sale otra del mapa al azar. Tengo que pensar como hacer que el personaje no pueda ponerse a entrar y salir infinitamente hasta que le salga la que quiera, sino que tenga que probar otra salida. Idea: la entrada por la que acabas de entrar siempre conecta con la pantalla anterior. ¡Sorted!
- Una fase de celebro donde haya enemigos lineales especiales que se pinten 8 pixels por arriba de donde se definen en el mapa, para poder poner electricidades por los axones de las neuronas.

~~

En algún momento de la vida tengo que refactorizar todo el código, dividirlo en módulos como dios manda, y ordenarlo. Pero me apetece menos...

No  es algo que de problemas, a ver, sólo tengo que cambiar de .h a .c, crear un .h asociado, y definir como extern todas las globales empleadas. Ya lo hice en Yun SMS y fue un rato. Pero me da pereza.

20170428
========

Hoy, finalmente, y aunque la cuarta fase aún está muy en bragas, voy empezar a montar la infraestructura para la ROM2 de Journey. Las enlazaré más tarde, con estas reglas:

- Comprueba checksum, y si no es válido -> al menú. Esto como siempre.
- ROM1 escribe las vidas del jugador en `COMM_STATS_LIVES` (`COMM_POOL [0x3]`).
- ROM1 escribe el nivel donde se debe empezar en `COMM_STATS_LEVEL` (`COMM_POOL [0x4]`). Level = 3, 4... por lo que al principio de la ejecución debo tomar que `level = COMM_STATS_LEVEL - FIRST_LEVEL` y definir correctamente `FIRST_LEVEL` en `definitions.h`.
- Con el game over se vuelve a la ROM principal poniendo en `COMM_STATS_STATUS` el valor 0xff (`GAME_STATUS_GAME_OVER`).

Tengo que ver de meter más tipos de enemigos. Hay sitio en el spriteset y va siendo hora.

~~

¡OK! Montado y compilando. Ahora a configurar y luego ver qué cosas nuevas meter. Y pensar en adaptar algunos enemigos más, como dije. 

~~

Dudo que use esto en más sitios, pero bueno, intentaré hacerlo lo mejor posible: torrentes de lava/ácido/whatever. Deben ser anchos, de 4 tiles. Se mueven a caracter. Tienen 4 estados, como los estrujators: entrando, dentro, saliendo, fuera. Deben modificar los tiles que tocan y ponerlos a 1. Les voy a llamar con una palabra que me encanta pero que tampoco tiene mucho que ver... ¿y a quién le importa eso? `cataracts`.

Las cataracts van a usar el mismo rollo que los estrujators, así que no va a poder haber ambas en pantalla, lo cual es sensiblemente inteligente, ya que de otro modo se me irán de madre las actualizaciones del update list.

~~

Todo muy guay, todo muy fale, todo muy de acuerdo. He metido homing fanties precalculados. A ver si termino esta fase y hago la que se reconfigura, que esa va a molal.

Tengo que probar y escribir los diálogos, además de terminar de poner los enemigos de la fase 4, pero ahora estoy cansado y no me apetece mucho. Ya buscaré el hueco.

Hay una cosa que me mosquea desde hace tiempo: cuando mueres en el agua y el respawn es fuera de ella, apareces dando un salto. WTF?

Otra cosa es que es posible quedarte pinchao en los tiles que te matan si los atraviesas con la inmunidad.  Tengo que revisar.

~~

He resuelto lo del rebotaco. Lo de los pinchos, mañana. Pinchos always porculo. Always. Porculo. Always porculo.

20170429
========

¡¡Sesión de tren, camino de Zaragoza!! 

Quiero mejorar los estrujadores. Hasta ahora les daba obstaculo+evil de beh para que matasen al superponerse con el jugador, pero eso no funciona bien con `EVIL_TILE_MULTI` o `EVIL_TILE_CENTER`. Lo voy a cambiar. Ahora el cuerpo es obstaculo y la punta es evil, que cambia a obstaculo en un estado extra de la FSM. A ver cómo va.

~~

Sigue habiendo una razón por la que un enemigo de una pantalla se queda encajado en la parte superior. Pasaba en la fase 3 y pasa de nuevo en la fase 4. El coño es que no es en la misma pantalla ni nada. Como estoy en fceux voy a ver los enemigos.

Va a costar encontrarlo... Veamos.

La pantalla es la 16. Estos son los enemigos definidos para la 16:

    0x12, 0x57, 0xb7, 0x02, 
    0x11, 0xb3, 0x63, 0x02, 
    0x11, 0xbc, 0x8c, 0x01

El que no funciona es el primero, el tipo 0x12. En la fase 3 pasaba igual: en la pantalla 0xD el que no funcionaba era el primero. Los valores, 0x57, 0xb7 significa que va de (7, 5) a (7, B), lo cual está bien. Por ahí no va. Vamos a mirar en memoria. Por ejemplo, ep_x, que debería ser fijo y valer 7*16=112.

`ep_x` empieza en 0x000597. El primer enemigo de la pantalla 16 estará en `ep_x` + 16*3, o sea, en 0x5c7, si no me equivoco. Vamos al visor HEX de fceux.

Debería encontrar `112, 48, 192 ($70, $30, $C0)`.

Hay un 0. ep_x se incializa mal en este supuesto. Odd. Very odd... Según el gráfico de actualización de fceux (los numeros del visor hexadecimal se ponen de colores segun se escriben y van pasando a negro según pasan los ciclos), este valor ni siquiera se llega a escribir (negro fijo siempre). O sea, que el problema está en la inicialización de los enemigos.

Odd.

Veámosla muy despacito.

~~

Cago en su vida. No sé qué pasa. Voy a tener un viaje diver diver. Si en un cuarto de hora no lo he visto que le den y lo busco en otro momento.

~~

Por lo pronto el bucle no debería iterar sobre MAX_PANTS porque itera de más y está llenando cosas con mierda, pero eso creo que va a dar más o menos igual porque en los buffers cabe todo sin problema aunque sean datos de mierda. Eso no me preocupa.

A ver, el bucle que incializa lee bien, en orden, 12, 11, 11. No debería pararse ...  Escribamos otras lecturas.

Escribo justo después de meter en el array y me aparece el correcto, pero luego en la tabla hay `$00 $30 $C0` en vez de `$70 $30 $C0`...

En serio wtf?

Voy a poner un break point en escrituras a 0x5c7

HM ¡detecto dos escrituras! Y la segunda con un 0. Pero a saber qué coño es XDDDD

El código es un `STA ($BA),Y @ $05C7 = #$00`. ¿Qué hay en `$BA`? `.ptr1`... Eso es interno. No es mío, joder. A saber qué hace eso :-/

Voy a poner pausas en el código para acotarlo. Joe, qué coñez. 

- Al final de `game_init` ya está a `0`...
- Tras salir de `persistent_enems_load` también ¡?!
- Al final de su vuelta (para la pantalla `0x10`) ya no. Hay algo que lo jode todo después! Puedo intentar saber el valor de gpit, espera...

¿gpit == 0? :-S

¿Qué está pasando aquí ? :-O

~~ 

He cambiado la estrategia. Estoy parando la ejecución y esperando a PAD_A tras escribir cada pantalla de enemigos. Al escribir la siguiente (pantalla 15) se pone un en ep_x. Si miro ep_y, también se sobrescribe!!

En la pantalla anterior, la 0x0f, ha escrito ep_x == a0 40 d0... Espera, porque en la pantalla 0x0f NO HAY NADA! ¿Qué hace escribiendo?

Pantalla 0x0e, está bien: 0x60, 0xA0, --

La pantalla 0x0d, --, --, --: Este se lo ha saltado guay.

Ahí va a estar el quid... En la pantalla C no hay nada tampoco, a ver qué escribe...

    70 40 d0... Mal también.

Esto está MUY mal. Voy a revisar que se lo salte bien.

~~

O la expresión "cortificada" estaba mal, o cc65 se estaba haciendo la picha un lío con ella, pero la he "descortificado" y ahora parece funcionar guay.

Jodó.

Bueno y ahora... ¿qué estaba haciendo yo? No sé, probablemente terminando de poner cosas en la fase 3 y pensando cómo mejorar los jodidos fantis. Creo que deberían irse más lejos cuando rebotamos contra ellos. Yo pondría el componente de Y al máximo, pero eso requeriría un patch, creo.


Joer, esto no acaba. ¿por que me da ahora la impresión de que las transiciones de pantalla son tan lentas? ¿Eran así antes o he hecho algo raro?

En la ROM 1 es mucho más rápido. Sé que cambié el cálculo de las sombras, pero ... Joder. Me parece mucha tela. Voy a probar.

```c
        rdb = (scr_attr [gpit - 16] & 8);
        rdd = ((gpit & 0xf) == 0);
        vram_adr (gp_addr++);
        vram_put (*(((rdd ? rdb : (scr_attr [gpit - 17] & 8)) ? 64 : 0) + gp_tmap));
        gp_tmap ++;
        vram_put (*((rdb ? 64 : 0) + gp_tmap));
        gp_tmap ++;
        gp_addr += 31;
        vram_adr (gp_addr++);
        vram_put (*((((scr_attr [gpit - 1] & 8) && !rdd) ? 64 : 0) + gp_tmap));
        gp_tmap ++;
        vram_put (*gp_tmap);
```

Sí que erea eso :-O Pues o se me ocurre un algoritmo menos pester o se queda el viejo. Otra cosa para pensar y perder la salud.

~~

Qué harture.

~~

12
3

Lo voy a intentar hacer más sencillo. 1 si ARRIBA o IZQUIERDA o ARRIBIZQUIERDA, 2 si ARRIBA, 3 si IZQUIERDA.

Si fuera así el mundo sería feliz, pero eso se me esbocia en los bordes. si Y = 0, ARRIBA = 0; si X = 0, IZQUIERDA = 0. Pero son más IFs.

```
    rdc = (gpit > 0x0f)
    rdd = (gpit & 0x0f)
    arribizquierda es rdc && rdd && (scr_attr [gpit-17] & 8)
    rda = izquierda es rdd && (scr_attr [gpit - 1] & 8)
    rdb = arriba es rdc && (scr_attr [gpit - 16] & 8)
```

Es incluso más complejo. Que le den por ahora.

~~

¿Queda muy feo si pongo sombra solo abajo? Test.

No, queda bien. Y es bastante más rápido.

~~

Ya he colocado toda la mierda de la fase 4, pero creo que me ha salido demasiado complicada. Hay demasiadads partes demasiado frustrantes. Tengo que jugarlo despacio y con buena letra para que quede difícil, pero justa. También es que he probado con el jodido teclado, tengo que darle un tiento con mando.

Voy a hacer un compare entre dev-a y dev-b para ver qué mejoras he hecho en el motor / configuración que deba propagar a la ROM 1, y luego ya lo dejo que estoy harto.

20170502
========

Muchos días sin escribir y tal y cual, pero bueno. Seguimos. La fase 4 está terminada y validada. En el interim he corregido un montón de detallitos tontos en las dos dev-a y dev-b, que intento llevar sincronizadas en cuanto a código de base se refieren.

Quiero hacer ahora la fase en la que el mapa cambia de configuración.  Tengo que pensar bien cómo voy a montar esto:

- Todas las habitaciones tienen 4 salidas; la conexión entre estas 4 salidas se resuelve en cada habitación.
- Todas las habitaciones son conectables. Empezaré el mapa con una plantilla.
- Si pasas a una nueva habitación, el nuevo n_pant es al azar, pero
- Si lo que haces es volver a tomar la salida por la que has entrado en la pantalla, la habitación anterior seguirá ahí.

Veamos, vamos a hablar así al pedo que se me suele ocurrir las cosas...

- Debo guardar por dónde he entrado a la pantalla actual: `entry = ENTRY_TOP`, `ENTRY_RIGHT`, `ENTRY_BOTTOM`, `ENTRY_LEFT`.
- Debo almacenar la última pantalla en la que estuve: `prev_pant`;
- A la hora de salir, si estoy saliendo por el mismo sitio almacenado en entry, `n_pant = prev_pant`; si no, `n_pant = rand8 () & 0xf`.
- En el momento de salir, almacenar bien prev_pant con el valor de la pantalla actual y entry con el valor de la salida correcta.

Creo que con lo de arriba funcionará guay y no será una paranoia rara. Voy a escribirlo en código y luego ya lo iré integrando cuando tenga mierda.

Quiero cambiar la paleta por algo más azulado / oscuro y pensar en qué parte del cuerpo lo voy a meter, que tenga sentido.

~~

Creo que lo he resuelto bastante bien, aunque todo cuenta: tener DOS roms para este juego me está resultando muy cómodo, aunque no quiero dormirme en los laureles.

La cacca es que necesitaría ponerme pero que ya a hacer otras músicas, y la inspiración musical suele rehuírme últimamente - o quizás siempre. Siempre recuerdo con añoranza la composición y elaboración de la OGT de Jill a principios de los 2000, pero la mente todo lo adorna, y es posible que las músicas fuesen goteando durante toooodo un año.

~~

He hecho el tileset y paleta y he empezado con el mapa, pero ahora cac.

20170503
========

La fase 5 está completamente terminada. Ahora sólo falta la fase 6. Tengo que inventarme algo chulo para terminar. No creo que tenga espacio para un boss (en patrones, me refiero), pero lo miraré. Hacer algo parecido al boss de Cave podría molar.

Hmmm. Había hablado de crear una especie de modificación de los enemigos lineales para pintarlos 8 pixeles más abajo de donde están definidos y que pudiese así simular destellos de electricidad en conductores, rollo impulso nervioso. Esto sería muy básico de implementar (incluso via parche, si el sprite es ID6, por ejemplo).

La idea del Boss también me llama, la verdad, y creo que hay espacio para combinar ambas cosas.

Quiero dejar algunos patrones de tiles para la secuencia final, una escena espacial en la que se vea un bicho muy amorfo y la nave espacial de PDT6 saliendo de lo que parece un culo.

Voy a ver como andamos de patrones, así, en general.

~~

Tengo 64 patrones en el set de sprites.

Idea de boss barato:

- Rollo homing fanty, con una vista muy corta.
- Hay que ir a por él para que te siga y llevarlo a un sitio que mate, por ejemplo, una cataract.
- Cuando recibe un golpe entra en estado de invulnerabilidad y vuelve a su sitio.
- Hay otros bichos en pantalla para jodel.

Creo que esto funcionará. Ahora tengo que ver qué aspecto darle, y ver como aprovechar los 64 patrones y que se vea lo suficientemente grande.

~~

He hecho a Vira como he podido. A ver cómo se come los patrones de sprites...

~~

¡Muy bien! Lo has dejado en 24 patrones y ni siquiera es feo. Ahora tengo que hacer un tileset en el que destaque el azul. Quizá si cojo el original de la fase 4 y lo pongo más a lo amarillico, rositado, etc. podría valer.

~~

Pero antes de meter al boss quiero meter las partículas necesarias para que los sopladores parezcan sopladores. Debería extender un poco los "hearts" que uso para las burbujas. Vamos a echarles un vistazo.

~~

Todo hecho, incluso sprites del BZZZ que quería poner y todo importado y metido.

Originalmente quería meter el boss al final de un nivel, pero creo que lo suyo es que haga un nivel y luego el boss por separado en una fase muy corta. No sé si me apetece más ahora hacer la fase corta del boss (pantalla antes, pantalla boss, pantalla después) y dejar la otra normal para el final, o al revés. 

La fase extra será la de las conexiones neuronales y tendrá esos rayos tan molones rampando a toda velocidad por plataformas no transpasables (los huesos). La haré lineal, con un buen número de pantallas, por ejemplo 20. La voy creando y luego si eso ya actualizo el git.

20170505
========

Tengo la terrible sensación de que la he liao con los commits y las cosas y que he perdido mierda. Pero terrible sensación.

En fin, luego lo comprobaré. Ahora quiero darle a Viras. Por ahora he replicado a los homing fanties. Tengo que meter un estado extra y luego pinchar la colisión. En este juego es el único enemigo que debe colisionar con algo que mate y morir.

Por el momento voy a ver que se pinte bien el sprite y tal y cual.

~~

Me acabo de dar cuenta que el tema de la colisión de los homing fantis percalculados esta muy mal (solo funciona en el estado PUSUING). Cuando la corrija tendré que propagar los cambios hacia atrás a Cheril Perils.

~~

Viras go go go!

Voy a unificar de nuevo los cambios en ambos engines dev-a y dev-b y lo dejo para mañana lo de hilar las dos ROMs. Y tengo que responder a Paul, pero eso lo haré mañana más tramquilo.

20170507
========

Muchas cosas hechas. Las dos ROMs ya forman parte de un todo. Me falta ampliar un poco la OGT, montarla, y pintar el final. Para el final quería poner un dibujo en el espacio con un super alien y un escape pod saliéndole del ohio. Tengo 64 patrones (en realidad 69, pero me gusta dejar algo de holgura por si acaso) de bg para pintar el alien y bastantes de sprites para hacer el escape pod. Tampoco hay que liarla mucho. Aunque no sé muy bien como currarme el final, no quiero tener que meter otra rutina de mostrar textos solo para eso, así que lo suyo quizá sería mostrar un texto y luego poner el dibujo final en estático.

20170508
========

Yo ya no sé qué apunto y qué no o si me piso o si me paso.

No está nada fino el hilado, pero nada fino. Hay un glitchazo bestial al cambiar de fase: primero el hud no aparece, y luego se va degradando todo fase a fase, hasta que se llega a la fase donde está el cambio de ROM. Ahí ya empieza a ir bien, supongo que porque se reinicializará algo. 

El tema es que probando, si desactivo la llamada a `game_event` que muestra el mensajito de "Stage Clear", se soluciona el problema.

Voy a volver a modo sencillo (NROM, sin montar) a ver si ocurre el problema, y miro qué puede ser. Es posible que sea un bug introducido desde Yun (que es donde aparecieron estas construcciones) y que estuviese enmascarado.

~~

Ya te digo que ocurre en NROM. Y el glitchazo es incluso más bestia. Voy a comentar la llamada a `game_event`... Funciona. El problema está ahí. ¿qué puede ser? Voy a ponérmelo todo aquí para verlo en perspectiva. Genital.

```c
    rdb = 0xfd; game_event ();

    // [...]

    void game_event (void) {
        enter_screen (palts1, screen_event);
        do_screen (5);
    }

    // [...]

    void screen_event (void) {
        cls ();
        switch (rdb) {
            /*
            case 0xfc:
                // Cutscene
                //vram_adr (NAMETABLE_A);
                //vram_unrle (event_rle);
                break;
            */

            case 0xfd:
                // Stage clear
                p_s (10, 15, "STAGE CLEAR!");
                break;

            case 0xfe:
                // Game over
                p_s (11, 15, "GAME OVER!");
                break;

            case 0xff:
                // Ending
                vram_adr (NAMETABLE_A);
                vram_unrle (ending_rle);
                break;
        }
    }
```

Por lo pronto, `enter_screen` ya tiene su `cls ()` al principio, así que lo quito de `screen_event`. Y probamos, por probar que no quede.

Nada, sigue el glitchazo. Por estupidear, voy a hacer que en vez de a llamar a `screen_event`, la función `game_event` llame a otra, por ejemplo `screen_title`.

Nada, glitchazo igual. Qué misterio.

A ver, llevo usando esto un eón. Debe haber algo que me estoy perdiendo. Voy a burrear del todo. Voy a dehsacer todas las llamadas a funciones y voy a meter este trozo en su lugar, a ver qué pasa:

```c
    cls ();
    pal_bg (palts1);

    p_s (10, 15, "STAGE CLEAR!");

    ppu_on_all ();
    fade_in ();

    game_time = 10; ticker = 0;
    wait_time_or_input ();
    
    oam_hide_rest (0);
    music_stop ();
    fade_out ();
    ppu_off (); 
```

Que no es más que el código que se va llamando en las llamadas anidadas... ¡¡GLITCH!!

Y reduciéndolo a la mínima expresión...

```c
    cls ();
```

Funciona. Voy poniendo y quitano cosas hasta que encuentre con la manzana de la discordia. O con la pera.

~~

¡¡¿Es la llamada a `p_s`?!!

A ver, tío, no puede ser. Tiene que ser un efecto colateral. Llevo usando p_s toda mi puta vida. Vamos a probar cualquier otra actuación sobre la pantalla, por ejemplo:

```c
    vram_adr (NAMETABLE_A + 330);
    vram_put (33);
```

Eso no causa glitch.

Jodó.

Es que llame con lo que llame, p_s lo jode todo. Que alguien venga y me lo explique, porfa.

~~

Porque la puta llamada a game_event para que en vez de STAGE CLEAR! ponga GAME OVER! funciona con to sus muertos.

~~

El tema es ese: cualquier "`p_s` ejecutado justo entre ejecuciones del main loop jode la marrana". O al menos eso es lo que observo. Quito el `p_s` y funciona perfe. Imprimo cualquier otra cosa en al pantalla (bueno, una 'a') y no.

HUM.

¿Será cosa de que me dejo el update list encendido o algo? ¿Algo que no cierro bien en `game_loop` ?

Mierda, tengo el `set_vram_update (0)` misteriosamente comentado en `exit_cleanly`... ¿A que va a ser eso? Pues no es eso, pero no está de más.

Hmmm, es que es como si el pattern generator no estuviese leyendo los patrones de donde debe... ¿pero qué causa esto? Porque no es solo que no pinte el hud, es que luego cuando empieza a pintar el mapa ya está haciéndose la picha un lío.

Joder, detesto perder el tiempo con estas cosas.

Sigo divagando. La principal diferencia con Yun y Perils es que al final del main loop, justo cuando ha salido del bucle principal porque `do_game == 0`, hace una llamada al tema de los diálogos, que emplean el update list:

```c
    // CUSTOM {
    if (!pkilled) {
        rda = MAX_LEVELS + level;
        run_talk_script (); 
    }
    // } END_OF_CUSTOM
```

Esto ocurre cuando lo último, últimísimo que ha ocurrido en el main loop es:

```c
    oam_hide_rest (oam_index);
    *ul = NT_UPD_EOF;
```

O sea, que es así como llegamos a la función `run_talk_script`. Voy a hacer la prueba y a no llamar a esto.

No, no es esto.

~~

Puede ser cualquier puta cosa.

~~

Me está empezando a acojonar el hecho de que glitchée diferente dependiendo del emulador. Algo muy chungo está pasando.

¿Qué puede ser tan chungo que en el emulador nester se jodan los CHR? ¿Está esto escribiendo en ese area de memoria de forma que nester, que quizá no la protege en modo NROM, está cargándose los patrones? 

Voy a poner algún breakpoint entre $0000-$1FFF de la PPU.

~~

Bingow. Hay un write a CHR-ROM después de que la pantalla de STAGE CLEAR se haya borrado. Saber en qué parte del código está pasando y por qué ocurre esto va a estar complicado. No sé qué puedo estar haciendo mal. Según el debugger de fceux, el código que está haciendo esto es así:

```
 00:8394:A8        TAY
 00:8395:86 1E     STX $001E = #$EE
 00:8397:A9 00     LDA #$00
 00:8399:85 1D     STA $001D = #$00
 00:839B:B1 1D     LDA ($1D),Y @ $EE23 = #$01
 00:839D:85 1F     STA $001F = #$01
 00:839F:C8        INY
 00:83A0:D0 02     BNE $83A4
 00:83A2:E6 1E     INC $001E = #$EE
 00:83A4:B1 1D     LDA ($1D),Y @ $EE23 = #$01
 00:83A6:C8        INY
 00:83A7:D0 02     BNE $83AB
 00:83A9:E6 1E     INC $001E = #$EE
 00:83AB:C5 1F     CMP $001F = #$01
 00:83AD:F0 07     BEQ $83B6
>00:83AF:8D 07 20  STA $2007 = #$00
 00:83B2:85 20     STA $0020 = #$08
 00:83B4:D0 EE     BNE $83A4
 00:83B6:B1 1D     LDA ($1D),Y @ $EE23 = #$01
 00:83B8:F0 10     BEQ $83CA
 00:83BA:C8        INY
 00:83BB:D0 02     BNE $83BF
 00:83BD:E6 1E     INC $001E = #$EE
 00:83BF:AA        TAX
 00:83C0:A5 20     LDA $0020 = #$08
 00:83C2:8D 07 20  STA $2007 = #$00
 00:83C5:CA        DEX
 00:83C6:D0 FA     BNE $83C2
 00:83C8:F0 DA     BEQ $83A4
 00:83CA:60        RTS 
```

Voy a ver qué parte de neslib es esta. Porque tiene aspecto de neslib.

Es la función VRAM_RLE.

Ahí se supone que está mandando tiles via `$2007` porque antes ha colocado la dirección donde va a escribir usando el registro `$2006` en 

```
    ;void __fastcall__ vram_adr(unsigned int adr);

    _vram_adr:
        stx PPU_ADDR
        sta PPU_ADDR
        rts
```

De hecho, si miro en el emulador, `$2006` = 0. Y es raro, porque estoy llamando a vram_adr justo antes con `vram_adr (NAMETABLE_A)`.

Voy a poner un breakpoint en donde cae la función vram_adr, que es en `$84E0` en esta compilación.

~~

Después de la pantalla de STAGE CLEAR, fade out, ppu_off, hay estas llamadas: 

- con adr = 0x2000. (debe ser en hud_draw).
- Luego el código carga 0x21 en A y 0xEE en X, y llama a `$8394` (vram_unrle).
- Y aquí dentro es cuando me salta el breakpoint por estar intentando escribir a PPU `$0620`. Y no me he fijado en cuando cambia eso.

Vamos a repetir la prueba. Volvamos al punto de después del fade out tras el main loop. Aquí, tenemos que PPU = 43A0, por alguna razón, y entonces se llama a vram_adr. A = `$00`, X = `$20`, o sea, pasándole el entero `$2000`. Antes del RTS de esta función compruebo que PPU = `$2000`, que está bien.

Luego le doy a RUN y esto hace su mierda. Ahora PPU = `$2400`, así que supongo que sería la llamada a `cls ()`.

La siguiente llamada a `ppu_addr` es con A = `$EA`, X = `$21`. La dirección PPU = `$21EA` es la coordenada (10, 15), que corresponde a `p_s (10, 15, "STAGE CLEAR!");`. Voy a tracera eso. Debería dar exactamente 12 vueltas de bucle y terminar en `$21F6`

Estoy en el punto en el que PPU = `$21F6`, justo después de una llamada a `vram_put`. Voy a ver qué hace ahora.

Vale, sale de p_s.

Y luego, ejecutando ejecutando, veo que tras un `JSR $82BA`, PPU = `$0000`. 

Mientras el fade in, PPU = `$0000` todavía. 

Luego de la pantalla, fade out y PPU = `$43A0`. 

Y ahora viene la llamada que supuestamente te quema: `ppu_addr (0x2000)`. Vamos despacio.

Le ha mandado, que lo he visto, `$20` y luego `$00`... Pero PPU = `$0620`. 

Y eso es lo raro. Voy a llamar DOS veces a `ppu_addr` y a leer la documentación sobre como funciona `PPU_ADDR`. Porque estoy dejando esto fritos fritos fritos. 

Veo que se establece la dirección de la PPU en la primera escritura a `PPU_ADDR`, por lo que estoy seguro de que el latch que controla qué mitad se escribe no está en su sitio. ¿Por qué? ¡Quién sabe!

~~

Me parece que el quid de la cuestión va a ser monitorizar las escrituras a `$2006` y así ver dónde está la que se "me escapa", o eso o curarme en salud y leer `PPU_STATUS` antes de poner la dirección nueva para resetear el latch. Pero me mosquea que haya por algún lado una escritura no controlada. El tema ocurre entre que se termina de imprimir la cadena y que se llama a `ppu_addr` para imprimir el hud. Al menos lo tengo más o menos controlado.

~~

Durante todos los waits se están ejecutando bien pareados los de la NMI.

Joder, qué difícil de ver.

~~

Llevo demasiado tiempo mirando y perdiendo la salud. Puede ser cualquier cosa. Creo que voy a poner un parche y a mirar a otro lado. Hay que leer PPU_STATUS ¿no? Pues sea.

A ver si así.

Sí, así sí. A tomar por culo. No soy tan dale fran.

~~

Ahora el tema es que de la fase 2 (tercera), última de la ROM1, salta a la fase 4 (quinta), segunda de la ROM2. Why. Fuck.

~~

Parece que llega a ROM2 con `COMM_STATS_LEVEL` = 4, misteriosamente, aunque quién sabe. Todo puede ser y yo estoy hasta los cullons.

~~

En efecto, asegurado con while mamporrero. Ahora a ver por qué coño pasa eso y no salta con la puta fase 3.

~~

Vale 4 porque es el jodido valor inicial. Parece que la doble indirección de defines (yo me entiendo) viene muy bien para leer pero no para escribir. Joder con los putos bugs del compilador.

~~

Creo que el compilador está pasando de mi otra vez saltándose las lineas que le pongo con su puta madre.

Mira, no sé, el código lo genera pero no hace su puta vida. Estoy cada vez más cansado. Voy a mirar una vez más con el debugger a ver y si no veo nada en 10 minutos a tomar por culo.

~~

Ya ves, muevo el código que prepara el `comm_pool` para saltar las ROMs a una función para que me salga en la lista de símbolos y poder encontrarlo en el debugger... Y ahora funciona.

Lo que no actualiza ahora guay es el número inicial de vidas. Y eso me toca el coño ya.

Lo muevo a una función `autosave_game` y ya funciona.

En fin, a lo mejor es hora de actualizar cc65

Voy a dejarlo por hoy.

20170521
========

Más tests. Ogt de Journey puesta al 100%. Ogt de Cave montada (al final uso la de SGTD en la fase 3 porque me encanta y estoy acostumbrado), pero faltaría el loop para el boss fight y, si entra, un loop para el título.

Mañana o bien hago eso o bien hago música para Espinete y cambio algo de su aspect

20170731
========

Todo está terminado. Llegó el momento de Pulir. Ahora voy a ir juego por juego del menñu y a ir arreglando y puliéndolo todo, jugando y tal, mierder potierder.

Empezamos por el principio. De los ocultos, considero "oficiales" Dark Yun y Cheril Perils. El resto me da igual que glitchée.

Journey to the Centre of the Alien
----------------------------------

- Revisa un poco la colisión culo para hacerla levemente más ventajosa para PDT6
- Forzar ppossee para activar el relay
- Revisar morir en pinchos, ha ido a pantalla negra en Viras, podría ser del emulador, pero me ha dado la impresión de que ha traspasado pinchos. - Digo, traspasa pinchos si está parpadenado. Pero por que no vuelve al safe point? <- Porque está registrando un safe point al coger el bocadillo.

Eso es otra. Por diseño los pinchos no te matan si estás en parpadeante. Vale, puedo arreglar eso. Pero no debería registrar safe spot si estás parpadenate.

- No registrar safe spot si estás parpadeante.

Toqué: 

```
	- dev-?/engine/player.h
	- dev-?/engine/hotspots.h
	- dev-?/engine/enems.h
	- dev-b/engine/enemmods/enem_viras.h
	- dev-b/engine/enemmods/enem_collisions_extras.h
```
