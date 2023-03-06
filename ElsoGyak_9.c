#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int n, i;
    char filename[50];
    clock_t numberT;
    clock_t fileT;


    printf("Enter the number of random numbers you want to generate: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));

    printf("Enter the name of the file you want to write the numbers to: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    srand(time(NULL));

    numberT = clock();
    for (i = 0; i < n; i++) {
        arr[i] = rand();
    }
    numberT = clock() - numberT;
    double numberTimeTaken = ((double)numberT)/CLOCKS_PER_SEC;

    fileT = clock();
    for (i = 0; i < n; i++) {
        fprintf(fp, "%d\n", arr[i]);
    }
    fclose(fp);
    fileT = clock() - fileT;
    double fileTimeTaken = ((double)fileT)/CLOCKS_PER_SEC;

    printf("Number generator took %f time\nFile writing took %f time\n", numberTimeTaken, fileTimeTaken);

    printf("Generated random numbers and wrote them to file %s successfully!\n", filename);

    // write time taken to file
    FILE *time_fp = fopen("time.txt", "w");
    fprintf(time_fp, "%f %f", numberTimeTaken, fileTimeTaken);
    fclose(time_fp);

    free(arr);

    return 0;
}
