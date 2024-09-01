#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX 100      

struct Book {
    char title[MAX];
    char author[MAX];
    char isbn[5];
    int year;
    float price;
};

void readBooksFromFile(struct Book *books[], int *n, const char *filename);
char* getBookByISBN(struct Book *books[], int n, const char* isbn);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("mention filename!");
        return 1;
    }

    struct Book *books[MAX];
    int n = 0;                      

    readBooksFromFile(books, &n, argv[1]);

    if (n == 0) {
        printf("No books were read from the file.\n");
        return 1;
    }

    char isbnToSearch[20];
    printf("Enter the ISBN to search for book: ");
    scanf("%s", isbnToSearch);

    char *title = getBookByISBN(books, n, isbnToSearch);
    if (title != NULL) {
        printf("Book found: %s\n", title);
    } else {
        printf("Book not found\n");
    }

    for (int i = 0; i < n; i++) {
        free(books[i]);
    }

    return 0;
}

void readBooksFromFile(struct Book *books[], int *n, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    while (*n < MAX) {
        books[*n] = (struct Book *)malloc(sizeof(struct Book));  
        if (books[*n] == NULL) {
            printf("Memory allocation failed\n");
            break;
        }

        if (fscanf(file, "%s %s %s %d %f",books[*n]->isbn, books[*n]->title, books[*n]->author, &books[*n]->year, &books[*n]->price) != 5) {
            free(books[*n]);  
            break;
        }

        (*n)++; 
    }

    fclose(file);
}


char* getBookByISBN(struct Book *books[], int n, const char *isbn) {
    for (int i = 0; i < n; i++) {
        if (strcmp(books[i]->isbn, isbn) == 0) {
            return books[i]->title;
        }
    }
    return NULL;  
}