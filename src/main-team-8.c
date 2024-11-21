/**
    @file main-team-8.c
*/

#include "functions-team-8.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// Check Arguments, Request Array and Open Menu
int main(int argc, char *argv[]) {
	// Declarar Array
	int array[20];

	// Verificar Argumentos
	for (int i = 0; i < argc; i++) {
		if (strcmp(argv[i], "--help") == 0) {
			helpmenu();
			printf("Pressione Qualquer Tecla para fechar a Ajuda");
			getchar();
		}
	}

	// Pedir Array
	request_array(array);

	// Abrir Menu
	menu(array, 20);
}