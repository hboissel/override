int main(int argc, char **argv) 
{
    int nb;
    char buffer[28];

    // puts 35 *
    puts("***********************************");
    puts("* \t     -Level00 -\t\t  *");
    puts("***********************************");
    printf("Password:");
    scanf("%d", &nb);
    // 0x149c = 5276
    if (nb == 5276) 
    {
        puts("\nAuthenticated!");
        system("/bin/sh");
    } 
    else 
    {
        puts("\nInvalid Password!");
    }
    return 0;
}