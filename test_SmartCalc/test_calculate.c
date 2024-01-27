#include "test.h"

START_TEST(RPN_TEST_0) {
  Node *input = NULL;
  Node *output = NULL;

  int error = 0;
  double result = -36.0200007;

  char string[SIZE] = "13.01 - 1.09 - 6.0 - ((0.0000001 * 7) + 6 * (9 - 2.01))";

  error = Reverse_polish_notation(&input, &output, string, 0);

  ck_assert_int_eq(0, error);
  ck_assert_double_eq_tol(result, output->val, 8);

  Remove_stack(&input);
  Remove_stack(&output);
}
END_TEST

START_TEST(RPN_TEST_1) {
  Node *input = NULL;
  Node *output = NULL;

  int error = 0;
  double result = -4.99621328606;

  char string[SIZE] =
      "(-((0.0000001 * 7) + 6 * (9 - 2.01) / 8.4 + (0.32 ^ 5)))";

  error = Reverse_polish_notation(&input, &output, string, 0);

  ck_assert_int_eq(0, error);
  ck_assert_double_eq_tol(result, output->val, 8);

  Remove_stack(&input);
  Remove_stack(&output);
}
END_TEST

START_TEST(RPN_TEST_2) {
  Node *input = NULL;
  Node *output = NULL;

  int error = 0;
  double result = -744.5;

  char string[SIZE] = "77 mod 4 - ((3 * (3 ^ 6)) - 700) / 24 * 12 - 2";

  error = Reverse_polish_notation(&input, &output, string, 0);

  ck_assert_int_eq(0, error);
  ck_assert_double_eq_tol(result, output->val, 8);

  Remove_stack(&input);
  Remove_stack(&output);
}
END_TEST

START_TEST(RPN_TEST_3) {
  Node *input = NULL;
  Node *output = NULL;

  int error = 0;
  double result = -52917.0091791;

  char string[SIZE] = "(-569.0000987) * (99 - 6)";

  error = Reverse_polish_notation(&input, &output, string, 0);

  ck_assert_int_eq(0, error);
  ck_assert_double_eq_tol(result, output->val, 8);

  Remove_stack(&input);
  Remove_stack(&output);
}
END_TEST

START_TEST(RPN_TEST_4) {
  Node *input = NULL;
  Node *output = NULL;

  int error = 0;
  double result = 63.52687747;

  char string[SIZE] = "88 + (2 ^ 2) * (-569.0000987) / (99 - 6)";

  error = Reverse_polish_notation(&input, &output, string, 0);

  ck_assert_int_eq(0, error);
  ck_assert_double_eq_tol(result, output->val, 8);

  Remove_stack(&input);
  Remove_stack(&output);
}
END_TEST

START_TEST(RPN_TEST_5) {
  Node *input = NULL;
  Node *output = NULL;

  int error = 0;
  double result = -7.0370370;

  char string[SIZE] = "(-7.0) + (-3 ^ (-3))";

  error = Reverse_polish_notation(&input, &output, string, 0);

  ck_assert_int_eq(0, error);
  ck_assert_double_eq_tol(result, output->val, 8);

  Remove_stack(&input);
  Remove_stack(&output);
}
END_TEST

START_TEST(RPN_TEST_6) {
  Node *input = NULL;
  Node *output = NULL;

  int error = 0;
  double result = -3.8376598;

  char string[SIZE] =
      "(-cos(3)) - (-cos(1)) + 4 / 2 - (sin(1))  * 6.09 / (-tan(2) / acos(-1)";

  error = Reverse_polish_notation(&input, &output, string, 0);

  ck_assert_int_eq(0, error);
  ck_assert_double_eq_tol(result, output->val, 8);

  Remove_stack(&input);
  Remove_stack(&output);
}
END_TEST

START_TEST(RPN_TEST_7) {
  Node *input = NULL;
  Node *output = NULL;

  int error = 0;
  double result = -6794.53374717;

  char string[SIZE] =
      "(-6696.0009867) + 1 / 4 / 2 / 1.3 * 5.0009 + (-56) + (-sqrt(9.9)) - 99 "
      "+ 1.4 ^ (-6) - 5 + 8 ^ 2";

  error = Reverse_polish_notation(&input, &output, string, 0);

  ck_assert_int_eq(0, error);
  ck_assert_double_eq_tol(result, output->val, 8);

  Remove_stack(&input);
  Remove_stack(&output);
}
END_TEST

START_TEST(RPN_TEST_8) {
  Node *input = NULL;
  Node *output = NULL;

  int error = 0;
  double result = 3.5759962;

  char string[SIZE] =
      "(-cos(3)) - (-cos(1)) + 4 / 2 - (sin(1)) + 1 ^ 2.0000007 * 6.09 / "
      "(-tan(2)) / acos(-1)";

  error = Reverse_polish_notation(&input, &output, string, 0);

  ck_assert_int_eq(0, error);
  ck_assert_double_eq_tol(result, output->val, 8);

  Remove_stack(&input);
  Remove_stack(&output);
}
END_TEST

START_TEST(RPN_TEST_9) {
  Node *input = NULL;
  Node *output = NULL;

  int error = 0;
  double result = -4.9;

  char string[SIZE] = "(-1) + (-1) + (-1) - 1.9 - (-1) - 1";

  error = Reverse_polish_notation(&input, &output, string, 0);

  ck_assert_int_eq(0, error);
  ck_assert_double_eq_tol(result, output->val, 8);

  Remove_stack(&input);
  Remove_stack(&output);
}
END_TEST

START_TEST(RPN_TEST_10) {
  Node *input = NULL;
  Node *output = NULL;

  int error = 0;
  double result = 0.6663667;

  char string[SIZE] = "cos(sin(1))";

  error = Reverse_polish_notation(&input, &output, string, 0);

  ck_assert_int_eq(0, error);
  ck_assert_double_eq_tol(result, output->val, 8);

  Remove_stack(&input);
  Remove_stack(&output);
}
END_TEST

START_TEST(RPN_TEST_11) {
  Node *input = NULL;
  Node *output = NULL;

  int error = 0;
  double result = 4096;

  char string[SIZE] = "8 ^ 2 ^ 2";

  error = Reverse_polish_notation(&input, &output, string, 0);

  ck_assert_int_eq(0, error);
  ck_assert_double_eq_tol(result, output->val, 8);

  Remove_stack(&input);
  Remove_stack(&output);
}
END_TEST

START_TEST(RPN_TEST_12) {
  Node *input = NULL;
  Node *output = NULL;

  int error = 0;
  double result = 8;

  char string[SIZE] = "(+8-(-9))-(+9)";

  error = Reverse_polish_notation(&input, &output, string, 0);

  ck_assert_int_eq(0, error);
  ck_assert_double_eq_tol(result, output->val, 8);

  Remove_stack(&input);
  Remove_stack(&output);
}
END_TEST

START_TEST(RPN_TEST_13) {
  Node *input = NULL;
  Node *output = NULL;

  int error = 0;
  double result = -1;

  char string[SIZE] = "(+8-9)";

  error = Reverse_polish_notation(&input, &output, string, 0);

  ck_assert_int_eq(0, error);
  ck_assert_double_eq_tol(result, output->val, 8);

  Remove_stack(&input);
  Remove_stack(&output);
}
END_TEST

START_TEST(RPN_TEST_14) {
  Node *input = NULL;
  Node *output = NULL;

  int error = 0;
  double result = -13.0700007;

  char string[SIZE] =
      "3 * (8.0987 / 8.0987) - 65.02 + 13.01 - 6.0 - (0.0000001 * 7) + 6 * (9 "
      "- 2.01)";

  error = Reverse_polish_notation(&input, &output, string, 0);

  ck_assert_int_eq(0, error);
  ck_assert_double_eq_tol(result, output->val, 8);

  Remove_stack(&input);
  Remove_stack(&output);
}
END_TEST

START_TEST(RPN_TEST_15) {
  Node *input = NULL;
  Node *output = NULL;

  int error = 0;
  double result = 4;

  char string[SIZE] = "(-2)^2";

  error = Reverse_polish_notation(&input, &output, string, 0);

  ck_assert_int_eq(0, error);
  ck_assert_double_eq_tol(result, output->val, 8);

  Remove_stack(&input);
  Remove_stack(&output);
}
END_TEST

START_TEST(RPN_TEST_16) {
  Node *input = NULL;
  Node *output = NULL;

  int error = 0;
  double result = -4;

  char string[SIZE] = "(-2)-2";

  error = Reverse_polish_notation(&input, &output, string, 0);

  ck_assert_int_eq(0, error);
  ck_assert_double_eq_tol(result, output->val, 8);

  Remove_stack(&input);
  Remove_stack(&output);
}
END_TEST

Suite *ReversePolishNotation(void) {
  Suite *s = suite_create("\033[45m-=SMART CALC=-\033[0m");
  TCase *tc1_1 = tcase_create("SmartCalc RPN: ");

  suite_add_tcase(s, tc1_1);

  tcase_add_test(tc1_1, RPN_TEST_0);
  tcase_add_test(tc1_1, RPN_TEST_1);
  tcase_add_test(tc1_1, RPN_TEST_2);
  tcase_add_test(tc1_1, RPN_TEST_3);
  tcase_add_test(tc1_1, RPN_TEST_4);
  tcase_add_test(tc1_1, RPN_TEST_5);
  tcase_add_test(tc1_1, RPN_TEST_6);
  tcase_add_test(tc1_1, RPN_TEST_7);
  tcase_add_test(tc1_1, RPN_TEST_8);
  tcase_add_test(tc1_1, RPN_TEST_9);
  tcase_add_test(tc1_1, RPN_TEST_10);
  tcase_add_test(tc1_1, RPN_TEST_11);
  tcase_add_test(tc1_1, RPN_TEST_12);
  tcase_add_test(tc1_1, RPN_TEST_13);
  tcase_add_test(tc1_1, RPN_TEST_14);
  tcase_add_test(tc1_1, RPN_TEST_15);
  tcase_add_test(tc1_1, RPN_TEST_16);

  return s;
}
