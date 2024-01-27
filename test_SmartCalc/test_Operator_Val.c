#include "test.h"

START_TEST(ERR_OP_0) {
  int error = 0;
  char mass[SIZE] = "11-";
  error = Operator_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(ERR_OP_1) {
  int error = 0;
  char mass[SIZE] = "(--1+1)";
  error = Operator_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(ERR_OP_2) {
  int error = 0;
  char mass[SIZE] = "1-1+9((-1)+(-cos(1-0.5)))";
  error = Operator_Validator(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(ERR_OP_3) {
  int error = 0;
  char mass[SIZE] = "1--1";
  error = Operator_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(ERR_OP_4) {
  int error = 0;
  char mass[SIZE] = "1-1-";
  error = Operator_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(ERR_OP_5) {
  int error = 0;
  char mass[SIZE] = "(-11)-+";
  error = Operator_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(ERR_OP_6) {
  int error = 0;
  char mass[SIZE] = "(11)/(cos(7+))";
  error = Operator_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(ERR_OP_7) {
  int error = 0;
  char mass[SIZE] = "11^2-";
  error = Operator_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(ERR_OP_8) {
  int error = 0;
  char mass[SIZE] = "11^^2";
  error = Operator_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(ERR_OP_9) {
  int error = 0;
  char mass[SIZE] = "11^(^2)";
  error = Operator_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(ERR_OP_10) {
  int error = 0;
  char mass[SIZE] = "11^(-^2)";
  error = Operator_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(ERR_OP_11) {
  int error = 0;
  char mass[SIZE] = "11^(2mod)";
  error = Operator_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(ERR_OP_12) {
  int error = 0;
  char mass[SIZE] = "1mod-1";
  error = Operator_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(ERR_OP_13) {
  int error = 0;
  char mass[SIZE] = "cos(1)cos(1)";
  error = Operator_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(ERR_OP_14) {
  int error = 0;
  char mass[SIZE] = "1mod2mod";
  error = Operator_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(ERR_OP_15) {
  int error = 0;
  char mass[SIZE] = "cos(1)+cos(1)modtan(1)-acos(-1)";
  error = Operator_Validator(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(ERR_OP_16) {
  int error = 0;
  char mass[SIZE] = "1-1+9(-1+(-cos(1-)))";
  error = Operator_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(ERR_OP_17) {
  int error = 0;
  char mass[SIZE] = "1^-1";
  error = Operator_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(ERR_OP_18) {
  int error = 0;
  char mass[SIZE] = "1-mod2mod";
  error = Operator_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(ERR_OP_19) {
  int error = 0;
  char mass[SIZE] = "-(-1)+tan(1)";
  error = Operator_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(ERR_OP_20) {
  int error = 0;
  char mass[SIZE] = "5000.0000-(-1)+tan(1)^2/(-2)*1+398mod3mod2";
  error = Operator_Validator(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(ERR_OP_21) {
  int error = 0;
  char mass[SIZE] = "cos(1)^sqrt(1)";
  error = Operator_Validator(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(ERR_OP_22) {
  int error = 0;
  char mass[SIZE] = "acos(1)ln(1)";
  error = Operator_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(ERR_OP_23) {
  int error = 0;
  char mass[SIZE] = "acos(1)modln(1)";
  error = Operator_Validator(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(ERR_OP_24) {
  int error = 0;
  char mass[SIZE] = "398mod3mod2mod";
  error = Operator_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(ERR_OP_25) {
  int error = 0;
  char mass[SIZE] = "mod";
  error = Operator_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(ERR_OP_26) {
  int error = 0;
  char mass[SIZE] = "cos(1)";
  error = Operator_Validator(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(ERR_OP_27) {
  int error = 0;
  char mass[SIZE] = "cos(3)mod1";
  error = Operator_Validator(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(ERR_OP_28) {
  int error = 0;
  char mass[SIZE] = "";
  error = Operator_Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(ERR_OP_29) {
  int error = 0;
  char mass[SIZE] = "cos(3)mod(-1)";
  error = Operator_Validator(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

// VALIDATOR ALL

START_TEST(ERR_OP_30) {
  int error = 0;
  char mass[SIZE] = "sin(1)-(-2*x)/x-(-1)mod(x^(-2))";
  error = Validator(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(ERR_OP_31) {
  int error = 0;
  char mass[SIZE] = "x";
  error = Validator(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(ERR_OP_32) {
  int error = 0;
  char mass[SIZE] = "x+x";
  error = Validator(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(ERR_OP_33) {
  int error = 0;
  char mass[SIZE] = "x^(-1)";
  error = Validator(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(ERR_OP_34) {
  int error = 0;
  char mass[SIZE] = "(-3.00009mod2modx)^xmodacos(x)";
  error = Validator(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(ERR_OP_35) {
  int error = 0;
  char mass[SIZE] = "9*x";
  error = Validator(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(ERR_OP_36) {
  int error = 0;
  char mass[SIZE] = "x^x";
  error = Validator(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(ERR_OP_37) {
  int error = 0;
  char mass[SIZE] = "x^xmodx(-2)modx";
  error = Validator(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(ERR_OP_38) {
  int error = 0;
  char mass[SIZE] = "asin(1)^xmodx(-2)modx";
  error = Validator(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(ERR_OP_39) {
  int error = 0;
  char mass[SIZE] = "atan(1)^log(2)modx-ln(10)";
  error = Validator(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(ERR_OP_40) {
  int error = 0;
  char mass[SIZE] = "sin(cos(tan(x)))";
  error = Validator(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(ERR_OP_41) {
  int error = 0;
  char mass[SIZE] = "4(4)-(5)";
  error = Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

START_TEST(ERR_OP_42) {
  int error = 0;
  char mass[SIZE] = "(x^2)";
  error = Validator(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(ERR_OP_43) {
  int error = 0;
  char mass[SIZE] = "(x)";
  error = Validator(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

START_TEST(ERR_OP_44) {
  int error = 0;
  char mass[SIZE] = "(-x^2)";
  error = Validator(mass);
  ck_assert_int_eq(0, error);
}
END_TEST

// 256 symbos
START_TEST(ERR_OP_45) {
  int error = 0;
  char mass[SIZE] =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "1111111111111111111111111111111111111111";
  error = Validator(mass);
  ck_assert_int_eq(ERROR_EXPRESSION, error);
}
END_TEST

Suite *Errors_Op(void) {
  Suite *s = suite_create("\033[45m-=OP_VALIDATOR=-\033[0m");
  TCase *tc1_1 = tcase_create("OP_VALIDATOR: ");

  suite_add_tcase(s, tc1_1);

  tcase_add_test(tc1_1, ERR_OP_0);
  tcase_add_test(tc1_1, ERR_OP_1);
  tcase_add_test(tc1_1, ERR_OP_2);
  tcase_add_test(tc1_1, ERR_OP_3);
  tcase_add_test(tc1_1, ERR_OP_4);
  tcase_add_test(tc1_1, ERR_OP_5);
  tcase_add_test(tc1_1, ERR_OP_6);
  tcase_add_test(tc1_1, ERR_OP_7);
  tcase_add_test(tc1_1, ERR_OP_8);
  tcase_add_test(tc1_1, ERR_OP_9);
  tcase_add_test(tc1_1, ERR_OP_10);
  tcase_add_test(tc1_1, ERR_OP_11);
  tcase_add_test(tc1_1, ERR_OP_12);
  tcase_add_test(tc1_1, ERR_OP_13);
  tcase_add_test(tc1_1, ERR_OP_14);
  tcase_add_test(tc1_1, ERR_OP_15);
  tcase_add_test(tc1_1, ERR_OP_16);
  tcase_add_test(tc1_1, ERR_OP_17);
  tcase_add_test(tc1_1, ERR_OP_18);
  tcase_add_test(tc1_1, ERR_OP_19);
  tcase_add_test(tc1_1, ERR_OP_20);
  tcase_add_test(tc1_1, ERR_OP_21);
  tcase_add_test(tc1_1, ERR_OP_22);
  tcase_add_test(tc1_1, ERR_OP_23);
  tcase_add_test(tc1_1, ERR_OP_24);
  tcase_add_test(tc1_1, ERR_OP_25);
  tcase_add_test(tc1_1, ERR_OP_26);
  tcase_add_test(tc1_1, ERR_OP_27);
  tcase_add_test(tc1_1, ERR_OP_28);
  tcase_add_test(tc1_1, ERR_OP_29);
  tcase_add_test(tc1_1, ERR_OP_30);
  tcase_add_test(tc1_1, ERR_OP_31);
  tcase_add_test(tc1_1, ERR_OP_32);
  tcase_add_test(tc1_1, ERR_OP_33);
  tcase_add_test(tc1_1, ERR_OP_34);
  tcase_add_test(tc1_1, ERR_OP_35);
  tcase_add_test(tc1_1, ERR_OP_36);
  tcase_add_test(tc1_1, ERR_OP_37);
  tcase_add_test(tc1_1, ERR_OP_38);
  tcase_add_test(tc1_1, ERR_OP_39);
  tcase_add_test(tc1_1, ERR_OP_40);
  tcase_add_test(tc1_1, ERR_OP_41);
  tcase_add_test(tc1_1, ERR_OP_42);
  tcase_add_test(tc1_1, ERR_OP_43);
  tcase_add_test(tc1_1, ERR_OP_44);
  tcase_add_test(tc1_1, ERR_OP_45);

  return s;
}