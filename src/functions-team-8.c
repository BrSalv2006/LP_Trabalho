/**
    @file functions-team-8.c
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/// @brief Limpar Terminal
void ClearTerminal() {
	system("clear");        // Invocar "CLEAR" no Terminal
	printf("\e[1;1H\e[2J"); // Mover o cursor para a linha 1, coluna 1 e mover todo o texto atualmente no terminal para o Scroll Buffer
}

/// @brief Limpar Input
void ClearInput() {
	fflush(stdin); // Liberta Buffer de Entrada
	scanf("%*s");  // Excluir Caráteres Inválidos Introduzidos
	printf("Input Inválido\n\n");
}

/// @brief Mostrar Ajuda com Algumas das Funcionalidades do Projeto
/// @param ArraySize Tamanho do Array
/// @param Minimum Número Mínimo Aceite no Array
/// @param Maximum Número Máximo Aceite no Array
void Help(int ArraySize, int Minimum, int Maximum) {
	ClearTerminal(); // Limpar Terminal
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

/// @brief Solicitar, verificar e armazenar números inteiros entre dois números num Array
/// @param Array Array Vazio
/// @param ArraySize Tamanho do Array
/// @param Minimum Número Mínimo Aceite no Array
/// @param Maximum Número Máximo Aceite no Array
/// @return Array com o tamanho do ArraySize, preenchido com números entre um Mínimo e um Máximo
int *RequestArray(int *Array, int ArraySize, int Minimum, int Maximum) {
	int Number, ValidNumber;
	ClearTerminal();                  // Limpar Terminal
	for (int i = 0; i < ArraySize;) { // Repetir para completar o Array
		printf("Insira um número inteiro entre %d e %d (%dº Número): ", Minimum, Maximum, i + 1);
		ValidNumber = scanf("%d", &Number);               // Guardar número de caráteres númericos válidos introduzidos
		ClearTerminal();                                  // Limpar Terminal
		if (ValidNumber == 1) {                           // Verificar se número introduzido é um caráter não númerico
			if (Number >= Minimum && Number <= Maximum) { // Verificar se número introduzido está entre um Mínimo e um Máximo
				Array[i] = Number;                        // Guardar número no Array
				i++;
			} else {
				printf("O número deve estar compreendido entre %d e %d.\n", Minimum, Maximum);
			}
		} else {
			ClearInput(); // Limpar Input em caso do caráter introduzido não ser um número
		}
	}
	ClearTerminal(); // Limpar Terminal
	return Array;
}

/// @brief Copiar um Array de Inteiros para outro Array
/// @param Array Array de onde os Números serão copiados
/// @param IntegerArray Array para o qual os Números serão copiados
/// @param ArraySize Tamanho do Array
/// @return Localização do Array na Memória
int *CopyArray(int *Array, int *IntegerArray, int ArraySize) {
	for (int i = 0; i < ArraySize; i++) {
		IntegerArray[i] = Array[i]; // Guardar número na posição i de um Array na posição i de outro Array
	}
	return IntegerArray;
}

/// @brief Alocar Memória para um Array de Inteiros com o tamanho de ArraySize
/// @param IntegerArray Array para o qual Alocar Memória
/// @param ArraySize Tamanho do Array
/// @return Localização do Array na Memória
int *AllocateIntegerArray(int *IntegerArray, int ArraySize) {
	IntegerArray = (int *)calloc(ArraySize, sizeof(int)); // Alocar Memória para um Array de Inteiros
	return IntegerArray;
}

/// @brief Alocar Memória para um Array de Reais com o tamanho de ArraySize
/// @param FloatArray Array para o qual Alocar Memória
/// @param ArraySize Tamanho do Array
/// @return Localização do Array na Memória
float *AllocateFloatArray(float *FloatArray, int ArraySize) {
	FloatArray = (float *)calloc(ArraySize, sizeof(float)); // Alocar Memória para um Array de Floats
	return FloatArray;
}

/// @brief Alocar Memória para um Array de duas dimensões de Inteiros com o tamanho de ArraySize
/// @param Matrix Array de duas dimensões para o qual Alocar Memória
/// @param ArraySize Tamanho do Array
/// @return Localização do Array na Memória
int **AllocateMatrix(int **Matrix, int ArraySize) {
	Matrix = (int **)calloc(ArraySize, sizeof(int *));     // Alocar Memória para uma linha de um Array de duas de dimensões de Inteiros
	for (int i = 0; i < ArraySize; i++) {                  // Repetir para todas as colunas do Array
		Matrix[i] = (int *)calloc(ArraySize, sizeof(int)); // Alocar Memória para cada coluna de um Array de duas de dimensões de Inteiros
	}
	return Matrix;
}

/// @brief Libertar Memória de um Array de Inteiros
/// @param IntegerArray Array de Inteiros para Libertar Alocação de Memória
void DisposeIntegerArray(int *IntegerArray) {
	free(IntegerArray); // Libertar Alocação de Memória de um Array de Inteiros
}

/// @brief Libertar Memória de um Array de Reais
/// @param FloatArray Array de Reais para Libertar Alocação de Memória
void DisposeFloatArray(float *FloatArray) {
	free(FloatArray); // Libertar Alocação de Memória de um Array de Reais
}

/// @brief Libertar Memória de um Array de duas dimensões de Inteiros
/// @param Matrix Array de duas dimensões de Inteiros para Libertar Alocação de Memória
/// @param ArraySize Tamanho do Array
/// @return Array NULL de duas dimensões
int **DisposeMatrix(int **Matrix, int ArraySize) {
	for (int i = 0; i < ArraySize; i++) { // Repetir para todas as colunas o Array
		free(Matrix[i]);                  // Libertar Memória das colunas do Array de duas dimensões
	}
	free(Matrix); // Libertar Memória das linhas do Array de duas dimensões
	Matrix = NULL;
	return Matrix;
}

/// @brief Mostrar Inteiro
/// @param Integer Inteiro a Mostrar
/// @param Text Mensagem a Mostrar
void PrintInteger(int Integer, char *Text) {
	printf("%s\n %d\n\n", Text, Integer);
}

/// @brief Mostrar Array de Inteiros
/// @param Array Array a Mostrar
/// @param Text Mensagem a Mostrar
/// @param ArraySize Tamanho do Array
void PrintIntegerArray(int *Array, char *Text, int ArraySize) {
	printf("%s\n", Text);
	for (int i = 0; i < ArraySize; i++) { // Repetir para todo o Array
		printf(" %d", Array[i]);
	}
	printf("\n\n");
}

/// @brief Mostrar Array de Reais
/// @param Array Array a Mostrar
/// @param Text Mensagem a Mostrar
/// @param ArraySize Tamanho do Array
void PrintFloatArray(float *Array, char *Text, int ArraySize) {
	printf("%s\n", Text);
	for (int i = 0; i < ArraySize; i++) { // Repetir para todo o Array
		printf(" %f", Array[i]);
	}
	printf("\n\n");
}

/// @brief Mostrar Array de duas dimensões de Inteiros
/// @param Matrix Array de duas dimensões a Mostrar
/// @param Text Mensagem a Mostrar
/// @param ArraySize Tamanho do Array
void PrintIntegerMatrix(int **Matrix, char *Text, int ArraySize) {
	printf("%s\n", Text);
	for (int i = 0; i < ArraySize; i++) {     // Repetir para as todas linhas do Array
		for (int j = 0; j < ArraySize; j++) { // Repetir para as todas colunas do Array
			printf(" %3d", Matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/// @brief Ordenar Array de Inteiros por ordem Crescente
/// @param Array Array com os Números Introduzidos
/// @param IntegerArray Array para o qual o resultado final é guardado
/// @param ArraySize Tamanho do Array
/// @return Array Ordenado por ordem Crescente
int *SortAscendingOrder(int *Array, int *IntegerArray, int ArraySize) {
	IntegerArray = CopyArray(Array, AllocateIntegerArray(IntegerArray, ArraySize), ArraySize); // Alocar Memória para o Array
	int k;
	do {
		k = 0;
		for (int i = 0; i < ArraySize - 1; i++) {        // Repetir para todo o Array
			if (IntegerArray[i] > IntegerArray[i + 1]) { // Verificar se o número i é maior que o número i+1
				int Temp = IntegerArray[i];              // Guardar número i na variável temporária
				IntegerArray[i] = IntegerArray[i + 1];   // Colocar número i+1 na posição do número i
				IntegerArray[i + 1] = Temp;              // Colocar número na variável temporária na posição i+1
				k++;
			}
		}
	} while (k != 0); // Repetir enquanto não ordenado
	return IntegerArray;
}

/// @brief Adicionar Primeira metade com a Segunda Metade do Array
/// @param Array Array com os Números Introduzidos
/// @param IntegerArray Array para o qual o resultado final é guardado
/// @param ArraySize Tamanho do Array
/// @return Array com a primeira metade somada à segunda metade
int *AddFirstSecondHalf(int *Array, int *IntegerArray, int ArraySize) {
	IntegerArray = AllocateIntegerArray(IntegerArray, ArraySize / 2); // Alocar Memória para o Array
	for (int i = 0; i < ArraySize / 2; i++) {                         // Repetir para o Array todo
		IntegerArray[i] = Array[i] + Array[i + ArraySize / 2];        // Somar número i com número i+ArraySize/2
	}
	return IntegerArray;
}

/// @brief Baralhar Array de Inteiros
/// @param Array Array com os números a baralhar
/// @param ArraySize Tamanho do Array
/// @return Array com os números baralhados
int *ShuffleArray(int *Array, int ArraySize) {
	for (int i = ArraySize - 1; i > 0; i--) { // Repetir para o Array todo
		int j = rand() % ArraySize;           // Gerar posição aleatória para a qual o número vai ir
		int Temp = Array[j];                  // Guardar número na posição gerada aleatóriamente na variável temporária
		Array[j] = Array[i];                  // Colocar número i na posição do número j
		Array[i] = Temp;                      // Colocar número na variável temporária na posição i
	}
	return Array;
}

/// @brief Gerar Matriz de Permutações do Array
/// @param Array Array com os Números Introduzidos
/// @param Matrix Array de duas dimensões para o qual o resultado final é guardado
/// @param ArraySize Tamanho do Array
/// @return Array de duas dimensões sendo cada uma das suas linhas uma combinação da primeira
int **GeneratePermutedMatrix(int *Array, int **Matrix, int ArraySize) {
	Matrix = AllocateMatrix(Matrix, ArraySize);             // Alocar Memória para o Array de duas dimensões
	CopyArray(Array, Matrix[0], ArraySize);                 // Copiar Array para a primeira linha do Array de duas dimensões
	for (int i = 1; i < ArraySize; i++) {                   // Repetir para o Array todo excluindo a primeira linha
		Matrix[i] = CopyArray(Array, Matrix[i], ArraySize); // Copiar Array para a linha i do Array de duas dimensões
		ShuffleArray(Matrix[i], ArraySize);                 // Baralhar Linha i do Array
	}
	return Matrix;
}

/// @brief Calcular Cosseno da segunda metade do Array
/// @param Array Array com os Números Introduzidos
/// @param FloatArray Array de Reais para o qual o resultado final é guardado
/// @param ArraySize Tamanho do Array
/// @return Array com o Cosseno da segunda metade do Array de números introduzidos
float *CosineSecondHalf(int *Array, float *FloatArray, int ArraySize) {
	FloatArray = AllocateFloatArray(FloatArray, ArraySize / 2); // Alocar Memória para o Array
	for (int i = ArraySize / 2; i < ArraySize; i++) {           // Repetir para toda a segunda metade do Array
		FloatArray[i - (ArraySize / 2)] = cos(Array[i]);        // Calcular Cosseno na posição i e guardar em um Array
	}
	return FloatArray;
}

/// @brief Selecionar um elemento aleatório do Array
/// @param Array Array com os Números Introduzidos
/// @param ArraySize Tamanho do Array
/// @return Número selecionado aleatoriamente do Array
int RandomElement(int *Array, int ArraySize) {
	int i = rand() % ArraySize; // Gerar posição aleatória
	return Array[i];
}

/// @brief Selecionar elementos em posições múltiplas de 3 do Array
/// @param Array Array com os Números Introduzidos
/// @param IntegerArray Array para o qual o resultado final é guardado
/// @param ArraySize Tamanho do Array
/// @return Array com os elementos em Posições Múltiplas de 3
int *PositionsMultipleof3(int *Array, int *IntegerArray, int ArraySize) {
	IntegerArray = AllocateIntegerArray(IntegerArray, ArraySize / 3); // Alocar Memória para o Array
	for (int i = 0; i * 3 + 2 < ArraySize; i++) {                     // Repetir para todo o Array
		IntegerArray[i] = Array[i * 3 + 2];                           // Guardar os números em posições múltiplas de 3 num Array
	}
	return IntegerArray;
}

/// @brief Misturar a Primeira Metade do Primeiro Array e a Segunda Metade do Segundo Array
/// @param Array Array com os Números Introduzidos
/// @param IntegerArray Array para o qual o resultado final é guardado
/// @param ArraySize Tamanho do Array
/// @param Minimum Número Mínimo Aceite no Array
/// @param Maximum Número Máximo Aceite no Array
/// @return Array com a primeira metade do Array originalmente introduzido e metade do novo array introduzido
int *MixHalfEachArray(int *Array, int *IntegerArray, int ArraySize, int Minimum, int Maximum) {
	IntegerArray = AllocateIntegerArray(IntegerArray, ArraySize); // Alocar Memória para o Array
	RequestArray(IntegerArray, ArraySize, Minimum, Maximum);      // Preencher Array
	for (int i = 0; i < ArraySize / 2; i++) {                     // Repetir para a primeira metade do Array
		IntegerArray[i] = Array[i];                               // Guardar número na posição i do Array Original na posição i do novo Array Introduzido
	}
	return IntegerArray;
}

/// @brief Calcular Mínimos Múltiplos Comuns entre dois números seguidos de um Array
/// @param Array Array com os Números Introduzidos
/// @param IntegerArray Array para o qual o resultado final é guardado
/// @param ArraySize Tamanho do Array
/// @return Array com os mínimos múltiplos comuns de dois números seguidos do Array
int *LeastCommonMultiple(int *Array, int *IntegerArray, int ArraySize) {
	IntegerArray = AllocateIntegerArray(IntegerArray, ArraySize - 1); // Alocar Memória para o Array
	int Temp;
	for (int i = 0; i < ArraySize - 1; i++) {                       // Repetir para todo o Array
		Temp = Array[i];                                            // Guardar número na posição i na variável temporária
		while (Temp <= Array[i] * Array[i + 1]) {                   // Repetir enquanto o produto entre o número i e i+1 é maior que Temp
			if (Temp % Array[i] == 0 && Temp % Array[i + 1] == 0) { // Verificar se encontrou um mínimo múltiplo comum
				IntegerArray[i] = Temp;                             // Guardar Mínimo Múltiplo Comum num Array
				break;
			}
			Temp += Array[i];
		}
	}
	return IntegerArray;
}

/// @brief Calcular Produto entre o Array Original e um Array gerado aleatoriamente
/// @param Array Array com os Números Introduzidos
/// @param IntegerArray Array para o qual o Array Gerado Aleatoriamente vai ser guardado
/// @param Matrix Array de duas dimensões para o qual o resultado final é guardado
/// @param ArraySize Tamanho do Array
/// @param Minimum Número Mínimo Aceite no Array
/// @param Maximum Número Máximo Aceite no Array
/// @return Array de duas dimensões com o produto entre dois Arrays
int **ProductBetweenTwoArrays(int *Array, int *IntegerArray, int **Matrix, int ArraySize, int Minimum, int Maximum) {
	IntegerArray = AllocateIntegerArray(IntegerArray, ArraySize);     // Alocar Memória para o Array
	Matrix = AllocateMatrix(Matrix, ArraySize);                       // Alocar Memória para o Array de duas dimensões
	for (int i = 0; i < ArraySize; i++) {                             // Repetir para todo o Array
		IntegerArray[i] = rand() % (Maximum + 1 - Minimum) + Minimum; // Gerar número Aleatório entre dois número e guardar num Array
	}
	for (int i = 0; i < ArraySize; i++) {              // Repetir para todas as linhas do Array de duas dimensões
		for (int j = 0; j < ArraySize; j++) {          // Repetir para todas as colunas do Array de duas dimensões
			Matrix[i][j] = IntegerArray[i] * Array[j]; // Calcular produto entre os dois Arrays e Guardar no Array de duas dimensões
		}
	}
	DisposeIntegerArray(IntegerArray); // Libertar Memória do Array
	return Matrix;
}

/// @brief Matriz Transposta do Produto entre o Array Original e um Array gerado aleatoriamente
/// @param Matrix Array de duas dimensões com o produto entre dois Arrays
/// @param TransposedMatrix Array de duas dimensões para o qual o resultado final é guardado
/// @param ArraySize Tamanho do Array
/// @return Transposta de um Array de duas dimensões com o produto entre dois Arrays
int **TransposeMatrix(int **Matrix, int **TransposedMatrix, int ArraySize) {
	TransposedMatrix = AllocateMatrix(TransposedMatrix, ArraySize); // Alocar Memória para o Array de duas dimensões
	for (int i = 0; i < ArraySize; i++) {                           // Repetir para todas as linhas do Array de duas dimensões
		for (int j = 0; j < ArraySize; j++) {                       // Repetir para todas as colunas do Array de duas dimensões
			int Temp = Matrix[i][j];                                // Guardar um elemento do Array de duas dimensões numa variável temporária
			TransposedMatrix[i][j] = Matrix[j][i];                  // Guardar o número na posição ij na posição ji do Array de duas dimensões
			TransposedMatrix[j][i] = Temp;                          // Guardar o número na variável temporária na posição ji do Array de duas dimensões
		}
	}
	return TransposedMatrix;
}