#include "formlogin.h"
#include <QtWidgets>

formlogin::formlogin(QWidget *parent) : QDialog(parent) {
  QRegularExpression emailRegular(
      "([a-zA-Z0-9_\\-\\.]+)@([a-zA-Z0-9_.-])+\\.([a-zA-Z]{2,4}|[0-9]{1,3})");
  QValidator *emailValidator =
      new QRegularExpressionValidator(emailRegular, this);

  QRegularExpression nameRegular("[A-Z][a-z]+");
  QValidator *nameValidator =
      new QRegularExpressionValidator(nameRegular, this);

  QRegularExpression passwordRegular(".{1,6}");
  QValidator *passwordValidator =
      new QRegularExpressionValidator(passwordRegular, this);

  nameLabel = new QLabel("Name");
  nameLineEdit = new QLineEdit;
  nameLineEdit->setValidator(nameValidator);
  nameLabel->setBuddy(nameLineEdit);

  emailLabel = new QLabel(tr("Email"));
  emailLineEdit = new QLineEdit;
  emailLineEdit->setValidator(emailValidator);
  emailLabel->setBuddy(emailLineEdit);

  passwordLabel = new QLabel("Password");
  passwordLineEdit = new QLineEdit;
  passwordLineEdit->setValidator(passwordValidator);
  passwordLabel->setBuddy(passwordLineEdit);

  regularButton = new QPushButton("Register");
  regularButton->setDefault(true);
  regularButton->setEnabled(false);

  closeButton = new QPushButton("Close");
  connect(closeButton, SIGNAL(clicked()), this, SLOT(reject()));
  connect(nameLineEdit, &QLineEdit::textChanged, this, &formlogin::set_vision);
  connect(emailLineEdit, &QLineEdit::textChanged, this, &formlogin::set_vision);
  connect(passwordLineEdit, &QLineEdit::textChanged, this,
          &formlogin::set_vision);
  connect(regularButton, SIGNAL(clicked()), this, SLOT(accept()));

  QVBoxLayout *leftLayout = new QVBoxLayout;
  leftLayout->addWidget(nameLabel);
  leftLayout->addWidget(emailLabel);
  leftLayout->addWidget(passwordLabel);
  leftLayout->addWidget(closeButton);

  QVBoxLayout *rightLayout = new QVBoxLayout;
  rightLayout->addWidget(nameLineEdit);
  rightLayout->addWidget(emailLineEdit);
  rightLayout->addWidget(passwordLineEdit);
  rightLayout->addWidget(regularButton);

  QHBoxLayout *mainLayout = new QHBoxLayout;
  mainLayout->addLayout(leftLayout);
  mainLayout->addLayout(rightLayout);
  setLayout(mainLayout);

  setWindowTitle("Form login");
  setFixedHeight(sizeHint().height());
}

void formlogin::set_vision() {
  regularButton->setEnabled(!(nameLineEdit->text().isEmpty() ||
                              emailLineEdit->text().isEmpty() ||
                              passwordLineEdit->text().isEmpty()));
}
