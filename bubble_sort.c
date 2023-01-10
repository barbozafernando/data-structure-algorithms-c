#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 15
#define RANDOM_ARRAY_SIZE 100

void display(int *array, int showMsg) {
  if (showMsg == 0) {
    printf("Before: [ ");
  } else if (showMsg == 1) {
    printf("After: [ ");
  } else {
    printf("[ ");
  }
  
  for(int i = 0; i < ARRAY_SIZE; i++) {
    printf("%d ", array[i]);
  }
  
  printf("]\n");
}

void bubble_sort(int *array) {
  for (int n = 0; n < ARRAY_SIZE; n++) {
    for (int i = 0; i < ARRAY_SIZE - 1 - n; i++) {
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
  int arr[ARRAY_SIZE];

  for (int z = 0; z < ARRAY_SIZE; z++) {
    arr[z] = rand() % RANDOM_ARRAY_SIZE;
  }

  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif

  display(arr, 0);    
  bubble_sort(arr);
  display(arr, 1);

  return 0;
}
