#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define END_OF_LINE 10
#define TAB 11
#define WHITE_SPACE 32
#define BACK_SLASH 92
#define BACK_SPACE 8

void full_count() {
        long chars = 0, lines = 0, white_space = 0, tabs = 0, wc = 0;
        int c;
        int active = 0;
        while((c = getchar()) != EOF) {
                switch (c) {
                        case WHITE_SPACE:
                                ++white_space;
                                if (active) ++wc;
                                active = 0;
                                break;
                        case END_OF_LINE:
                                ++lines;
                                if(active) ++wc;
                                active = 0;
                                break;
                        case TAB:
                                ++tabs;
                                if(active) ++wc;
                                active = 0;
                                break;
                        default:
                                active = 1;
                                ++chars;
                                break;
             }
        }
        printf("chars: %ld, lines: %ld, white spaces %ld, tabs %ld, words %ld \n", chars, lines, white_space, tabs, wc);
}

void replace_white_space_characters() {
        char* str = malloc(100);
        int capacity = 100;
        int length = 0;

        int c;
        int active = 0;

        while((c = getchar()) != EOF) {
                if (length >= capacity - 1) {
                        capacity *= 2;
                        str = realloc(str, capacity);
                }

                switch (c) {
                        case WHITE_SPACE:
                                if (!active) {
                                        str[length] = (char) c;
                                        ++length;
                                };
                                active = 1;
             break;
                        case END_OF_LINE:
                                active = 0;
                                str[length] = (char) c;
                                ++length;
                                break;
                        case TAB:
                                str[length] = (char) c;
                                ++length;
                                break;
                        default:
                                str[length] = (char) c;
                                active = 0;
                                ++length;
                                break;
                }

        }
        str[length] = '\0';
        printf("%s", str);
        free(str);

        str = NULL;
}

void replace_special_characters() {
        int c;
        while((c = getchar()) != EOF) {
                switch(c) {
                        case '\t':
                                printf("\\t");
                                break;
                        case '\b':
                                printf("\\b");
                                break;
                        case '\\':
                                printf("\\\\");
                                break;
                        default:
                                putchar(c);
                }
        };
};

void print_one_word_per_line() {
        int c;
        int active = 0;

        while((c = getchar()) != EOF) {
                switch (c) {
                        case WHITE_SPACE:
                                if (active) {
                                        printf("\n");
                                };
                                active = 0;
                                break;
                        case END_OF_LINE:
                                if (active) {
                                        printf("\n");
                                }
                                active = 0;
                                break;
                        case TAB:
                                if (active) {
                                        printf("\n");
                                };
                               active = 0;
                                break;
                        default:
                                printf("%c", c);
                                active = 1;
                                break;
                }
        }
}


int main() {
        // full_count();

        // kinda cheating since I used malloc here :trollface:
        // replace_white_space_characters();

        // replace_special_characters();
        
        print_one_word_per_line();
}
