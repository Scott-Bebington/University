extern encryptChar
extern populateMatrix
global encryptString

section .data
section .bss
    outputString resb 500
    spaces resb 1
section .text
; char encryptString(char*, char, char*)

encryptString:
    ; Parameters: rdi = matrix, rsi = input string, rdx = keyword
    mov r12, 0                                      ; r12 = spaces
    mov r8, rsi                                     ; r8 = input string
    xor rcx, rcx                                    ; rcx = input string index
    xor r9, r9                                      ; r9 = keyword index
    mov r10, rdx                                    ; r10 = keyword
    messageLoop:
        
        mov byte bl, [r8 + rcx]                     ; bl = input string char
        cmp rbx, 0                                  ; if bl == 0
        je endMessageLoop                           ; return outputString

        cmp rbx, 32                                 ; if bl == ' '
        je space                                    ; increment spaces

        mov rsi, rbx                                ; rsi = input string char
        xor rdx, rdx                                ; rdx = 0
        mov byte dl, [r10 + r9]                     ; dl = keyword char
        call encryptChar                            ; encryptChar(input string char, keyword char)
        mov [outputString + rcx + r12], rax         ; outputString[input string index - spaces] = encrypted char
        inc rcx                                     ; increment input string index
        inc r9                                      ; increment keyword index
        mov byte bl, [r10 + r9]                     ; bl = keyword char
        cmp rbx, 0                                  ; if bl == 0
        je resetR9                                  ; reset keyword index
        jmp messageLoop                             ; continue
    space:
        dec r12
        inc rcx
        jmp messageLoop
    resetR9:
        xor r9, r9
        jmp messageLoop
    endMessageLoop:
        mov byte [outputString + rcx + r12], 0
        mov rax, outputString
        ret