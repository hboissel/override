#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int auth(char *login, unsigned int serial)
{
    char buffer1[40];
    int len; // ebp-0xc
    int result; // ebp-0x10
    int i; // ebp-0x14

    *(strcspn(login, "\n") + login) = 0;
    len = strnlen(login, 32);
    if ( len <= 5 )
        return 1;
    if ( (unsigned int)ptrace(0, 0, 1, 0) == -1 ) // prevent debugging
    {
        puts("\x1B[32m.---------------------------.");
        puts("\x1B[31m| !! TAMPERING DETECTED !!  |");
        puts("\x1B[32m'---------------------------'");
        return 1;
    }
    result = (*(login + 3) ^ 4919) + 6221293;
    for ( i = 0; i < len; ++i )
    {
      if ( login[i] <= 31 ) // check if non printable char
        return 1;
      result += (result ^ (unsigned int)login[i]) % 1337;
    }
    return serial != result;
}

int main()
{
    char buffer2[28]; // esp+0x0
    char buffer1[12]; // esp+0x1c <- ebp+0xc
    unsigned int serial; // esp+0x28
    char login[32]; // esp+0x2c
    unsigned int x; // esp+0x4c <- gs:0x14

    x = __readgsdword('\x14');
    puts("***********************************");
    puts("*\t\tlevel06\t\t  *");
    puts("***********************************");
    printf("-> Enter Login: ");
    fgets(login, 32, stdin);
    puts("***********************************");
    puts("***** NEW ACCOUNT DETECTED ********");
    puts("***********************************");
    printf("-> Enter Serial: ");
    __isoc99_scanf("%u", &serial);
    if ( auth(login, serial) )
        return 1;
    puts("Authenticated!");
    system("/bin/sh");
    return 0;
}