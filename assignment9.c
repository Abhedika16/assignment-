#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp1, *fp2;
    int ch;

    // Create source.txt with sample text first
    fp1 = fopen("source.txt", "w");
    if (fp1 == NULL) {
        printf("Could not create source file.\n");
        exit(1);
    }
    fprintf(fp1, "Hello! This is sample text.\n");
    fclose(fp1);

    // Open source file in read mode
    fp1 = fopen("source.txt", "r");
    if (fp1 == NULL) {
        printf("Source file cannot be opened.\n");
        exit(1);
    }

    // Open destination file in write mode
    fp2 = fopen("destination.txt", "w");
    if (fp2 == NULL) {
        printf("Destination file cannot be opened.\n");
        fclose(fp1);
        exit(1);
    }

    // Read and copy contents character by character
    while ((ch = fgetc(fp1)) != EOF) {
        fputc(ch, fp2);
    }

    printf("File copied successfully.\n");

    // Close both files
    fclose(fp1);
    fclose(fp2);

    return 0;
}