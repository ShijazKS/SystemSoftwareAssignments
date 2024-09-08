#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char ISBN[20];
    int price;
} Book;

Book pricelist[MAX];
int heapSize = 0;


void swap(Book *a, Book *b) {
    Book temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && pricelist[left].price > pricelist[largest].price)
        largest = left;

    if (right < heapSize && pricelist[right].price > pricelist[largest].price)
        largest = right;

    if (largest != i) {
        swap(&pricelist[i], &pricelist[largest]);
        maxHeapify(largest);
    }
}

void insertBook(char ISBN[], int price) {
    for (int i = 0; i < heapSize; i++) {
        if (strcmp(pricelist[i].ISBN, ISBN) == 0) {
            pricelist[i].price = price;  
            maxHeapify(i);              
            return;
        }
    }

    strcpy(pricelist[heapSize].ISBN, ISBN);
    pricelist[heapSize].price = price;
    heapSize++;

    int i = heapSize - 1;
    while (i != 0 && pricelist[(i - 1) / 2].price < pricelist[i].price) {
        swap(&pricelist[i], &pricelist[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}


void printMaxPricedBook() {
    if (heapSize > 0)
        printf("%s\n", pricelist[0].ISBN);
    else
        printf("NULL\n");
}


void deleteMaxPricedBook() {
    if (heapSize == 0) {
        printf("No books to delete.\n");
        return;
    }
    pricelist[0] = pricelist[heapSize - 1];
    heapSize--;

    maxHeapify(0);
}


void updateMaxPrice(char ISBN[], int newPrice) {
    for (int i = 0; i < heapSize; i++) {
        if (strcmp(pricelist[i].ISBN, ISBN) == 0) {
            pricelist[i].price = newPrice;

            
            int parent = (i - 1) / 2;
            while (i != 0 && pricelist[parent].price < pricelist[i].price) {
                swap(&pricelist[i], &pricelist[parent]);
                i = parent;
                parent = (i - 1) / 2;
            }

            
            maxHeapify(i);
            return;
        }
    }
    printf("Book not found!\n");
}



int main() {
    int n, price;
    char isbn[20];  
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf(" %[^,],%d", isbn, &price);  
        insertBook(isbn, price);
    }

    char opt;

    while (scanf(" %c", &opt) != EOF) {  
        switch(opt) {
            case 'p':
                printMaxPricedBook();
                break;
            case 'i':
                scanf(" %[^,],%d", isbn, &price); 
                insertBook(isbn, price);
                break;
            case 'd':
                deleteMaxPricedBook();
                break;
            case 'u':
                scanf(" %[^,],%d", isbn, &price);  
                updateMaxPrice(isbn, price);
                break;
            case 'q':
                return 0;
            default:
                break;
        }
    }

    return 0;
}
