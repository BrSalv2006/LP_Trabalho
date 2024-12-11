/**
    @file functions-team-8.h
*/

// Limpar Terminal
void ClearTerminal();

// Limpar Input
void ClearInput();

// Mostrar Ajuda
void Help(int ArraySize, int Minimum, int Maximum);

// Alocar Memória para um Array de Inteiros com o tamanho de ArraySize
int *AllocateIntegerArray(int *IntegerArray, int ArraySize);

// Libertar Memória de um Array de Inteiros
void DisposeIntegerArray(int *IntegerArray);

// Libertar Memória de um Array de Reais
void DisposeFloatArray(float *FloatArray);

// Libertar Memória de um Array de duas dimensões de Inteiros
int **DisposeMatrix(int **Matrix, int ArraySize);

// Solicitar, verificar e armazenar números inteiros entre dois números num Array
int *RequestArray(int *Array, int ArraySize, int Minimum, int Maximum);

// Mostrar Inteiro
void PrintInteger(int Integer, char *Text);

// Mostrar Array de Inteiros
void PrintIntegerArray(int *Array, char *Text, int ArraySize);

// Mostrar Array de Reais
void PrintFloatArray(float *Array, char *Text, int ArraySize);

// Mostrar Array de duas dimensões de Inteiros
void PrintIntegerMatrix(int **Matrix, char *Text, int ArraySize);

// Ordenar Array por ordem Crescente
int *SortAscendingOrder(int *Array, int *IntegerArray, int ArraySize);

// Adicionar Primeira metade com a Segunda Metade do Array
int *AddFirstSecondHalf(int *Array, int *IntegerArray, int ArraySize);

// Gerar Matriz de Permutações
int **GeneratePermutedMatrix(int *Array, int **Matrix, int ArraySize);

// Calcular Cosseno da segunda metade do Array
float *CosineSecondHalf(int *Array, float *FloatArray, int ArraySize);

// Selecionar um elemento aleatório do Array
int RandomElement(int *Array, int ArraySize);

// Elementos em Posições Múltiplas de 3 do Array
int *PositionsMultipleof3(int *Array, int *IntegerArray, int ArraySize);

// Misturar metade de cada Array
int *MixHalfEachArray(int *Array, int *IntegerArray, int ArraySize, int Minimum, int Maximum);

// Mínimo Múltiplo Comum entre dois números seguidos de um Array
int *LeastCommonMultiple(int *Array, int *IntegerArray, int ArraySize);

// Produto entre o Array Original e um Array gerado aleatoriamente
int **ProductBetweenTwoArrays(int *Array, int *IntegerArray, int **Matrix, int ArraySize, int Minimum, int Maximum);

// Matriz Transposta do Produto entre o Array Original e um Array gerado aleatoriamente
int **TransposeMatrix(int **Matrix, int **TransposedMatrix, int ArraySize);