#ifndef TEST_SMARTCALC
#define TEST_SMARTCALC

#include <check.h>

#include "../SmartCalc.h"

Suite *ReversePolishNotation(void);
Suite *Errors_Dot(void);
Suite *Errors_Breackets(void);
Suite *Errors_Op(void);

#endif