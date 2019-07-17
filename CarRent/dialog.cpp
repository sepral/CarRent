#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(MainWindow *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    model1 = new QSqlQueryModel(this);
    model1->setQuery("SELECT * FROM auto");
    ui->tableView->setModel(model1);

}

Dialog::~Dialog()
{

    delete ui;
}


void Dialog::on_pushButton_clicked()
{

}

