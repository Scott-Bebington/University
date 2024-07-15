; This makes your function available to other files
global greeting

section .data
  greeting_message db "Welcome to the Bank of <<Redacted>>", 0x0A ; 0x0A is the newline character

section .text
; void greeting()
; This function prints a greeting to the screen
greeting:
  push rbp
  mov rbp, rsp

; Do not modify anything above this line unless you know what you are doing

  ; Output the greeting message to the console
  mov rdi, 1                  ; File descriptor 1 (stdout)
  mov rax, 1                  ; System call number for sys_write
  mov rsi, greeting_message   ; Pointer to the message
  mov rdx, 36                 ; Message length
  syscall

; Do not modify anything below this line unless you know what you are doing

  leave
  ret