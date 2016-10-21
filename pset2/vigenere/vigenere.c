#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isalphaonly(const char * str)
{
    string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    return strspn(str, letters) == strlen(str);
}

int main(int argc, const char * argv[])
{
    if (argc != 2 || !isalphaonly(argv[1]))
    {
        printf("Usage: %s <key>\n", argv[0]);
        printf("<key> can only contain letters.\n");
        return 1;
    }
    
    const char * key = argv[1];
    
    printf("plaintext:  ");
    char * plain = get_string();
    if (plain == NULL)
    {
        printf("Error during input\n");
    }
    
    printf("ciphertext: ");
    printf("\n");
    
    
    return 0;
}