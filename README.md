# Minigames

Colección de minijuegos de consola escritos en C.

## Wordle

Versión de consola del juego **Wordle**: el jugador tiene que adivinar una palabra secreta y el programa le indica qué letras acertó.


### Funcionalidades

- **Validación de la entrada:** la palabra tiene que tener la cantidad exacta de letras y contener solo letras. Si el texto supera el largo permitido, se descarta el resto del buffer para no afectar la próxima lectura.
- **Mayúsculas y minúsculas:** la entrada se pasa a minúsculas antes de compararla.
- **Letras repetidas:** el programa cuenta cuántas veces aparece cada letra en la palabra secreta, para que una letra no se marque más veces de las que realmente está.

### Cómo se muestra el resultado

| Símbolo | Significado                                 |
|---------|---------------------------------------------|
| `O`     | Letra correcta en la posición correcta.     |
| `=`     | La letra está en la palabra, en otro lugar. |
| `×`     | La letra no está en la palabra.             |


### Próximas mejoras

- Varios intentos (por ejemplo, 6, como en el juego original).
- Elegir la palabra secreta al azar desde un archivo de palabras.
- Mostrar el resultado con colores en la consola.
- Más juegos en la colección.

## Conceptos aplicados

Manejo de cadenas en C · validación de entrada · memoria dinámica (`malloc`/`free`) · estructuras (`struct`) · conteo de frecuencias.
