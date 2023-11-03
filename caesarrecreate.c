#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *encrypt(char *message, int shift) {

    for (int i = 0; message[i] != '\0'; i++) {
        char currentchar = message[i];
        if (isalpha(currentchar)) {
            if (currentchar >= 'A' && currentchar <= 'Z') {
                message[i] = ((currentchar -'A' + shift) % 26) + 'A';
            }
            else if ( currentchar >= 'a' && currentchar <= 'z') {
                message[i] = ((currentchar - 'a' + shift) % 26) + 'a';
            }
        }
    }

    return message;
}

char *decrypt(char *message, int shift) {

    for (int i = 0; message[i] != '\0'; i++) {
        char currentchar = message[i];
        if (isalpha(currentchar)) {
            if (currentchar >= 'A' && currentchar <= 'Z') {
                message[i] = ((currentchar -'A' - shift + 26) % 26) + 'A';
            }
            else if ( currentchar >= 'a' && currentchar <= 'z') {
                message[i] = ((currentchar - 'a' - shift + 26) % 26) + 'a';
            }
        }
    }

    return message;
}

char *bruteforce(char *message) {
    
    for (int shift = 0; shift <= 25; shift++) {
        char cpmsg[100];
        strcpy(cpmsg, message);
        for (int i=0; cpmsg[i] != '\0'; i++) {
            if (isalpha(cpmsg[i])) {
                if (cpmsg[i] >= 'A' && cpmsg[i] <= 'Z') {
                    cpmsg[i] = ((cpmsg[i] -'A' - shift + 26) % 26) + 'A';
                }
                else if ( cpmsg[i] >= 'a' && cpmsg[i] <= 'z') {
                    cpmsg[i] = ((cpmsg[i] - 'a' - shift + 26) % 26) + 'a';
                }
            }
        }
    printf("Shift %d: %s\n", shift, cpmsg);
    }

    return NULL;
}

int main() {

    char input[255];
    int shift;
    int choice;

    printf("Welcome to Nhat caesar's, what do you want to do?");
    printf("\n1) Encrypt message");
    printf("\n2) Decrypt ciphertext");
    printf("\n3) Bruteforce");
    printf("\nChoice: ");
    scanf("%d", &choice);

    if ( choice == 1) {
        printf("Enter message: ");
        getchar();
        fgets(input, sizeof(input), stdin);
        printf("\nEnter shift value: ");
        scanf("%d", &shift);

        printf("This is your encrypted message: ");
        printf(encrypt(input, shift));
    }
    else if (choice == 2) {
        printf("Enter message: ");
        getchar();
        fgets(input, sizeof(input), stdin);
        printf("\nEnter shift value: ");
        scanf("%d", &shift);

        printf("This is your encrypted message: ");
        printf(decrypt(input, shift));
    }
    else if (choice == 3) {
        printf("Enter Cipher text to brute force: ");
        getchar();
        fgets(input, sizeof(input), stdin);
        printf("Here are all possibilities: \n");
        bruteforce(input);

    }
    else {
        printf("Please input 1 or 2");
        return 1;
    } 
        

}