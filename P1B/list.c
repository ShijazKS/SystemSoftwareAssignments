#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "queue.h"


Book* availableBooksList = NULL;
Book* unavailableBooksList = NULL;

Book* createBook(char* ISBN, char* title, char* author, int year, float price) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->ISBN, ISBN);
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->year = year;
    newBook->price = price;
    newBook->isLent = 0; 
    newBook->next = NULL;
    return newBook;
}


void insertBook(Book** head, Book* newBook) {
    // printf("#%s#\n",newBook->ISBN);
    if (*head == NULL || strcmp((*head)->ISBN, newBook->ISBN) > 0) {
        newBook->next = *head;
        *head = newBook;
    } else {
        Book* current = *head;
        while (current->next != NULL && strcmp(current->next->ISBN, newBook->ISBN) < 0) {
            current = current->next;
        }
        newBook->next = current->next;
        current->next = newBook;
    }
}

Book* findBook(Book* head, char* ISBN) {
    Book* current = head;
    while (current != NULL && strcmp(current->ISBN, ISBN) != 0) {
        current = current->next;
    }
    return current;
}

void removeBook(Book** head, char* ISBN) {
    if (*head == NULL) return;
    
    Book* current = *head;
    Book* prev = NULL;
    
    while (current != NULL && strcmp(current->ISBN, ISBN) != 0) {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL) return;  
    
    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }
    
}

void lendBook(char* ISBN) {
    Book* book = findBook(availableBooksList, ISBN);
    if (book != NULL) {
        book->isLent = 1;
        removeBook(&availableBooksList, ISBN);
        insertBook(&unavailableBooksList, book);
    } else {
        printf("Book not available for lending.\n");
    }
}

void returnBook(char* ISBN) {
    Book* book = findBook(unavailableBooksList, ISBN);
    if (book != NULL) {
        book->isLent = 0;
        removeBook(&unavailableBooksList, ISBN);
        insertBook(&availableBooksList, book);
        removeFromReservationQueue(ISBN);  // Check if any student is waiting for this book
        printf("Returned \n\n");
    } else {
        printf("Book not found in unavailable list.\n");
    }
}

void printAvailableBooks() {
    Book* current = availableBooksList;
    while (current != NULL) {
        printf("%s, %s, %s, %d, %.2f \n", current->ISBN, current->title, current->author, current->year, current->price);
        current = current->next;
    }
    printf("\n");
}

void printUnavailableBooks() {
    Book* current = unavailableBooksList;
    while (current != NULL) {
        printf("%s, %s, %s, %d, %.2f \n", current->ISBN, current->title, current->author, current->year, current->price);
        current = current->next;
    }
    printf("\n");
}


