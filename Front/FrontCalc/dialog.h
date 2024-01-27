#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#ifdef __cplusplus
extern "C" {
#endif
#include "../../SmartCalc.h"

int Credit_Calc(double *CreditBalance, double *CreditPeriod,
                double *InterestRate, double *tmp_Last_payment, int Y_M,
                int type);

#ifdef __cplusplus
}
#endif

namespace Ui {
class Dialog;
}

class Dialog : public QDialog {
  Q_OBJECT

 public:
  explicit Dialog(QWidget *parent = nullptr);
  ~Dialog();

 private slots:

  void on_Credit_Button_Calculate_clicked();
  void on_Credit_Button_Calculate_2_clicked();

 private:
  Ui::Dialog *ui;
};

#endif  // DIALOG_H
