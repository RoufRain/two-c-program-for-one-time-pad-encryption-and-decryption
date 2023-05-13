#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void decrypt(char* encrypted_message, char* key, char* decrypted_message) {
    int i, size = strlen(encrypted_message);
    for (i = 0; i < size; i++) {
        decrypted_message[i] = ((encrypted_message[i] - 'A') - (key[i] - 'A') + 26) % 26 + 'A';
    }
    decrypted_message[size] = '\0';
}

int main() {
    char encrypted_message[100], key[100], decrypted_message[100];
    printf("Enter encrypted message (in capital letters): ");
    scanf("%s", encrypted_message);
    printf("Enter key used for encryption: ");
    scanf("%s", key);
    decrypt(encrypted_message, key, decrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);
    return 0;
}

