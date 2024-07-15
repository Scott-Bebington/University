global obscure_pin

section .data
; ==========================
; Your data goes here
; ==========================

; void obscure_pin(char* pin)
; Obscures a 4-digit ASCII PIN in place.
; Assumes pin is in rdi.
section .text
obscure_pin:
  push rbp
  mov rbp, rsp

; Do not modify anything above this line unless you know what you are doing
; ==========================

  ; Load PIN digits and obscure them
  mov rsi, rdi            ; move value stored in rdi to rsi
  mov ecx, 4              ; specify how many times the loop must run

  ; Run loop
  xor_loop:
    mov al, byte [rsi]    ; Load the current digit into AL
    sub al, 48            ; Convert ASCII digit to numerical value
    xor al, 0xF           ; XOR operation to obscure the digit
    add al, 48            ; Convert back to ASCII representation
    mov byte [rsi], al    ; Store the obscured digit back

    inc rsi               ; Move to the next digit
    loop xor_loop         ; Loop for all 4 digits

  ;mov rsi, rdi            ; Reset rsi to point to the start of the PIN

  ; Reverse the order of the digits
  mov al, byte [rdi]       ; Load the first digit
  mov ah, byte [rdi + 1]   ; Load the second digit
  mov dl, byte [rdi + 2]   ; Load the third digit
  mov cl, byte [rdi + 3]   ; Load the last digit

  mov byte [rdi], cl       ; Store the last digit at the beginning
  mov byte [rdi + 1], dl   ; Store the third digit after the second
  mov byte [rdi + 2], ah   ; Store the second digit after the third
  mov byte [rdi + 3], al   ; Store the first digit at the end


  ; Reverse the order of the digits
  ;mov rsi, rdi            ; Reset rsi to point to the start of the PIN
  ;mov al, byte [rsi]      ; Load the first digit
  ;mov ah, byte [rsi + 3]  ; Load the last digit
  ;mov byte [rsi], ah      ; Store the last digit at the beginning
  ;mov byte [rsi + 3], al  ; Store the first digit at the end

  ;inc rsi                 ; Move to the second digit
 ; mov al, byte [rsi]      ; Load the second digit
  ;mov ah, byte [rsi + 1]  ; Load the third digit
  ;mov byte [rsi], ah      ; Store the third digit after the second
  ;mov byte [rsi + 1], al  ; Store the second digit after the third

; ==========================
; Do not modify anything below this line unless you know what you are doing

  leave
  ret