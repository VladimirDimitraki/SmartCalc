#include "SmartCalc.h"

int Parse_stack(Node **stack, char mass[SIZE], double val_x) {
  int res = 0, flag = 0;
  double n = 0;
  int step = 0;
  char tmp[SIZE] = {0};
  while (*mass != '\0') {
    step = 1;
    // Digit
    if (*mass >= '0' && *mass <= '9') {
      n = StringToDouble(mass, &step);
      sprintf(tmp, "%lf", n);
      res = push(stack, n, number, 0);
      n = 0;
      // Brackets
    } else if (*mass == '(') {
      res = push(stack, n, brackets_left, 1);
    } else if (*mass == ')') {
      res = push(stack, n, brackets_right, 2);
      // Multiply
    } else if (*mass == '*') {
      res = push(stack, n, mult, 3);
    } else if (*mass == '/') {
      res = push(stack, n, division, 4);
    } else if (*mass == '+') {
      flag = 1;
      Parse_unary(stack, flag, mass);
    } else if (*mass == '-') {
      flag = 2;
      Parse_unary(stack, flag, mass);
    } else {
      Parse_func(stack, mass, &step, val_x);
    }
    mass += step;
  }
  return res;
}

int Parse_func(Node **stack, char mass[SIZE], int *step, double val_x) {
  double n = 0;
  int res = 0;
  if (strncmp(mass, "cos", 3) == 0) {
    res = push(stack, n, cos_f, 10);
    *step = 3;
  } else if (strncmp(mass, "sin", 3) == 0) {
    res = push(stack, n, sin_f, 11);
    *step = 3;
  } else if (strncmp(mass, "tan", 3) == 0) {
    res = push(stack, n, tan_f, 12);
    *step = 3;
  } else if (strncmp(mass, "asin", 4) == 0) {
    res = push(stack, n, asin_f, 13);
    *step = 4;
  } else if (strncmp(mass, "acos", 4) == 0) {
    res = push(stack, n, acos_f, 14);
    *step = 4;
  } else if (strncmp(mass, "atan", 4) == 0) {
    res = push(stack, n, atan_f, 15);
    *step = 4;
  } else if (strncmp(mass, "sqrt", 4) == 0) {
    res = push(stack, n, sqrt_f, 16);
    *step = 4;
  } else if (strncmp(mass, "ln", 2) == 0) {
    res = push(stack, n, ln_f, 17);
    *step = 2;
  } else if (strncmp(mass, "log", 3) == 0) {
    res = push(stack, n, log_f, 18);
    *step = 3;
  } else if (strncmp(mass, "mod", 3) == 0) {
    res = push(stack, n, mod_f, 8);
    *step = 3;
  } else if (*mass == '^') {
    res = push(stack, n, pow_f, 7);
  } else if (*mass == 'x') {
    push(stack, val_x, 0, 0);
  }
  return res;
}

int Parse_unary(Node **stack, int flag, char mass[SIZE]) {
  int res = 0;
  if (*(mass - 1) == '(') {
    if (flag == 1) {
      res = push(stack, 0.0, unary_plus, 19);
    } else if (flag == 2) {
      res = push(stack, 0.0, unary_minus, 9);
    }
  } else {
    if (flag == 1) {
      res = push(stack, 0.0, plus, 5);
    } else if (flag == 2) {
      res = push(stack, 0.0, minus, 6);
    }
  }
  return res;
}

double StringToDouble(char mass[SIZE], int *step) {
  char tmp[SIZE] = {0};
  int i = 0;
  double n = 0;
  while ((*mass >= '0' && *mass <= '9') || *mass == '.') {
    tmp[i] = *mass;
    mass += 1;
    i++;
  }
  *step = strlen(tmp);
  sscanf(tmp, "%lf", &n);
  return n;
}
