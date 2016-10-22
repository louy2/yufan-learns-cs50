#define _XOPEN_SOURCE
#include <unistd.h>

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int brute_salt(const char * plaintext, const char * target)
{
    char salt[3] = {'\0', '\0', '\0'};
    memcpy(salt, target, 2);
    char * ciphertext = crypt(plaintext, salt);
    if (ciphertext == NULL)
        return false;
    if (strcmp(ciphertext, target) == 0)
        return true;
    return false;
}

int main(int argc, const char * argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <hashed password>\n", argv[0]);
        return 1;
    } // argc == 2
    
    const char * hashed_pw = argv[1];
    const char * letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int letters_len = strlen(letters);
    
    char plaintext[5] = {'\0', '\0', '\0', '\0', '\0'};
    // strlen(plaintext) == 1
    for (int i = 0; i < letters_len; i++)
    {
        plaintext[0] = letters[i];
        if (brute_salt(plaintext, hashed_pw))
            goto found;
    }
    // strlen(plaintext) == 2
    for (int i = 0; i < letters_len; i++)
    {
        plaintext[0] = letters[i];
        for (int j = 0; j < letters_len; j++)
        {
            plaintext[1] = letters[j];
            if (brute_salt(plaintext, hashed_pw))
                goto found;
        }
    }
    // strlen(plaintext) == 3
    for (int i = 0; i < letters_len; i++)
    {
        plaintext[0] = letters[i];
        for (int j = 0; j < letters_len; j++)
        {
            plaintext[1] = letters[j];
            for (int k = 0; k < letters_len; k++)
            {
                plaintext[2] = letters[k];
                if (brute_salt(plaintext, hashed_pw))
                    goto found;
            }
        }
    }
    // strlen(plaintext) == 4
    for (int i = 0; i < letters_len; i++)
    {
        plaintext[0] = letters[i];
        for (int j = 0; j < letters_len; j++)
        {
            plaintext[1] = letters[j];
            for (int k = 0; k < letters_len; k++)
            {
                plaintext[2] = letters[k];
                for (int l = 0; l < letters_len; l++)
                {
                    plaintext[3] = letters[l];
                    if (brute_salt(plaintext, hashed_pw))
                        goto found;
                }
            }
        }
    }
    
    
    plaintext[0] = '\0';
found:
    printf("%s\n", plaintext);
    
    return 0;
}