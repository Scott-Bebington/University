global initialiseLibrary
global addBook
global searchBookByISBN
extern malloc
extern strcpy
extern strcmp
; extern searchBookByISBN

section .data
    error_message db "Error: malloc failed", 10
    Book_Exists db "Error: Book already exists", 10
    Book_Doesnt_Exist db "Error: Book doesn't exist", 10
    null_terminator dd 0

    struc Library
        .books: resb Book_size * 5      ; 5 books : Needs aligning to 8 bytes
        .count: resd 1                  ; 1 count : Needs aligning to 8 bytes for the next pointer or next library
        align 8
    endstruc

    struc Book
        .isbn: resb 13                  ; 13 bytes for the ISBN:    No alignment needed
        .title: resb 50                 ; 50 bytes for the title:   No alignment needed
        align 4                         ; Align the next field to a 4 byte boundary for price
        .price: resd 1                  ; 4 bytes for the price:    Needs to start at an address divisible by 4
        .quantity: resd 1               ; 4 bytes for the quantity: Needs to start at an address divisible by 4
    endstruc

    libPointer dq 0

section .text

initialiseLibrary:

    push rdi
    push rsi
    push rdx

    mov rdi, Library_size
    call malloc

    pop rdx
    pop rsi
    pop rdi

    mov [rax + Library.count], dword 0

    ret

addBook:
    ; Params
    ; rdi = library (Pointer to the library)
    ; rsi = book (Pointer to the book)

    
    ; call searchBookByISBN
    ; cmp rax, 0
    ; je AddNewBook
    ; jmp BookExists
    ; ret
    
    ; ==============================================
    ; Check to see if the max books has been reached
    ; ==============================================

    mov r8, [rdi + Library.count]                       ; Book count
    cmp r8, 5
    jge TooManyBooks                                    ; Jump to TooManyBooks if the count >= 5
    jmp AddNewBook                                      ; Jump to searchBookByISBN if count < 5
    ret

BookExists:

    ; ==============================
    ; Adding quantity if book Exists
    ; ==============================

    mov r9, [rsi + Book.quantity]               ; Get the quantity from the book
    mov r10, [rax + Book.quantity]              ; Get the quantity from the library
    add r9, r10                                 ; Add the quantity from the book to the quantity in the library
    mov [rax + Book.quantity], r9               ; Store the quantity back in the library
    mov rax, 1                                  ; Return 1 if quantity added
    ret
    
AddNewBook:

    ; ==========================
    ; Adding book to the library
    ; ==========================

    mov r9, [rsi + Book.isbn]                       ; Get the ISBN from the book
    mov r10, [rsi + Book.title]                     ; Get the title from the book
    mov r11, [rsi + Book.price]                     ; Get the price from the book
    mov r12, [rsi + Book.quantity]                  ; Get the quantity from the book

    mov r13, Book_size                              ; Get the size of the book
    imul r13, r8                                    ; Multiply the size of the book by the count of books in the library
    mov [rdi + Book.price + r13], r11               ; Store the price in the library
    mov [rdi + Book.quantity + r13], r12            ; Store the quantity in the library

    xor r15, r15                                    ; ISBN loop counter
    xor r9, r9                                      ; Title loop counter
    ISBNLoop:
        xor rax, rax                                ; Clear rax
        movzx rax, byte [rsi + Book.isbn + r15]     ; rax = Title string char
        cmp rax, 0                                  ; if rax == 0
        je resetBookSize

        mov [rdi + Book.isbn + r13], rax            ; Store the title in the library
        inc r15                                     ; Increment the title loop counter
        inc r13                                     ; Increment the library loop counter
        jmp ISBNLoop                                ; Jump back to TitleLoop

    resetBookSize:
    mov r13, Book_size                              ; Get the size of the book
    imul r13, r8                                    ; Multiply the size of the book by the count of books in the library

    TitleLoop:
        xor rax, rax                                ; Clear rax
        movzx rax, byte [rsi + Book.title + r9]     ; rax = Title string char
        cmp rax, 0                                  ; if rax == 0
        je IncrementCount

        mov [rdi + Book.title + r13], rax           ; Store the title in the library
        inc r9                                      ; Increment the title loop counter
        inc r13                                     ; Increment the library loop counter
        jmp TitleLoop                               ; Jump back to TitleLoop


searchBookByISBN:
    ; Params
    ; rdi = library (Pointer to the library)
    ; rsi = isbn (Pointer to the ISBN string)

    xor rax, rax                        ; Clear rax (used for return value)
    mov r8, [rdi + Library.count]       ; Get the book count
    mov r9, rsi                         ; r9 = Pointer to the ISBN to search for

    ; Loop to check each book's ISBN
    xor rcx, rcx                        ; Clear rcx (used as a loop counter)
    mov r10, rdi                        ; r10 = Pointer to the library's first book

    ISBNLoop2:
        cmp rcx, r8                         ; Compare the loop counter to the book count
        je BookNotFound                     ; If all books checked, book not found

        ; Compare ISBN strings
        mov r11, r10                        ; r11 = Pointer to the current book
        add r11, Book.isbn                  ; r11 = Pointer to the current book's ISBN
        xor r12, r12                        ; Clear r12 (used as a loop counter)

    CompareLoop:
        mov al, [r11 + r12]                 ; Load a character from the current book's ISBN
        cmp al, byte [r9 + r12]             ; Compare it to the character in the ISBN to search for
        jne StringsDontMatch                ; If not equal, jump to the next book

        cmp al, 0                           ; Check for null termination
        je BookFound                        ; If null-terminated, the ISBNs match

        inc r12                             ; Increment the loop counter
        jmp CompareLoop                     ; Continue comparing characters

    BookFound:
        ; ISBNs match; return a pointer to the current book
        mov rax, r10                        ; rax = Pointer to the current book
        ret

    StringsDontMatch:
        ; ISBNs don't match; move to the next book
        add r10, Book_size                  ; Move to the next book's data
        inc rcx                             ; Increment the loop counter
        jmp ISBNLoop2                       ; Continue checking the next book

    BookNotFound:
        ; Book not found; return NULL
        xor rax, rax
        ret


IncrementCount:
    ; ===========================================
    ; Increment the count of books in the library
    ; ===========================================
    mov r8, [rdi + Library.count]
    inc r8             
    mov [rdi + Library.count], r8                   ; Store the count back in the library

    mov rax, 1                                      ; Return 1 if book added
    ret

TooManyBooks:
    mov rax, 0                                      ; Too many books added, return 0
    ret
