[BITS 64]

global memset

section .text

memset:
    xor rcx, rcx    ; rcx = 0
    mov rax, rdi    ; rax = rdi

loop:
    cmp rcx, rdx    ; if (rcx >= rdx) goto end_loop
    jge end_loop
    mov Byte [rax + rcx], sil
    inc rcx         ; rcx++
    jmp loop        ; goto loop

end_loop:
    ret