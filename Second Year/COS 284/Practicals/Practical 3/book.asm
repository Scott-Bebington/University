section .data
    c dq 0                           ; Pointer to the current book
    tempBook dq 0                       ; Pointer to the temporary book

section .bss
    struc Book
        .isbn: resb 13                  ; 13 bytes for the ISBN:    No alignment needed
        .title: resb 50                 ; 50 bytes for the title:   No alignment needed
        align 4                         ; Align the next field to a 4 byte boundary for price
        .price: resd 1                  ; 4 bytes for the price:    Needs to start at an address divisible by 4
        .quantity: resd 1               ; 4 bytes for the quantity: Needs to start at an address divisible by 4
    endstruc
    
    BookPrice dd 0.0                        ; Price of the book
    BookQuantity dd 0                       ; Quantity of the book

section .text
    global allocateBook
    extern malloc
    extern strcpy

allocateBook:
    ; Parameters:
    ;   rdi - ISBN (char*)
    ;   rsi - Name (char*)
    ;   xmmo - Price (int)
    ;   edx - Quantity (int)

    ;=============================================
    push rdi
    push rsi
    push rdx

    movss [BookPrice], xmm0
    mov [BookQuantity], edx
    mov r8, rsi
    mov rdi, Book_size
    call malloc
    mov [c], rax

    pop rdx
    pop rdi
    pop rsi
    
    push rsi

    lea rsi, [rdi]                  
    lea rdi, [rax + Book.title]
    call strcpy
    mov rax, [c]

    pop rsi

    lea rdi, [rax + Book.isbn]
    call strcpy
    mov rax, [c]
    
    ; Assigning the price
    movss xmm0, dword [BookPrice]
    movss [rax + Book.price], xmm0

    ; Assigning the quantity
    mov ecx, [BookQuantity]
    mov [rax + Book.quantity], ecx
    ;=============================================

    ret