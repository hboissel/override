#include <stdio.h>
#include <unistd.h>

char user_name[0x100];

int verify_user_name()
{
    puts("verifying username....\n");
    return strncmp(user_name, "dat_wil", 7);
}

int verify_user_pass(char *password)
{
    return strncmp(password, "admin", 5);
}

int main(int argc, char **argv)
{
    int x; // [esp+0x5c] [esp+0x60]
    char buffer1[64]; // [esp+0x1c] [ebp-0x5b] 0xffffd5dc
    char buffer[28]; // [esp+0x00] [ebp-0x1b]

    memset(buffer1, 0x0, 64);
    x = 0;
    puts("********* ADMIN LOGIN PROMPT *********");
    printf("Enter Username: ");
    fgets(user_name, 0x100, STDIN_FILENO);
    x = verify_user_name();
    if (x != 0)
    {
        puts("nope, incorrect username...\n");
        return 1;
    }
    else
    {
        puts("Enter Password: ");
        fgets(buffer1, 0x64, STDIN_FILENO); // 0x64 = 100
        x = verify_user_pass(buffer1);
        if (x != 0)
        {
            if (x != 0)
            {
                puts("nope, incorrect password...\n");
                return 1;
            }
            else {
                return 0;
            }
        }
        else {
            puts("nope, incorrect password...\n");
            return 1;
        }
    }
}