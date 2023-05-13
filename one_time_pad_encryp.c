#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

char* generate_key(int size) {
    srand(time(NULL));
    char* key = (char*) malloc(sizeof(char) * (size + 1));
    int i;
    for (i = 0; i < size; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[size] = '\0';
    return key;
}

void encrypt(char* message, char* key, char* encrypted_message) {
    int i, size = strlen(message);
    for (i = 0; i < size; i++) {
        encrypted_message[i] = ((message[i] - 'A') + (key[i] - 'A')) % 26 + 'A';
    }
    encrypted_message[size] = '\0';
}

int main() {
    char message[100], *key, encrypted_message[100];
    printf("Enter message to be encrypted (in capital letters): ");
    scanf("%s", message);
    int size = strlen(message);
    key = generate_key(size);
    printf("Key generated: %s\n", key);
    encrypt(message, key, encrypted_message);
    printf("Encrypted message: %s\n", encrypted_message);
    return 0;
}

