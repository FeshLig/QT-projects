#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  MainWindow *dialog = new MainWindow;
  dialog->show();
  return app.exec();
}
