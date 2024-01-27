#include "test.h"

START_TEST(Breackets_ERR_0) {
  int error = 0;
  char mass[SIZE] = "(11 - 1.1))";
  error = Breackets_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(Breackets_ERR_1) {
  int error = 0;
  char mass[SIZE] = "((1))";
  error = Breackets_Validator(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(Breackets_ERR_2) {
  int error = 0;
  char mass[SIZE] = "()(1)-(1))";
  error = Breackets_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(Breackets_ERR_3) {
  int error = 0;
  char mass[SIZE] = "()";
  error = Breackets_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(Breackets_ERR_4) {
  int error = 0;
  char mass[SIZE] = "(-1 * )1())";
  error = Breackets_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(Breackets_ERR_5) {
  int error = 0;
  char mass[SIZE] = ")";
  error = Breackets_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(Breackets_ERR_6) {
  int error = 0;
  char mass[SIZE] = "(";
  error = Breackets_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(Breackets_ERR_7) {
  int error = 0;
  char mass[SIZE] = "(1(";
  error = Breackets_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(Breackets_ERR_8) {
  int error = 0;
  char mass[SIZE] = "(1)(2)";
  error = Breackets_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(Breackets_ERR_9) {
  int error = 0;
  char mass[SIZE] = "cos((1))-(1))";
  error = Breackets_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(Breackets_ERR_10) {
  int error = 0;
  char mass[SIZE] = "cos(1(";
  error = Breackets_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(Breackets_ERR_11) {
  int error = 0;
  char mass[SIZE] = "";
  error = Breackets_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

Suite *Errors_Breackets(void) {
  Suite *s = suite_create("\033[45m-=VALIDATOR_BREACKETS=-\033[0m");
  TCase *tc1_1 = tcase_create("Breackets_Validator: ");

  suite_add_tcase(s, tc1_1);

  tcase_add_test(tc1_1, Breackets_ERR_0);
  tcase_add_test(tc1_1, Breackets_ERR_1);
  tcase_add_test(tc1_1, Breackets_ERR_2);
  tcase_add_test(tc1_1, Breackets_ERR_3);
  tcase_add_test(tc1_1, Breackets_ERR_4);
  tcase_add_test(tc1_1, Breackets_ERR_5);
  tcase_add_test(tc1_1, Breackets_ERR_6);
  tcase_add_test(tc1_1, Breackets_ERR_7);
  tcase_add_test(tc1_1, Breackets_ERR_8);
  tcase_add_test(tc1_1, Breackets_ERR_9);
  tcase_add_test(tc1_1, Breackets_ERR_10);
  tcase_add_test(tc1_1, Breackets_ERR_11);

  return s;
}
