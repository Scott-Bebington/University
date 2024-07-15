%include "constants.inc"
section .data
section .bss
    info resb 1
section .text
global simulateDfa
extern strlen

; Input
; rdi = DFA
; rsi = input string

simulateDfa:
    mov r8, rdi                 ; r8 = DFA
    mov r9, rsi                 ; r9 = input string
    push rdi
    mov rdi, rsi
    call strlen                 
    mov r10, rax                ; r10 = length of string
    pop rdi
    
    mov r11, [r8 + 8]           ; r11 = transitions
    mov r12, [r8 + 16]          ; r12 = accepting states
    mov r13, [r8 + 24]          ; r13 = Current State

    mov r14, 0                  ; r14 = index of input string
    mov r15, 0                  ; r15 = transition index


nextTransition:

    ; mov rax, [r9]
    ; mov [info], rax              ; info = first character of input string

    ; call PrintChar               ; Print the first character of the input string

    ; ; First compare to see if the transition state is the same as the current state
    ; cmp [r11 + r15], r13
    ; jne ReturnTrue                ; If they are equal, return true
    ; jmp ReturnFalse              ; If they are not equal, return false
    


    ; mov ax, [info + r14]               ; ax = character of input string
    ; cmp [r11 + Transition.symbol], ax             ; Compare the first character of the input string to the first transition symbol
    ; ; jne ReturnFalse             ; If they are not equal, return false


    mov rax, [r11 + r15]
    ret

ReturnFalse:
    mov rax, 0
    ret

ReturnTrue:
    mov rax, 1
    ret

PrintChar:
    push rax
    ; Print the info.
    mov eax, 4      ; sys_write system call
    mov ebx, 1      ; standard output file descriptor
    mov ecx, info   ; buffer containing the read data
    mov edx, 1     ; number of bytes to print
    int 0x80        ; call kernel
    pop rax

    ret






; simulateDfa:
    
;     ; Get the length and return it in rax
;     mov rdi, rsi
;     call strlen

;     ; If the length is 4, return false
;     cmp rax, 4
;     je ReturnFalse
;     jmp ReturnTrue
;     ret

; ReturnFalse:
;     mov rax, 0
;     ret

; ReturnTrue:
;     mov rax, 1
;     ret

