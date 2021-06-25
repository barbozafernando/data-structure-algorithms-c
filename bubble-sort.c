#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define RANDOM_MAX 50

void display(int *array, int showMsg) {
  int i;

  if (showMsg == 0) {
    printf("Before: [ ");
  } else if (showMsg == 1) {
    printf("After: [ ");
  } else {
    printf("[ ");
  }
  
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
  int arr[MAX];
  int z, y;

  for (z = 0; z < MAX; z++) {
    arr[z] = rand() % RANDOM_MAX;
  }

  system("cls");

  display(arr, 0);    
  bubble_sort(arr);
  display(arr, 1);

  return 0;
}