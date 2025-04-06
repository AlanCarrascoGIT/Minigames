#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define EQUIVOCADO 158
#define CORRECTA 'O'
#define VACIO '-'
#define OTRO_LUGAR '='


typedef struct {
	char letra;
	int cant;
} LETRAS;
typedef	struct {
	LETRAS* letras;
	int longitud;
} CONTADOR;

int es_palabra(char* cadena);

static void limpiar_buffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

char* quitar(char* palabra);
int check_amarillo(char* palabra, char caracter, CONTADOR* completa);
int check_verde(char letra, char caracter, CONTADOR* completa);
void a_minus(char* palabra, int len);
void contar_palabra(LETRAS* cont, char* palabra, int tam);
int check_word(char* palabra, char* input);
int main()
{
	char palabras[4][10] = { "PASTAAL","ChAu","comIDA","pASta" };
	int tamanio = strlen(palabras[0]) + 1;
	char* input = malloc(tamanio);
	for (int i = 0; i < 4; i++){
		a_minus(palabras[i], strlen(palabras[i]));
		printf("%s\n", palabras[i]);
	}
	while (1) {
		if (fgets(input, tamanio, stdin) != NULL) {
			// Si la cadena ingresada es más larga, limpiar el buffer
			if (strchr(input, '\n') == NULL) { // Si no hay '\n', significa que la entrada fue mayor al buffer
				limpiar_buffer();
			}

			// Eliminar el sala de línea si está presente
			input[strcspn(input, "\n")] = '\0';

			printf("Los caracteres ingresados son: \"%s\"\n", input);
			if (strlen(input) == strlen(palabras[0]) && es_palabra(input)) {
				break; // Salimos del bucle si es válida
			}
			else {
				printf("Entrada invalida.Debe tener exactamente %d caracteres y solo letras.\n", strlen(palabras[0]));
			}
		}
		else {
			printf("Error al leer la entrada.\n");
		}
	}
	while (1) {
		a_minus(input, tamanio);
		if (check_word(palabras[0],input)) {
			break;
		}
	}


	return 777;
}

void contar_palabra(LETRAS* cont, char* palabra,int tam) {
	for (int i = 0; i < strlen(palabra); i++) {
		for (int j = 0; j < tam; j++) {
			if (cont[j].letra == palabra[i]) cont[j].cant += 1;

		}
	}
	return;
}

char* quitar(char* palabra) {
	int len = strlen(palabra);
	char* clean = malloc(len + 1);

	int j = 0;
	for (int i = 0; i < len; i++) {
		// Verifica si el carácter ya está en la nueva cadena
		if (!strchr(clean, palabra[i])) {
			clean[j] = palabra[i];
			j++;
		}
	}
	clean[j] = '\0'; // Terminar la nueva cadena

	return clean;
}

int check_verde(char letra, char caracter, CONTADOR* completa) {
	int result = 0;
	
	if (letra == caracter) { 
		for (int i = 0; i < completa->longitud; i++) {//se podria hacer una funcion para esa 
			if (completa->letras[i].letra == caracter) {
				completa->letras[i].cant -= 1;
				result = 1;
				break;
			}
		}
	}

	return result;
}

int check_amarillo(char* palabra, char caracter, CONTADOR* completa) {
	int result = 0;

	if (strchr(palabra,caracter) != NULL) {
		for (int i = 0; i < completa->longitud; i++) {//se podria hacer una funcion para esa 
			if (completa->letras[i].letra == caracter && completa->letras[i].cant > 0) {
				completa->letras[i].cant -= 1;
				result = 1;
				break;
			}
		}
	}
	
	return result;
}

int check_word(char* palabra, char* input){
	char* temp = malloc(strlen(palabra) + 1);
	char* sinRep = quitar(palabra);
	int len = strlen(palabra);
	temp[len] = '\0';
	int lenSinRep = strlen(sinRep);
	LETRAS* letrasCont = malloc(sizeof(LETRAS) * lenSinRep);
	CONTADOR* cont = malloc(sizeof(CONTADOR));

	
	for (int i = 0; i < lenSinRep; i++) { 
		letrasCont[i].letra = sinRep[i];
		letrasCont[i].cant = 0;
	}

	cont->letras = letrasCont;
	cont->longitud = lenSinRep;
	
	printf("%s\n", sinRep);
	contar_palabra(letrasCont, palabra, lenSinRep);

	for (int i = 0; i < len; i++) {
		temp[i] = EQUIVOCADO;
	}

	for (int i = 0; i < len; i++) {
		if (check_verde(palabra[i], input[i], cont)) {
			temp[i] = CORRECTA;
		}
	}
	for (int i = 0; i < len; i++) {
		if (check_amarillo(palabra, input[i],cont)) {
			temp[i] = OTRO_LUGAR;
		}
	}
	printf("%s\n",temp);
	return 1;
}

void a_minus(char* palabra, int len) {
	for (int i = 0; i < len; i++) {
		if (palabra[i] >= 65 && palabra[i] <= 90) {
			palabra[i] += 32;
		}
	}
}
int es_palabra(char* cadena) {
	for (int i = 0; cadena[i] != '\0'; i++) {
		if (!((cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] >= 'a' && cadena[i] <= 'z'))) {
			return 0; // No es válida si hay algo fuera de 'A-Z' o 'a-z'
		}
	}
	return 1; // Es válida
}
