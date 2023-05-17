#ifndef FORMLOGIN_H
#define FORMLOGIN_H

#include <QDialog>

class QLabel;
class QLineEdit;
class QPushButton;

class formlogin : public QDialog {
  Q_OBJECT

public:
  explicit formlogin(QWidget *parent = 0);

public slots:
  void set_vision();

private:
  QLabel *nameLabel;
  QLabel *emailLabel;
  QLabel *passwordLabel;

  QLineEdit *nameLineEdit;
  QLineEdit *emailLineEdit;
  QLineEdit *passwordLineEdit;

  QPushButton *regularButton;
  QPushButton *closeButton;
};

#endif // FORMLOGIN_H
