# Proprogramadores
Programación de un videojuego sencillo empleando C++ y la programación orientada a objetos.

## Diseño
El tipo de videojuego seleccionado es un juego de plataformas en 2D estilo Metroid, en el que el jugador puede disparar para eliminar a los distintos enemigos mientras intenta atravesar un nivel con obstáculos para llegar a la zona final, donde se enfrentará con un jefe. El juego contará con 5 niveles, cada uno con su mapa y su jefe, aumentando la dificultad a medida que se avance de nivel, siendo el jefe del nivel 5 el jefe final, al cual habrá que vencer para ganar el juego.
###### Pantalla
Al iniciar el juego aparecerá una pantalla de inicio, de forma que al ejecutar el programa no comience inmediatamente un nivel. Durante el juego, el mapa no será visible en su totalidad, si no que la “cámara” seguirá al jugador continuamente, situando a este en el centro de la pantalla y dejando visible solo una parte del mapa. Finalmente, al terminar una partida aparecerá una pantalla de puntuación.
###### Jugador
El personaje controlado por el jugador podrá moverse hacia los lados de la pantalla y saltar, además de disparar en línea recta en la dirección que esté mirando. El arma empleada podrá ser mejorada durante el transcurso del juego mediante los bonus.
###### Bonus
Distintos bonus podrán ser recogidos por el jugador en el transcurso del juego. 
-	**Disparo triple**: el jugador pasa a disparar proyectiles de tres en tres, pudiendo golpear a más enemigos a la vez.
-	**Disparo grueso**: el disparo común es sustituido por un disparo de mayor grosor que puede eliminar a más enemigos.
-	**Armadura**: hace al personaje invencible ante la mayoría de los obstáculos y enemigos.
-	**Bomba**: elimina todos los enemigos situados en la pantalla actual.
Todos estos bonus se podrán encontrar de forma aleatoria en el medio de un nivel o al matar a un enemigo. Los bonus duran hasta que el jugador se choque con un obstáculo o hasta que un enemigo le golpee, momento en el que el jugador regresa a su estado normal. Los bonus no podrán conservarse al pasar de nivel.
###### Obstáculos
Durante los niveles el jugador deberá sortear distintos obstáculos:
- **Obstáculo simple**: si el jugador cae en alguno de estos obstáculos, acabará la partida, a menos que cuente con un bonus, caso en el que el bonus desaparecerá y el jugador podrá seguir jugando sin la mejora obtenida.
- **Obstáculo absoluto**: de caer en este tipo de obstáculos, la partida finalizará, indiferentemente de si el jugador cuenta con algún bonus.
- **Obstáculo que mata pasado un tiempo**: si el personaje no sale de la zona designada en un tiempo determinado, acabará la partida. Sigue la misma dinámica que el obstáculo simple, de forma que si se cuenta con algún bonus primero se eliminará este.
###### Enemigos
En los niveles aparecerán distintos tipos de enemigos que el jugador deberá evitar o eliminar.
- **Enemigo simple con movimiento lineal eliminable**.
- **Enemigo saltarín eliminable.**
- **Enemigo inmóvil inmortal.**
- **Enemigo que dispara eliminable.**
- **Enemigo simple con doble vida.**
Los enemigos simples, saltarines y los que disparan pueden ser eliminados con un solo disparo del personaje. Para eliminar al enemigo con doble vida es necesario golpearlo dos veces, y para eliminar al enemigo inmortal solo se puede emplear el bonus de la bomba.
###### Jefes de nivel
Al final de cada nivel, el jugador se deberá enfrentar con un enemigo de mayor tamaño, poder y vida que los mencionados anteriormente. Estos jefes tendrán una barra de vida, y para eliminarlos será necesario golpearlos repetidamente en un lugar concreto de su cuerpo. La dificultad de vencer a los jefes aumentará a medida que avancen los niveles, siendo el más complicado de vencer el del nivel 5, que será el jefe final.
###### Puntuaciones
Al finalizar una partida se asignará una puntuación al jugador en base a los enemigos que haya sido capaz de eliminar. La puntuación obtenida por eliminar a los distintos enemigos es:
- Enemigo simple con movimiento lineal eliminable—**5 puntos**.
- Enemigo saltarín eliminable—**10 puntos.**
- Enemigo inmóvil inmortal—**100 puntos.**
- Enemigo que dispara eliminable—**20 puntos.**
- Enemigo simple con doble vida—**10 puntos.**
- Jefes de nivel—**100 puntos.**
- Jefe final—**500 puntos.**
