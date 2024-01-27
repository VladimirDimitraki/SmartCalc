#include "mainwindow.h"

#include "dialog.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  ui->Result_Window->setText("");
  dialog_ptr = new Dialog;

  // DIGITS
  connect(ui->Button_0, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->Button_1, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->Button_2, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->Button_3, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->Button_4, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->Button_5, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->Button_6, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->Button_7, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->Button_8, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->Button_9, SIGNAL(clicked()), this, SLOT(numbers()));

  // OPERATIONS
  connect(ui->Button_plus, SIGNAL(clicked()), this, SLOT(operators()));
  connect(ui->Button_minus, SIGNAL(clicked()), this, SLOT(operators()));
  connect(ui->Button_div, SIGNAL(clicked()), this, SLOT(operators()));
  connect(ui->Button_mult, SIGNAL(clicked()), this, SLOT(operators()));
  connect(ui->Button_mul_x, SIGNAL(clicked()), this, SLOT(operators()));
  connect(ui->Button_mod, SIGNAL(clicked()), this, SLOT(operators()));

  // TRIGONOMETRY
  connect(ui->Button_cos, SIGNAL(clicked()), this, SLOT(Trigonometry()));
  connect(ui->Button_sin, SIGNAL(clicked()), this, SLOT(Trigonometry()));
  connect(ui->Button_tan, SIGNAL(clicked()), this, SLOT(Trigonometry()));
  connect(ui->Button_acos, SIGNAL(clicked()), this, SLOT(Trigonometry()));
  connect(ui->Button_asin, SIGNAL(clicked()), this, SLOT(Trigonometry()));
  connect(ui->Button_atan, SIGNAL(clicked()), this, SLOT(Trigonometry()));
  connect(ui->Button_sqrt, SIGNAL(clicked()), this, SLOT(Trigonometry()));
  connect(ui->Button_ln, SIGNAL(clicked()), this, SLOT(Trigonometry()));
  connect(ui->Button_log, SIGNAL(clicked()), this, SLOT(Trigonometry()));

  // EQ
  connect(ui->pushButton_eq, SIGNAL(clicked()), this, SLOT(eq_B()));

  // AC
  connect(ui->Button_AC, SIGNAL(clicked()), this, SLOT(Clear_Window()));

  // Dot
  connect(ui->Button_dot, SIGNAL(clicked()), this, SLOT(Dot()));

  // Brackets
  connect(ui->Button_breackets_l, SIGNAL(clicked()), this, SLOT(operators()));
  connect(ui->Button_breackets_r, SIGNAL(clicked()), this, SLOT(operators()));

  // X_Value
  connect(ui->Button_x, SIGNAL(clicked()), this, SLOT(operators()));

  // Credit_CALC_Buttons
}

MainWindow::~MainWindow() { delete ui; }

// Обработка цифр
void MainWindow::numbers() {
  QPushButton *Button = (QPushButton *)sender();

  ui->Result_Window->setText(ui->Result_Window->text() + Button->text());
  //    ui->Result_Window->setText(ui->Result_Window->text() + " ");
}

// Обработка строки
void MainWindow::Str_Parse() {
  QString string = ui->Result_Window->text();
  QByteArray array = string.toLocal8Bit();
  str = array.data();
}

// Dot_Func
void MainWindow::Dot() {
  QString string = ui->Result_Window->text();
  QByteArray array = string.toLocal8Bit();
  str = array.data();
  ui->Result_Window->setText(ui->Result_Window->text() + ".");
}

// EQ_Button
void MainWindow::eq_B() {
  QString str = ui->Result_Window->text();
  QByteArray Len = str.toLocal8Bit();
  char *Str = Len.data();
  int error = 0;
  QString result;
  if (Validator(Str) == 0) {
    double x_value = ui->doubleSpinBoxX->value();
    double res = Calculate(Str, x_value, &error);
    if (fabs(res) == INFINITY || fabs(res) == NAN || res != res || error == 1) {
      ui->Result_Window->setText("");
    } else {
      result = QString::number(res, 'g', 15);
      ui->Result_Window->setText(result);
    }
  } else {
    ui->Result_Window->clear();
  }
}

// Операторы
void MainWindow::operators() {
  QPushButton *Button = (QPushButton *)sender();

  if (Button->text() == "%") {
    ui->Result_Window->setText(ui->Result_Window->text() + "mod");
  } else if (Button->text() == "+") {
    ui->Result_Window->setText(ui->Result_Window->text() + "+");
  } else if (Button->text() == "*") {
    ui->Result_Window->setText(ui->Result_Window->text() + "*");
  } else if (Button->text() == "-") {
    ui->Result_Window->setText(ui->Result_Window->text() + "-");
  } else if (Button->text() == "/") {
    ui->Result_Window->setText(ui->Result_Window->text() + "/");
  } else if (Button->text() == "x^2") {
    ui->Result_Window->setText(ui->Result_Window->text() + "^");
  } else if (Button->text() == "(") {
    ui->Result_Window->setText(ui->Result_Window->text() + "(");
  } else if (Button->text() == ")") {
    ui->Result_Window->setText(ui->Result_Window->text() + ")");
  } else if (Button->text() == "x") {
    ui->Result_Window->setText(ui->Result_Window->text() + "x");
  }
}

// Triginimetry
void MainWindow::Trigonometry() {
  QPushButton *Button = (QPushButton *)sender();

  QString string = ui->Result_Window->text();
  QByteArray array = string.toLocal8Bit();
  str = array.data();

  if (Button->text() == "cos") {
    ui->Result_Window->setText(ui->Result_Window->text() + "cos(");
  } else if (Button->text() == "sin") {
    ui->Result_Window->setText(ui->Result_Window->text() + "sin(");
  } else if (Button->text() == "tan") {
    ui->Result_Window->setText(ui->Result_Window->text() + "tan(");
  } else if (Button->text() == "acos") {
    ui->Result_Window->setText(ui->Result_Window->text() + "acos(");
  } else if (Button->text() == "asin") {
    ui->Result_Window->setText(ui->Result_Window->text() + "asin(");
  } else if (Button->text() == "atan") {
    ui->Result_Window->setText(ui->Result_Window->text() + "atan(");
  } else if (Button->text() == "sqrt") {
    ui->Result_Window->setText(ui->Result_Window->text() + "sqrt(");
  } else if (Button->text() == "ln") {
    ui->Result_Window->setText(ui->Result_Window->text() + "ln(");
  } else if (Button->text() == "log") {
    ui->Result_Window->setText(ui->Result_Window->text() + "log(");
  }
}

// Clear Window
void MainWindow::Clear_Window() { ui->Result_Window->clear(); }

// Graphic
void MainWindow::on_Graphic_do_clicked() {
  int error;
  double x_val, xBegin, xEnd, h;
  int n;
  QVector<double> x, y;

  QString str = ui->Result_Window->text();
  QByteArray Len = str.toLocal8Bit();
  char *Str = Len.data();

  h = 0.1;

  xBegin = ui->Graph_X->value();
  xEnd = ui->Graph_Y->value();

  x_val = xBegin;
  n = (xEnd - xBegin) / h + 2;

  if (Validator(Str) == 0) {
    for (int i = 0; i < n; i++) {
      x.push_back(x_val);
      y.push_back(Calculate(Str, x_val, &error));
      x_val += h;
    }
  } else {
    ui->Result_Window->clear();
  }
  ui->Graph->xAxis->setRange(xBegin, xEnd);
  ui->Graph->yAxis->setRange(xBegin, xEnd);

  ui->Graph->clearGraphs();
  ui->Graph->addGraph();
  ui->Graph->graph(0)->addData(x, y);
  ui->Graph->replot();
}

// Credit_Button
void MainWindow::on_Button_Credit_clicked() { dialog_ptr->show(); }
