# Level00

## Reconnaissance

We have two security enabled:
- **RELRO Partial enabled** = GOT (Global Offset Table) placed were we cannot overflow
- **NX enabled** = not every part of the memory are considered as being executable

The binary is asking for a password

Lets have a look on gdb:
We notice that a shell is started once the password is correct.
We see that the password (read as a decimal) is compared to `0x149c` which is equal to `5276`

## Exploit

Insert `5276` for the password.

Got a shell !