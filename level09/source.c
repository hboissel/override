#include <stdio.h>
#include <string.h>

int secret_backdoor()
{
    char s[128]; // [rsp+0h] [rbp-80h] BYREF

    fgets(s, 128, stdin);
    return system(s);
}

char set_msg(char *buffer)
{
  char s[1024]; // [rsp+10h] [rbp-400h] BYREF

  memset(s, 0, sizeof(s));
  puts(">: Msg @Unix-Dude");
  printf(">>: ");
  fgets(s, 1024, stdin);
  return strncpy(buffer, s, *(int *)(buffer + 180));
}

int set_username(char *buffer)
{
    char s[140]; // [rsp+10h] [rbp-90h] BYREF
    int i; // [rsp+9Ch] [rbp-4h]

    memset(s, 0, 128);
    puts(">: Enter your username");
    printf(">>: ");
    fgets(s, 128, stdin);
    for ( i = 0; i <= 40 && s[i]; ++i ) // can write 41 bytes 
        buffer[i + 140] = s[i];
    return printf(">: Welcome, %s", buffer + 140);
}

int handle_msg()
{
    char buffer[140]; // [rsp+0h] [rbp-C0h] BYREF
    char username[40]; // [rsp+8Ch] [rbp-34h]
    int size; // [rsp+B4h] [rbp-Ch]

    *((int *)username) = 0;
    *((int *)username + 1) = 0;
    *((int *)username + 2) = 0;
    *((int *)username + 3) = 0;
    *((int *)username + 4) = 0;
    size = 140;
    set_username(buffer);
    set_msg(buffer);
    return puts(">: Msg sent!");
}

int main(int argc, const char **argv, const char **envp)
{
    puts(
        "--------------------------------------------\n"
        "|   ~Welcome to l33t-m$n ~    buffer337        |\n"
        "--------------------------------------------");
    handle_msg();
    return 0;
}