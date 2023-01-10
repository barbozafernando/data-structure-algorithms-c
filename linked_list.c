#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
  void *next;
  int data;
} Node;

Node *head = NULL;

Node *add_node(uint16_t data) {
  Node *new_node = NULL;

  // if the list is empty.
  if (head == NULL) {
    new_node = malloc(sizeof(Node));

    if (new_node == NULL)
      return NULL;

    new_node->data = data;
    head = new_node;
    new_node->next = NULL;
  } else {
    new_node = malloc(sizeof(Node));

    if (new_node == NULL)
      return NULL;

    new_node->data = data;
    new_node->next = head;
    head = new_node;
  }

  return new_node;
}

uint16_t remove_node(uint16_t data) {
  Node *current = head;
  Node *prev = head;
  while (current != NULL) {
    if (current->data == data) {
      // if current node is the list head
      if (current == head) {
        head = current->next;
      } else {
        prev->next = current->next;
        free(current);
        current = NULL;
      }

      return 1;
    }
    prev = current;
    current = current->next;
  }

  return 0;
}

// insert a node into a position in the list
Node *insert_node(uint16_t data, uint16_t position) {
  Node *current = head;
  while (current != NULL && position != 0) {
    position--;
  }

  if (position != 0) {
    printf("Requested position too far into list\n");
    return NULL;
  }

  Node *new = malloc(sizeof(Node));
  if (new == NULL)
    return NULL;

  new->data = data;
  new->next = current->next;
  current->next = new;

  return new;
}

void print_list() {
  Node *current = head;
  while (current != NULL) {
    printf("%d->", current->data);
    current = current->next;
  }

  printf("\n");
  return;
}

void print_menu() {
  printf("You have the following options:\n");
  printf("1. Add a node to the list.\n");
  printf("2. Remove a node from the list.\n");
  printf("3. Insert a node to the list.\n");
  printf("4. Print your list\n");
  printf("5. Quit.\n");
  return;
}


int main(int argc, char **argv)
{
  int option = -1;
  int arg1 = 0;
  int arg2 = 0;
  while (option != 5)
  {
    print_menu();
    int num_received = scanf("%d", &option);
    if (num_received == 1 && option > 0 && option <= 5) {
      switch(option) {
        case 1:
          printf("What data should I insert?:\n");
          scanf("%d", &arg1);
          Node *new = add_node(arg1);
          break;
        case 2:
          printf("What data should I remove?:\n");
          scanf("%d", &arg1);
          int success = remove_node(arg1);
          if (!success)
            printf("Element not found\n");

          break;
        case 3:
          printf("What data should I insert?:\n");
          scanf("%d", &arg1);
          printf("What position?:\n");
          scanf("%d", &arg2);
          new = insert_node(arg1, arg2);
          if (new == NULL)
            printf("Failed to insert into list\n");
          break;
        case 4:
          print_list();
          break;
        case 5:
          break;
      }
    }
  }

  return 0;
}
