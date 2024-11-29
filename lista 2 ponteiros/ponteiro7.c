#include <stdio.h>
#include <windows.h>
#include <math.h>
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}

void esferometro(float raio, float *area, float *volume) {
    *area = 4 * 3.14 * (powf(raio, 2)); 
    *volume = 1.333 * 3.14 * (powf(raio, 3));
}

int main() {
    anbt();

    float zap = 0;
    float zone = 0;
    float sound = 0;

    float *ptrZone = &zone;
    float *ptrSound = &sound;

    printf("insira o tamanho do raio (cm) - ");
    scanf("%f", &zap);

    esferometro(zap, ptrZone, ptrSound);

    printf("resultados do esferômetro: \n");
    printf("àrea da esfera: ~%.2fcm²\n", zone);
    printf("volume da esfera: ~%.2fcm³\n", sound);

    system("pause");

    return 0;
}