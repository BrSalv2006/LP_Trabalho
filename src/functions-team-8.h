/**
    @file functions-team-8.h
*/

void ClearTerminal();
void ClearInput();
void Help(int ArraySize, int Minimum, int Maximum);
void DisposeIntegerArray(int *IntegerArray);
void DisposeFloatArray(float *FloatArray);
int **DisposeMatrix(int **Matrix, int ArraySize);
int *RequestArray(int *Array, int ArraySize, int Minimum, int Maximum);
void PrintInteger(int Integer, char *Text);
void PrintIntegerArray(int *Array, char *Text, int ArraySize);
void PrintFloatArray(float *Array, char *Text, int ArraySize);
void PrintIntegerMatrix(int **Matrix, char *Text, int ArraySize);
int *SortAscendingOrder(int *Array, int *IntegerArray, int ArraySize);
int *AddFirstSecondHalf(int *Array, int *IntegerArray, int ArraySize);
int **GeneratePermutedMatrix(int *Array, int **Matrix, int ArraySize);
float *CosineSecondHalf(int *Array, float *FloatArray, int ArraySize);
int RandomElement(int *Array, int ArraySize);
int *PositionsMultipleof3(int *Array, int *IntegerArray, int ArraySize);
int *MixHalfEachArray(int *Array, int *IntegerArray, int ArraySize, int Minimum, int Maximum);
int *LeastCommonMultiple(int *Array, int *IntegerArray, int ArraySize);
int **ProductBetweenTwoArrays(int *Array, int *IntegerArray, int **Matrix, int ArraySize, int Minimum, int Maximum);
int **TransposeMatrix(int **Matrix, int **TransposedMatrix, int ArraySize);