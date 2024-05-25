level00:level00

RELRO Partial enabled = GOT (Global Offset Table) placed were we cannot overflow
NX enabled = not every part of the memory are considered as being executable

analyse with gdb and we see that the password (read as a decimal) is compared to `0x149c` which is equal to `5276`
Got a shell !