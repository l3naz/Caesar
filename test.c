#include <stdio.h>

int main() {
    char plain[] = "Pjcvfgrvtck";

    for (int i = 0; plain[i] != '\0'; i++) {
        char currentchar = plain[i];

        if (currentchar >= 'A' && currentchar <= 'Z') {
            plain[i] = ((currentchar - 'A' - 2) % 26) + 'A';
        }

        else if (currentchar >= 'a' && currentchar <= 'z') {
            plain[i] = ((currentchar - 'a' - 2) % 26) + 'a';
        }
    }

    printf("%s", plain);

    return 0;
}