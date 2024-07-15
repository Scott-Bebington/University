; This tells the function that these exist outside of this file
extern greeting
extern get_pin
extern obscure_pin
extern calculate_balance
extern calculate_account

; This makes your function available to other files
global create_account

section .data
; ==========================
; Your data goes here
  acc_ptr dq 0
  pin_ptr dq 0
  bal_ptr dq 0
  acc_num_val dd 0
  pin_val dd 0

  Acc_Num_Msg db "Your account number is:", 0x0A
  Bal_Msg db "Your balance is:", 0x0A
  Pin_Msg db "Your obscured PIN is:", 0x0A

  newline db 10                  ; ASCII value for newline character
; ==========================

section .text
; void create_account(char *account_number, char *obscured_pin, char *balance)
; 
; Inputs:
;   rdi - account number
;   rsi - pin
;   rdx - balance
; 
; README:
; A lot has been given to start you off. You should be able to complete this without fully understanding how
; the functions work. I recommend using the foundation provided, however, you are free to change it as you see fit.


create_account:
  push rbp
  mov rbp, rsp
  sub rsp, 32

  mov qword [acc_ptr], rdi
  mov qword [pin_ptr], rsi
  mov qword [bal_ptr], rdx


  ; Greet the user (Diplomacy)
  call greeting

  ; Get the pin as a 32 bit integer
  call get_pin ; Call get_pin function
  mov [pin_val], eax  ; save pin

  ; Calculate the account number
  mov edi, eax
  call calculate_account
  mov [acc_num_val], eax  ; save account number
  
  ; Convert the account number to ASCII and store it in the account number pointer
  mov eax, [acc_num_val]
  mov rsi, [acc_ptr]
  mov rbx, 10
  mov rcx, 5

  .account_loop:
    xor rdx, rdx
    idiv rbx
    add dl, 48
    mov [rsi + 4], dl
    dec rsi
    test rax, rax
    loop .account_loop

  ; Output account message
  mov rdi, 1                  ; File descriptor 1 (stdout)
  mov rax, 1                  ; System call number for sys_write
  mov rsi, Acc_Num_Msg        ; Pointer to the message
  mov rdx, 24                 ; Message length (including newline)
  syscall

  ; Output account number
  mov rdi, 1                  ; File descriptor 1 (stdout)
  mov rax, 1                  ; System call number for sys_write
  mov rsi, [acc_ptr]          ; Pointer to the balance
  mov rdx, 6                  ; Message length (including newline)
  syscall

  ; Output a new line
  mov rax, 1                  ; System call number for sys_write
  mov rdi, 1                  ; File descriptor 1 (stdout)
  mov rsi, newline            ; Pointer to the newline character
  mov rdx, 1                  ; Message length (1 byte for newline)
  syscall

  ; Calculate the balance
  mov edi, eax  ; set account number as the first argument to calculate balance
  mov esi, [pin_val]  ; set pin as the second argument to calculate balance
  call calculate_balance

  ; Convert the balance to ASCII and store it in the balance pointer
  mov rsi, [bal_ptr]
  mov rbx, 10
  mov rcx, 5

  .balance_loop:
    xor rdx, rdx
    idiv rbx
    add dl, 48
    mov [rsi + 4], dl
    dec rsi
    test rax, rax
    loop .balance_loop


  ; Output balance message
  mov rdi, 1                  ; File descriptor 1 (stdout)
  mov rax, 1                  ; System call number for sys_write
  mov rsi, Bal_Msg            ; Pointer to the message
  mov rdx, 17                 ; Message length (including newline)
  syscall

  ; Output balance
  mov rdi, 1                  ; File descriptor 1 (stdout)
  mov rax, 1                  ; System call number for sys_write
  mov rsi, [bal_ptr]          ; Pointer to the balance
  mov rdx, 5                  ; Message length (including newline)
  syscall

  ; Output a new line
  mov rax, 1                  ; System call number for sys_write
  mov rdi, 1                  ; File descriptor 1 (stdout)
  mov rsi, newline            ; Pointer to the newline character
  mov rdx, 1                  ; Message length (1 byte for newline)
  syscall


  ; Convert the PIN to ASCII and store it in the PIN pointer
  mov eax, [pin_val]
  mov rsi, [pin_ptr]
  mov rbx, 10
  mov rcx, 4

  .pin_loop:
    xor rdx, rdx
    idiv rbx
    add dl, 48
    mov [rsi + 3], dl
    dec rsi
    test rax, rax
    loop .pin_loop

  mov rdi, [pin_ptr]

  ; Obsfucate the pin
  call obscure_pin

  ; Output pin message
  mov rdi, 1                  ; File descriptor 1 (stdout)
  mov rax, 1                  ; System call number for sys_write
  mov rsi, Pin_Msg            ; Pointer to the message
  mov rdx, 22                 ; Message length (including newline)
  syscall

  ; Output obscured pin
  mov rdi, 1                  ; File descriptor 1 (stdout)
  mov rax, 1                  ; System call number for sys_write
  mov rsi, [pin_ptr]        ; Pointer to the balance
  mov rdx, 6                  ; Message length (including newline)
  syscall

  ; Output a new line
  mov rax, 1                  ; System call number for sys_write
  mov rdi, 1                  ; File descriptor 1 (stdout)
  mov rsi, newline            ; Pointer to the newline character
  mov rdx, 1                  ; Message length (1 byte for newline)
  syscall

  leave
  ret




