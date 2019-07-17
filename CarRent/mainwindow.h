#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QMessageBox>
#include <tablewindow.h>

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT
    QSqlDatabase mydb;
    int QT_DEBUG_PLUGINS = 1;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void sendLog(QString str);
    void sendDbInfo(QString ip, QString host, QString base_name);


private slots:
    void on_connectButton_clicked();

    void on_pushButton_clicked();

    void on_questionButton_clicked();

private:

    Ui::MainWindow *ui;
    QString log;
};

#endif // MAINWINDOW_H
