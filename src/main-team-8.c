/**
    @file main-team-8.c
*/

#include "functions-team-8.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ArraySize 20 ///< Size of the Array
#define Minimum 8    ///< Minimum Valid Number for the Array
#define Maximum 29   ///< Maximum Valid Number for the Array

int *OriginalArray;     ///< Define Original Array of Integers
int *IntegerArray;      ///< Define Array of Integers
int **Matrix;           ///< Define Two Dimensional Array
int **TransposedMatrix; ///< Define Two Dimensional Array for the Transposed Matrix
float *FloatArray;      ///< Define Array of Floats

/// @brief Show Menu and Choose Sub-Menu
/// @param OriginalArray Array with Entered Numbers
void Menu(int *OriginalArray) {
	int MenuChoice, ValidMenuChoice;
	srand(time(NULL));
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
			PrintIntegerArray(SortAscendingOrder(OriginalArray, IntegerArray, ArraySize), "Vetor ordenado por ordem crescente:", ArraySize);
			DisposeIntegerArray(IntegerArray);
			Menu(OriginalArray);
		case 2:
			PrintIntegerArray(AddFirstSecondHalf(OriginalArray, IntegerArray, ArraySize), "Soma da primeira metade dos elementos no vetor com os da segunda metade:", ArraySize / 2);
			DisposeIntegerArray(IntegerArray);
			Menu(OriginalArray);
		case 3:
			Matrix = GeneratePermutedMatrix(OriginalArray, Matrix, ArraySize);
			PrintIntegerMatrix(Matrix, "Matriz 20x20 com o vetor original e algumas das suas permutações:", ArraySize);
			Matrix = DisposeMatrix(Matrix, ArraySize);
			Menu(OriginalArray);
		case 4:
			PrintFloatArray(CosineSecondHalf(OriginalArray, FloatArray, ArraySize), "Cosseno da segunda metade dos elementos no vetor:", ArraySize / 2);
			DisposeFloatArray(FloatArray);
			Menu(OriginalArray);
		case 5:
			PrintInteger(RandomElement(OriginalArray, ArraySize), "Elemento aleatório do vetor:");
			Menu(OriginalArray);
		case 6:
			PrintIntegerArray(PositionsMultipleof3(OriginalArray, IntegerArray, ArraySize), "Posições múltiplas de 3:", ArraySize / 3);
			DisposeIntegerArray(IntegerArray);
			Menu(OriginalArray);
		case 7:
			Help(ArraySize, Minimum, Maximum);
			Menu(OriginalArray);
		case 8:
			exit(0);
		case 9:
			PrintIntegerArray(MixHalfEachArray(OriginalArray, IntegerArray, ArraySize, Minimum, Maximum), "Misturar metade de cada vetor:", ArraySize);
			DisposeIntegerArray(IntegerArray);
			Menu(OriginalArray);
		case 10:
			PrintIntegerArray(LeastCommonMultiple(OriginalArray, IntegerArray, ArraySize), "Mínimo múltiplo comum de cada dois números seguidos do vetor:", ArraySize - 1);
			DisposeIntegerArray(IntegerArray);
			Menu(OriginalArray);
		case 11:
			Matrix = ProductBetweenTwoArrays(OriginalArray, IntegerArray, Matrix, ArraySize, Minimum, Maximum);
			PrintIntegerMatrix(Matrix, "Matriz 20x20 do produto de um vetor aleatório 1x20 e o vetor original:", ArraySize);
			Menu(OriginalArray);
		case 12:
			if (Matrix == NULL) {
				printf("Antes de utilizar esta Opção é necessário utilizar a Opção 11\n\n");
				Menu(OriginalArray);
			} else {
				TransposedMatrix = TransposeMatrix(Matrix, TransposedMatrix, ArraySize);
				PrintIntegerMatrix(TransposedMatrix, "Matriz 20x20 do produto de um vetor aleatório 1x20 e o vetor original Transposta:", ArraySize);
				DisposeMatrix(TransposedMatrix, ArraySize);
				Menu(OriginalArray);
			}
		default:
			printf("Opção Inexistente\n\n");
			Menu(OriginalArray);
		}
	} else {
		ClearInput();
		Menu(OriginalArray);
	}
}

/// @brief Check Arguments, Request Array and Open Menu
/// @param NArgs Number of Entered Arguments
/// @param AArgs Array of the Entered Arguments
/// @return Exit Status fo the Program
int main(int NArgs, char **AArgs) {
	for (int i = 0; i < NArgs; i++) {
		if (strcmp(AArgs[i], "--help") == 0) {
			Help(ArraySize, Minimum, Maximum);
			printf("Pressione Enter para fechar a Ajuda\n");
			getchar();
			ClearTerminal();
			return 0;
		}
	}
	OriginalArray = (int *)malloc(ArraySize * sizeof(int));
	RequestArray(OriginalArray, ArraySize, Minimum, Maximum);
	Menu(OriginalArray);
}