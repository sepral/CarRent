#ifndef TABLEWINDOW_H
#define TABLEWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <mainwindow.h>
#include "printwindow.h"
#include <QPrinter>


namespace Ui {
class TableWindow;
}

class TableWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TableWindow(QWidget *parent = 0);
    ~TableWindow();


public slots:
        void recieveLogin(QString str);
        void on_dumpButton_clicked(QString ip, QString port, QString base_name);


private slots:
    void on_tabWidget_tabBarClicked(int index);

    void on_tabWidget_currentChanged(int index);

    void showAutoTable();

    void showClientTable();

    void showContractTable();

    void showDtpTable();

    void showInspectTable();

    void showInsurerTable();

    void showPtsTable();

    void showRegTable();

    void showWorkerTable();

    void on_saveButton_clicked();

    void on_pushButton_clicked();

    void on_export_button_clicked();

    void on_pushButton_2_clicked();

    void on_addButton_clicked();

    void on_delButton_clicked();

    void on_exportButton_clicked();

    void on_search_edit_textChanged(const QString &arg1);

    void showBrandTable();

    void showModelTable();

    void showControlTable();

    void updateAutoTable();

    void on_printButton_clicked();

    void print(QPrinter* printer);

    void on_importButton_clicked();

    void on_tableViewAuto_clicked(const QModelIndex &index);

    void on_searchEdit_textChanged(const QString &arg1);

    void showPrintWindow();

    void on_resetButton_clicked();


    void on_autoComboBox_activated(const QString &arg1);

    void on_autoComboBox_activated(int index);

    void on_autoComboBox_highlighted(const QString &arg1);

    void on_clientComboBox_activated(const QString &arg1);

    void on_printContrButton_clicked();

private:

    Ui::TableWindow *ui;
    QSqlQueryModel *model1;
    QSqlRelationalTableModel * rTableModel;
    QItemDelegate * delegate;
    QString fileName;
    QCompleter *mycompletear;
    QTextStream stream;
    QStringList linesForExport;
    QString position;
    QSqlTableModel *csvModel;
    PrintWindow *print_window;

};


#endif // TABLEWINDOW_H
