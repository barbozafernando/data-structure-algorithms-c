#include <stdio.h>

int insert_sort(int *arr)
{
  int key, i, j;

  for(j = 0; j < 5; j++) {
    key = arr[j];
    i = j - 1;

    while(i >= 0 && arr[i] > key) {
      arr[i + 1] = arr[i];
      i -= 1;
    }

    arr[i + 1] = key;
  }
}

int main()
{
  int i, array[] = {4,5,2,1,3};

  printf("Array original\n");

  for(i = 0; i < 5; i++) {
    printf("%d,", array[i]);
  }

  printf("\n");

  insert_sort(array);
  
  printf("Array ordenado\n");

  for(i = 0; i < 5; i++) {
    printf("%d,", array[i]);
  }
}
