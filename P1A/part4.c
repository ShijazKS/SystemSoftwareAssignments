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
void saveToFile(struct Book books[], int n);

int main() {
     int n;
    printf("Enter the number of books : ");
    scanf("%d",&n);
    struct Book books[n];  

    createBookList(books, n);

    saveToFile(books, n);

    printf("Book details saved to booklist.txt.\n");

    return 0;
}



void createBookList(struct Book books[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter details for book %d:\n", i + 1);
        getchar();  

        printf("Title: ");
        fgets(books[i].title, MAX, stdin);
        books[i].title[strcspn(books[i].title, "\n")] = 0;  

        printf("Author: ");
        fgets(books[i].author, MAX, stdin);
        books[i].author[strcspn(books[i].author, "\n")] = 0;  

        printf("ISBN: ");
        scanf("%s", books[i].isbn);

        printf("Year of Publication: ");
        scanf("%d", &books[i].year);

        printf("Price: ");
        scanf("%f", &books[i].price);

        printf("\n");
    }
}


char* getBookByISBN(struct Book books[], int n, char* isbn) {
    for (int i = 0; i < n; i++) {
        if (strcmp(books[i].isbn, isbn) == 0) {
            return books[i].title;
        }
    }
    return NULL;
}


void saveToFile(struct Book books[], int n) {
    FILE *file = fopen("booklist.txt", "w"); 

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%s %s %s %d %.2f\n", 
                books[i].isbn, 
                books[i].title, 
                books[i].author, 
                books[i].year, 
                books[i].price);
    }

    fclose(file);  
}
