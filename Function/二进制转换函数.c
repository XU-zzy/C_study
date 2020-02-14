#include <stdio.h>

void bprint(int p) {
    int i = 0;
    int bit1 = 1;
    for (i = sizeof(p) * 8 - 1; i >= 0; i--) {
        unsigned int x = (((bit1 << i) & p) != 0);
        printf("%d", x);
    }

    printf("\n ");
}

int main() {
    int n;
    scanf("%d", &n);
    bprint(n);
    return 0;
}
