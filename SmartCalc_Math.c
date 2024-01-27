#include "SmartCalc.h"

int Reverse_polish_notation(Node **input, Node **output, char mass[SIZE],
                            double val_x) {
  int error = 0, unary = 0;
  double x = 0, y = 0;
  Node *stack_number = NULL;
  if (Polish_notation(input, output, mass, val_x) == 1) {
    return ERROR_EXPRESSION;
  }
  while (*output != NULL) {
    if ((*output)->type == number) {
      error = push(&stack_number, (*output)->val, (*output)->priority,
                   (*output)->type);
      // '+'
    } else if ((*output)->type == 5) {
      error = SmartCalc_Arithmetic(&stack_number, x, y, 5);
      // '-'
    } else if ((*output)->type == 6) {
      error = SmartCalc_Arithmetic(&stack_number, x, y, 6);
      // '*'
    } else if ((*output)->type == 3) {
      error = SmartCalc_Arithmetic(&stack_number, x, y, 3);
      // '/'
    } else if ((*output)->type == 4) {
      error = SmartCalc_Arithmetic(&stack_number, x, y, 4);
    } else if ((*output)->type == 9) {
      unary = 1;
      error = SmartCalc_Arithmetic(&stack_number, x, y, 9);
      unary = 0;
    } else if ((*output)->type == 7) {
      error = SmartCalc_Arithmetic(&stack_number, x, y, 7);
      // MATH FUNC
    } else if ((*output)->type <= 18 && (*output)->type >= 10) {
      error = SmartCalc_triginometry(&stack_number, output, unary);
    } else if ((*output)->type == 19) {
      error = SmartCalc_Arithmetic(&stack_number, x, y, 19);
    } else if ((*output)->type == 8) {
      error = SmartCalc_Arithmetic(&stack_number, x, y, 8);
    }
    error = pop(output);
  }
  x = peek_num(&stack_number);
  error = push(output, x, 0, 0);
  Remove_stack(&stack_number);
  return error;
}

int SmartCalc_Arithmetic(Node **stack_number, double x, double y, int flag) {
  int error = 0;
  if (*stack_number == NULL) {
    return STACK_UNDERFLOW;
  }
  x = peek_num(stack_number);
  error = pop(stack_number);
  if (flag <= 8) {
    y = peek_num(stack_number);
    error = pop(stack_number);
  }
  if (flag == 5) {
    x += y;
  } else if (flag == 6) {
    x = y - x;
  } else if (flag == 3) {
    x *= y;
  } else if (flag == 4) {
    x = y / x;
  } else if (flag == 7) {
    x = pow(y, x);
  } else if (flag == 9) {
    x *= -1;
  } else if (flag == 19) {
    x *= 1;
  } else if (flag == 8) {
    x = fmod(y, x);
  }
  error = push(stack_number, x, number, 0);

  return error;
}

int SmartCalc_triginometry(Node **stack_number, Node **output, int unary) {
  int error = 0;
  if (*stack_number == NULL) {
    return STACK_UNDERFLOW;
  }
  double x = peek_num(stack_number);
  error = pop(stack_number);
  if ((*output)->type == 10) {
    x = cos(x);
  } else if ((*output)->type == 11) {
    x = sin(x);
  } else if ((*output)->type == 12) {
    x = tan(x);
  } else if ((*output)->type == 13) {
    x = asin(x);
  } else if ((*output)->type == 14) {
    x = acos(x);
  } else if ((*output)->type == 15) {
    x = atan(x);
  } else if ((*output)->type == 16) {
    x = sqrt(x);
  } else if ((*output)->type == 17) {
    x = log(x);
  } else if ((*output)->type == 18) {
    x = log10(x);
  }
  if (unary == 1) {
    x *= -1;
  }
  error = push(stack_number, x, number, 0);
  return error;
}