#include <stdio.h>
#include <stdlib.h>

void kurangiKemungkinan(int * kemungkinan_sekarang, int kemungkinan_turun) {
    (*kemungkinan_sekarang) = (*kemungkinan_sekarang) * (1-(float)kemungkinan_turun /100);
}

int main() {
    int count;
    int kemungkinan_sekarang;
    int kemungkinan_maksimum;
    int kemungkinan_turun;

    scanf("%d", &kemungkinan_sekarang);
    scanf("%d", &kemungkinan_maksimum);
    scanf("%d", &kemungkinan_turun);

    count = 0;
    while (kemungkinan_sekarang > kemungkinan_maksimum) {
        kurangiKemungkinan(&kemungkinan_sekarang, kemungkinan_turun);
        ++count;
    }

    printf("%d\n", count);
    return 0;
}