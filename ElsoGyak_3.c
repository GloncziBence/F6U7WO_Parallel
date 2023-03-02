#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i;
    int randomI_num;
    float randomF_num;
    srand(time(NULL));

    printf("random floating-point numbers between 500 and 1000:\n");
    for (i = 0; i < 10; i++) {
        randomF_num = ((float)rand() / RAND_MAX) * 500 + 500;
        printf("%f\n", randomF_num);
    }

    srand(time(NULL));
    printf("random numbers between 500 and 1000:\n");
    for (i = 0; i < 10; i++){
        randomI_num = rand() % 501 + 500;
        printf("%d\n", randomI_num);
    }

    return 0;
}
