#ifndef SMARTCALC
#define SMARTCALC

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 257

/*                          MACROS ERRORS                      */
#define STACK_OVERFLOW 1
#define STACK_UNDERFLOW 1
#define STACK_EMPTY 1
#define STRING_EMPTY 1
#define STRING_OVERFLOW 1
#define STRING_OVERFLOW 1
#define ERROR_EXPRESSION 1

typedef struct Node {
  double val;
  int type;
  int priority;
  struct Node *next;
} Node;

typedef enum {
  number,  // 0

  brackets_left = 0,   // 1
  brackets_right = 0,  // 2

  unary_minus = 5,  // type 9
  unary_plus = 5,   // type 19

  pow_f = 6,  // type 7 '^'

  mult = 3,      // type 3
  division = 3,  // type 4
  mod_f = 3,     // type 8

  plus = 2,   // type 5
  minus = 2,  // type 6

  cos_f = 6,   // type 10
  sin_f = 6,   // type 11
  tan_f = 6,   // type 12
  asin_f = 6,  // type 13
  acos_f = 6,  // type 14
  atan_f = 6,  // type 15
  sqrt_f = 6,  // type 16
  ln_f = 6,    // type 17
  log_f = 6,   // type 18
} Priority;

/*                       Polish Notation                       */
int Polish_notation(Node **infix, Node **postfix, char mass[SIZE],
                    double val_x);
int Reverse_polish_notation(Node **input, Node **output, char mass[SIZE],
                            double val_x);

/*                           Priority                          */
int Priority_operation(Node **infix, Node **postfix, Node **reserve);
int breackets_priority(Node **reserve_op, Node **postfix);

/*                          Arithmetic                         */
int SmartCalc_Arithmetic(Node **stack_number, double x, double y, int flag);
int SmartCalc_triginometry(Node **stack_number, Node **output, int unary);

/*                            Parse                            */
int Parse_stack(Node **stack, char mass[SIZE], double val_x);
int Parse_func(Node **stack, char mass[SIZE], int *step, double val_x);
int Parse_unary(Node **stack, int flag, char mass[SIZE]);
double StringToDouble(char mass[SIZE], int *step);

/*                            Stack                            */
int push_back(Node **reserve, double num, int priority, int type);
int push(Node **head, double num, int priority, int type);
int pop(Node **head);
double peek_num(Node **head);
int Ineverse_stack(Node **stack_laufend);

/*                        Remove Stack                         */
void Remove_stack(Node **stack);

/*                          VALIDATOR                          */
int Dot_Validator(char mass[SIZE]);
int All_Case(char mass[SIZE]);
int Breackets_Validator(char mass[SIZE]);
int Operator_Validator(char mass[SIZE]);
int Additionaly_Operator_Validator(char mass[SIZE]);
int Trigonometry_Validator(char mass[SIZE]);
int Mod_Func(char mass[SIZE]);
int Validator(char mass[SIZE]);

/*                          Calculate                          */
double Calculate(char mass[SIZE], double val_x, int *error);

/*                            Credit                           */
int Credit_Calc(double *CreditBalance, double *CreditPeriod,
                double *InterestRate, double *tmp_Last_payment, int Y_M,
                int type);

#endif