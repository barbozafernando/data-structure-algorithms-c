#include <stdio.h>
#include <stdlib.h>

#define MAX 6

void display(int *array) {
   int i;
   printf("[ ");
	
   // navigate through all items 
   for(i = 0; i < MAX; i++) {
      printf("%d ", array[i]);
   }
	
   printf("]\n");
}

void bubble_sort(int *array) {
    int i,n;

    for (n = 0; n < MAX-1; n++) {
        for (i = 0; i < MAX-1; i++) {

            if (array[i] > array[i+1]) {
                int temp = array[i];

                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
    }
}

int main()
{
    int arr[MAX] = {3, 2, 5, 1, 4, 0};
    
    bubble_sort(arr);
    display(arr);

    return 0;
}