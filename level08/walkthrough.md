# Level08

## Reconnaissance

We have two security enabled:
- **RELRO Full enabled** = GOT (Global Offset Table) set as read only
- **Canary** = Random value added after the return address, if it is modified, the program leave. Prevent overwrite of return address

## Exploit