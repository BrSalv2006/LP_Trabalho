#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions-team-8.h"

int main(int argc, char *argv[])
{
    // Check Arguments
    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "--help") == 0)
        {
            helpmenu(argv[i]);
        }
    }

    // Pedir Array
    int array[20];
    request_array(array);

    // Calcular quantos elementos o Array tem
    int arraysize = sizeof(array) / sizeof(int);

    // Chamar o Menu
    menu(array, arraysize);
}