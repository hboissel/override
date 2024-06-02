#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, const char **argv, const char **envp)
{
    FILE *buffer_log; // [rsp+28h] [rbp-88h]
    FILE *fd_file; // [rsp+30h] [rbp-80h]
    int fd_backup; // [rsp+38h] [rbp-78h]
    char buf; // [rsp+3Fh] [rbp-71h] BYREF
    char dest[104]; // [rsp+40h] [rbp-70h] BYREF
    unsigned long int v9; // [rsp+A8h] [rbp-8h]

    v9 = __readfsqword(0x28u);
    buf = -1;
    if ( argc != 2 )
        printf("Usage: %s filename\n", *argv);
    buffer_log = fopen("./backups/.log", "w");
    if ( !buffer_log )
    {
        printf("ERROR: Failed to open %s\n", "./backups/.log");
        exit(1);
    }
    log_wrapper(buffer_log, "Starting back up: ", argv[1]);
    fd_file = fopen(argv[1], "r");
    if ( !fd_file )
    {
        printf("ERROR: Failed to open %s\n", argv[1]);
        exit(1);
    }
    strcpy(dest, "./backups/");
    strncat(dest, argv[1], 99 - strlen(dest));
    fd_backup = open(dest, O_WRONLY | O_EXCL | O_CREAT, 0660);
    if ( fd_backup < 0 )
    {
        printf("ERROR: Failed to open %s%s\n", "./backups/", argv[1]);
        exit(1);
    }
    while ( 1 )
    {
        buf = fgetc(fd_file);
        if ( buf == -1 )
            break;
        write(fd_backup, &buf, 1);
    }
    log_wrapper(buffer_log, "Finished back up ", argv[1]);
    fclose(fd_file);
    close(fd_backup);
    return 0;
}