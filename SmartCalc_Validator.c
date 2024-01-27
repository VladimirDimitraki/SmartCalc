#include "SmartCalc.h"

int Dot_Validator(char mass[SIZE]) {
  if (mass == NULL || strlen(mass) == 0) {
    return STRING_EMPTY;
  }
  int error = 0;
  int count_dot = 0;
  int digit = 0;
  while (*mass != '\0') {
    if (All_Case(mass) == 0) {
      if (*mass >= '0' && *mass <= '9') {
        digit++;
      } else if (*mass == '.') {
        count_dot++;
        if (!digit) {
          return ERROR_EXPRESSION;
        } else if (*(mass + 1) == '\0') {
          return ERROR_EXPRESSION;
        }
        if (count_dot > 1) {
          error = ERROR_EXPRESSION;
        }
      }
    } else {
      count_dot = 0;
      digit = 0;
      if (*(mass - 1) == '.') {
        return ERROR_EXPRESSION;
      }
    }
    if (*mass == ')') {
      if (*(mass - 1) == '.') {
        return ERROR_EXPRESSION;
      }
    }
    mass += 1;
  }
  return error;
}

int All_Case(char mass[SIZE]) {
  int error = 1;
  if (*mass != 'm' && *mass != '^' && *mass != '+' && *mass != '-' &&
      *mass != '*' && *mass != '/' && *mass != 'x') {
    error = 0;
  }
  return error;
}

int Breackets_Validator(char mass[SIZE]) {
  if (mass == NULL || strlen(mass) == 0) {
    return STRING_EMPTY;
  }
  int count_l = 0;
  int count_r = 0;
  int count = 0;
  int error = 0;
  while (*mass != '\0') {
    if (count < 0) {
      return ERROR_EXPRESSION;
    } else if (*mass == '(') {
      if ((*(mass - 1) >= '0' && *(mass - 1) <= '9')) {
        return ERROR_EXPRESSION;
      }
      if (*(mass + 1) == ')') {
        return ERROR_EXPRESSION;
      }
      count_l++;
      count++;
    } else if (*mass == ')') {
      if (*(mass + 1) == '(') {
        return ERROR_EXPRESSION;
      }
      count_r++;
      count--;
    }
    mass += 1;
  }
  if (count_l != count_r) {
    return ERROR_EXPRESSION;
  }
  return error;
}

int Operator_Validator(char mass[SIZE]) {
  if (mass == NULL || strlen(mass) == 0) {
    return STRING_EMPTY;
  }
  int flag_x = 0;
  int error = 0;
  int i = 0;
  while (*mass != '\0' && !error) {
    if (All_Case(mass) == 1) {
      if ((i == 0 || *(mass + 1) == ')') && *mass != 'x') {
        return ERROR_EXPRESSION;
      }
      if (*mass == 'm') {
        if (Mod_Func(mass) || *(mass - 1) == '(') {
          return ERROR_EXPRESSION;
        }
        if (*(mass + 3) == '\0' || *(mass + 3) == ')' ||
            (*(mass + 3) && !All_Case(mass))) {
          return ERROR_EXPRESSION;
        }
      }
      if (*mass == 'x' && (*(mass - 1) >= '0' && *(mass - 1) <= '9')) {
        return ERROR_EXPRESSION;
      }
      if (*mass == 'x') {
        flag_x = 1;
      } else {
        if (*(mass + 1) == 'x') {
          flag_x = 1;
        }
        *(mass += 1) == '\0' ? error = 1 : error;
        if (All_Case(mass) == 1 && !flag_x) {
          return ERROR_EXPRESSION;
        }
      }
    } else if ((*(mass) >= '0' && *(mass) <= '9') && *(mass + 1) == 'x') {
      return ERROR_EXPRESSION;
    }
    if (Additionaly_Operator_Validator(mass) && !error) {
      return ERROR_EXPRESSION;
    } else if (Trigonometry_Validator(mass) && !error) {
      return ERROR_EXPRESSION;
    }
    mass++;
    i++;
  }
  return error;
}

int Trigonometry_Validator(char mass[SIZE]) {
  int error = 0;
  if (*mass == ')') {
    if (*(mass + 1) == 'c' || *(mass + 1) == 's' || *(mass + 1) == 'a' ||
        *(mass + 1) == 't' || *(mass + 1) == 'l' || *(mass + 1) == 'x') {
      error = 1;
    }
  }
  return error;
}

int Mod_Func(char mass[SIZE]) {
  int error = 1;
  if (*(mass + 3) == 'c' || *(mass + 3) == 's' || *(mass + 3) == 'a' ||
      *(mass + 3) == 't' || *(mass + 3) == 'l' || *(mass + 3) == 'x' ||
      (*(mass + 3) >= '0' && *(mass + 3) <= '9') || *(mass + 3) == '(') {
    error = 0;
  }
  return error;
}

int Additionaly_Operator_Validator(char mass[SIZE]) {
  int error = 0;
  if (*mass == '(') {
    if (*(mass + 1) == '*' || *(mass + 1) == '/' || *(mass + 1) == '^') {
      error = 1;
    }
  }
  return error;
}

int Validator(char mass[SIZE]) {
  if (mass == NULL || strlen(mass) == 0 || strlen(mass) == 256) {
    return STRING_EMPTY;
  }
  int err = 0;
  err = Dot_Validator(mass);
  if (!err) {
    err = Breackets_Validator(mass);
  }
  if (!err) {
    err = Operator_Validator(mass);
  }
  return err;
}