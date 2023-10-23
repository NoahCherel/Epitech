[BITS 64]

global strrchr

section .text
strrchr:
    push rbp
    mov rbp, rsp
    test rdi, rdi ; check for null pointer
    jz end
    xor rax, rax ; initialize rax to 0
    mov rbx, rax ; initialize rbx to 0

loop:
    movzx edx, byte [rdi] ; load the current character into edx
    cmp dl, sil ; check if current character is equal to character given in parameter
    je found ; move to found if equal
    cmp dl, 0 ; test end of string
    je end ; go to end
    inc rdi ; move to next character of the string
    jmp loop ; loop

found:
    mov rbx, rdi ; set last found position
    inc rdi ; move to next character of the string
    cmp byte [rdi], 0 ; test end of string
    jne loop ; loop if not at end of string

end:
    mov rax, rbx ; set function return to last found position
    mov rsp, rbp
    pop rbp
    ret
