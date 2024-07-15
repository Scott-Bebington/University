; This makes your function available to other files
global get_pin

section .data
  prompt db "Enter 4-digit PIN: ", 0
  input_buffer db 0, 0, 0, 0          ; Buffer to store ASCII digits for conversion
  newline db 0x0A                     ; Newline character for printing

section .text
; uint32_t get_pin()
; Reads a 4-digit PIN from stdin and converts it to an integer.
; The PIN returned must be a valid 4-digit (32-bit) integer.

get_pin:
  push rbp
  mov rbp, rsp

; Do not modify anything above this line unless you know what you are doing

; ==========================

  ; Print the prompt message
  mov rdi, 1            ; File descriptor 1 (stdout)
  mov rax, 1            ; System call number for sys_write
  mov rsi, prompt       ; Pointer to the prompt message
  mov rdx, 19           ; Message length
  syscall

  ; Read the PIN as ASCII characters
  mov rdi, 0            ; File descriptor 0 (stdin)
  mov rax, 0            ; System call number for sys_read
  mov rsi, input_buffer ; Pointer to the input buffer
  mov rdx, 4            ; Number of characters to read
  syscall

  ; Convert ASCII digits to integer
  xor rax, rax          ; Clear rax to accumulate the integer
  mov rcx, 10           ; Multiplier for decimal conversion

  movzx rsi, byte [input_buffer + 0] ; Convert ASCII to integer (thousands digit)
  sub rsi, '0'
  imul rax, rcx
  add rax, rsi

  movzx rsi, byte [input_buffer + 1] ; Convert ASCII to integer (hundreds digit)
  sub rsi, '0'
  imul rax, rcx
  add rax, rsi

  movzx rsi, byte [input_buffer + 2] ; Convert ASCII to integer (tens digit)
  sub rsi, '0'
  imul rax, rcx
  add rax, rsi

  movzx rsi, byte [input_buffer + 3] ; Convert ASCII to integer (units digit)
  sub rsi, '0'
  imul rax, rcx
  add rax, rsi


; ==========================

; Do not modify anything below this line unless you know what you are doing

  leave
  ret