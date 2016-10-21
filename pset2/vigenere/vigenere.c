#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isalphaonly(const char * str)
{
    string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    return strspn(str, letters) == strlen(str);
}

void encrypt(char * plain, const char * key, char * cipher)
{
    // turn key into rotation index
    int key_len = strlen(key);
    char rots[key_len];
    for (int i = 0; i < key_len; i++)
    {
        rots[i] = toupper(key[i]) - 65;
    }
    // rotate encrypt
    int plain_len = strlen(plain);
    int j = 0;
    for (int i = 0; i < plain_len; i++)
    {
        if (isalpha(plain[i]))
        {
            char c = plain[i];
            char pad = 0;
            if (isupper(c))
                pad = 65;
            else
                pad = 97;
            cipher[i] = (c - pad + rots[j]) % 26 + pad;
            j = (j + 1) % key_len;
        }
        else
            cipher[i] = plain[i];
    }
    cipher[plain_len] = '\0';
}

int main(int argc, const char * argv[])
{
    if (argc != 2 || !isalphaonly(argv[1]))
    {
        printf("Usage: %s <key>\n", argv[0]);
        printf("<key> can only contain letters.\n");
        return 1;
    } // argc == 2 && isalphaonly(argv[1])
    
    const char * key = argv[1];
    
    printf("plaintext:  ");
    char * plain = get_string();
    if (plain == NULL)
    {
        printf("Error during input\n");
    }
    
    char cipher[strlen(plain) + 1]; // +1 for NULL term
    encrypt(plain, key, cipher);
    
    printf("ciphertext: ");
    printf("%s", cipher);
    printf("\n");
    
    
    return 0;
}