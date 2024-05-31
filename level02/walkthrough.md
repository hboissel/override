# Level02

## Reconnaissance

No security enabled.

ELF 64 bits
Arguments for functions:
1. rdi
2. rsi
3. rdx
4. rcx

Some interresting stuff with `strings`:
```shell
level02@OverRide:~$ strings level02 
...
/home/users/level03/.pass
ERROR: failed to open password file
ERROR: failed to read password file
===== [ Secure Access System v1.0 ] =====
/***************************************\
| You must login to access this system. |
\**************************************/
--[ Username: 
--[ Password: 
*****************************************
Greetings, %s!
/bin/sh
 does not have access!
...
```
Lets have a look with gdb:
We find a `printf` with a format string that we control, the username we insert.
The `.pass` file is loaded at the beginning of the execution, we can print the stack and get the pass.

## Exploit

`rbp-0xa0`
where pass is stored: `0x7fffffffe430`

I tryed to put as `password` the address where the `.pass` is supposed to be and then in the format string
reading the string from the address stored in `password` with `%8$s` but for some reasons, it is not working.

So I decided to just print the stack with `%p` multiple times in the format string and then convert it to string 
with a python script.

