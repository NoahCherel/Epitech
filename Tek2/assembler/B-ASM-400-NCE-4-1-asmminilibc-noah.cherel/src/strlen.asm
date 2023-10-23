[BITS 64]

global strlen

section .text

strlen:
    xor   rcx, rcx      ; clear out counter

strlen_next:
    cmp   [rdi], byte 0  ; null byte yet?
    jz    strlen_null   ; yes, get out
    inc   rcx            ; char is ok, count it
    inc   rdi            ; move to next char
    jmp   strlen_next   ; process again

strlen_null:
    mov   rax, rcx       ; rcx = the length (put in rax)
    ret

