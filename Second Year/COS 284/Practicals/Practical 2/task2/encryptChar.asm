section .data


section .text
    global encryptChar

    ; Inputs
    ; Matrix = rdi
    ; input char = rsi
    ; key char = rdx

encryptChar:
    
    sub rsi, 'A'
    sub rdx, 'A'
    mov rax, [rdi + rdx * 8]
    mov rax, [rax + rsi]
    ret