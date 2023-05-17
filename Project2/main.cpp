#include <QApplication>

#include "formlogin.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  formlogin *dialog = new formlogin;
  dialog->show();
  return app.exec();
}
