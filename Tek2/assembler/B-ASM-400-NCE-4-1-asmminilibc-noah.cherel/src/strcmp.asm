[BITS 64]

global strcmp

section .text

strcmp:
    xor rdx, rdx ; initialize the result to zero
    xor r10, r10 ; initialize the counter to zero
.loop:
    mov al, BYTE [rdi + rdx] ; load the current character from the first string
    mov r10b, BYTE [rsi + rdx] ; load the current character from the second string
    cmp rax, 0 ; check if the current character of the first string is the null terminator
    je .exit ; if it is, exit the loop
    cmp r10, 0 ; check if the current character of the second string is the null terminator
    je .exit ; if it is, exit the loop
    cmp AL, r10b ; check if the two characters are equal
    je .continue ; if they are equal, continue the loop
.exit:
    sub al, r10b ; subtract the two characters
    movsx rax, al
    ret
.continue:
    inc rdx ; increment the counter
    jmp .loop ; continue the loop