#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Definir Cópia do Array Original
int arraycopy[20];
int matriz[20][20];
float floatarray[10];

// Função Pedir, Verificar e Guardar vinte números inteiros entre 8 e 29
int *request_array(int array[])
{
    int k, readResult;
    // system("clear");
    for (int i = 0; i < 20;)
    {
        printf("\rInsira um número inteiro entre 8 e 29: ");
        readResult = scanf("%d", &k);
        system("clear");
        if (readResult == 1)
        {
            if (k >= 8 && k <= 29)
            {
                array[i] = k;
                i++;
            }
            else
            {
                printf("O número deve estar compreendido entre 8 e 29.\n");
            }
        }
        else
        {
            clearerr(stdin);
            scanf("%*s");
            printf("Input Inválido\n");
        }
    }
    printf("\e[1;1H\e[2J");
    return array;
}

// Função Print Integer
void print_int(int integer, char print_text[])
{
    printf("%s\n", print_text);
    printf(" %d", integer);
    printf("\n\n");
}

// Função Print Integer Array
void print_array(int array[], char print_text[], int arraysize)
{
    printf("%s\n", print_text);
    for (int a = 0; a < arraysize; a++)
    {
        printf(" %d", array[a]);
    }
    printf("\n\n");
}

// Função Print Float Array
void print_float_array(float array[], char print_text[], int arraysize)
{
    printf("%s\n", print_text);
    for (int a = 0; a < arraysize; a++)
    {
        printf(" %f", array[a]);
    }
    printf("\n\n");
}

// Função Print Matrix
void print_matrix(int matrix[20][20], char print_text[])
{
    printf("%s\n", print_text);
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            printf(" %2d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função Reiniciar Cópia do Array
void resetarraycopy(int array[])
{
    for (int a = 0; a < 20; a++)
    {
        arraycopy[a] = array[a];
    }
}

// Função Ordenar Array por Ordem Crescente
int *sort_by_ascending_order(int array[])
{
    resetarraycopy(array);
    int i, k, tmp;
    do
    {
        k = 0;
        i = 0;
        while (i < 19)
        {
            if (arraycopy[i] > arraycopy[i + 1])
            {
                tmp = arraycopy[i];
                arraycopy[i] = arraycopy[i + 1];
                arraycopy[i + 1] = tmp;
                i++;
                k++;
            }
            else
            {
                i++;
            }
        }
    } while (k != 0);
    return arraycopy;
}

// Função Soma a Primeira Metade dos Elementos do Array com a Segunda Metade
int *addfs(int array[])
{
    resetarraycopy(array);
    for (int a = 0; a < 10; a++)
    {
        arraycopy[a] = arraycopy[a] + arraycopy[a + 10];
    }
    return arraycopy;
}

// Função Shuffle Array
int *shuffle_array(int matrix_array[])
{
    for (int i = 19; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = matrix_array[i];
        matrix_array[i] = matrix_array[j];
        matrix_array[j] = temp;
    }
    return matrix_array;
}

// Função para gerar uma matriz 20x20 com o vetor original e suas permutações
int (*generate_permuted_matrix(int array[], int matriz[20][20]))[20]
{
    resetarraycopy(array);
    for (int j = 0; j < 20; j++)
    {
        matriz[0][j] = arraycopy[j];
    }
    for (int i = 1; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            matriz[i][j] = arraycopy[j];
        }
        shuffle_array(matriz[i]);
    }
    return matriz;
}

// Função Coseno da Segunda Metade do Array
float *cosine_second_half(int array[])
{
    resetarraycopy(array);
    for (int i = 10; i < 20; i++)
    {
        floatarray[i - 10] = cos(arraycopy[i]);
    }
    return floatarray;
}

// Função Random Element
int random_element(int array[])
{
    resetarraycopy(array);
    int integer = rand() % 20;
    return arraycopy[integer];
}

// Função Menu de Ajuda
void helpmenu(char argv[])
{
    printf("Argument = %s\n\n", argv);
}

// Função Mostrar Menu e Escolher Sub-Menu
void menu(int array[], int arraysize)
{
    int menuchoice, readResult;
    srand(time(NULL));
    print_array(array, "Vetor Original:", arraysize);
    printf("Menu:\n");
    printf("1 - Vetor ordenado por ordem crescente\n");
    printf("2 - Soma da primeira metade dos elementos no vetor com os da segunda metade\n");
    printf("3 - Matriz 20x20 com o vetor original e algumas das suas permutações\n");
    printf("4 - Cosseno da segunda metade dos elementos no vetor\n");
    printf("5 - Elemento aleatório do vetor\n");
    printf("6 - \n");
    printf("7 - Menu de Ajuda\n");
    printf("8 - Sair\n");
    readResult = scanf("%d", &menuchoice);
    system("clear");
    if (readResult == 1)
    {
        switch (menuchoice)
        {
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

        case 7:
            helpmenu("--help");
            menu(array, arraysize);
        case 8:
            exit(0);
        default:
            menu(array, arraysize);
        }
    }
    else
    {
        clearerr(stdin);
        scanf("%*s");
        menu(array, arraysize);
    }
}