[BITS 64]

global strncmp

section .text

strncmp:
    xor rax, rax        ; initialize the result to zero
    xor rcx, rcx        ; initialize the loop counter to zero
    cmp rdx, rcx        ; check if the maximum number of characters to compare is zero
    je .exit            ; if it is, exit the loop

.loop:
    mov al, BYTE [rdi + rcx]    ; load the current character from the first string
    mov r10b, BYTE [rsi + rcx]  ; load the current character from the second string
    cmp AL, r10b                ; check if the two characters are equal
    jne .not_equal              ; if they are not equal, exit the loop
    inc rcx                     ; increment the loop counter
    cmp rdx, rcx                ; check if the maximum number of characters to compare has been reached
    jg .loop                    ; if it has not, loop
    jmp .exit                   ; otherwise, exit the loop

.not_equal:
    sub al, r10b        ; subtract the two characters
    movsx rax, al       ; sign-extend the result to 64 bits
    jmp .exit           ; exit the loop

.exit:
    ret                 ; return the result
