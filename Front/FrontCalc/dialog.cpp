#include "dialog.h"

#include <QDebug>

#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog) {
  ui->setupUi(this);
}

Dialog::~Dialog() { delete ui; }

void Dialog::on_Credit_Button_Calculate_clicked() {
  //    QPushButton *Button_Credit_calc = (QPushButton *)sender();
  double CreditBalance, CreditPeriod, InterestRate, tmp_Last_Payment;
  int type = 0, Y_M = 0;

  CreditBalance = ui->Balance_Window->value();
  CreditPeriod = ui->Period_window->value();
  InterestRate = ui->Procent_Window->value();

  if (ui->Creditperiod_Year->isChecked()) {
    Y_M = 1;
  } else if (ui->Creditperiod_Mounth->isChecked()) {
    Y_M = 2;
  } else {
    Y_M = 0;
  }

  if (ui->Annuities->isChecked()) {
    type = 1;
  } else if (ui->Differentiated->isChecked()) {
    type = 2;
  } else {
    type = 0;
  }
  qDebug() << "typre = " << type << "y_m = " << Y_M << CreditBalance
           << CreditPeriod << InterestRate;

  if (Credit_Calc(&CreditBalance, &CreditPeriod, &InterestRate,
                  &tmp_Last_Payment, Y_M, type) == 0) {
    ui->Mounthpayment_score->setText(QString::number(CreditPeriod, 'f', 2));
    ui->AccuredInterest_score->setText(QString::number(InterestRate, 'f', 2));
    ui->TotalPayment_score->setText(QString::number(CreditBalance, 'f', 2));
    ui->Mounthpayment_score_lust->setText(
        QString::number(tmp_Last_Payment, 'f', 2));
  }
}

void Dialog::on_Credit_Button_Calculate_2_clicked() {
  ui->Balance_Window->setValue(0);
  ui->Period_window->setValue(0);
  ui->Procent_Window->setValue(0);
  ui->Mounthpayment_score->setText("0");
  ui->AccuredInterest_score->setText("0");
  ui->TotalPayment_score->setText("0");
  ui->Mounthpayment_score_lust->setText("0");
}
