#include "mainwindow.h"
#include <QApplication>
#include <Qt>
#include <QMessageBox>
#include "mainwindow.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow *w = new MainWindow;   // Указатель на главное окно

    w->setMinimumHeight(140);         // Задание минимальной длины окна
    w->setMaximumHeight(140);         // Задание максимальной длины окна
    w->setMinimumWidth(150);          // Задание минимальной ширины окна
    w->setMaximumWidth(150);          // Задание максимальной ширины окна

    // Скрытие системных кнопок
    w->setWindowFlags( Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    w->show();

    return a.exec();


}
