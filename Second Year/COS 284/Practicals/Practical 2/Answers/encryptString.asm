section .data
    output resb 500             ; Output string

section .text
    global encryptString
    extern encryptChar
    extern populateMatrix

encryptString:
    mov r8, rsi                 ; r8 = input (OHWHYOHWHYDOWEWAIT)
    mov r9, rdx                 ; r9 = keyword (POTATO)
    mov r10, 0                  ; r10 = 0, check for white spaces
    
    call populateMatrix
    mov rdi, rax

    xor r11, r11                ; Clear r11, White Space Counter
    xor r12, r12                ; Clear r12, Keyword position counter
    xor r13, r13                ; Clear r13, Input String position counter

    EncryptLoop:

        ; Check to see if the end of the string has been reached
        movzx rax, byte [r8 + r13]  ; bl = input string char
        cmp rax, 0                  ; if bl == 0
        je EndEncryption            ; If rax = 0, jump to EndEncryption
        xor rax, rax

        ; Check to see if the end of the keyword has been reached
        movzx rax, byte [r9 + r12]  ; bl = keyword char
        cmp rax, 0                  ; if bl == 0
        je ResetKeyword             ; If rax = 0, jump to ResetKeyword
        xor rax, rax

        ; Check to see if the character is a white space
        movzx rax, byte [r8 + r13]  ; bl = input string char
        cmp rax, 32                 ; if bl == 32
        je WhiteSpaceCheck          ; If rax = 32, jump to WhiteSpaceCheck
        xor rax, rax

        ; Load the character from the input string and keyword into rsi and rdx
        movzx rsi, byte [r8 + r13] ; Load the byte (character) from r8 (Input String) into rsi
        movzx rdx, byte [r9 + r12] ; Load the byte (character) from r9 (Keyword) into rdx

        call encryptChar
        mov [output + r13 + r11], rax

        inc r13                    ; Increment r13
        inc r12                    ; Increment r12

        jmp EncryptLoop


    WhiteSpaceCheck:
        dec r11
        inc r13
        jmp EncryptLoop
        
    
    ResetKeyword:
        xor r12, r12
        jmp EncryptLoop

        
    EndEncryption:
        mov byte [output + r13 + r11], 0
        mov rax, output

        ret       
    
