#include <stdio.h>

int main() {
    int dizi[] = { 10, 20, 20 };
    int n = sizeof(dizi) / sizeof(dizi[0]);

    int elmlar[10];
    int frekans[10];
    int sayac = 0;
    for (int i = 0; i < n; i++) {
        int eleman = dizi[i];
        int j;
        for (j = 0; j < sayac; j++) {
            if (elmlar[j] == eleman) {
                frekans[j]++;
                break;
            }
        }
        if (j == sayac) {
            elmlar[sayac] = eleman;
            frekans[sayac] = 1;
            sayac++;
        }
    }

    for (int i = 0; i < sayac; i++) {
        printf("%d -> %d\n", elmlar[i], frekans[i]);
    }

    return 0;
}
