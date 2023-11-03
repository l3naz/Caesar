#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *encryption(char *plain, int num_shift) {

    for (int i = 0; plain[i] != '\0'; i++) {
        char currentchar = plain[i];
        
        if (isalpha(currentchar)) {

            if (currentchar >= 'A' && currentchar <= 'Z') {
                plain[i] = ((currentchar - 'A' + num_shift) % 26) + 'A';
            }

            else if (currentchar >= 'a' && currentchar <= 'z') {
                plain[i] = ((currentchar - 'a' + num_shift) % 26) + 'a';
            }
        }
        
    }

    return plain;

}

char *decryption(char *cipher, int num_shift) {

    for (int i = 0; cipher[i] != '\0'; i++) {
        char currentchar = cipher[i];

        if (isalpha(currentchar)) {
            if (currentchar >= 'A' && currentchar <= 'Z') {
                cipher[i] = ((currentchar - 'A' - num_shift + 26) % 26) + 'A';
            }

            else if (currentchar >= 'a' && currentchar <= 'z') {
                cipher[i] = ((currentchar - 'a' - num_shift + 26) % 26) + 'a';
            }
        }
    }

    return cipher;

}

char *bruteforce(char *cipher) {
    
    for (int shift = 0; shift <= 25; shift++){
        char result[100];
        strcpy(result, cipher);
        for (int i = 0; result[i] != '\0'; i++) {
            char currentchar = result[i];

            if (isalpha(currentchar)) {
                if (currentchar >= 'A' && currentchar <= 'Z') {
                    result[i] = ((currentchar - 'A' - shift + 26) % 26) + 'A';
                }

                else if (currentchar >= 'a' && currentchar <= 'z') {
                    result[i] = ((currentchar - 'a' - shift + 26) % 26) + 'a';
                }
            }
        }
        printf("Shift %d: %s", shift, result);
    }
    return 0;
}

int main() {

    char message[100];
    int shift;
    int choice;
    int de_choice;

    printf("Hello, welcome to Nhat's Caesar, how can I help you?\n");
    printf("1) Encrypt message\n");
    printf("2) Decrypt Cipher text\n");
    printf("choice: ");
    scanf("%d", &choice);

    if ( choice == 1 ) {
        printf("\nEnter your message: ");
        getchar();
        fgets(message, sizeof(message), stdin);
        printf("\nEnter number of shift you want (0-25): ");
        scanf("%d", &shift);

        if (shift < 0 || shift > 25) {
            printf("Unvalid number of shift, please try again (0-25)");
            return 1;
        }

        char *result_en = encryption(message, shift);
        printf("Your cipher text is: %s", result_en);
    }
    else if (choice == 2) {

        printf("1) Enter specific shift key\n");
        printf("2) Brute force\n");
        printf("choice: ");
        scanf("%d", &de_choice);

        if (de_choice == 1) {

            printf("Enter your cipher text: ");
            getchar();
            fgets(message, sizeof(message), stdin);
            printf("\nEnter number of shift you want (0-25): ");
            scanf("%d", &shift);

            if (shift < 0 || shift > 25) {
                printf("Unvalid number of shift, please try again (0-25)");
                return 1;
            }

            char *result_de = decryption(message, shift);
            printf("Your plain text is: %s", result_de);
        }
        else {
            printf("Enter your cipher text: ");
            getchar();
            fgets(message, sizeof(message), stdin);
            printf("These are all 26 possibilities: \n");
            bruteforce(message);

        }

    }
    else {
        printf("Option not available, try again");
        return 2;
    }


    return 0;


}
