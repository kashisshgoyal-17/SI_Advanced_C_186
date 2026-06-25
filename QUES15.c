#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;

    printf("Enter a character: ");
    scanf("%c", &ch);

    ch = tolower(ch);

    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        printf("%c is a vowel\n", ch);
    else if (ch >= 'a' && ch <= 'z')
        printf("%c is a consonant\n", ch);
    else
        printf("%c is not an alphabet\n", ch);

    return 0;
}