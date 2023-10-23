[BITS 64]

global strcasecmp

section .text

strcasecmp:
    xor rax, rax
    xor rcx, rcx
    jmp .loop

.loop:
    mov r8b, byte [rsi + rcx]
    mov r9b, byte [rdi + rcx]
    cmp r8b, 0
    je .end
    cmp r9b, 0
    je .end

    cmp r8b, 'A'
    jb .end
    cmp r8b, 'z'
    ja .end
    cmp r8b, 'Z'
    jbe .comparaison
    cmp r8b, 'a'
    jae .comparaison
    jmp .end

.comparaison:
    or r8b, 32
    or r9b, 32
    cmp r8b, r9b
    jne .end
    inc rcx
    jmp .loop

.end:
    sub r9b, r8b
    movsx rax, r9b
    ret