#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float* items;
    int length;
    int capacity;
} NumbersArray;

#define na_push(na, n)\
    do {\
        if (na.length >= na.capacity) {\
            if (na.capacity == 0) na.capacity = 256;\
            else na.capacity *= 2;\
            na.items = realloc(na.items, na.capacity * sizeof(*na.items));\
        }\
        na.items[na.length++] = i;\
    } while(0)

int main()
{
    NumbersArray na = {0};

    for(int i = 0; i < 10; ++i) na_push(na, i);
    for (int i = 0; i < na.length; ++i) printf("%f\n", na.items[i]);
    return 0;
}
