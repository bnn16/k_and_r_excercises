#include <stdio.h>

int math_pow(int m, int n);

int main() {
        int i;
        for (i = 0; i < 10; ++i)
                printf("%d %d %d\n", i, math_pow(2,i), math_pow(-3,i));
        return 0;
}

int math_pow(int m, int n) {
        int i, p;

        p = 1;

        for(i = 0; i <= n; ++i) {
                p = p * n;
        }

        return p;
}
