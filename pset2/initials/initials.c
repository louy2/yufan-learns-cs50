#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char * first_letter_after(char * str) {
    string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    return strpbrk(str, letters);
}

char * first_space_after(char * str) {
    return strpbrk(str, " ");
}

int main(void)
{
    
    string name_in = get_string();
    char * initial = name_in;
    while (initial != NULL)
    {
        initial = first_letter_after(initial);
        if (initial == NULL) break;
        printf("%c", toupper(*initial));
        initial = first_space_after(initial);
    }
    printf("\n");
    
}
