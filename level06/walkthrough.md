# Level06

## Reconnaissance

We have three security enabled:
- **RELRO Partial enabled** = GOT (Global Offset Table) placed were we cannot overflow
- **NX enabled** = not every part of the memory are considered as being executable
- **Canary** = Random value added after the return address, if it is modified, the program leave. Prevent overwrite of return address

We analyse the binary and we notice that it asks for a login of 32 char and a Serial which is an `unsigned int`
Then, both are passed to an `auth` function and if `auth` return `false`, we get a shell.

Lets break into `auth` function:
- checks if the login if above 5, otherwise return `True`
- prevent debugging with `ptrace` (try to trace itself, if debugger, there is an error)
- execute several computation based on `login` and check if it is equal to `serial`, if so return `True`

## Exploit

We can just create a program which is gonna recreate the computation, gives us the value at the end and we will just have to use it as `Serial`.

Script located in [Ressources](Ressources/findSerial.py)