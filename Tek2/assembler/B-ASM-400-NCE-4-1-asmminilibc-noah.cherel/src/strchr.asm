[BITS 64]

global strchr

section .text

strchr:
    xor rax, rax

loop:
    cmp byte [rdi], sil ; check if current character is equal to character given in parameter
    je found            ; go to found
    cmp byte [rdi], 0   ; test end of string
    je null            ; go to end
    inc rdi             ; increment pointer
    jne loop            ; loop

found:
    mov rax, rdi        ; set function return
    jmp end

end:
    ret

null:                   ; change following follow up
	mov	rax, 0
	ret
