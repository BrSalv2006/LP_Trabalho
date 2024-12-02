/**
    @file functions-team-8.h
*/

void ClearTerminal();
void ClearInput();
void Help();
void DisposeArrayCopy();
void DisposeHalfArray();
void DisposePositionsMultipleof3Array();
void DisposeHalfFloatArray();
void DisposeMatrix(int ArraySize);
int *RequestArray(int *Array, int ArraySize, int Minimum, int Maximum);
void PrintInteger(int Integer, char *Text);
void PrintIntegerArray(int *Array, char *Text, int ArraySize);
void PrintFloatArray(float *Array, char *Text, int ArraySize);
void PrintIntegerMatrix(int **Matrix, char *Text, int MatrixSize);
int *SortAscendingOrder(int *Array, int ArraySize);
int *AddFirstSecondHalf(int *Array, int ArraySize);
int **GeneratePermutedMatrix(int *Array, int ArraySize);
float *CosineSecondHalf(int *Array, int ArraySize);
int RandomElement(int *Array, int ArraySize);
int *PositionsMultipleof3(int *Array, int ArraySize);