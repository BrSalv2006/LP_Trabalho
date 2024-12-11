/**
    @file main-team-8.c
*/

#include "functions-team-8.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ArraySize 20 ///< Tamanho do Array
#define Minimum 8    ///< Número Mínimo Válido do Array
#define Maximum 29   ///< Número Máximo Válido do Array

int *OriginalArray;     ///< Declarar Array dos números introduzidos
int *IntegerArray;      ///< Declarar Array de Inteiros
int **Matrix;           ///< Declarar Array de duas dimensões
int **TransposedMatrix; ///< Declarar Array de duas dimensões para a Matriz Transposta
float *FloatArray;      ///< Declarar Array de Reais

/// @brief Mostrar Menu
/// @param OriginalArray Array com os números introduzidos
void Menu(int *OriginalArray) {
	int MenuChoice, ValidMenuChoice;
	PrintIntegerArray(OriginalArray, "Vetor Original:", ArraySize);
	printf("Menu:\n");
	printf("1  - Vetor ordenado por ordem crescente\n");
	printf("2  - Soma da primeira metade dos elementos no vetor com os da segunda metade\n");
	printf("3  - Matriz 20x20 com o vetor original e algumas das suas permutações\n");
	printf("4  - Cosseno da segunda metade dos elementos no vetor\n");
	printf("5  - Elemento aleatório do vetor\n");
	printf("6  - Elementos em posições múltiplas de 3\n");
	printf("7  - Menu de ajuda\n");
	printf("8  - Sair\n");
	printf("9  - Misturar metade de cada vetor\n");
	printf("10 - Mínimo múltiplo comum de cada dois números seguidos do vetor\n");
	printf("11 - Matriz 20x20 do produto de um vetor aleatório 1x20 e o vetor original\n");
	printf("12 - Matriz 20x20 transposta do produto de um vetor aleatório 1x20 e o vetor original\n");

	ValidMenuChoice = scanf("%d", &MenuChoice); // Guardar se escolha é válida
	ClearTerminal();                            // Limpar Terminal
	if (ValidMenuChoice == 1) {                 // Verificar se existe uma escolha válida
		switch (MenuChoice) {
		case 1:
			PrintIntegerArray(SortAscendingOrder(OriginalArray, IntegerArray, ArraySize), "Vetor ordenado por ordem crescente:", ArraySize); // Ordenar e Mostrar Array ordenado
			DisposeIntegerArray(IntegerArray);                                                                                               // Libertar Memória do Array
			Menu(OriginalArray);                                                                                                             // Abrir Menu
		case 2:
			PrintIntegerArray(AddFirstSecondHalf(OriginalArray, IntegerArray, ArraySize), "Soma da primeira metade dos elementos no vetor com os da segunda metade:", ArraySize / 2); // Calcular e mostrar soma da primeira metade dos elementos do Array com os da segundo metade
			DisposeIntegerArray(IntegerArray);                                                                                                                                        // Libertar Memória do Array
			Menu(OriginalArray);                                                                                                                                                      // Abrir Menu
		case 3:
			Matrix = GeneratePermutedMatrix(OriginalArray, Matrix, ArraySize);                                          // Gerar Matriz de permutações
			PrintIntegerMatrix(Matrix, "Matriz 20x20 com o vetor original e algumas das suas permutações:", ArraySize); // Mostar Matriz de Permutações
			Matrix = DisposeMatrix(Matrix, ArraySize);                                                                  // Libertar Memória do Array de duas dimensões
			Menu(OriginalArray);                                                                                        // Abrir Menu
		case 4:
			PrintFloatArray(CosineSecondHalf(OriginalArray, FloatArray, ArraySize), "Cosseno da segunda metade dos elementos no vetor:", ArraySize / 2); // Calcular e Mostrar cosseno da segunda metade do Array
			DisposeFloatArray(FloatArray);                                                                                                               // Libertar Memória do Array
			Menu(OriginalArray);                                                                                                                         // Abrir Menu
		case 5:
			PrintInteger(RandomElement(OriginalArray, ArraySize), "Elemento aleatório do vetor:"); // Escolher e Mostrar elemento aleatório do Array
			Menu(OriginalArray);                                                                   // Abrir Menu
		case 6:
			PrintIntegerArray(PositionsMultipleof3(OriginalArray, IntegerArray, ArraySize), "Posições múltiplas de 3:", ArraySize / 3); // Calcular e Mostrar Elementos em Posições Múltiplas de 3 do Array
			DisposeIntegerArray(IntegerArray);                                                                                          // Libertar Memória do Array
			Menu(OriginalArray);                                                                                                        // Abrir Menu
		case 7:
			Help(ArraySize, Minimum, Maximum); // Mostrar Ajuda
			Menu(OriginalArray);               // Abrir Menu
		case 8:
			exit(0); // Terminar Programa com Sucesso
		case 9:
			PrintIntegerArray(MixHalfEachArray(OriginalArray, IntegerArray, ArraySize, Minimum, Maximum), "Misturar metade de cada vetor:", ArraySize); // Mostrar a Mistura de metade do Array Original e outro Array Introduzido
			DisposeIntegerArray(IntegerArray);                                                                                                          // Libertar Memória do Array
			Menu(OriginalArray);                                                                                                                        // Abrir Menu
		case 10:
			PrintIntegerArray(LeastCommonMultiple(OriginalArray, IntegerArray, ArraySize), "Mínimo múltiplo comum de cada dois números seguidos do vetor:", ArraySize - 1); // Calcular e Mostrar mínimos múltiplos comuns entre dois números seguidos de um Array
			DisposeIntegerArray(IntegerArray);                                                                                                                              // Libertar Memória do Array
			Menu(OriginalArray);                                                                                                                                            // Abrir Menu
		case 11:
			Matrix = ProductBetweenTwoArrays(OriginalArray, IntegerArray, Matrix, ArraySize, Minimum, Maximum);              // Calcular Produto entre o Array Original e um Array gerado aleatoriamente
			PrintIntegerMatrix(Matrix, "Matriz 20x20 do produto de um vetor aleatório 1x20 e o vetor original:", ArraySize); // Mostrar Matriz do Produto entre o Array Original e um Array gerado aleatoriamente
			Menu(OriginalArray);                                                                                             // Abrir Menu
		case 12:
			if (Matrix == NULL) { // Verificar se Matriz é Nula
				printf("Antes de utilizar esta Opção é necessário utilizar a Opção 11\n\n");
				Menu(OriginalArray); // Abrir Menu
			} else {
				TransposedMatrix = TransposeMatrix(Matrix, TransposedMatrix, ArraySize);                                                              // Calcular Transposta do Produto entre o Array Original e um Array gerado aleatoriamente
				PrintIntegerMatrix(TransposedMatrix, "Matriz 20x20 transposta do produto de um vetor aleatório 1x20 e o vetor original:", ArraySize); // Mostrar Transposta do Produto entre o Array Original e um Array gerado aleatoriamente
				DisposeMatrix(TransposedMatrix, ArraySize);                                                                                           // Libertar Memória do Array de duas dimensões
				Menu(OriginalArray);                                                                                                                  // Abrir Menu
			}
		default: // Se Opção não existir
			printf("Opção Inexistente\n\n");
			Menu(OriginalArray); // Abrir Menu
		}
	} else {
		ClearInput();        // Limpar Input
		Menu(OriginalArray); // Abrir Menu
	}
}

/// @brief Verificar argumentos, solicitar Array e abrir menu
/// @param argc Número de Argumentos Introduzidos
/// @param argv Array dos Argumentos Introduzidos
/// @return Estado de Saída do Programa
int main(int argc, char **argv) {
	srand(time(NULL));                         // Iniciar Geração Aleatória com SEED do momento em que o programa foi executado
	for (int i = 0; i < argc; i++) {           // Repetir para todos os argumentos
		if (strcmp(argv[i], "--help") == 0) {  // Verificar se o argumento introduzido é o argumento para abrir a ajuda
			Help(ArraySize, Minimum, Maximum); // Mostrar Ajuda
			printf("Pressione Enter para fechar a Ajuda\n");
			getchar();       // Esperar por Input do utilizador para fechar a ajuda
			ClearTerminal(); // Limpar o Terminal
			return 0;        // Terminar Programa com Sucesso
		}
	}
	OriginalArray = AllocateIntegerArray(OriginalArray, ArraySize); // Alocar Memória para o Array
	RequestArray(OriginalArray, ArraySize, Minimum, Maximum);       // Preencher o Array
	Menu(OriginalArray);                                            // Abrir Menu
}