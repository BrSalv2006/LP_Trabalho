/**
    @file functions-team-8.c
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/// @brief Clear Terminal
void ClearTerminal() {
	system("clear");
	printf("\e[1;1H\e[2J");
}

/// @brief Clear Input
void ClearInput() {
	fflush(stdin);
	scanf("%*s");
	printf("Input Inválido\n\n");
}

/// @brief Show Help
/// @param ArraySize Size of the Array
/// @param Minimum Minimum Number Accepted on the Array
/// @param Maximum Maximum Number Accepted on the Array
void Help(int ArraySize, int Minimum, int Maximum) {
	ClearTerminal();
	printf("O objetivo deste trabalho  é  implementar  um programa que peça ao utilizador %d números inteiros e os guarde num vetor, para posteriormente providenciar forma de calcular algumas estatísticas ou fazer operações sobre esses valores.\n", ArraySize);
	printf("Os valores pedidos devem estar compreendidos entre %d e %d.\n", Minimum, Maximum);
	printf("Deve ser feita a VALIDAÇÃO DE ENTRADA!\n\n");
	printf("Após terem sido pedidos os valores, deve  ser mostrado um menu ao utilizador que lhe permita calcular cada  uma  das  estatísticas referidas em baixo, exatamente pela  ordem  colocadas  neste  enunciado.  Depois de  se  escolher  uma opção, o resultado deve ser mostrado no ecrã, e o menu deve voltar a ser exibido.\n\n");
	printf("As funcionalidades mínimas a disponibilizar são as seguintes:\n");
	printf(" 1 - Devolução do vetor ordenado por ordem crescente;\n");
	printf(" 2 - Cálculo  da  soma  da  primeira metade  dos  elementos no  vetor com os da segunda metade (dá um vetor com metado do tamanho);\n");
	printf(" 3 - Construção de uma matriz %d por %d, em que cada linha é composta pelo vetor lido (primeira linha) e por permutações dos seus valores (outras linhas);\n", ArraySize, ArraySize);
	printf(" 4 - Cálculo do coseno (cos) da segunda metade dos elementos no vetor;\n");
	printf(" 5 - Retorno de um elemento aleatório desse vetor (que deve mudar sempre que se executa o programa);\n");
	printf(" 6 - Devolução dos valores em posições múltiplas de três do vetor.\n\n");
	printf("Uma versão mais elaborada do projeto deve exibir adicionalmente as seguintes características e funcionalidades:\n");
	printf(" 1 - Leitura de um novo vetor, e devolução de um vetor que mistura metade do primeiro vetor e metade do segundo;\n");
	printf(" 2 - Cálculo do mínimo múltiplo comum de cada dois números seguidos do vetor;\n");
	printf(" 3 - Geração de um novo vetor 1x%d aleatório, cálculo e devolução da matriz %dx%d resultante do produto do vetor inicial com o novo vetor lido;\n", ArraySize, ArraySize, ArraySize);
	printf(" 4 - Cálculo e apresentação da matriz transposta referida no ponto anterior;\n");
	printf(" 5 - O programa apresenta adicionalmente uma página de ajuda, acessível como sendo a entrada 7 no menu;\n");
	printf(" 6 - O programa mostra alguma ajuda quando é executado a partir da linha de comandos com a flag --help.\n\n");
}

/// @brief Request, Verify and Store Integers between two numbers in an Array
/// @param Array Empty Array
/// @param ArraySize Size of the Array
/// @param Minimum Minimum Number Accepted on the Array
/// @param Maximum Maximum Number Accepted on the Array
/// @return Array with Size of ArraySize, filled with Numbers between Minimum and Maximum
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

/// @brief Copy an Array of Integers to another Array
/// @param Array Array from which the numbers will be copied
/// @param IntegerArray Array to which the numbers will be copied
/// @param ArraySize Size of the Array
/// @return Memory Location of the Array to which the Numbers where copied
int *CopyArray(int *Array, int *IntegerArray, int ArraySize) {
	for (int i = 0; i < ArraySize; i++) {
		IntegerArray[i] = Array[i];
	}
	return IntegerArray;
}

/// @brief Allocate Memory for an Array of Integers with the size of ArraySize
/// @param IntegerArray Array to Allocate Memory
/// @param ArraySize Size of the Array
/// @return Memory Location of the Allocated Array
int *AllocateIntegerArray(int *IntegerArray, int ArraySize) {
	IntegerArray = (int *)calloc(ArraySize, sizeof(int));
	return IntegerArray;
}

/// @brief Allocate Memory for an Array of Floats with the size of ArraySize
/// @param FloatArray Array to Allocate Memory
/// @param ArraySize Size of the Array
/// @return Memory Location of the Allocated Array
float *AllocateFloatArray(float *FloatArray, int ArraySize) {
	FloatArray = (float *)calloc(ArraySize, sizeof(float));
	return FloatArray;
}

/// @brief Allocate Memory for an two Dimension Array of Integers with the size of ArraySize
/// @param Matrix Two Dimensional Array To Allocate Memory
/// @param ArraySize Size of the Array
/// @return Memory Location of the Allocated Array
int **AllocateMatrix(int **Matrix, int ArraySize) {
	Matrix = (int **)calloc(ArraySize, sizeof(int *));
	for (int i = 0; i < ArraySize; i++) {
		Matrix[i] = (int *)calloc(ArraySize, sizeof(int));
	}
	return Matrix;
}

/// @brief Dispose Integer Array
/// @param IntegerArray Integer Array to Free Memory Allocation
void DisposeIntegerArray(int *IntegerArray) {
	free(IntegerArray);
}

/// @brief Dispose Float Array
/// @param FloatArray Float Array to Free Memory Allocation
void DisposeFloatArray(float *FloatArray) {
	free(FloatArray);
}

/// @brief Dispose Two Dimensional Array
/// @param Matrix Two Dimensional Array to Free Memory Allocation
/// @param ArraySize Size of the Array
/// @return Two Dimensional Array with no Memory Allocated
int **DisposeMatrix(int **Matrix, int ArraySize) {
	for (int i = 0; i < ArraySize; i++) {
		free(Matrix[i]);
	}
	free(Matrix);
	Matrix = NULL;
	return Matrix;
}

/// @brief Print Integer
/// @param Integer Integer to Print
/// @param Text Message to Display
void PrintInteger(int Integer, char *Text) {
	printf("%s\n %d\n\n", Text, Integer);
}

/// @brief Print Array of Integers
/// @param Array Array to Print
/// @param Text Message to Display
/// @param ArraySize Size of the Array
void PrintIntegerArray(int *Array, char *Text, int ArraySize) {
	printf("%s\n", Text);
	for (int i = 0; i < ArraySize; i++) {
		printf(" %d", Array[i]);
	}
	printf("\n\n");
}

/// @brief Print Array of Floats
/// @param Array Array to Print
/// @param Text Message to Display
/// @param ArraySize Size of the Array
void PrintFloatArray(float *Array, char *Text, int ArraySize) {
	printf("%s\n", Text);
	for (int i = 0; i < ArraySize; i++) {
		printf(" %f", Array[i]);
	}
	printf("\n\n");
}

/// @brief Print Matrix of Integers
/// @param Matrix Two Dimensional Array to Print
/// @param Text Message to Display
/// @param ArraySize Size of the Array
void PrintIntegerMatrix(int **Matrix, char *Text, int ArraySize) {
	printf("%s\n", Text);
	for (int i = 0; i < ArraySize; i++) {
		for (int j = 0; j < ArraySize; j++) {
			printf(" %3d", Matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/// @brief Sort Array in Ascending Order
/// @param Array Array with the Entered Numbers
/// @param IntegerArray Array to which the Final Result will be Saved
/// @param ArraySize Size of the Array
/// @return Array with the Original Array Sorted in Ascending Order
int *SortAscendingOrder(int *Array, int *IntegerArray, int ArraySize) {
	IntegerArray = CopyArray(Array, AllocateIntegerArray(IntegerArray, ArraySize), ArraySize);
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

/// @brief Add First and Second Half of the Array
/// @param Array Array with the Entered Numbers
/// @param IntegerArray Array to which the Final Result will be Saved
/// @param ArraySize Size of the Array
/// @return Array with the First Half of and Array Added to it's Second Half
int *AddFirstSecondHalf(int *Array, int *IntegerArray, int ArraySize) {
	IntegerArray = AllocateIntegerArray(IntegerArray, ArraySize / 2);
	for (int i = 0; i < ArraySize / 2; i++) {
		IntegerArray[i] = Array[i] + Array[i + ArraySize / 2];
	}
	return IntegerArray;
}

/// @brief Shuffle Array
/// @param Array Array with the Numbers to Shuffle
/// @param ArraySize Size of the Array
/// @return Shuffled Array
int *ShuffleArray(int *Array, int ArraySize) {
	for (int i = ArraySize - 1; i > 0; i--) {
		int j = rand() % ArraySize;
		int Temp = Array[j];
		Array[j] = Array[i];
		Array[i] = Temp;
	}
	return Array;
}

/// @brief Generate Permuted Matrix
/// @param Array Array with the Entered Numbers
/// @param Matrix Two Dimensional Array to which the Final Result will be Saved
/// @param ArraySize Size of the Array
/// @return Two Dimensional Array with each of it's rows being a combination of the first
int **GeneratePermutedMatrix(int *Array, int **Matrix, int ArraySize) {
	Matrix = AllocateMatrix(Matrix, ArraySize);
	for (int j = 0; j < ArraySize; j++) {
		Matrix[0][j] = Array[j];
	}
	for (int i = 1; i < ArraySize; i++) {
		Matrix[i] = CopyArray(Array, Matrix[i], ArraySize);
		ShuffleArray(Matrix[i], ArraySize);
	}
	return Matrix;
}

/// @brief Cosine of the Second Half of the Array
/// @param Array Array with the Entered Numbers
/// @param FloatArray Float Array to which the Final Result will be Saved
/// @param ArraySize Size of the Array
/// @return Array with the Cosine of the Second Half of the Original Array
float *CosineSecondHalf(int *Array, float *FloatArray, int ArraySize) {
	FloatArray = AllocateFloatArray(FloatArray, ArraySize / 2);
	for (int i = ArraySize / 2; i < ArraySize; i++) {
		FloatArray[i - (ArraySize / 2)] = cos(Array[i]);
	}
	return FloatArray;
}

/// @brief Select a Random Element of the Array
/// @param Array Array with the Entered Numbers
/// @param ArraySize Size of the Array
/// @return Randomly Selected Number of the Array
int RandomElement(int *Array, int ArraySize) {
	int i = rand() % ArraySize;
	return Array[i];
}

/// @brief Positions Multiple of 3 of the Array
/// @param Array Array with the Entered Numbers
/// @param IntegerArray Array to which the Final Result will be Saved
/// @param ArraySize Size of the Array
/// @return Array with the Numbers on Positions Multiple of 3
int *PositionsMultipleof3(int *Array, int *IntegerArray, int ArraySize) {
	IntegerArray = AllocateIntegerArray(IntegerArray, ArraySize / 3);
	for (int i = 0; i * 3 + 2 < ArraySize; i++) {
		IntegerArray[i] = Array[i * 3 + 2];
	}
	return IntegerArray;
}

/// @brief Mix Half of Each Array
/// @param Array Array with the Entered Numbers
/// @param IntegerArray Array to which the Final Result will be Saved
/// @param ArraySize Size of the Array
/// @param Minimum Minimum Number Accepted on the Array
/// @param Maximum Maximum Number Accepted on the Array
/// @return Array with the First Half of the Orinal Entered Array and the Second Half of the Newly Entered Array
int *MixHalfEachArray(int *Array, int *IntegerArray, int ArraySize, int Minimum, int Maximum) {
	IntegerArray = AllocateIntegerArray(IntegerArray, ArraySize);
	RequestArray(IntegerArray, ArraySize, Minimum, Maximum);
	for (int i = 0; i < ArraySize / 2; i++) {
		IntegerArray[i] = Array[i];
	}
	return IntegerArray;
}

/// @brief Least Common Multiple
/// @param Array Array with the Entered Numbers
/// @param IntegerArray Array to which the Final Result will be Saved
/// @param ArraySize Size of the Array
/// @return Array with Least Common Multiples of two Followed Numbers of the Array
int *LeastCommonMultiple(int *Array, int *IntegerArray, int ArraySize) {
	IntegerArray = AllocateIntegerArray(IntegerArray, ArraySize - 1);
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

/// @brief Product Between Original Array and Random Array
/// @param Array Array with the Entered Numbers
/// @param IntegerArray Array to which the Random Generated Array will be Saved
/// @param Matrix Two Dimensional Array to which the Final Result will be Saved
/// @param ArraySize Size of the Array
/// @param Minimum Minimum Number Accepted on the Array
/// @param Maximum Maximum Number Accepted on the Array
/// @return Two Dimensional Array with the Product Between Two Arrays
int **ProductBetweenTwoArrays(int *Array, int *IntegerArray, int **Matrix, int ArraySize, int Minimum, int Maximum) {
	IntegerArray = AllocateIntegerArray(IntegerArray, ArraySize);
	Matrix = AllocateMatrix(Matrix, ArraySize);
	for (int i = 0; i < ArraySize; i++) {
		IntegerArray[i] = rand() % (Maximum + 1 - Minimum) + Minimum;
	}
	for (int i = 0; i < ArraySize; i++) {
		for (int j = 0; j < ArraySize; j++) {
			Matrix[i][j] = IntegerArray[i] * Array[j];
		}
	}
	DisposeIntegerArray(IntegerArray);
	return Matrix;
}

/// @brief Transpose Matrix of Product Between Original Array and Random Array
/// @param Matrix Two Dimensional Array with the Product Between Two Arrays
/// @param TransposedMatrix Two Dimensional Array to which the Final Result will be Saved
/// @param ArraySize Size of the Array
/// @return Transposed Two Dimensional Array of the Original Two Dimensional Array
int **TransposeMatrix(int **Matrix, int **TransposedMatrix, int ArraySize) {
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