#include "SmartCalc.h"

int Credit_Calc(double *CreditBalance, double *CreditPeriod,
                double *InterestRate, double *tmp_Last_payment, int Y_M,
                int type) {
  int error = 0;
  double n = 0;
  double r = 0;
  if (Y_M == 0 || type == 0 || *CreditBalance == 0 || *CreditPeriod == 0 ||
      *InterestRate == 0) {
    return error = 1;
  }
  if (Y_M == 1) {
    n = *CreditPeriod * 12;
  } else {
    n = *CreditPeriod;
  }
  // annuities
  if (type == 1) {
    r = *InterestRate / 100 / 12;
    double P = (*CreditBalance * r) / (1 - pow(1 + r, -n));
    double TotalPayment = P * n;
    double TotalInterest = TotalPayment - *CreditBalance;
    *CreditPeriod = P;
    *InterestRate = TotalInterest;
    *CreditBalance = TotalPayment;
    // differentiated
  } else {
    r = *InterestRate / 100 / 12;
    double MounthPayment = 0, Procent = 0, tmp = *CreditBalance;
    double TotalPayment = 0;
    MounthPayment = *CreditBalance / n;
    double tmp_Interest = 0;
    for (int i = 0; i < n; i++) {
      Procent = *CreditBalance * r;
      *CreditBalance -= MounthPayment;
      tmp_Interest += Procent;
      if (i == 0) {
        *CreditPeriod = MounthPayment + Procent;
      } else if (i == n - 1) {
        *tmp_Last_payment = MounthPayment + Procent;
      }
    }
    TotalPayment = tmp + tmp_Interest;

    *InterestRate = tmp_Interest;
    *CreditBalance = TotalPayment;
  }
  return error;
}