#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#define EPSILON 0.0001

struct Book
{
    char isbn[13];
    char title[50];
    float price;
    int quantity;
};

struct Library
{
    struct Book books[5];
    int count;
};

struct Library *initialiseLibrary(void);
int addBook(struct Library *lib, struct Book *book);
struct Book *searchBookByISBN(struct Library *lib, char *isbn);
extern struct Book *allocateBook(char *isbn, char *title, float price, int quantity);

void printBookDetails(struct Book book)
{
    printf("ISBN: %s\n", book.isbn);
    printf("Title: %s\n", book.title);
    printf("Price: %.2f\n", book.price);
    printf("Quantity: %d\n", book.quantity);
}

int main()
{
    /*
        As always, this will only partially test your code. Please write more rigorous tests
        to verify that everything is as expected. That means testing negative flows as well as edge cases.
    */
    // Initialising library and asserting it's not NULL
    struct Library *lib = initialiseLibrary();
    assert(lib != NULL);

    // Testing addition of books to the library
    assert(addBook(lib, allocateBook("978316148\0", "The C Programming Language\0", 9.99, 10)) == 1);
    // assert(addBook(lib, allocateBook("978316148\0", "The C Programming Language\0", 9.99, 10)) == 1);
    assert(addBook(lib, allocateBook("978012345\0", "Another Book Title\0", 15.49, 5)) == 1);
    // assert(addBook(lib, allocateBook("978012345\0", "Another Book Title\0", 15.49, 5)) == 1);
    assert(addBook(lib, allocateBook("978098765\0", "Yet Another Book\0", 20.89, 7)) == 1);
    // assert(addBook(lib, allocateBook("978098765\0", "Yet Another Book\0", 20.89, 7)) == 1);
    assert(addBook(lib, allocateBook("978111111\0", "Some Book\0", 10.0, 2)) == 1);
    // assert(addBook(lib, allocateBook("978111111\0", "Some Book\0", 10.0, 2)) == 1);
    assert(addBook(lib, allocateBook("978222222\0", "Some Other Book\0", 5.0, 3)) == 1);
    // assert(addBook(lib, allocateBook("978222222\0", "Some Other Book\0", 5.0, 3)) == 1);

    for (int i = 0; i < 5; i++)
    {
        printf("\nBook %d:\n", i + 1);
        printBookDetails(lib->books[i]);
    }
    

    // Cleanup
    free(lib);

    printf("All tests passed successfully.\n");

    return 0;
}
