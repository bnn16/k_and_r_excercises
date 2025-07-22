#include <stdio.h>


int simple() {
        int c;

        c = getchar();

        while (c != EOF) {
                putchar(c);

                c = getchar();
        }

        return c;
}

int clean() {
        int c;
        while ((c = getchar()) != EOF) {
                putchar(c);
        }

        return c;
}

int main() {
        int c = clean();
        printf("eof value is %d\n", c);
}
