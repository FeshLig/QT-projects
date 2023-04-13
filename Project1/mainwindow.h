#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>

class QLabel;
class QLineEdit;
class QPushButton;

class MainWindow : public QDialog {
    Q_OBJECT
    public:
        explicit MainWindow(QWidget *parent = 0);

    signals:
        void findPrevious(const QString &str1, const QString &str2, const QString &str3);

    public slots:
        void findClicked();
        void clearLines();
        void enableAddButton(const QString &text);

    private:
        QLabel *label1;
        QLineEdit *lineEdit1;
        QLabel *label2;
        QLineEdit *lineEdit2;
        QLabel *label3;
        QLineEdit *lineEdit3;
        QPushButton *addButton;
        QPushButton *clearButton;

};

#endif // MAINWINDOW_H
