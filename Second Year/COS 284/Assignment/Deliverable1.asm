section .data
    fd: dd 0
    fileName db "dfa1.txt"

section .bss
    info resb 1
    tempData resb 1
  
section .text
    extern initDfa 
    global readDfa

readDfa:

    ; Open the file for reading.
    mov eax, 5 ; sys_open system call
    mov rbx, rdi ; file name
    mov ecx, 0 ; read only access
    mov edx, 0777 ; permissions (read, write, and execute for all)
    int 0x80 ; call kernel
    
    mov [fd], eax

    call ReadChar
    mov rdi, [info]
    sub rdi, '0'

    call ReadChar
    call ReadChar
    mov rsi, [info]
    sub rsi, '0'

    push rdi
    call initDfa
    pop rdi

    call ReadChar

read_loop:
    ; Set the states and the transitions and a counter
    mov rdi, [rax]              ; rdi = states
    mov rsi, [rax + 8]          ; rsi = transitions
    xor r8, r8                  ; r8 = 0

    call ReadStatesIDs
    xor r8, r8

    call ReadAcceptingStates
    xor r8, r8
    
    call ReadTransitions
    call ReadTransitions
    call ReadTransitions
    call ReadTransitions
    call ReadTransitions
    call ReadTransitions

    mov r9, [rax + 20]
    cmp r9, 8
    je ReadExtraTransitions

    ; call ReadFileName

    ret

ReadStatesIDs:

    call ReadChar
    ; Move Info into a register so that it can be tuned into a number
    mov rbx, [info]
    sub rbx, '0'
    mov [rdi + r8], rbx
    add r8, 8

    call ReadChar               ; Reading ","

    ; Compare the value stored in info to a newline character
    cmp byte [info], 10
    je EndReadStatesIDs
    jmp ReadStatesIDs

    EndReadStatesIDs:
        ret

ReadAcceptingStates:
    ; First Accepting State
    call ReadChar

    CheckNextState:
        ; Move Info into a register so that it can be tuned into a number
        mov rbx, [info]         ; rbx = 0
        sub rbx, '0'
        ; Compare the ID of the First State to the ID of the Accepting State
        mov r9, [rdi + r8]
        cmp r9, rbx
        je AcceptState

    ; Moved to the next state and try again
    add r8, 8
    jmp CheckNextState
    
    AcceptState:
        mov byte [rdi + r8 + 4], 1
        add r8, 8

        call ReadChar               ; Reading ","
        ; Compare the value stored in info to a newline character
        cmp byte [info], 10
        je EndReadAcceptingStates
        jmp ReadAcceptingStates

        ret

    EndReadAcceptingStates:
            ret

ReadTransitions:
    call ReadChar       ; Starting State ID

    ; Move Info into a register so that it can be tuned into a number
    mov rbx, [info]         
    sub rbx, '0'
    mov [rsi + r8], rbx

    call ReadChar       ; Reads ","
    ; call PrintChar
    call ReadChar       ; Ending State ID
    ; call PrintChar

    ; Move Info into a register so that it can be tuned into a number
    mov rbx, [info]         
    sub rbx, '0'
    mov [rsi + r8 + 4], rbx

    call ReadChar       ; Reads ","
    call ReadChar       ; Transition char

    ; Move Info into a register so that it can be assigned
    push ax
    mov ax, [info]         
    mov [rsi + r8 + 8], ax
    pop ax

    call ReadChar

    ; Move to next Transition
    add r8, 12

    EndReadTransitions:
        ret
    
    ReadExtraTransitions:
        call ReadTransitions
        call ReadTransitions

ReadChar:
    push rax
    mov eax, 3 ; sys_read system call
    mov ebx, [fd] ; file descriptor is in the rax register
    mov ecx, info ; buffer to store the read data
    mov edx, 1 ; number of bytes to read
    int 0x80 ; call kernel
    pop rax

    ; cmp byte [info], 10
    ; je end_of_file

    ret