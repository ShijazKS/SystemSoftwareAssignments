#include <stdio.h>

int main(){
 int n;
 printf("Enter the number of Books:");
 scanf("%d",&n);
 int isbn[n];
 for(int i=0;i<n;i++){
   printf("Enter the 5-digit ISBN of book %d:",i+1);
   scanf("%d",&isbn[i]);
   if(isbn[i]<10000 || isbn[i]>99999){
   	printf("Incorrect Format\n");
   	--i;
   }
 } 
 
    printf("The ISBNs of the books are:\n");
  for(int i=0;i<n;i++){
   printf("Book %d ISBN: %d\n",i+1,isbn[i]);
  } 
}
