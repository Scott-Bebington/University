#include <stdio.h>
#include <stdlib.h>

extern char** populateMatrix();
extern char encryptChar(char**, char, char);
extern void testing(void);

int main()
{

    // char** matrix = populateMatrix();

    int rows = 26;
    int cols = 26;

    // Allocate memory for the char** matrix
    char **matrix = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (char *)malloc(cols * sizeof(char));
    }
    
    for (int i = 0; i < rows; i++) {
        char currentChar = 'A' + i;

        for (int j = 0; j < cols; j++) {
            matrix[i][j] = currentChar;
            currentChar = (currentChar + 1) > 'Z' ? 'A' : (currentChar + 1);
        }
    }
    

    for (int i = 0; i < 26; i++)
    {
        char currentChar = 'A' + i;

        for (int j = 0; j < 26; j++)
        {
            matrix[i][j] = currentChar;
            currentChar = (currentChar + 1) > 'Z' ? 'A' : (currentChar + 1);
        }
    }

    
    char input = 'A';
    char key = 'L';
    printf("%c - %c -> %c\n", input, key, encryptChar(matrix, input, key));

    input = 'T';
    key = 'E';
    printf("%c - %c -> %c\n", input, key, encryptChar(matrix, input, key));

    input = 'T';
    key = 'M';
    printf("%c - %c -> %c\n", input, key, encryptChar(matrix, input, key));
    
    input = 'A';
    key = 'O';
    printf("%c - %c -> %c\n", input, key, encryptChar(matrix, input, key));

    input = 'C';
    key = 'N';
    printf("%c - %c -> %c\n", input, key, encryptChar(matrix, input, key));

    input = 'K';
    key = 'L';
    printf("%c - %c -> %c\n", input, key, encryptChar(matrix, input, key));

    // encryptChar(matrix, 'B', 'Z');

    for (int i = 0; i < 26; ++i) {
        free(matrix[i]);
    }
    free(matrix);

    

    return 0;
}
/*
B - Z -> A
Z - Z -> Y
A - L -> L
O - P -> D
*/

/*
Output
'A' 'B' 'C' 'D' 'E' 'F' 'G' 'H' 'I' 'J' 'K' 'L' 'M' 'N' 'O' 'P' 'Q' 'R' 'S' 'T' 'U' 'V' 'W' 'X' 'Y' 'Z'
'B' 'C' 'D' 'E' 'F' 'G' 'H' 'I' 'J' 'K' 'L' 'M' 'N' 'O' 'P' 'Q' 'R' 'S' 'T' 'U' 'V' 'W' 'X' 'Y' 'Z' 'A'
'C' 'D' 'E' 'F' 'G' 'H' 'I' 'J' 'K' 'L' 'M' 'N' 'O' 'P' 'Q' 'R' 'S' 'T' 'U' 'V' 'W' 'X' 'Y' 'Z' 'A' 'B'
'D' 'E' 'F' 'G' 'H' 'I' 'J' 'K' 'L' 'M' 'N' 'O' 'P' 'Q' 'R' 'S' 'T' 'U' 'V' 'W' 'X' 'Y' 'Z' 'A' 'B' 'C'
'E' 'F' 'G' 'H' 'I' 'J' 'K' 'L' 'M' 'N' 'O' 'P' 'Q' 'R' 'S' 'T' 'U' 'V' 'W' 'X' 'Y' 'Z' 'A' 'B' 'C' 'D'
'F' 'G' 'H' 'I' 'J' 'K' 'L' 'M' 'N' 'O' 'P' 'Q' 'R' 'S' 'T' 'U' 'V' 'W' 'X' 'Y' 'Z' 'A' 'B' 'C' 'D' 'E'
'G' 'H' 'I' 'J' 'K' 'L' 'M' 'N' 'O' 'P' 'Q' 'R' 'S' 'T' 'U' 'V' 'W' 'X' 'Y' 'Z' 'A' 'B' 'C' 'D' 'E' 'F'
'H' 'I' 'J' 'K' 'L' 'M' 'N' 'O' 'P' 'Q' 'R' 'S' 'T' 'U' 'V' 'W' 'X' 'Y' 'Z' 'A' 'B' 'C' 'D' 'E' 'F' 'G'
'I' 'J' 'K' 'L' 'M' 'N' 'O' 'P' 'Q' 'R' 'S' 'T' 'U' 'V' 'W' 'X' 'Y' 'Z' 'A' 'B' 'C' 'D' 'E' 'F' 'G' 'H'
'J' 'K' 'L' 'M' 'N' 'O' 'P' 'Q' 'R' 'S' 'T' 'U' 'V' 'W' 'X' 'Y' 'Z' 'A' 'B' 'C' 'D' 'E' 'F' 'G' 'H' 'I'
'K' 'L' 'M' 'N' 'O' 'P' 'Q' 'R' 'S' 'T' 'U' 'V' 'W' 'X' 'Y' 'Z' 'A' 'B' 'C' 'D' 'E' 'F' 'G' 'H' 'I' 'J'
'L' 'M' 'N' 'O' 'P' 'Q' 'R' 'S' 'T' 'U' 'V' 'W' 'X' 'Y' 'Z' 'A' 'B' 'C' 'D' 'E' 'F' 'G' 'H' 'I' 'J' 'K'
'M' 'N' 'O' 'P' 'Q' 'R' 'S' 'T' 'U' 'V' 'W' 'X' 'Y' 'Z' 'A' 'B' 'C' 'D' 'E' 'F' 'G' 'H' 'I' 'J' 'K' 'L'
'N' 'O' 'P' 'Q' 'R' 'S' 'T' 'U' 'V' 'W' 'X' 'Y' 'Z' 'A' 'B' 'C' 'D' 'E' 'F' 'G' 'H' 'I' 'J' 'K' 'L' 'M'
'O' 'P' 'Q' 'R' 'S' 'T' 'U' 'V' 'W' 'X' 'Y' 'Z' 'A' 'B' 'C' 'D' 'E' 'F' 'G' 'H' 'I' 'J' 'K' 'L' 'M' 'N'
'P' 'Q' 'R' 'S' 'T' 'U' 'V' 'W' 'X' 'Y' 'Z' 'A' 'B' 'C' 'D' 'E' 'F' 'G' 'H' 'I' 'J' 'K' 'L' 'M' 'N' 'O'
'Q' 'R' 'S' 'T' 'U' 'V' 'W' 'X' 'Y' 'Z' 'A' 'B' 'C' 'D' 'E' 'F' 'G' 'H' 'I' 'J' 'K' 'L' 'M' 'N' 'O' 'P'
'R' 'S' 'T' 'U' 'V' 'W' 'X' 'Y' 'Z' 'A' 'B' 'C' 'D' 'E' 'F' 'G' 'H' 'I' 'J' 'K' 'L' 'M' 'N' 'O' 'P' 'Q'
'S' 'T' 'U' 'V' 'W' 'X' 'Y' 'Z' 'A' 'B' 'C' 'D' 'E' 'F' 'G' 'H' 'I' 'J' 'K' 'L' 'M' 'N' 'O' 'P' 'Q' 'R'
'T' 'U' 'V' 'W' 'X' 'Y' 'Z' 'A' 'B' 'C' 'D' 'E' 'F' 'G' 'H' 'I' 'J' 'K' 'L' 'M' 'N' 'O' 'P' 'Q' 'R' 'S'
'U' 'V' 'W' 'X' 'Y' 'Z' 'A' 'B' 'C' 'D' 'E' 'F' 'G' 'H' 'I' 'J' 'K' 'L' 'M' 'N' 'O' 'P' 'Q' 'R' 'S' 'T'
'V' 'W' 'X' 'Y' 'Z' 'A' 'B' 'C' 'D' 'E' 'F' 'G' 'H' 'I' 'J' 'K' 'L' 'M' 'N' 'O' 'P' 'Q' 'R' 'S' 'T' 'U'
'W' 'X' 'Y' 'Z' 'A' 'B' 'C' 'D' 'E' 'F' 'G' 'H' 'I' 'J' 'K' 'L' 'M' 'N' 'O' 'P' 'Q' 'R' 'S' 'T' 'U' 'V'
'X' 'Y' 'Z' 'A' 'B' 'C' 'D' 'E' 'F' 'G' 'H' 'I' 'J' 'K' 'L' 'M' 'N' 'O' 'P' 'Q' 'R' 'S' 'T' 'U' 'V' 'W'
'Y' 'Z' 'A' 'B' 'C' 'D' 'E' 'F' 'G' 'H' 'I' 'J' 'K' 'L' 'M' 'N' 'O' 'P' 'Q' 'R' 'S' 'T' 'U' 'V' 'W' 'X'
'Z' 'A' 'B' 'C' 'D' 'E' 'F' 'G' 'H' 'I' 'J' 'K' 'L' 'M' 'N' 'O' 'P' 'Q' 'R' 'S' 'T' 'U' 'V' 'W' 'X' 'Y'
*/
