#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct Data {
    char buffer[4];
    uint8_t number;
    long int padding;
};

void vulnerable_function() {
    struct Data *data = (struct Data *)malloc(sizeof(struct Data));
    if (data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    data->number = 0;

    printf("Enter some text: ");
    // gets(data->buffer);
    fgets(data->buffer, sizeof(data->buffer), stdin);

    if (data->number == 0) {
        printf("\nAccess Denied!\n");
    } else {
        printf("\nAccess Granted!\n");
        printf("Revealing sensitive data (number): %d\n", data->number);
        printf("Revealing sensitive data (padding): %d\n", data->padding);
    }

    free(data);
}

int main() {
    vulnerable_function();
    return 0;
}
