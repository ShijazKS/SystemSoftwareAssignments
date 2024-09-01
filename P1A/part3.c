#include <stdio.h>
#include <string.h>

#define MAX 100  

struct Book {
    char title[MAX];
    char author[MAX];
    char isbn[5];
    int year;
    float price;
};

void createBookList(struct Book books[], int n);
char* getBookByISBN(struct Book books[], int n, char* isbn);

int main() {
    int n;
    printf("Enter the number of books: ");
    scanf("%d",&n);
    struct Book books[n];  
    char isbnToSearch[5];         
    createBookList(books, n);

    printf("\nEnter ISBN to search for a book: ");
    scanf("%s", isbnToSearch);

    char* title = getBookByISBN(books, n, isbnToSearch);

    if (title != NULL) {
        printf("Book found %s: ", title);
    } else {
        printf("Book not found!\n");
    }

    return 0;
}

void createBookList(struct Book books[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter details for book %d:\n", i + 1);

        printf("Title: ");
        getchar();  // Clear input buffer
        fgets(books[i].title, MAX, stdin);
        books[i].title[strcspn(books[i].title, "\n")] = 0;  // Remove trailing newline

        printf("Author: ");
        fgets(books[i].author, MAX, stdin);
        books[i].author[strcspn(books[i].author, "\n")] = 0;  // Remove trailing newline

        printf("ISBN: ");
        scanf("%s", books[i].isbn);

        printf("Year of Publication: ");
        scanf("%d", &books[i].year);

        printf("Price: ");
        scanf("%f", &books[i].price);

        printf("\n");
    }
}

// Function to search for a book by ISBN and return its title
char* getBookByISBN(struct Book books[], int n, char* isbn) {
    for (int i = 0; i < n; i++) {
        if (strcmp(books[i].isbn, isbn) == 0) {
            return books[i].title;
        }
    }
    return NULL;  // Return NULL if ISBN not found
}