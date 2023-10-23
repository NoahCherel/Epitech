[BITS 64]

global strpbrk

section .text

strpbrk:
    xor rcx, rcx        ; reset haystack index to 0
    xor rdx, rdx        ; reset match_found flag to false
.loop:
    mov al, [rdi + rcx] ; get next character from haystack
    cmp al, 0x00        ; check for null terminator
    je .ret_zero        ; if null terminator, return null pointer
    inc rcx             ; increment haystack index
    xor r9, r9          ; reset needle index to 0

.search:
    mov r8b, [rsi + r9] ; get next character from needle
    cmp r8b, 0x00       ; check for null terminator
    je .loop            ; if null terminator, go to next character in haystack
    inc r9              ; increment needle index
    cmp al, r8b         ; compare haystack character to needle character
    jne .search         ; if not equal, go to next character in needle
    mov rdx, 1          ; set match_found flag to true
    jmp .ret            ; return pointer to matched character

.ret_zero:    
    xor rax, rax        ; set return value to null pointer
    ret                 ; return

.ret:
    mov rax, rcx        ; set return value to haystack index
    add rax, rdi        ; add haystack pointer to return value
    sub rax, rdx        ; subtract match_found flag from return value
    ret                 ; return