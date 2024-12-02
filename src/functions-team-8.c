/**
    @file functions-team-8.c
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/// Define Arrays and Matrices
int *IntegerArray, **Matrix, **TransposedMatrix;
float *FloatArray;

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
				printf("O número deve estar compreendido entre %d e %d.\n", Minimum, Maximum);
			}
		} else {
			ClearInput();
		}
	}
	ClearTerminal();
	return Array;
}

/// Copy Integer Array
void CopyArray(int *Array, int *ArrayToFill, int ArraySize) {
	for (int i = 0; i < ArraySize; i++) {
		ArrayToFill[i] = Array[i];
	}
}

/// Allocate Integer Array
int *AllocateIntegerArray(int ArraySize) {
	IntegerArray = (int *)calloc(ArraySize, sizeof(int));
	return IntegerArray;
}

/// Allocate Float Array
float *AllocateFloatArray(int ArraySize) {
	FloatArray = (float *)calloc(ArraySize, sizeof(float));
	return FloatArray;
}

/// Allocate Matrix
int **AllocateMatrix(int **Matrix, int ArraySize) {
	Matrix = (int **)calloc(ArraySize, sizeof(int *));
	for (int i = 0; i < ArraySize; i++) {
		Matrix[i] = (int *)calloc(ArraySize, sizeof(int));
	}
	return Matrix;
}

/// Dispose Integer Array
void DisposeIntegerArray() {
	free(IntegerArray);
}

/// Dispose Float Array
void DisposeFloatArray() {
	free(FloatArray);
}

/// Dispose Matrix
void DisposeMatrix(int ArraySize) {
	for (int i = 0; i < ArraySize; i++) {
		free(Matrix[i]);
	}
	free(Matrix);
	Matrix = NULL;
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
	IntegerArray = AllocateIntegerArray(ArraySize);
	CopyArray(Array, IntegerArray, ArraySize);
	int k;
	do {
		k = 0;
		for (int i = 0; i < ArraySize - 1; i++) {
			if (IntegerArray[i] > IntegerArray[i + 1]) {
				int Temp = IntegerArray[i];
				IntegerArray[i] = IntegerArray[i + 1];
				IntegerArray[i + 1] = Temp;
				k++;
			}
		}
	} while (k != 0);
	return IntegerArray;
}

/// Add First and Second Half of the Array
int *AddFirstSecondHalf(int *Array, int ArraySize) {
	IntegerArray = AllocateIntegerArray(ArraySize / 2);
	for (int i = 0; i < ArraySize / 2; i++) {
		IntegerArray[i] = Array[i] + Array[i + ArraySize / 2];
	}
	return IntegerArray;
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
	Matrix = AllocateMatrix(Matrix, ArraySize);
	for (int j = 0; j < ArraySize; j++) {
		Matrix[0][j] = Array[j];
	}
	for (int i = 1; i < ArraySize; i++) {
		CopyArray(Array, Matrix[i], ArraySize);
		for (int j = 0; j < ArraySize; j++) {
			Matrix[i][j] = Array[j];
		}
		ShuffleArray(Matrix[i], ArraySize);
	}
	return Matrix;
}

/// Cosine of the Second Half of the Array
float *CosineSecondHalf(int *Array, int ArraySize) {
	FloatArray = AllocateFloatArray(ArraySize / 2);
	for (int i = ArraySize / 2; i < ArraySize; i++) {
		FloatArray[i - (ArraySize / 2)] = cos(Array[i]);
	}
	return FloatArray;
}

/// Random Element of the Array
int RandomElement(int *Array, int ArraySize) {
	int i = rand() % ArraySize;
	return Array[i];
}

/// Positions Multiple of 3 of the Array
int *PositionsMultipleof3(int *Array, int ArraySize) {
	IntegerArray = AllocateIntegerArray(ArraySize / 3);
	for (int i = 0; i * 3 + 2 < ArraySize; i++) {
		IntegerArray[i] = Array[i * 3 + 2];
	}
	return IntegerArray;
}

/// Mix Half of Each Array
int *MixHalfEachArray(int *Array, int ArraySize, int Minimum, int Maximum) {
	IntegerArray = AllocateIntegerArray(ArraySize);
	RequestArray(IntegerArray, ArraySize, Minimum, Maximum);
	for (int i = 0; i < ArraySize / 2; i++) {
		IntegerArray[i] = Array[i];
	}
	return IntegerArray;
}

/// Least Common Multiple;
int *LeastCommonMultiple(int *Array, int ArraySize) {
	IntegerArray = AllocateIntegerArray(ArraySize - 1);
	int Temp;
	for (int i = 0; i < ArraySize - 1; i++) {
		Temp = Array[i];
		while (Temp <= Array[i] * Array[i + 1]) {
			if (Temp % Array[i] == 0 && Temp % Array[i + 1] == 0) {
				IntegerArray[i] = Temp;
				break;
			}
			Temp += Array[i];
		}
	}
	return IntegerArray;
}

// Product Between Original Array and Random Array
int **ProductBetweenTwoArrays(int *Array, int ArraySize, int Minimum, int Maximum) {
	IntegerArray = AllocateIntegerArray(ArraySize);
	Matrix = AllocateMatrix(Matrix, ArraySize);
	for (int i = 0; i < ArraySize; i++) {
		IntegerArray[i] = rand() % (Maximum + 1 - Minimum) + Minimum;
	}
	for (int i = 0; i < ArraySize; i++) {
		for (int j = 0; j < ArraySize; j++) {
			Matrix[i][j] = IntegerArray[i] * Array[j];
		}
	}
	return Matrix;
}

/// Transpose Matrix of Product Between Original Array and Random Array
int **TransposeMatrix(int **Matrix, int ArraySize) {
	TransposedMatrix = AllocateMatrix(TransposedMatrix, ArraySize);
	for (int i = 0; i < ArraySize; i++) {
		for (int j = 0; j < ArraySize; j++) {
			int Temp = Matrix[i][j];
			TransposedMatrix[i][j] = Matrix[j][i];
			TransposedMatrix[j][i] = Temp;
		}
	}
	return TransposedMatrix;
}