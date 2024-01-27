#include "SmartCalc.h"

int push(Node **head, double num, int priority, int type) {
  Node *tmp = (Node *)malloc(sizeof(Node));
  if (tmp == NULL) {
    return STACK_OVERFLOW;
  }
  tmp->priority = priority;
  tmp->type = type;
  tmp->val = num;
  tmp->next = *head;
  *head = tmp;
  return 0;
}

int push_back(Node **reserve, double num, int priority, int type) {
  Node *new_n = (Node *)malloc(sizeof(Node));
  new_n->priority = priority;
  new_n->type = type;
  new_n->val = num;

  new_n->next = NULL;

  if (*reserve == NULL) {
    *reserve = new_n;
    return STACK_OVERFLOW;
  }
  Node *new_node = *reserve;
  while (new_node->next != NULL) {
    new_node = new_node->next;
  }
  new_node->next = new_n;
  return 0;
}

int pop(Node **head) {
  if (*head == NULL) {
    return STACK_UNDERFLOW;
  }
  Node *out = *head;
  *head = (*head)->next;
  free(out);
  return 0;
}

double peek_num(Node **head) { return (*head)->val; }

void Remove_stack(Node **stack) {
  Node *tmp;
  if (stack) {
    while (*stack != NULL) {
      tmp = (*stack)->next;
      free(*stack);
      *stack = tmp;
    }
  }
}

int Ineverse_stack(Node **stack_curr) {
  if (stack_curr == NULL || (*stack_curr)->next == NULL) {
    return STACK_OVERFLOW;
  }
  Node *prev = NULL;
  Node *current = *stack_curr;
  Node *next = NULL;
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *stack_curr = prev;
  return 0;
}