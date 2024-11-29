#include <stdio.h>
#include <windows.h>
//balls 101
void anbt() {
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);
}

boolean findPrimo(num) {
    int primo;
    if(num == 2){
        primo = 1;
    }
    for(int i = num;i > 2;i--){
        if(num % (i-1) != 0 || num==3){
            primo=1;
        }else{
            primo=0;
            break;
        }
    }
    if(primo==1){
        return TRUE;
    }else{
        return FALSE;
    }
}

void ignition(int base, int *th1, int *th2) {
    for(int i=base; i!=0;i--) {
        if(findPrimo(i)) {
            *th1 = i;
            break;
        }
    }
    for(int i=base; i!=(base+100000); i++) {
        if(findPrimo(i)) {
            *th2 = i;
            break;
        }
    }
}

int main() {
    anbt();

    int tulin = 0;
    int ph1 = 0;
    int ph2 = 0;

    int *ptrPh1 = &ph1;
    int *ptrPh2 = &ph2;

    printf("insira umm número - ");
    scanf("%i", &tulin);

    ignition(tulin, ptrPh1, ptrPh2);

    printf("maior número primo antes de %d: %d\n", tulin, ph1);
    printf("menor número primo depois de %d: %d\n", tulin, ph2);

    system("pause");
    return 0;
}