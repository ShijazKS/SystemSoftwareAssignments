#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "queue.h"

#define MAX_LINE_LENGTH 256

void loadBooks(int n) {
    char line[MAX_LINE_LENGTH];
    for (int i = 0; i < n; i++) {
        if (fgets(line, sizeof(line), stdin) != NULL) {
            char ISBN[20], title[50], author[50];
            int year;
            float price;
            sscanf(line, "%[^,], %[^,], %[^,], %d, %f", ISBN, title, author, &year, &price);
            Book* newBook = createBook(ISBN, title, author, year, price);
            insertBook(&availableBooksList, newBook);
        }
    }
}

void processCommands() {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), stdin) != NULL) {
        char command = line[0];
        switch (command) {
            case 'l': {
                char ISBN[20];
                sscanf(line + 2, "%s", ISBN);
                lendBook(ISBN);
                break;
            }
            case 'r': {
                char ISBN[20];
                sscanf(line + 2, "%s", ISBN);
                returnBook(ISBN);
                break;
            }
            case 'a': {
                printAvailableBooks();
                break;
            }
            case 'u': {  
                printUnavailableBooks();
                break;
            }
            case 'q': {
                char studentName[50], ISBN[20];
                int studentID;
                sscanf(line + 2, "%[^,], %d, %s", studentName, &studentID, ISBN);
                addToReservationQueue(studentName, studentID, ISBN);
                break;
            }
            case 'p': {
                viewReservationQueue();
                break;
            }
            case 's': {
                return;
            }
            default:
                printf("Unknown command: %c\n", command);
        }
    }
}

int main() {
    int n;
    char line[MAX_LINE_LENGTH];
    
    if (fgets(line, sizeof(line), stdin) != NULL) {
        sscanf(line, "%d", &n);
        loadBooks(n);
    }
    
    processCommands();
}
