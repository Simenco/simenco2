
#include <stdio.h>

main() {
   int LA[] = {1,3,5,7,8};
   int item = 10, k = 3, n = 5;
   int i = 0, j = n;
   
   printf("The original array elements are :\n");

   for(i = 0; i<n; i++) {
      printf("LA[%d] = %d \n", i, LA[i]);
   }

  n = n + 1;
  printf("\nn is: %d",n);
  printf("\nj is: %d",j);
	
   while( j >= k) {
      LA[j] = LA[j-1];
      printf("\n LA[%d] = %d",j,LA[j-1]);
      j = j - 1;
   }
   
   printf("\n");
   for(i = 0; i<n; i++) {
      printf("LA[%d] = %d \n", i, LA[i]);
   }

   LA[k] = item;

   printf("\nThe array elements after insertion :\n");

   for(i = 0; i<n; i++) {
      printf("LA[%d] = %d \n", i, LA[i]);
   }
}
