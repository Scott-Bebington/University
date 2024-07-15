global testing

section .data

    alphabet db "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    newline db 10                  ; ASCII value for newline character

section .text
; encryptChar(matrix, input, key)
; 
; Inputs:
;   rdi - matrix
;   rsi - input (char1)
;   rdx - key (char2)

testing:

    ; ; Output the alphabet
    ; mov rdi, 1                  ; File descriptor 1 (stdout)
    ; mov rax, 1                  ; System call number for sys_write
    ; mov rsi, alphabet              ; Pointer to the message
    ; mov rdx, 26                  ; Message length
    ; syscall

    ret
