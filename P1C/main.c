#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    char ISBN[6];
    char title[100];
    char author[100];
    char genre[50];
    int accession_number;
    int year;
    float price;
    struct Book *left, *right, *parent;
} Book;

Book* createBook(char ISBN[], char title[], char author[], char genre[], int accession_number, int year, float price) {
    Book *newBook = (Book *)malloc(sizeof(Book));
    strcpy(newBook->ISBN, ISBN);
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    strcpy(newBook->genre, genre);
    newBook->accession_number = accession_number;
    newBook->year = year;
    newBook->price = price;
    newBook->left = newBook->right = newBook->parent = NULL;
    return newBook;
}

Book* insertBook(Book* root, Book* newBook) {
    if (root == NULL) return newBook;

    if (newBook->accession_number < root->accession_number) {
        root->left = insertBook(root->left, newBook);
        root->left->parent = root;
    } else if (newBook->accession_number > root->accession_number) {
        root->right = insertBook(root->right, newBook);
        root->right->parent = root;
    } else {
        printf("Book with accession number %d already exists.\n", newBook->accession_number);
    }
    return root;
}



void inorderInventoryWalk(Book* root) {
    if (root == NULL) return;
    inorderInventoryWalk(root->left);

    // Print the current node's accession number
    printf("%d", root->accession_number);
    
    // Check if there is a next node on the right
    if (root->right != NULL || (root->parent != NULL && root->parent->right != root)) {
        printf(",");
    }

    inorderInventoryWalk(root->right);
}

void preorderInventoryWalk(Book* root) {
    if (root == NULL) return;

    // Print the current node's accession number
    printf("%d", root->accession_number);

    // Check if there is a next node on the left or right
    if (root->left != NULL || root->right != NULL) {
        printf(",");
    }

    preorderInventoryWalk(root->left);
    preorderInventoryWalk(root->right);
}


Book* searchBook(Book* root, int accession_number) {
    if (root == NULL || root->accession_number == accession_number)
        return root;

    if (accession_number < root->accession_number)
        return searchBook(root->left, accession_number);
    
    return searchBook(root->right, accession_number);
}

int main() {
    Book* root = NULL;
    int n, accession_number, year;
    float price;
    char ISBN[6], title[100], author[100], genre[50];
    char operation;

    scanf("%d", &n);
    getchar(); // to consume the newline after the number of books

    for (int i = 0; i < n; i++) {
        // Use %[^,] to read up to the next comma, allowing spaces in the strings
        scanf("%5[^,], %99[^,], %99[^,], %49[^,], %d, %d, %f", ISBN, title, author, genre, &accession_number, &year, &price);
        getchar(); // to consume the newline or comma
        root = insertBook(root, createBook(ISBN, title, author, genre, accession_number, year, price));
        printf("%s, %s, %s, %s, %d, %d, %.2f\n", ISBN, title, author, genre, accession_number, year, price);
    }
    char line[500];
    
    while (fgets(line, sizeof(line),stdin) != NULL) {
        operation = line[0];
        if (operation == 'i') {
            sscanf(line+3,"%5[^,],%99[^,],%99[^,],%49[^,], %d, %d, %f", ISBN, title, author, genre, &accession_number, &year, &price);
            root = insertBook(root, createBook(ISBN, title, author, genre, accession_number, year, price));
            printf("%s,%s,%s,%s, %d, %d, %.2f\n", ISBN, title, author, genre, accession_number, year, price);
        } else if (operation == 'l') {
            inorderInventoryWalk(root);
            printf("\n");
        } else if (operation == 'p') {
            preorderInventoryWalk(root);
            printf("\n");
        } else if (operation == 's') {
            sscanf(line+3, "%d", &accession_number);
            Book* found = searchBook(root, accession_number);
            if (found != NULL) {
                printf("%s, %s, %s, %s, %d, %d, %.2f\n",  found->ISBN, found->title, found->author, found->genre,found->accession_number, found->year, found->price);
            } else {
                printf("NOT FOUND\n");
            }
        }
    }

    return 0;
}
