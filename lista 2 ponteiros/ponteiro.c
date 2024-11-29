#include <stdio.h>
#include <stdlib.h>
#include <windows.h.>
//balls 101
int main() {    
    int inte = 0;
    //printf("endereco do int:    %p\n", &inte);
    float flutua = 0;
    //printf("endereco do float:  %p\n", &flutua);
    char charada = '\0';
    //printf("endereco do char:   %p\n\n", &charada);

    int *pontInte = &inte;
    //printf("endereco do *int:   %p\n", pontInte);
    float *pontFlutua = &flutua;
    //printf("endereco do *float: %p\n", pontFlutua);
    char *pontCharada = &charada;
    //printf("endereco do *char:  %p\n\n", pontCharada);

    printf("valores antes dos bagulhonsons\n");
    printf("int: %i\n", inte);
    printf("float: %i\n", inte);
    printf("char: %i\n\n", inte);

    *pontInte = 4;
    *pontFlutua =  (float)6.9;
    *pontCharada = 'O';

    printf("valores depois dos bagulhonsons\n");
    printf("int: %i\n", inte);
    printf("float: %f\n", flutua);
    printf("char: %c\n\n", charada);

    system("pause");

    return 0;
}