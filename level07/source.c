#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_unum()
{
    unsigned int v1; // [esp+1Ch] [ebp-Ch] BYREF

    v1 = 0;
    fflush(stdout);
    scanf("%u", v1);
    clear_stdin();
    return v1;
}

int read_number(int *storage)
{
    unsigned int index; // [esp+1Ch] [ebp-Ch]

    printf(" Index: ");
    index = get_unum();
    printf(" Number at data[%u] is %u\n", index, storage[4 * index]);
    return 0;
}

int store_number(int *storage)
{
    unsigned int number; // [esp+18h] [ebp-10h]
    unsigned int index; // [esp+1Ch] [ebp-Ch]

    printf(" Number: ");
    number = get_unum();
    printf(" Index: ");
    index = get_unum();
    if ( index == 3 * (index / 3) || HIBYTE(number) == 183 )
    {
        puts(" *** ERROR! ***");
        puts("   This index is reserved for wil!");
        puts(" *** ERROR! ***");
        return 1;
    }
    else
    {
        storage[4 * index] = number;
        return 0;
    }
}

int main(int argc, const char **argv, const char **envp)
{
    unsigned int storage[100]; // [esp+24h] [ebp-1B8h] BYREF
    int number; // [esp+1B4h] [ebp-28h]
    char input[20]; // [esp+1B8h] [ebp-24h] BYREF
    unsigned int v13; // [esp+1CCh] [ebp-10h]

    v13 = __readgsdword(0x14u);
    number = 0;
    *((int *)input) = 0;
    *((int *)input + 1) = 0;
    *((int *)input + 2) = 0;
    *((int *)input + 3) = 0;
    *((int *)input + 4) = 0;
    memset(storage, 0, sizeof(storage));
    // empty argv and envp
    while ( *argv )
    {
        memset(*argv, 0, strlen(*argv));
        ++argv;
    }
    while ( *envp )
    {
        memset(*envp, 0, strlen(*envp));
        ++envp;
    }
    puts(
        "----------------------------------------------------\n"
        "  Welcome to wil's crappy number storage service!   \n"
        "----------------------------------------------------\n"
        " Commands:                                          \n"
        "    store - store a number into the data storage    \n"
        "    read  - read a number from the data storage     \n"
        "    quit  - exit the program                        \n"
        "----------------------------------------------------\n"
        "   wil has reserved some storage :>                 \n"
        "----------------------------------------------------\n");
    while ( 1 )
    {
        printf("Input command: ");
        number = 1;
        fgets(&input, 20, stdin);
        *((char *)&input + strlen((const char *)&input) - 1) = 0;
        if ( !memcmp(&input, "store", 5) )
            number = store_number(storage);
        else if ( !memcmp(&input, "read", 4) )
            number = read_number(storage);
        else if ( !memcmp(&input, "quit", 4) )
            return 0;
        if ( number )
            printf(" Failed to do %s command\n", (const char *)&input);
        else
            printf(" Completed %s command successfully\n", (const char *)&input);
        *((int *)input) = 0;
        *((int *)input + 1) = 0;
        *((int *)input + 2) = 0;
        *((int *)input + 3) = 0;
        *((int *)input + 4) = 0;
    }
}