#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tablewindow.h"
#include <QtDebug>
#include <QtSql>
#include <QtDebug>
#include <QtWidgets>
#include <QFileDialog>
#include <QDataStream>
#include <QStringList>
#include <QTextDocument>
#include <QDebug>
#include <QPrinter>
#include <QPrintDialog>
#include <QPrinterInfo>
#include <QPrintPreviewDialog>
#include <sql.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QCommonStyle styleButtons;

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_connectButton_clicked()
{
    QString ip;
    QString port;
    QString base_name;



    mydb = QSqlDatabase::addDatabase("QMYSQL");
    QFile file("./config.cfg");

    if(file.open(QIODevice::ReadOnly |QIODevice::Text))
    {
       while(!file.atEnd())
       {
          QString str = file.readLine();
          QStringList str_n = str.split(":");
          ip = str_n.at(0);
          port = str_n.at(1);
          base_name = str_n.at(2);
          mydb.setHostName(ip);
          mydb.setPort(port.toDouble());
          mydb.setDatabaseName(base_name);
          qDebug() << ip << base_name << port;         

       }
    }

    else

    {
        QMessageBox::critical(NULL,QObject::tr("Ошибка"),tr("Файл конфигурации не найден"));
    }

    mydb.setUserName(ui->loginEdit->text());
    mydb.setPassword(ui->passEdit->text());

    if(!mydb.open())

    QMessageBox::information(this, "Ошибка", mydb.lastError().databaseText(), QMessageBox::Cancel);

    else

    {

        TableWindow *table_window = new TableWindow();

        QSqlQuery query;

        QString login = (ui->loginEdit->text()); // Запись в переменную login значения редактируемого поля loginEdit.

        query.exec("SELECT full_name FROM worker WHERE user_login = \'"+login+"\' "); // Выборка ФИО по логину пользователя.

        query.first();

        QString full_name = query.value(0).toString(); // Запись результата запроса в переменную.

        table_window->show(); // Показ формы table_window.

        qDebug() << full_name;
        qDebug() << login;

        connect(this, &MainWindow::sendLog, table_window, &TableWindow::recieveLogin); // Создание связи сигнал-слот, где sendLog - сигнал, receivelogin - слот.
        emit sendLog(full_name); // Посылка сигнала в форму TableWindow, для последущего отображения.

        this->close(); // Закрытие формы MainWindow.

   }
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_questionButton_clicked()
{

}
