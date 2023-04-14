#include "mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) : QDialog(parent) {
  label1 = new QLabel(tr("Constant value"));
  lineEdit1 = new QLineEdit;
  label1->setBuddy(lineEdit1);

  label2 = new QLabel(tr("Formula or notation"));
  lineEdit2 = new QLineEdit;
  label2->setBuddy(lineEdit2);

  label3 = new QLabel(tr("Numeric value"));
  lineEdit3 = new QLineEdit;
  label3->setBuddy(lineEdit3);

  addButton = new QPushButton(tr("&Add"));
  addButton->setDefault(true);
  addButton->setEnabled(false);

  clearButton = new QPushButton(tr("&Clear"));

  connect(lineEdit1, SIGNAL(textChanged(const QString &)), this,
          SLOT(enableAddButton()));
  connect(lineEdit2, SIGNAL(textChanged(const QString &)), this,
          SLOT(enableAddButton()));
  connect(lineEdit3, SIGNAL(textChanged(const QString &)), this,
          SLOT(enableAddButton()));
  connect(addButton, SIGNAL(clicked()), this, SLOT(findClicked()));
  connect(clearButton, SIGNAL(clicked()), this, SLOT(clearLines()));

  QVBoxLayout *topLayout = new QVBoxLayout;
  topLayout->addWidget(label1);
  topLayout->addWidget(lineEdit1);
  topLayout->addWidget(label2);
  topLayout->addWidget(lineEdit2);
  topLayout->addWidget(label3);
  topLayout->addWidget(lineEdit3);

  QHBoxLayout *bottomLayout = new QHBoxLayout;
  bottomLayout->addWidget(clearButton);
  bottomLayout->addWidget(addButton);

  QVBoxLayout *mainLayout = new QVBoxLayout;
  mainLayout->addLayout(topLayout);
  mainLayout->addLayout(bottomLayout);
  setLayout(mainLayout);

  setWindowTitle(tr("MainWindow"));
  setFixedHeight(sizeHint().height());
}

void MainWindow::findClicked() {
  QString text1 = lineEdit1->text();
  QString text2 = lineEdit2->text();
  QString text3 = lineEdit3->text();
  emit createNewLog(text1, text2, text3);
  close();
}

void MainWindow::clearLines() {
  lineEdit1->clear();
  lineEdit2->clear();
  lineEdit3->clear();
}

void MainWindow::enableAddButton() {
  addButton->setEnabled(!(lineEdit1->text().isEmpty() || lineEdit2->text().isEmpty() || lineEdit3->text().isEmpty()));
}
