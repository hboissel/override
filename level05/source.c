#include <stdio.h>

int main()
{
    char tmp[40]; // 40
    char buffer[100]; // esp+0x28
    int i; // esp+0x8c

    i = 0;
    fgets(buffer, 100, stdin);
    // change uppercase to lowercase
    for ( i = 0; i < strlen(buffer); ++i )
    {
        if ( buffer[i] > 64 && buffer[i] <= 90 )
            buffer[i] ^= ' ';
    }
    printf(buffer);
    exit(0);
}