#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/prctl.h>
#include <unistd.h>

int main()
{
  int status;
  char buffer[128]; //[esp+0x20]
  int v6;
  int v7;
  int event;
  int pid;

  pid = fork();
  memset(buffer, 0, sizeof(buffer));
  event = 0;
  status = 0;
  if ( pid )
  {
    do
    {
      wait(&status);
      v6 = status;
      if ( (status & 0x7F) == 0 || (v7 = status, (char)((status & 0x7F) + 1) >> 1 > 0) )
      {
        puts("child is exiting...");
        return 0;
      }
      event = ptrace(3, pid, 44, 0);
    }
    while ( event != 11 );
    puts("no exec() for you");
    kill(pid, 9);
  }
  else
  {
    prctl(1, 1);
    ptrace(0, 0, 0, 0);
    puts("Give me some shellcode, k");
    gets(buffer);
  }
  return 0;
}