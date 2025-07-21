#include <stdio.h>
#include <string.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int convert_to_farh(int celsius) {
        return celsius * 1.8 + 32;
}

int oops_main(int argv, char* argc[]) {
        if(argv == 1) {
                printf("no args provided\n");
                return 1;
        }


        char arg1[] = "--temp";

        int result = strcmp(arg1, argc[1]);

        if(result != 0) {
                printf("invalid arg\n");
                return 1;
        }

        char *arg_celsius = argc[2];

        int celsius;

        sscanf(arg_celsius, "%d", &celsius);

        printf("Celsius to decimal is %d\n", convert_to_farh(celsius));

        return 0;

}

void fahr_to_celsius() {
        float fahr, celsius;

        fahr = LOWER;

        while(fahr <= UPPER) {
                celsius = 5 * (fahr - 32) / 9;
                printf("%3f\t%6f\n", fahr, celsius);

                fahr = fahr + STEP;
        }
}

void fahr_to_celsius_for() {
        float fahr;

        for(fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
                printf("%3f\t%6f\n", fahr, (5.0 /9.0) * (fahr - 32));
        }
}

void fahr_to_celsius_for_reversed() {
        float fahr;

        for(fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP) {
                printf("%3f\t%6f\n", fahr, (5.0 /9.0) * (fahr - 32));
        }
}


int main(int argv, char* argc[]) {
        // return oops_main(argv, argc);
        // fahr_to_celsius();
        // fahr_to_celsius_for();
        fahr_to_celsius_for_reversed();

       return 0;
}
