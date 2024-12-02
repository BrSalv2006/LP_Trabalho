/**
    @file main-team-8.c
*/

#include "functions-team-8.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ArraySize 20
#define Minimum 8
#define Maximum 29

/// Função Mostrar Menu e Escolher Sub-Menu
void Menu(int *OriginalArray) {
	int MenuChoice, ValidMenuChoice;
	PrintIntegerArray(OriginalArray, "Vetor Original:", ArraySize);
	printf("Menu:\n");
	printf("1  - Vetor ordenado por ordem crescente\n");
	printf("2  - Soma da primeira metade dos elementos no vetor com os da segunda metade\n");
	printf("3  - Matriz 20x20 com o vetor original e algumas das suas permutações\n");
	printf("4  - Cosseno da segunda metade dos elementos no vetor\n");
	printf("5  - Elemento aleatório do vetor\n");
	printf("6  - Posições Múltiplas de 3\n");
	printf("7  - Menu de Ajuda\n");
	printf("8  - Sair\n");
	printf("9  - Misturar Metade de Cada Vetor\n");
	printf("10 - Mínimo múltiplo comum de cada dois números seguidos do vetor\n");
	printf("11 - Matriz 20x20 do produto de um vetor aleatório 1x20 e o vetor original\n");
	printf("12 - Matriz 20x20 do produto de um vetor aleatório 1x20 e o vetor original Transposta\n");

	ValidMenuChoice = scanf("%d", &MenuChoice);
	ClearTerminal();
	if (ValidMenuChoice == 1) {
		switch (MenuChoice) {
		case 1:
			PrintIntegerArray(SortAscendingOrder(OriginalArray, ArraySize), "Vetor ordenado por ordem crescente:", ArraySize);
			DisposeArrayCopy();
			Menu(OriginalArray);
		case 2:
			PrintIntegerArray(AddFirstSecondHalf(OriginalArray, ArraySize), "Soma da primeira metade dos elementos no vetor com os da segunda metade:", ArraySize / 2);
			DisposeHalfArray();
			Menu(OriginalArray);
		case 3:
			PrintIntegerMatrix(GeneratePermutedMatrix(OriginalArray, ArraySize), "Matriz 20x20 com o vetor original e algumas das suas permutações:", ArraySize);
			DisposeMatrix(ArraySize);
			Menu(OriginalArray);
		case 4:
			PrintFloatArray(CosineSecondHalf(OriginalArray, ArraySize), "Cosseno da segunda metade dos elementos no vetor:", ArraySize / 2);
			DisposeHalfFloatArray();
			Menu(OriginalArray);
		case 5:
			PrintInteger(RandomElement(OriginalArray, ArraySize), "Elemento aleatório do vetor:");
			Menu(OriginalArray);
		case 6:
			PrintIntegerArray(PositionsMultipleof3(OriginalArray, ArraySize), "Posições múltiplas de 3:", ArraySize / 3);
			DisposePositionsMultipleof3Array();
			Menu(OriginalArray);
		case 7:
			Help();
			Menu(OriginalArray);
		case 8:
			exit(0);
		case 9:
			// PrintIntegerArray(mixhalfarray(OriginalArray), "Misturar metade de cada vetor:", ArraySize);
			Menu(OriginalArray);
		case 10:
			// PrintIntegerArray(leastcommummultiple(OriginalArray), "Mínimo múltiplo comum de cada dois números seguidos do vetor:", ArraySize - 1);
			Menu(OriginalArray);
		case 11:
			// PrintIntegerMatrix(twoarrayscalcmatrix(OriginalArray, matriz), "Matriz 20x20 do produto de um vetor aleatório 1x20 e o vetor original:", 20);
			// PrintIntegerArray(second_array, "Vetor Aleatório:", 20);
			Menu(OriginalArray);
		case 12:
			// PrintIntegerMatrix(transposematrix(twoarrayscalcmatrix(OriginalArray, matriz)), "Matriz 20x20 do produto de um vetor aleatório 1x20 e o vetor original Transposta:", 20);
			// PrintIntegerArray(second_array, "Vetor Aleatório:", 20);
			Menu(OriginalArray);
		default:
			Menu(OriginalArray);
		}
	} else {
		ClearInput();
		Menu(OriginalArray);
	}
}

/// Check Arguments, Request Array and Open Menu
int main(int argc, char *argv[]) {
	int *OriginalArray = (int *)malloc(ArraySize * sizeof(int));

	for (int i = 0; i < argc; i++) {
		if (strcmp(argv[i], "--help") == 0) {
			Help();
			printf("Pressione Qualquer Tecla para fechar a Ajuda");
			getchar();
			ClearTerminal();
			exit(0);
		}
	}

	RequestArray(OriginalArray, ArraySize, Minimum, Maximum);
	Menu(OriginalArray);
}