[BITS 64]

section .text
    global memmove

memmove:
    mov rax, rdi
    cmp rdi, rsi
    je finish
    jb overlap
    mov rcx, rsi
    add rcx, rdx
    cmp rdi, rcx
    jae notOverlap
overlap:
    std
    mov rcx, rdx
    sub rdx, 1
    lea rsi, [rsi + rdx]
    add rdi, rdx
    rep movsb
    cld
    jmp finish
notOverlap:
    mov rcx, rdx
    rep movsb
finish:
    ret