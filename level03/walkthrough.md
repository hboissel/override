# Level03

## Reconnaissance

We have two security enabled:
- **RELRO Partial enabled** = GOT (Global Offset Table) placed were we cannot overflow
- **NX enabled** = not every part of the memory are considered as being executable
- **Canary** = Random value added after the return address, if it is modified, the program leave. Prevent overwrite of return address

With gdb, we find:
`322424845` - `input` and if the result is between 1 and 21, a function `decrypt` will be call with the result as argument
otherwise, a random value while calling the `decrypt` function.
Then, the `decrypt` function will open a shell if ```Q}|u`sfg~sf{}|a3``` xor on each char with the result is equal to `Congratulations!`

## Exploit

Since the exploit might not involve random, we will try the input value which give a result from `1` to `21`
and `322424827` works. We get a shell.