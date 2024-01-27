#include "test.h"

START_TEST(Dot_0) {
  int error = 0;
  char mass[SIZE] = "1.1 -. 1.1";
  error = Dot_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(Dot_1) {
  int error = 0;
  char mass[SIZE] = "1.1 - 1.1";
  error = Dot_Validator(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(Dot_2) {
  int error = 0;
  char mass[SIZE] = "11.- 1.1";
  error = Dot_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(Dot_3) {
  int error = 0;
  char mass[SIZE] = "11 - 1.1";
  error = Dot_Validator(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(Dot_4) {
  int error = 0;
  char mass[SIZE] = "11-.11";
  error = Dot_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(Dot_5) {
  int error = 0;
  char mass[SIZE] = "1.1-11.";
  error = Dot_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(Dot_6) {
  int error = 0;
  char mass[SIZE] = "1.1-11";
  error = Dot_Validator(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(Dot_7) {
  int error = 0;
  char mass[SIZE] = "1..1-11";
  error = Dot_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(Dot_8) {
  int error = 0;
  char mass[SIZE] = "1.1.-1.1";
  error = Dot_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(Dot_9) {
  int error = 0;
  char mass[SIZE] = "11.-1.1";
  error = Dot_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(Dot_10) {
  int error = 0;
  char mass[SIZE] = ".11-11";
  error = Dot_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(Dot_11) {
  int error = 0;
  char mass[SIZE] = ".cos(1)";
  error = Dot_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(Dot_12) {
  int error = 0;
  char mass[SIZE] = "acos(1.)";
  error = Dot_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(Dot_13) {
  int error = 0;
  char mass[SIZE] = "acos(1.1.)";
  error = Dot_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(Dot_14) {
  int error = 0;
  char mass[SIZE] = "acos(1.1-3.3-.)";
  error = Dot_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(Dot_15) {
  int error = 0;
  char mass[SIZE] = "";
  error = Dot_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

Suite *Errors_Dot(void) {
  Suite *s = suite_create("\033[45m-=VALIDATOR_DOT=-\033[0m");
  TCase *tc1_1 = tcase_create("SmartCalc Dot_Validator: ");

  suite_add_tcase(s, tc1_1);

  tcase_add_test(tc1_1, Dot_0);
  tcase_add_test(tc1_1, Dot_1);
  tcase_add_test(tc1_1, Dot_2);
  tcase_add_test(tc1_1, Dot_3);
  tcase_add_test(tc1_1, Dot_4);
  tcase_add_test(tc1_1, Dot_5);
  tcase_add_test(tc1_1, Dot_6);
  tcase_add_test(tc1_1, Dot_7);
  tcase_add_test(tc1_1, Dot_8);
  tcase_add_test(tc1_1, Dot_9);
  tcase_add_test(tc1_1, Dot_10);
  tcase_add_test(tc1_1, Dot_11);
  tcase_add_test(tc1_1, Dot_12);
  tcase_add_test(tc1_1, Dot_13);
  tcase_add_test(tc1_1, Dot_14);
  tcase_add_test(tc1_1, Dot_15);

  return s;
}