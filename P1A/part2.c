#include <stdio.h>


int main() {
    int n;
    printf("Enter the number of books: ");
    scanf("%d",&n);
    char title[n][100];
    getchar();

    for(int i=0;i<n;i++){
        printf("Enter the title of book %d: ",i+1);
        fgets(title[i],100,stdin);  
   } 
  printf("\nThe titles of the books are:\n");
  for(int i=0;i<n;i++){
   printf("Book %d Title: %s",i+1,title[i]);
  } 
}
