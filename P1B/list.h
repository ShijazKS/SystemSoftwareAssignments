#ifndef LIST_H
#define LIST_H

typedef struct Book {
    char ISBN[20];
    char title[50];
    char author[50];
    int year;
    float price;
    int isLent;
    struct Book* next;
} Book;


Book* createBook(char* ISBN, char* title, char* author, int year, float price);
void insertBook(Book** head, Book* newBook);
Book* findBook(Book* head, char* ISBN);
void removeBook(Book** head, char* ISBN);
void lendBook(char* ISBN);
void returnBook(char* ISBN);
void printAvailableBooks();
void printUnavailableBooks();


extern Book* availableBooksList;
extern Book* unavailableBooksList;

#endif
