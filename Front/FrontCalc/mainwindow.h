#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qcustomplot.h>

#include <QMainWindow>
#include <QVector>

#include "dialog.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "../../SmartCalc.h"

double Calculate(char mass[SIZE], double val_x, int *error);
int Dot_Validator(char mass[SIZE]);
int Validator(char mass[SIZE]);
int Breackets_Validator(char mass[SIZE]);
int Operator_Validator(char mass[SIZE]);
int Validator(char mass[SIZE]);

#ifdef __cplusplus
}
#endif

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  Dialog *dialog_ptr;
  char *str;

 private slots:
  void numbers();
  void operators();
  void eq_B();
  void Clear_Window();
  void Dot();
  void Str_Parse();
  void Trigonometry();
  void on_Button_Credit_clicked();
  void on_Graphic_do_clicked();
};

#endif  // MAINWINDOW_H
