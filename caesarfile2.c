#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char encrypt(char plain, int shift) {
    if (isalpha(plain)) {
        if (plain >= 'A' && plain <= 'Z') {
            plain = ((plain - 'A' + shift) % 26) + 'A';
        }
        else if (plain >= 'a' && plain <= 'z') {
            plain = ((plain - 'a' + shift + 26) % 26) + 'a';
        }
    }

    return plain;

}

int main() {
    FILE *inputFile, *outputFile;

    char *inputPath = malloc(256);
    char *outputPath = malloc(256);
    char character;
    int shift;

    printf("Enter path of file you want to encrypt: ");
    fgets(inputPath, 256, stdin);
    inputPath[strcspn(inputPath, "\n")] = '\0';

    printf("\nEnter path of output file: ");
    fgets(outputPath, 256, stdin);
    outputPath[strcspn(outputPath, "\n")] = '\0';

    printf("\nEnter number of shift: ");
    scanf("%d", &shift);

    inputFile = fopen(inputPath, "r");

    if (inputFile == NULL) {
        printf("Failed to open input file");
        free(inputPath);
        free(outputPath);
        return 1;
    }

    outputFile = fopen(outputPath, "w");
    
    if (outputFile == NULL) {
        printf("Failed to open output file");
        free(inputPath);
        free(outputPath);
        fclose(inputFile);
        return 1;
    }

    while ((character = fgetc(inputFile)) != EOF) {
        char encryptedchar = encrypt(character, shift);
        fputc(encryptedchar, outputFile);
    }

    free(inputPath);
    free(outputPath);
    fclose(inputFile);
    fclose(outputFile);

    printf("Encrypt successfully!");

    return 0;
}