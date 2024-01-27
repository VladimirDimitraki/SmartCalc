#include "SmartCalc.h"

int Polish_notation(Node **infix, Node **postfix, char mass[SIZE],
                    double val_x) {
  int error = 0;
  Node *reserve_op = NULL;
  if (Parse_stack(infix, mass, val_x) != 0) {
    return STRING_EMPTY;
  }
  Ineverse_stack(infix);
  while (*infix != NULL) {
    if ((*infix)->type == number) {
      error = push_back(postfix, (*infix)->val, 0, 0);
    } else if ((*infix)->type == 1) {
      error =
          push(&reserve_op, (*infix)->val, (*infix)->priority, (*infix)->type);
    } else if ((*infix)->type == 2) {
      error = breackets_priority(&reserve_op, postfix);
    } else {
      if (reserve_op == NULL) {
        error = push(&reserve_op, (*infix)->val, (*infix)->priority,
                     (*infix)->type);
      } else {
        error = Priority_operation(infix, postfix, &reserve_op);
      }
    }
    error = pop(infix);
  }
  while (reserve_op != NULL) {
    error = push_back(postfix, reserve_op->val, reserve_op->priority,
                      reserve_op->type);
    error = pop(&reserve_op);
  }
  Remove_stack(&reserve_op);
  return error;
}

int breackets_priority(Node **reserve_op, Node **postfix) {
  int error = 0;
  while ((*reserve_op)->type != 1) {
    error = push_back(postfix, (*reserve_op)->val, (*reserve_op)->priority,
                      (*reserve_op)->type);
    error = pop(reserve_op);
  }
  error = pop(reserve_op);
  return error;
}

int Priority_operation(Node **infix, Node **postfix, Node **reserve) {
  int error = 0;
  int flag = 0;
  if ((*reserve)->type == 7) {
    if ((*infix)->type == 7) {
      flag = 1;
    }
  }
  while (*reserve != NULL && (*reserve)->priority >= (*infix)->priority &&
         !flag) {
    error = push_back(postfix, (*reserve)->val, (*reserve)->priority,
                      (*reserve)->type);
    error = pop(reserve);
  }
  if (*infix != NULL) {
    error = push(reserve, (*infix)->val, (*infix)->priority, (*infix)->type);
  }
  return error;
}
