[BITS 64]

global strcspn

section .text

strcspn:
    xor rax, rax     ; Clear result register
    mov rcx, rdi     ; Save pointer to first string
    mov rdx, rsi     ; Save pointer to second string
    xor r8, r8       ; Initialize inner loop counter to zero
.loop:
    movzx eax, byte [rcx]  ; Load next character from first argument
    test al, al            ; Test if character is zero
    jz .zend               ; If character is zero, jump to end
    movzx r8d, byte [rdx]  ; Load next character from second argument
    test r8d, r8d          ; Test if character is zero
    jz .loop               ; If character is zero, continue searching
    cmp al, r8b            ; Compare characters
    je .zend               ; If characters are equal, jump to end
    inc rcx                ; Increment pointer to first string
    jmp .loop              ; Continue searching
.zend:
    sub rcx, rdi           ; Subtract start of first string from current position to get length
    mov rax, rcx           ; Move result to return register
    ret                    ; Return from function
