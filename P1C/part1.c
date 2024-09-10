#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    char ISBN[20];
    char title[100];
    char author[100];
    char genre[50];
    int accession_number;
    int year;
    int price;
    struct Book *left, *right, *parent;
} Book;


Book* insertBook(Book* root, char* ISBN, char* title, char* author, char* genre, int accession_number, int year, int price);
void inorderInventoryWalk(Book* root);
void preorderInventoryWalk(Book* root);
Book* searchBook(Book* root, int accession_number);
void printBookDetails(Book* book);

int isFirst=1;

Book* createBook(char* ISBN, char* title, char* author, char* genre, int accession_number, int year, int price) {
    Book* newBook = (Book*)malloc(sizeof(Book));
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

Book* insertBook(Book* root, char* ISBN, char* title, char* author, char* genre, int accession_number, int year, int price) {
    if (root == NULL) return createBook(ISBN, title, author, genre, accession_number, year, price);
    
    if (accession_number < root->accession_number) {
        Book* leftChild = insertBook(root->left, ISBN, title, author, genre, accession_number, year, price);
        root->left = leftChild;
        leftChild->parent = root;
    } else if (accession_number > root->accession_number) {
        Book* rightChild = insertBook(root->right, ISBN, title, author, genre, accession_number, year, price);
        root->right = rightChild;
        rightChild->parent = root;
    }
    return root;
}

void inorderInventoryWalk(Book* root) {
    if (root != NULL) {
        inorderInventoryWalk(root->left);
        if(isFirst){
            printf("%d", root->accession_number);
            isFirst=0;
        }else{
            printf(",%d", root->accession_number);
        }
        inorderInventoryWalk(root->right);
    }
}

void preorderInventoryWalk(Book* root) {
    if (root != NULL) {
       if(isFirst){
            printf("%d", root->accession_number);
            isFirst=0;
        }else{
            printf(",%d", root->accession_number);
        }
        preorderInventoryWalk(root->left);
        preorderInventoryWalk(root->right);
    }
}

Book* searchBook(Book* root, int accession_number) {
    if (root == NULL || root->accession_number == accession_number)
        return root;
    
    if (accession_number < root->accession_number)
        return searchBook(root->left, accession_number);
    else
        return searchBook(root->right, accession_number);
}

void printBookDetails(Book* book) {
    if (book != NULL) {
        printf("%s,%s,%s,%s,%d,%d,%d\n",
               book->ISBN, book->title, book->author, book->genre, book->accession_number, book->year, book->price);
    } else {
        printf("NULL\n");
    }
}

int main() {
    Book* root = NULL;
    int accession_number, year, price;
    char title[100], author[100], genre[50],ISBN[20];
    
   
    char command;
    while (scanf(" %c", &command) != EOF) {
        switch(command){
            case 'i':
                {
                scanf(" %[^,],%[^,],%[^,],%[^,],%d,%d,%d", &ISBN, title, author, genre, &accession_number, &year, &price);
                root = insertBook(root, ISBN, title, author, genre, accession_number, year, price);
                break;
                }
            case 'l':
                {
                    inorderInventoryWalk(root);
                    isFirst=1;
                    printf("\n");
                    break;
                }
            case 'p':
                {
                    preorderInventoryWalk(root);
                    isFirst=1;
                    printf("\n");
                    break;
                }
            case 's':
                {
                scanf("%d", &accession_number);
                Book* found = searchBook(root, accession_number);
                printBookDetails(found);
                break;
                }
            case 'q':
                return 0;
            default:
                printf("null");
        }

    }

    return 0;
}
