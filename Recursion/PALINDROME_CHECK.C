#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool checking(int mover, char s[], int size)
{
    if (mover >= size / 2)
        return true;

    if (s[mover] != s[size - mover - 1])
        return false;

    return checking(mover + 1, s, size);
}

int main()
{
    char s[] = "madam";
    int mover = 0;
    int size = strlen(s);

    if (checking(mover, s, size))
        printf("Palindrome");
    else
        printf("Not Palindrome");

    return 0;
}
