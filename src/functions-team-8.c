/**
    @file functions-team-8.c
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/// Definir Cópia do Array Original
int arraycopy[20];
/// Declarar Matriz 20x20
int matriz[20][20];
/// Declarar Array de Floats
float floatarray[10];
/// Declarar um Segundo Array
int second_array[20];
/// Declarar um Outro Array
int mixed_array[20];

/// Pedir, Verificar e Guardar vinte números inteiros entre 8 e 29
int *request_array(int array[]) {
	int k, readResult;
	system("clear");
	for (int i = 0; i < 20;) {
		printf("\rInsira um número inteiro entre 8 e 29: ");
		readResult = scanf("%d", &k);
		system("clear");
		if (readResult == 1) {
			if (k >= 8 && k <= 29) {
				array[i] = k;
				i++;
			} else {
				printf("O número deve estar compreendido entre 8 e 29.\n");
			}
		} else {
			clearerr(stdin);
			scanf("%*s");
			printf("Input Inválido\n");
		}
	}
	printf("\e[1;1H\e[2J");
	return array;
}

/// Função Print Integer
void print_int(int integer, char print_text[]) {
	printf("%s\n", print_text);
	printf(" %d", integer);
	printf("\n\n");
}

/// Função Print Integer Array
void print_array(int array[], char print_text[], int arraysize) {
	printf("%s\n", print_text);
	for (int a = 0; a < arraysize; a++) {
		printf(" %d", array[a]);
	}
	printf("\n\n");
}

/// Função Print Float Array
void print_float_array(float array[], char print_text[], int arraysize) {
	printf("%s\n", print_text);
	for (int a = 0; a < arraysize; a++) {
		printf(" %f", array[a]);
	}
	printf("\n\n");
}

/// Função Print Matrix
void print_matrix(int matrix[20][20], char print_text[]) {
	printf("%s\n", print_text);
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			printf(" %3d", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/// Função Reiniciar Cópia do Array
void resetarraycopy(int array[]) {
	for (int a = 0; a < 20; a++) {
		arraycopy[a] = array[a];
	}
}

/// Função Ordenar Array por Ordem Crescente
int *sort_by_ascending_order(int array[]) {
	resetarraycopy(array);
	int i, k, tmp;
	do {
		k = 0;
		i = 0;
		while (i < 19) {
			if (arraycopy[i] > arraycopy[i + 1]) {
				tmp = arraycopy[i];
				arraycopy[i] = arraycopy[i + 1];
				arraycopy[i + 1] = tmp;
				i++;
				k++;
			} else {
				i++;
			}
		}
	} while (k != 0);
	return arraycopy;
}

/// Função Soma a Primeira Metade dos Elementos do Array com a Segunda Metade
int *addfs(int array[]) {
	resetarraycopy(array);
	for (int a = 0; a < 10; a++) {
		arraycopy[a] = arraycopy[a] + arraycopy[a + 10];
	}
	return arraycopy;
}

/// Função Shuffle Array
int *shuffle_array(int matrix_array[]) {
	for (int i = 19; i > 0; i--) {
		int j = rand() % 20;
		int temp = matrix_array[j];
		matrix_array[j] = matrix_array[i];
		matrix_array[i] = temp;
	}
	return matrix_array;
}

/// Função para gerar uma matriz 20x20 com o vetor original e suas permutações
int (*generate_permuted_matrix(int array[], int matriz[20][20]))[20] {
	resetarraycopy(array);
	for (int j = 0; j < 20; j++) {
		matriz[0][j] = arraycopy[j];
	}
	for (int i = 1; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			matriz[i][j] = arraycopy[j];
		}
		shuffle_array(matriz[i]);
	}
	return matriz;
}

/// Função Coseno da Segunda Metade do Array
float *cosine_second_half(int array[]) {
	resetarraycopy(array);
	for (int i = 10; i < 20; i++) {
		floatarray[i - 10] = cos(arraycopy[i]);
	}
	return floatarray;
}

/// Função Random Element
int random_element(int array[]) {
	resetarraycopy(array);
	int integer = rand() % 20;
	return arraycopy[integer];
}

/// Função Multiple of 3
int *multipleof3(int array[]) {
	resetarraycopy(array);
	for (int i = 0; i * 3 + 2 < 20; i++) {
		arraycopy[i] = arraycopy[i * 3 + 2];
	}
	return arraycopy;
}

/// Função Misturar Metade de Cada Array
int *mixhalfarray(int array[]) {
	resetarraycopy(array);
	request_array(second_array);
	for (int i = 0; i < 10; i++) {
		mixed_array[i] = arraycopy[i];
	}
	for (int i = 0; i < 10; i++) {
		mixed_array[10 + i] = second_array[10 + i];
	}
	return mixed_array;
}

/// Função mínimo múltiplo comum de cada dois números seguidos do vetor;
int *leastcommummultiple(int array[]) {
	int max, adder;
	resetarraycopy(array);

	for (int i = 0; i < 19; i++) {
		if (arraycopy[i] > arraycopy[i + 1]) {
			max = arraycopy[i + 1];
			adder = arraycopy[i + 1];
		} else {
			max = arraycopy[i];
			adder = arraycopy[i];
		}

		while (max <= arraycopy[i] * arraycopy[i + 1]) {
			if (max % arraycopy[i] == 0 && max % arraycopy[i + 1] == 0) {
				arraycopy[i] = max;
				break;
			}
			max += adder;
		}
	}
	return arraycopy;
}

/// Função Matriz 20x20 do produto de um vetor aleatório 1x20 e o vetor original
int (*twoarrayscalcmatrix(int array[], int matriz[20][20]))[20] {
	int n;
	resetarraycopy(array);

	for (int i = 0; i < 20; i++) {
		second_array[i] = (rand() % 29) + 8;
	}

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			matriz[i][j] = second_array[i] * array[j];
		}
	}
	return matriz;
}

/// Função Matriz Transposta
int (*transposematrix(int matriz[][20]))[20] {
	int tmp;

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			tmp = matriz[i][j];
			matriz[i][j] = matriz[j][i];
			matriz[j][i] = tmp;
		}
	}
	return matriz;
}

/// Função Menu de Ajuda
void helpmenu() {
	system("clear");
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

/// Função Mostrar Menu e Escolher Sub-Menu
void menu(int array[], int arraysize) {
	int menuchoice, readResult;
	print_array(array, "Vetor Original:", arraysize);
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

	readResult = scanf("%d", &menuchoice);
	system("clear");
	if (readResult == 1) {
		switch (menuchoice) {
		case 1:
			print_array(sort_by_ascending_order(array), "Vetor ordenado por ordem crescente:", arraysize);
			menu(array, arraysize);
		case 2:
			print_array(addfs(array), "Soma da primeira metade dos elementos no vetor com os da segunda metade:", arraysize / 2);
			menu(array, arraysize);
		case 3:
			print_matrix(generate_permuted_matrix(array, matriz), "Matriz 20x20 com o vetor original e algumas das suas permutações:");
			menu(array, arraysize);
		case 4:
			print_float_array(cosine_second_half(array), "Cosseno da segunda metade dos elementos no vetor:", arraysize / 2);
			menu(array, arraysize);
		case 5:
			print_int(random_element(array), "Elemento aleatório do vetor:");
			menu(array, arraysize);
		case 6:
			print_array(multipleof3(array), "Posições múltiplas de 3:", arraysize / 3);
			menu(array, arraysize);
		case 7:
			helpmenu();
			menu(array, arraysize);
		case 8:
			exit(0);
		case 9:
			print_array(mixhalfarray(array), "Misturar metade de cada vetor:", arraysize);
			menu(array, arraysize);
		case 10:
			print_array(leastcommummultiple(array), "Mínimo múltiplo comum de cada dois números seguidos do vetor:", arraysize - 1);
			menu(array, arraysize);
		case 11:
			print_matrix(twoarrayscalcmatrix(array, matriz), "Matriz 20x20 do produto de um vetor aleatório 1x20 e o vetor original:");
			print_array(second_array, "Vetor Aleatório:", 20);
			menu(array, arraysize);
		case 12:
			print_matrix(transposematrix(twoarrayscalcmatrix(array, matriz)), "Matriz 20x20 do produto de um vetor aleatório 1x20 e o vetor original Transposta:");
			print_array(second_array, "Vetor Aleatório:", 20);
			menu(array, arraysize);
		default:
			menu(array, arraysize);
		}
	} else {
		clearerr(stdin);
		scanf("%*s");
		menu(array, arraysize);
	}
}