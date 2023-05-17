#include <QCoreApplication>
#include <QDebug>
#include <QScriptEngine>

QVariant eval(QString expression);

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);
  QString expression = "2 + 2 * 3";
  QVariant result = eval(expression);
  qDebug() << result.toString();
  return 0;
}

QVariant eval(QString expression) {
  QScriptEngine engine;
  QScriptValue result = engine.evaluate(expression);
  return result.toNumber();
}
