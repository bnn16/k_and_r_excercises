#include <stdio.h>
#include <stdlib.h>

#define END_OF_LINE 10
#define TAB 11
#define WHITE_SPACE 32
#define BACK_SLASH 92
#define BACK_SPACE 8


void array_example() {
        int c, i, nwhite, nother;
        int digit[10];

        nwhite = nother = 0;

        for(i = 0; i < 10; ++i) {
                digit[i] = 0;
        }

        while((c = getchar()) != EOF) {
                if (c >= '0' || c <= '9') {
                        ++digit[c-'0'];
                } else if (c == WHITE_SPACE || c == TAB || c == END_OF_LINE) {
                        ++nwhite;
                } else {
                        ++nother;
                }
        }

        printf("digits =");
        for(i = 0; i < 10; ++i) {
                printf(" %d", digit[i]);
        }

        printf(", white space = %d, other = %d\n", nwhite, nother);
}

void print_histogram(int *digit, int longest_character) {
        for(int i = 0; i <= longest_character; ++i) {
                if(digit[i] == 0) continue;

                printf("Length %d:" , i);

                for(int j = 0; j < digit[i]; ++j) {
                        printf("*");
                }

                printf("\n");
        }
}

void histogram_1_13_simple() {
        int current_char;
        int digit[10] = {0};

        int count = 0;

        while((current_char = getchar()) != EOF) {
                if(current_char == END_OF_LINE || current_char == TAB || current_char == WHITE_SPACE) {
                        ++digit[count];
                        count = 0;
                } else {
                        ++count;
                }
        }

        print_histogram(digit, 10);
}

void histogram_1_13_harder() {
        int *digit = calloc(10, sizeof(int));
        int max_length = 10;

        int current_char;
        int count = 0;

        int longest_character = 0;

        while((current_char = getchar()) != EOF) {
                int is_end = current_char == END_OF_LINE || current_char == TAB || current_char == WHITE_SPACE; 

                if(is_end) {
                        if(count > longest_character) {
                                longest_character = count;
                        }
                        ++digit[count];
                        count = 0;

                        continue;
                }

                ++count;

                if(count < max_length) {
                        continue;
                }

                int old_max = max_length;
                max_length *= 2;
                digit = realloc(digit, max_length * sizeof(int));

                for(int i = old_max; i < max_length; i++) {
                        digit[i] = 0;
                }
        }

        print_histogram(digit, longest_character);

        free(digit);
}

int main() {
        // array_example();

        // histogram_1_13_harder();

        // histogram_1_14();
}
