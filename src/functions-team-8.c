/**
    @file functions-team-8.c
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/// Define Arrays and Matrices
int *ArrayCopy, *HalfArray, *PositionsMultipleof3Array, **Matrix;
float *HalfFloatArray;

/// Clear Terminal
void ClearTerminal() {
	system("clear");
	printf("\e[1;1H\e[2J");
}

/// Clear Input
void ClearInput() {
	fflush(stdin);
	scanf("%*s");
	printf("Input Inválido\n\n");
}

/// Help
void Help() {
	ClearTerminal();
	printf("O objetivo deste trabalho  é  implementar  um programa que peça ao utilizador 20 números inteiros e os guarde num vetor, para posteriormente providenciar forma de calcular algumas estatísticas ou fazer operações sobre esses valores.\n");
	printf("Os valores pedidos devem estar compreendidos entre 8 e 29.\n");
	printf("Deve ser feita a VALIDAÇÃO DE ENTRADA!\n\n");
	printf("Após terem sido pedidos os valores, deve  ser mostrado um menu ao utilizador que lhe permita calcular cada  uma  das  estatísticas referidas em baixo, exatamente pela  ordem  colocadas  neste  enunciado.  Depois de  se  escolher  uma opção, o resultado deve ser mostrado no ecrã, e o menu deve voltar a ser exibido.\n\n");
	printf("As funcionalidades mínimas a disponibilizar são as seguintes:\n");
	printf(" 1 - Devolução do vetor ordenado por ordem crescente;\n");
	printf(" 2 - Cálculo  da  soma  da  primeira metade  dos  elementos no  vetor com os da segunda metade (dá um vetor com metado do tamanho);\n");
	printf(" 3 - Construção de uma matriz 20 por 20, em que cada linha é composta pelo vetor lido (primeira linha) e por permutações dos seus valores (outras linhas);\n");
	printf(" 4 - Cálculo do coseno (cos) da segunda metade dos elementos no vetor;\n");
	printf(" 5 - Retorno de um elemento aleatório desse vetor (que deve mudar sempre que se executa o programa);\n");
	printf(" 6 - Devolução dos valores em posições múltiplas de três do vetor.\n\n");
	printf("Uma versão mais elaborada do projeto deve exibir adicionalmente as seguintes características e funcionalidades:\n");
	printf(" 1 - Leitura de um novo vetor, e devolução de um vetor que mistura metade do primeiro vetor e metade do segundo;\n");
	printf(" 2 - Cálculo do mínimo múltiplo comum de cada dois números seguidos do vetor;\n");
	printf(" 3 - Geração de um novo vetor 1x20 aleatório, cálculo e devolução da matriz 20x20 resultante do produto do vetor inicial com o novo vetor lido;\n");
	printf(" 4 - Cálculo e apresentação da matriz transposta referida no ponto anterior;\n");
	printf(" 5 - O programa apresenta adicionalmente uma página de ajuda, acessível como sendo a entrada 7 no menu;\n");
	printf(" 6 - O programa mostra alguma ajuda quando é executado a partir da linha de comandos com a flag --help.\n\n");
}

/// Request, Verify and Store Integers between two numbers in an Array
int *RequestArray(int *Array, int ArraySize, int Minimum, int Maximum) {
	int Number, ValidNumber;
	ClearTerminal();
	for (int i = 0; i < ArraySize;) {
		printf("Insira um número inteiro entre %d e %d: ", Minimum, Maximum);
		ValidNumber = scanf("%d", &Number);
		ClearTerminal();
		if (ValidNumber == 1) {
			if (Number >= Minimum && Number <= Maximum) {
				Array[i] = Number;
				i++;
			} else {
				printf("O número deve estar compreendido entre 8 e 29.\n");
			}
		} else {
			ClearInput();
		}
	}
	ClearTerminal();
	return Array;
}

/// Allocate and Fill Array Copy
int *AllocateFillArrayCopy(int *Array, int ArraySize) {
	ArrayCopy = (int *)malloc(ArraySize * sizeof(int));
	for (int i = 0; i < 20; i++) {
		ArrayCopy[i] = Array[i];
	}
	return ArrayCopy;
}

/// Allocate Half Array
int *AllocateHalfArray(int ArraySize) {
	HalfArray = (int *)malloc(ArraySize / 2 * sizeof(int));
	return HalfArray;
}

/// Allocate Positions Multiple of 3 Array
int *AllocatePositionsMultipleof3Array(int ArraySize) {
	PositionsMultipleof3Array = (int *)malloc(ArraySize / 3 * sizeof(int));
	return PositionsMultipleof3Array;
}

/// Allocate Half Float Array
float *AllocateHalfFloatArray(int ArraySize) {
	HalfFloatArray = (float *)malloc(ArraySize / 2 * sizeof(float));
	return HalfFloatArray;
}

/// Allocate Matrix
int **AllocateMatrix(int ArraySize) {
	Matrix = (int **)malloc(ArraySize * sizeof(int *));
	for (int i = 0; i < ArraySize; i++) {
		Matrix[i] = (int *)malloc(ArraySize * sizeof(int));
	}
	return Matrix;
}

/// Dispose Array Copy
void DisposeArrayCopy() {
	free(ArrayCopy);
}

/// Dispose Half Array
void DisposeHalfArray() {
	free(HalfArray);
}

/// Dispose Half Array
void DisposeHalfFloatArray() {
	free(HalfFloatArray);
}

/// Dispose Positions Multiple of 3 Array
void DisposePositionsMultipleof3Array() {
	free(PositionsMultipleof3Array);
}

/// Dispose Matrix
void DisposeMatrix(int ArraySize) {
	for (int i = 0; i < ArraySize; i++) {
		free(Matrix[i]);
	}
	free(Matrix);
}

/// Print Integer
void PrintInteger(int Integer, char *Text) {
	printf("%s\n %d\n\n", Text, Integer);
}

/// Print Array of Integers
void PrintIntegerArray(int *Array, char *Text, int ArraySize) {
	printf("%s\n", Text);
	for (int i = 0; i < ArraySize; i++) {
		printf(" %d", Array[i]);
	}
	printf("\n\n");
}

/// Print Array of Floats
void PrintFloatArray(float *Array, char *Text, int ArraySize) {
	printf("%s\n", Text);
	for (int i = 0; i < ArraySize; i++) {
		printf(" %f", Array[i]);
	}
	printf("\n\n");
}

/// Print Matrix of Integers
void PrintIntegerMatrix(int **Matrix, char *Text, int MatrixSize) {
	printf("%s\n", Text);
	for (int i = 0; i < MatrixSize; i++) {
		for (int j = 0; j < MatrixSize; j++) {
			printf(" %3d", Matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/// Sort Array in Ascending Order
int *SortAscendingOrder(int *Array, int ArraySize) {
	ArrayCopy = AllocateFillArrayCopy(Array, ArraySize);
	int k;
	do {
		k = 0;
		for (int i = 0; i < ArraySize - 1; i++) {
			if (ArrayCopy[i] > ArrayCopy[i + 1]) {
				int Temp = ArrayCopy[i];
				ArrayCopy[i] = ArrayCopy[i + 1];
				ArrayCopy[i + 1] = Temp;
				k++;
			}
		}
	} while (k != 0);
	return ArrayCopy;
}

/// Add First and Second Half of the Array
int *AddFirstSecondHalf(int *Array, int ArraySize) {
	HalfArray = AllocateHalfArray(ArraySize);
	for (int i = 0; i < ArraySize / 2; i++) {
		HalfArray[i] = Array[i] + Array[i + ArraySize / 2];
	}
	return HalfArray;
}

/// Shuffle Array
int *ShuffleArray(int *Array, int ArraySize) {
	for (int i = ArraySize - 1; i > 0; i--) {
		int j = rand() % ArraySize;
		int Temp = Array[j];
		Array[j] = Array[i];
		Array[i] = Temp;
	}
	return Array;
}

/// Generate Permuted Matrix
int **GeneratePermutedMatrix(int *Array, int ArraySize) {
	Matrix = AllocateMatrix(ArraySize);
	for (int j = 0; j < 20; j++) {
		Matrix[0][j] = Array[j];
	}
	for (int i = 1; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			Matrix[i][j] = Array[j];
		}
		ShuffleArray(Matrix[i], ArraySize);
	}
	return Matrix;
}

/// Cosine of the Second Half of the Array
float *CosineSecondHalf(int *Array, int ArraySize) {
	HalfFloatArray = AllocateHalfFloatArray(ArraySize);
	for (int i = 10; i < 20; i++) {
		HalfFloatArray[i - 10] = cos(Array[i]);
	}
	return HalfFloatArray;
}

/// Random Element of the Array
int RandomElement(int *Array, int ArraySize) {
	int i = rand() % 20;
	return Array[i];
}

/// Positions Multiple of 3 of the Array
int *PositionsMultipleof3(int *Array, int ArraySize) {
	PositionsMultipleof3Array = AllocatePositionsMultipleof3Array(ArraySize);
	for (int i = 0; i * 3 + 2 < ArraySize; i++) {
		PositionsMultipleof3Array[i] = Array[i * 3 + 2];
	}
	return PositionsMultipleof3Array;
}

///// Função Misturar Metade de Cada Array
//int *mixhalfarray(int *Array, int ArraySize) {
//	int *ArrayCopy = AllocateFillArrayCopy(Array, ArraySize);
//	RequestArray(second_array, 20, 8, 29);
//	for (int i = 0; i < 10; i++) {
//		mixed_array[i] = ArrayCopy[i];
//	}
//	for (int i = 0; i < 10; i++) {
//		mixed_array[10 + i] = second_array[10 + i];
//	}
//	return mixed_array;
//}
//
///// Função mínimo múltiplo comum de cada dois números seguidos do vetor;
//int *leastcommummultiple(int *Array, int ArraySize) {
//	int max, adder;
//	int *ArrayCopy = AllocateFillArrayCopy(Array, ArraySize);
//
//	for (int i = 0; i < 19; i++) {
//		if (ArrayCopy[i] > ArrayCopy[i + 1]) {
//			max = ArrayCopy[i + 1];
//			adder = ArrayCopy[i + 1];
//		} else {
//			max = ArrayCopy[i];
//			adder = ArrayCopy[i];
//		}
//
//		while (max <= ArrayCopy[i] * ArrayCopy[i + 1]) {
//			if (max % ArrayCopy[i] == 0 && max % ArrayCopy[i + 1] == 0) {
//				ArrayCopy[i] = max;
//				break;
//			}
//			max += adder;
//		}
//	}
//	return ArrayCopy;
//}
//
///// Função Matriz 20x20 do produto de um vetor aleatório 1x20 e o vetor original
//int (*twoarrayscalcmatrix(int *Array, int ArraySize, int matriz[20][20]))[20] {
//	int n;
//	int *ArrayCopy = AllocateFillArrayCopy(Array, ArraySize);
//
//	for (int i = 0; i < 20; i++) {
//		second_array[i] = (rand() % 29) + 8;
//	}
//
//	for (int i = 0; i < 20; i++) {
//		for (int j = 0; j < 20; j++) {
//			matriz[i][j] = second_array[i] * ArrayCopy[j];
//		}
//	}
//	return matriz;
//}
//
///// Função Matriz Transposta
//int (*transposematrix(int matriz[][20]))[20] {
//	int tmp;
//
//	for (int i = 0; i < 20; i++) {
//		for (int j = 0; j < 20; j++) {
//			tmp = matriz[i][j];
//			matriz[i][j] = matriz[j][i];
//			matriz[j][i] = tmp;
//		}
//	}
//	return matriz;
//}