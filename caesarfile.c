#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char encrypt(const char plain, int shift) {
    char cipher = plain;
    if (isalpha(plain)) {
        if (plain >= 'A' && plain <= 'Z') {
            cipher = ((plain - 'A' + shift) % 26) + 'A';
        } else if (plain >= 'a' && plain <= 'z') {
            cipher = ((plain - 'a' + shift) % 26) + 'a';
        }
    }
    return cipher;
}

int main() {
    FILE *inputFile, *outputFile;
    char character;
    int shift;
    char *inputPath = malloc(256);
    char *outputPath = malloc(256);

    if (inputPath == NULL || outputPath == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter path of your file that you want to encrypt: ");
    fgets(inputPath, 256, stdin);
    inputPath[strcspn(inputPath, "\n")] = '\0';

    printf("Enter path of your output file: ");
    fgets(outputPath, 256, stdin);
    outputPath[strcspn(outputPath, "\n")] = '\0';

    printf("Enter number of Caesar shift: ");
    scanf("%d", &shift);

    inputFile = fopen(inputPath, "r");

    if (inputFile == NULL) {
        printf("Failed to open input file\n");
        free(inputPath);
        free(outputPath);
        return 1;
    }

    outputFile = fopen(outputPath, "w");

    if (outputFile == NULL) {
        printf("Failed to open the output file\n");
        fclose(inputFile);
        free(inputPath);
        free(outputPath);
        return 1;
    }

    while ((character = fgetc(inputFile)) != EOF) {
        char cipher = encrypt(character, shift);
        fputc(cipher, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
    free(inputPath);
    free(outputPath);

    printf("Encrypt successfully!\n");

    return 0;
}
