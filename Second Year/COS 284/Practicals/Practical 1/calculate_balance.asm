; This makes your function available to other files
global calculate_balance

section .data
; ==========================
  B_result dw 0        ; Placeholder for B = 0
; ==========================

section .text
; Calculate balance based on account number and pin
; Inputs:
;   rdi - account number
;   rsi - pin
; Outputs:
;   rax - balance
calculate_balance:
  push rbp
  mov rbp, rsp

; Do not modify anything above this line unless you know what you are doing
; ==========================

  ; Add A and P
  mov rax, rdi    ; rax = account number (A)
  add rax, rsi    ; rax = A + P

  ; Multiply by P
  imul rax, rsi   ; rax = (A + P) * P

  ; xor P and A
  xor rdx, rdi    ; rdx = P ^ A

  ; Calculate the final result
  and rax, rdx    ; rax = (A + P) * P & (P ^ A)

  mov [B_result], rax ; Store the result in B_result

  ; Mod B_result by 50000 then add 50000
  mov rax, [B_result]
  add rax, 50000

; ==========================
; Do not modify anything below this line unless you know what you are doing

  leave
  ret
