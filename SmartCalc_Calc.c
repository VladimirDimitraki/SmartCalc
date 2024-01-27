#include "SmartCalc.h"

double Calculate(char mass[SIZE], double val_x, int *error) {
  Node *input = NULL;
  Node *output = NULL;
  double x = 0;
  if (mass == NULL || *mass == '\0') {
    *error = 1;
  } else {
    if (Reverse_polish_notation(&input, &output, mass, val_x) == 1) {
      *error = 1;
    } else if (output != NULL) {
      x = output->val;
      Remove_stack(&input);
      Remove_stack(&output);
    } else {
      *error = 1;
    }
  }
  return x;
}