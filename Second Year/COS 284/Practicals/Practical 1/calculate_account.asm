; This makes your function available to other files
global calculate_account

section .data
; ==========================
; Your data goes here
; ==========================

section .text
; Inputs:
;   rdi - pin
; Outputs:
;   eax - balance
calculate_account:
  push rbp
  mov rbp, rsp

; Do not modify anything above this line unless you know what you are doing
; ==========================

  ; Calculate account number: account = pin + 10000

  mov eax, edi  ; Move the pin value from rdi to eax
  add eax, 10000
  mov edi, eax  ; Move the account value from eax to edi

; ==========================
; Do not modify anything below this line unless you know what you are doing

  leave
  ret