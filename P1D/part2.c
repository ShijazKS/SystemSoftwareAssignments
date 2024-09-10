#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    char ISBN[20];
    char author[50];
    struct Book* next;
} Book;

typedef struct Graph {
    int numBooks;
    Book** adjList; 
} Graph;

Book* createBook(char* ISBN, char* author) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->ISBN, ISBN);
    strcpy(newBook->author, author);
    newBook->next = NULL;
    return newBook;
}


Graph* createGraph(int numBooks) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numBooks = numBooks;
    graph->adjList = (Book**)malloc(numBooks * sizeof(Book*));

    for (int i = 0; i < numBooks; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}


void addEdge(Graph* graph, int src, int dest) {
    Book* srcBook = graph->adjList[src];
    Book* destBook = graph->adjList[dest];

    Book* newBook = createBook(destBook->ISBN, destBook->author);
    newBook->next = graph->adjList[src]->next;
    graph->adjList[src]->next = newBook;
   
    newBook = createBook(srcBook->ISBN, srcBook->author);
    newBook->next = graph->adjList[dest]->next;
    graph->adjList[dest]->next = newBook;
}


void createBookGraph(Graph* graph) {
    for (int i = 0; i < graph->numBooks; i++) {
        for (int j = i + 1; j < graph->numBooks; j++) {
            if (strcmp(graph->adjList[i]->author, graph->adjList[j]->author) == 0) {
                addEdge(graph, i, j);
            }
        }
    }
}


void printBooksByAuthor(Graph* graph, char* author) {
    for (int i = 0; i < graph->numBooks; i++) {
        if (strcmp(graph->adjList[i]->author, author) == 0) {
            printf("%s ", graph->adjList[i]->ISBN);
        }
    }
    printf("\n");
}


void DFS(Graph* graph, int v, int* visited) {
    visited[v] = 1;
    printf("%s ", graph->adjList[v]->ISBN); 


    Book* adjBook = graph->adjList[v];  
    while (adjBook != NULL) {
        int adjacentIndex = -1;
        

        for (int i = 0; i < graph->numBooks; i++) {
            if (strcmp(graph->adjList[i]->ISBN, adjBook->ISBN) == 0) {
                adjacentIndex = i;
                break;
            }
        }


        if (adjacentIndex != -1 && !visited[adjacentIndex]) {
            DFS(graph, adjacentIndex, visited);
        }

        adjBook = adjBook->next;  
    }
}


void graphTraversal(Graph* graph) {
    int* visited = (int*)malloc(graph->numBooks * sizeof(int));

    for (int i = 0; i < graph->numBooks; i++) {
        visited[i] = 0;
    }


    for (int i = 0; i < graph->numBooks; i++) {
        if (!visited[i]) {
            DFS(graph, i, visited);
        }
    }
    printf("\n");
    free(visited);
}

int main() {
    int n;
    scanf("%d", &n);
    getchar(); 

    Graph* graph = createGraph(n);

    for (int i = 0; i < n; i++) {
        char isbn[20], author[50];

        scanf("%19[^,], %49[^\n]", isbn, author);
        getchar(); 
        graph->adjList[i] = createBook(isbn, author);
    }

    createBookGraph(graph);

    char command;
    char author[50];
    while (1) {
        scanf("%c", &command);

        if (command == 'p') {  
            scanf(" %49[^\n]", author);
            printBooksByAuthor(graph, author);

        } else if (command == 'd') {  
            graphTraversal(graph);

        } else if (command == 'q') {  
            break;
        }
    }


    for (int i = 0; i < n; i++) {
        Book* current = graph->adjList[i];
        while (current != NULL) {
            Book* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->adjList);
    free(graph);
    return 0;
}
