#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int XOR(int op1, int op2) {
  return op1 ^ op2;
}

int main(int argc, char **argv) {
  uint8_t seed = atoi(argv[1]);

  if (seed == 0 || seed > UINT8_MAX) {
    fprintf(stderr, "Number must be between 1 <> 255");
    exit(EXIT_FAILURE);
  }

  char* msg = argv[2];

  size_t msg_index = 0;
  while (msg[msg_index] != '\0') {
    msg[msg_index] = XOR(msg[msg_index], seed);
    msg_index++;
  }

  printf("-------------------------------------------------------------------------------------------------------------");
  printf("\nencrypted msg: %s\n",msg);
  printf("-----------------------------------------------------------------------------------------------------------\n");

  size_t msg_index2 = 0;
  while (msg[msg_index2] != '\0') {
    msg[msg_index2] = XOR(msg[msg_index2], seed);
    msg_index2++;
  }

  printf("decrypted msg: %s\n",msg);
  printf("-----------------------------------------------------------------------------------------------------------\n");

  return 0;
}