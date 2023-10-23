[BITS 64]
global memcpy
section .text

memcpy:
    mov rax, rdi
    xor rcx, rcx
    jmp .loop

.loop:
    cmp rcx, rdx
    je .end
    mov r8b, byte [rsi + rcx]
    mov byte [rdi + rcx], r8b
    inc rcx
    jmp .loop

.end:
    ret