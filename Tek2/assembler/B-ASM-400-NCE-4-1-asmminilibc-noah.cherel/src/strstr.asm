global strstr

section .text

strstr:
    push rbx
    push rbp

    mov rbp, rsp
    mov rbx, rdi ; pointer to X
    mov rdi, rsi ; pointer to Y

.loop:
    cmp byte [rdi], 0
    je .found

    cmp byte [rbx], 0
    je .not_found

    mov rcx, rdi
    mov rsi, rbx
.inner_loop:
    mov al, [rcx]
    cmp al, 0
    je .not_found

    cmp al, [rsi]
    jne .outer_loop

    inc rcx
    inc rsi
    cmp byte [rcx], 0
    je .found

    jmp .inner_loop

.outer_loop:
    inc rbx

    cmp byte [rbx], 0
    je .not_found

    jmp .loop

.not_found:
    mov rbx, [rsp]
    mov rsp, rbp
    pop rbp
    pop rbx
    xor rax, rax
    ret

.found:
    lea rax, [rbx]
    mov rbx, [rsp]
    mov rsp, rbp
    pop rbp
    pop rbx
    ret
