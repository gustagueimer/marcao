#include <stdio.h>
#include <windows.h>
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}

void time(int ts, int *seg, int *min, int *hr) {
    *seg = ts  % 60;
    *min = ts / 60;
    *hr = *min / 60;
    *min = *min - (*hr * 60);
}

int main() {
    anbt();

    int tempoTotal = 0;
    int segundos = 0;
    int minutos = 0;
    int horas = 0;

    int *ptrSegundos = &segundos;
    int *ptrMinutos = &minutos;
    int *ptrHoras = &horas;

    printf("insira uma quantidade de segundos - ");
    scanf("%i", &tempoTotal);

    time(tempoTotal, ptrSegundos, ptrMinutos, ptrHoras);

    printf("resultados do tempo: \n");
    printf("%d:%d:%d\n", horas, minutos, segundos);

    system("pause");

    return 0;
}