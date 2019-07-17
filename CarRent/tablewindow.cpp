
#include "tablewindow.h"
#include "ui_tablewindow.h"
#include "mainwindow.h"
#include "printwindow.h"
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

  TableWindow::TableWindow(QWidget * parent):
  QMainWindow(parent),
  ui(new Ui::TableWindow) {

    ui -> setupUi(this);

    ui -> tableViewControl -> hide();

    rTableModel = new QSqlRelationalTableModel(this);
    delegate = new QSqlRelationalDelegate(this);

    ui -> tableViewAuto -> setItemDelegate(delegate);
    ui -> tableViewAuto -> setModel(rTableModel);

  }

TableWindow::~TableWindow() {
  delete ui;
}

class Delegate: public QItemDelegate {
  public: Delegate(QObject * parent = 0): QItemDelegate(parent) {}
  virtual QWidget * createEditor(QWidget * ,
    const QStyleOptionViewItem & ,
      const QModelIndex & ) const {

    return 0;
  }

};

void TableWindow::on_tabWidget_tabBarClicked(int index) {

  if (index == 0) {

    ui -> tableViewControl -> hide();
    ui -> functionBox -> show();
    ui -> tableViewAuto -> show();
    showAutoTable();
  }

  if (index == 1) {

    ui -> tableViewControl -> hide();
    ui -> functionBox -> show();
    ui -> tableViewAuto -> show();
    showClientTable();
  }

  if (index == 2) {

    ui -> tableViewControl -> hide();
    ui -> functionBox -> show();
    ui -> tableViewAuto -> show();
    showContractTable();
  }

  if (index == 3) {

    ui -> tableViewControl -> hide();
    ui -> functionBox -> show();
    ui -> tableViewAuto -> show();
    showWorkerTable();
  }

  if (index == 4) {

    ui -> tableViewControl -> hide();
    ui -> functionBox -> show();
    ui -> tableViewAuto -> show();
    showInsurerTable();
  }

  if (index == 5) {

    ui -> tableViewControl -> hide();
    ui -> functionBox -> show();
    ui -> tableViewAuto -> show();
    showRegTable();
  }

  if (index == 6) {

    ui -> tableViewControl -> hide();
    ui -> functionBox -> show();
    ui -> tableViewAuto -> show();
    showInspectTable();
  }

  if (index == 7) {

    ui -> tableViewControl -> hide();
    ui -> functionBox -> show();
    ui -> tableViewAuto -> show();
    showPtsTable();
  }

  if (index == 8) {

    ui -> tableViewControl -> hide();
    ui -> functionBox -> show();
    ui -> tableViewAuto -> show();
    showDtpTable();
  }

  if (index == 9) {

    ui -> tableViewAuto -> hide();
    ui -> functionBox -> hide();
    ui -> tableViewControl -> show();

    showControlTable();
  }

  if (index == 10) {

    ui -> tableViewControl -> hide();
    ui -> functionBox -> show();
    ui -> tableViewAuto -> show();
    showBrandTable();
  }

  if (index == 11) {

    ui -> tableViewControl -> hide();
    ui -> functionBox -> show();
    ui -> tableViewAuto -> show();
    showModelTable();
  }

}

void TableWindow::showAutoTable() {

  if (position == "Менеджер") {

    rTableModel -> setTable("auto");

    rTableModel -> setJoinMode(QSqlRelationalTableModel::LeftJoin);

    rTableModel -> setHeaderData(1, Qt::Horizontal, "Бренд");
    rTableModel -> setHeaderData(2, Qt::Horizontal, "Модель");
    rTableModel -> setHeaderData(4, Qt::Horizontal, "Год");
    rTableModel -> setHeaderData(3, Qt::Horizontal, "Цвет");

    rTableModel -> setRelation(rTableModel -> fieldIndex("id_brand"), QSqlRelation("brand", "id", "brand_name"));
    rTableModel -> setRelation(rTableModel -> fieldIndex("id_model"), QSqlRelation("models", "id", "model"));

    ui -> tableViewAuto -> setItemDelegateForColumn(1, new Delegate());
    ui -> tableViewAuto -> setItemDelegateForColumn(2, new Delegate());
    ui -> tableViewAuto -> setItemDelegateForColumn(3, new Delegate());
    ui -> tableViewAuto -> setItemDelegateForColumn(4, new Delegate());

    rTableModel -> select();

    ui -> tableViewAuto -> hideColumn(0);
    ui -> tableViewAuto -> hideColumn(5);
    ui -> tableViewAuto -> hideColumn(7);
    ui -> tableViewAuto -> hideColumn(8);
    ui -> tableViewAuto -> hideColumn(9);
    ui -> tableViewAuto -> hideColumn(10);
    ui -> tableViewAuto -> hideColumn(11);

  }

  if (position == "Начальник парка") {

    rTableModel -> setTable("auto");

    rTableModel -> setJoinMode(QSqlRelationalTableModel::LeftJoin);

    rTableModel -> setHeaderData(1, Qt::Horizontal, "Бренд");
    rTableModel -> setHeaderData(2, Qt::Horizontal, "Модель");
    rTableModel -> setHeaderData(4, Qt::Horizontal, "Год");
    rTableModel -> setHeaderData(3, Qt::Horizontal, "Цвет");

    rTableModel -> setRelation(rTableModel -> fieldIndex("id_brand"), QSqlRelation("brand", "id", "brand_name"));
    rTableModel -> setRelation(rTableModel -> fieldIndex("id_model"), QSqlRelation("models", "id", "model"));

    rTableModel -> select();

    updateAutoTable();

    ui -> tableViewAuto -> hideColumn(0);
    ui -> tableViewAuto -> hideColumn(5);
    ui -> tableViewAuto -> hideColumn(7);
    ui -> tableViewAuto -> hideColumn(8);
    ui -> tableViewAuto -> hideColumn(9);
    ui -> tableViewAuto -> hideColumn(10);

  }

}

void TableWindow::showClientTable() {

  if (position == "Менеджер") {

    rTableModel -> setTable("client");

    rTableModel -> setHeaderData(1, Qt::Horizontal, "Имя");
    rTableModel -> setHeaderData(2, Qt::Horizontal, "Фамилия");
    rTableModel -> setHeaderData(3, Qt::Horizontal, "Отчество");
    rTableModel -> setHeaderData(4, Qt::Horizontal, "Серия паспорта");
    rTableModel -> setHeaderData(5, Qt::Horizontal, "Номер паспорта");
    rTableModel -> setHeaderData(6, Qt::Horizontal, "Серия ВУ");
    rTableModel -> setHeaderData(7, Qt::Horizontal, "Номер ВУ");
    rTableModel -> setHeaderData(8, Qt::Horizontal, "Телефон");

    ui -> tableViewAuto -> setItemDelegateForColumn(1, delegate);
    ui -> tableViewAuto -> setItemDelegateForColumn(2, delegate);
    ui -> tableViewAuto -> setItemDelegateForColumn(3, delegate);
    ui -> tableViewAuto -> setItemDelegateForColumn(4, delegate);
    ui -> tableViewAuto -> setItemDelegateForColumn(5, delegate);

    rTableModel -> select();

    ui -> tableViewAuto -> hideColumn(0);
    ui -> tableViewAuto -> hideColumn(9);
    ui -> tableViewAuto -> hideColumn(10);
    ui -> tableViewAuto -> hideColumn(11);
    ui -> tableViewAuto -> hideColumn(12);

  }

  if (position == "Начальник парка") {

    rTableModel -> setTable("client");

    rTableModel -> setHeaderData(1, Qt::Horizontal, "Имя");
    rTableModel -> setHeaderData(2, Qt::Horizontal, "Фамилия");
    rTableModel -> setHeaderData(3, Qt::Horizontal, "Отчество");
    rTableModel -> setHeaderData(4, Qt::Horizontal, "Серия паспорта");
    rTableModel -> setHeaderData(5, Qt::Horizontal, "Номер паспорта");
    rTableModel -> setHeaderData(6, Qt::Horizontal, "Серия ВУ");
    rTableModel -> setHeaderData(7, Qt::Horizontal, "Номер ВУ");
    rTableModel -> setHeaderData(8, Qt::Horizontal, "Телефон");

    rTableModel -> select();

    //SELECT id_brand, id_model FROM auto WHERE id = 1
    //SELECT model FROM models WHERE id = 1 // Accord
    //SELEC T brand_name FROM brand WHERE id = 1 // Alfa Romeo

    ui -> tableViewAuto -> hideColumn(0);
    ui -> tableViewAuto -> hideColumn(9);
    ui -> tableViewAuto -> hideColumn(10);
    ui -> tableViewAuto -> hideColumn(11);
    ui -> tableViewAuto -> hideColumn(12);

  }

}

void TableWindow::showContractTable() {

  QSqlQuery query;
  query.exec();

  rTableModel -> setTable("contract");

  rTableModel -> setHeaderData(1, Qt::Horizontal, "Клиент");
  rTableModel -> setHeaderData(2, Qt::Horizontal, "Менеджер");
  rTableModel -> setHeaderData(3, Qt::Horizontal, "Авто");
  rTableModel -> setHeaderData(4, Qt::Horizontal, "Цена");
  rTableModel -> setHeaderData(5, Qt::Horizontal, "Дата начала");
  rTableModel -> setHeaderData(6, Qt::Horizontal, "Дата окончания");

  rTableModel -> setRelation(rTableModel -> fieldIndex("id_client"), QSqlRelation("client", "id", "full_name"));
  rTableModel -> setRelation(rTableModel -> fieldIndex("id_auto"), QSqlRelation("auto", "id", "auto_full"));

  rTableModel -> setRelation(rTableModel -> fieldIndex("id_worker"), QSqlRelation("worker", "id", "full_name"));

  rTableModel -> select();

  ui -> tableViewAuto -> hideColumn(0);
  ui -> tableViewAuto -> hideColumn(7);
  ui -> tableViewAuto -> hideColumn(8);

}

void TableWindow::showWorkerTable() {

  rTableModel -> setTable("worker");

  rTableModel -> setHeaderData(1, Qt::Horizontal, "Имя");
  rTableModel -> setHeaderData(2, Qt::Horizontal, "Фамилия");
  rTableModel -> setHeaderData(3, Qt::Horizontal, "Отчество");
  rTableModel -> setHeaderData(4, Qt::Horizontal, "Должность");
  rTableModel -> setHeaderData(5, Qt::Horizontal, "Логин");

  rTableModel -> select();

  ui -> tableViewAuto -> hideColumn(0);
  ui -> tableViewAuto -> hideColumn(6);
  ui -> tableViewAuto -> hideColumn(7);
}

void TableWindow::showDtpTable() {

  rTableModel -> setTable("dtp");

  rTableModel -> setHeaderData(1, Qt::Horizontal, "Авто");
  rTableModel -> setHeaderData(2, Qt::Horizontal, "Дата");
  rTableModel -> setHeaderData(3, Qt::Horizontal, "Место");
  rTableModel -> setHeaderData(4, Qt::Horizontal, "Вывод");

  rTableModel -> setRelation(rTableModel -> fieldIndex("id_auto_dtp"), QSqlRelation("auto", "id", "auto_full"));

  rTableModel -> select();

  ui -> tableViewAuto -> hideColumn(0);
}

void TableWindow::showPtsTable() {

  rTableModel -> setTable("pts");

  rTableModel -> setHeaderData(1, Qt::Horizontal, "Авто");
  rTableModel -> setHeaderData(2, Qt::Horizontal, "Серия");
  rTableModel -> setHeaderData(3, Qt::Horizontal, "Номер");
  rTableModel -> setHeaderData(4, Qt::Horizontal, "Дата выдачи");

  rTableModel -> setRelation(rTableModel -> fieldIndex("id_auto_pts"), QSqlRelation("auto", "id", "auto_full"));

  rTableModel -> select();

  ui -> tableViewAuto -> hideColumn(0);
  ui -> tableViewAuto -> hideColumn(5);
}

void TableWindow::showInspectTable() {

  rTableModel -> setTable("inspect");

  rTableModel -> setHeaderData(1, Qt::Horizontal, "Авто");
  rTableModel -> setHeaderData(2, Qt::Horizontal, "Дата прохождения");
  rTableModel -> setHeaderData(3, Qt::Horizontal, "Дата окончания");
  rTableModel -> setHeaderData(4, Qt::Horizontal, "Итог");

  rTableModel -> setRelation(rTableModel -> fieldIndex("id_auto_inspect"), QSqlRelation("auto", "id", "auto_full"));

  rTableModel -> select();

  ui -> tableViewAuto -> hideColumn(0);
}

void TableWindow::showInsurerTable() {

  rTableModel -> setTable("insurer");

  rTableModel -> setHeaderData(1, Qt::Horizontal, "Авто");
  rTableModel -> setHeaderData(2, Qt::Horizontal, "Название Страховой");
  rTableModel -> setHeaderData(3, Qt::Horizontal, "Дата оформления");
  rTableModel -> setHeaderData(4, Qt::Horizontal, "Дата окончания");

  rTableModel -> setRelation(rTableModel -> fieldIndex("id_auto_insurer"), QSqlRelation("auto", "id", "auto_full"));

  rTableModel -> select();

  ui -> tableViewAuto -> hideColumn(0);
  ui -> tableViewAuto -> hideColumn(4);
  ui -> tableViewAuto -> hideColumn(5);
}

void TableWindow::showRegTable() {
  rTableModel -> setTable("reg");

  rTableModel -> setHeaderData(1, Qt::Horizontal, "Авто");
  rTableModel -> setHeaderData(2, Qt::Horizontal, "Серия");
  rTableModel -> setHeaderData(3, Qt::Horizontal, "Номер");
  rTableModel -> setHeaderData(4, Qt::Horizontal, "Дата оформления");

  rTableModel -> setRelation(rTableModel -> fieldIndex("id_auto_reg"), QSqlRelation("auto", "id", "auto_full"));

  rTableModel -> select();

  ui -> tableViewAuto -> hideColumn(0);
}

void TableWindow::showBrandTable() {

  rTableModel -> setTable("brand");

  rTableModel -> setHeaderData(1, Qt::Horizontal, "Название");

  rTableModel -> select();

  ui -> tableViewAuto -> hideColumn(0);

}

void TableWindow::showModelTable() {

  rTableModel -> setTable("models");

  rTableModel -> setHeaderData(1, Qt::Horizontal, "Название модели");
  rTableModel -> setHeaderData(2, Qt::Horizontal, "Название бренда");

  rTableModel -> setRelation(rTableModel -> fieldIndex("id_brand"), QSqlRelation("brand", "id", "brand_name"));

  rTableModel -> select();

  ui -> tableViewAuto -> hideColumn(0);

}

void TableWindow::on_tabWidget_currentChanged(int index) {

  if (position == "Менеджер") {

    if (index == 0 || index == 10 || index == 11) {
      ui -> importButton -> setDisabled(true);
      ui -> exportButton -> setDisabled(true);
      ui -> delButton -> setDisabled(true);
      ui -> addButton -> setDisabled(true);
      ui -> cancelButton -> setDisabled(true);
      ui -> saveButton -> setDisabled(true);
    }

    if (index == 1 || index == 2 || index == 3) {
      ui -> importButton -> setDisabled(false);
      ui -> exportButton -> setDisabled(false);
      ui -> delButton -> setDisabled(false);
      ui -> addButton -> setDisabled(false);
      ui -> cancelButton -> setDisabled(false);
      ui -> saveButton -> setDisabled(false);
    }

  }

}

// UPDATE TABLE_NAME SET NEW_COLUMN = CONCAT(FIRST_NAME, " ", LAST_NAME);

void TableWindow::on_saveButton_clicked() {

  rTableModel -> submitAll();
  updateAutoTable();
}

void TableWindow::on_pushButton_clicked() {
  rTableModel -> revertAll();
}

void TableWindow::on_addButton_clicked() {
  rTableModel -> insertRow(rTableModel -> rowCount());
}

void TableWindow::on_delButton_clicked() {
  rTableModel -> removeRows(ui -> tableViewAuto -> currentIndex().row(), 1);
}

void TableWindow::on_exportButton_clicked() {
  QString fileName = QFileDialog::getSaveFileName(this, "Экспорт", "/Users/" + QDir::home().dirName() + "/Desktop/" + rTableModel -> tableName(), "CSV File (*.csv);;XML File (*.xml)");

  QFile file(fileName);

  if (file.open(QIODevice::WriteOnly)) {

    QTextStream stream( & file);

    QStringList strlineExp;

    QFileInfo fileInfo(fileName);

    if (fileInfo.completeSuffix() == "csv") {

      for (int i = 0; i < ui -> tableViewAuto -> verticalHeader() -> count(); i++)

      {

        strlineExp.clear();

        for (int j = 0; j < ui -> tableViewAuto -> horizontalHeader() -> count(); j++) {
          if (ui -> tableViewAuto -> model() -> headerData(j, Qt::Horizontal).toString() != "id") {
            strlineExp << ui -> tableViewAuto -> model() -> data(ui -> tableViewAuto -> model() -> index(i, j), Qt::DisplayRole).toString();
          }
        }

        stream << strlineExp.join(";") + "\n";

      }

    } else if (fileInfo.completeSuffix() == "xml") {

      stream << "<?xml version=\"1.0\" encoding=\"Windows-1251\"?>\n";
      stream << "<" + rTableModel -> tableName() + ">\n";

      QSqlRelationalTableModel * tempModel;

      tempModel = new QSqlRelationalTableModel(this);
      tempModel -> setTable(rTableModel -> tableName());
      tempModel -> select();

      for (int i = 0; i < ui -> tableViewAuto -> verticalHeader() -> count(); i++) {

        strlineExp.clear();
        stream << "\t<line number=\"" + QString::number(i + 1) + "\">\n";

        for (int j = 0; j < ui -> tableViewAuto -> horizontalHeader() -> count(); j++) {

          if (tempModel -> headerData(j, Qt::Horizontal).toString() != "id")

          {

            stream << "\t\t<" + tempModel -> headerData(j, Qt::Horizontal).toString() + ">" +
              ui -> tableViewAuto -> model() -> data(ui -> tableViewAuto -> model() -> index(i, j), Qt::DisplayRole).toString() + "</" +
              tempModel -> headerData(j, Qt::Horizontal).toString() + ">\n";

          }

        }

        stream << "\t</line>\n";

      }

      stream << "</" + rTableModel -> tableName() + ">";

      delete tempModel;

    }

    file.close();

  }

}


void TableWindow::recieveLogin(QString str) {

  rTableModel -> setEditStrategy(QSqlTableModel::OnManualSubmit);
  ui -> tableViewAuto -> horizontalHeader() -> setSectionResizeMode(QHeaderView::ResizeToContents);
  ui -> tableViewAuto -> resizeRowsToContents();
  ui -> tableViewAuto -> resizeColumnsToContents();
  ui -> tableViewAuto -> horizontalHeader() -> setDefaultAlignment(Qt::AlignHCenter);

  QCommonStyle styleButtons;

  ui -> saveButton -> setIcon(styleButtons.standardIcon(QStyle::SP_DialogSaveButton));
  ui -> cancelButton -> setIcon(styleButtons.standardIcon(QStyle::SP_DialogCancelButton));
  ui -> importButton -> setIcon(styleButtons.standardIcon(QStyle::SP_ArrowUp));
  ui -> exportButton -> setIcon(styleButtons.standardIcon(QStyle::SP_ArrowDown));
  ui -> printButton -> setIcon(styleButtons.standardIcon(QStyle::SP_FileIcon));
  ui -> addButton -> setIcon(styleButtons.standardIcon(QStyle::SP_FileDialogStart));
  ui -> delButton -> setIcon(styleButtons.standardIcon(QStyle::SP_TrashIcon));
  ui -> cancelButton -> setIcon(styleButtons.standardIcon(QStyle::SP_DialogCancelButton));
  ui -> resetButton -> setIcon(styleButtons.standardIcon(QStyle::SP_DialogDiscardButton));

  QSqlQuery query;

  query.exec("SELECT position FROM worker WHERE full_name =  \'" + str + "\' "); // Выборка позиции работника по его ФИО

  query.first();

  position = query.value(0).toString(); // Запись в переменную position результата запроса содержащий позицию работника.

  ui -> userLabel -> setText("Вы вошли как: \n" + str + "\n \nВаш уровень доступа: \n" + position); // Вывод позиции и ФИО в userLabel

  qDebug() << position;

  if (position == "Менеджер") {

    ui -> tabWidget -> setCurrentIndex(0);

    showAutoTable();

    ui -> tabWidget -> setTabEnabled(3, false);
    ui -> tabWidget -> setTabEnabled(4, false);
    ui -> tabWidget -> setTabEnabled(5, false);
    ui -> tabWidget -> setTabEnabled(6, false);
    ui -> tabWidget -> setTabEnabled(7, false);
    ui -> tabWidget -> setTabEnabled(8, false);

    if (ui -> tabWidget -> currentIndex() == 0) {
      ui -> importButton -> setDisabled(true);
      ui -> exportButton -> setDisabled(true);
      ui -> delButton -> setDisabled(true);
      ui -> addButton -> setDisabled(true);
      ui -> cancelButton -> setDisabled(true);
      ui -> saveButton -> setDisabled(true);
    }

  }

  if (position == "Начальник парка") {

    ui -> tabWidget -> setCurrentIndex(0);
    showAutoTable();

  }

}

void TableWindow::on_printButton_clicked() {

  //   QPrinter printer(QPrinter::HighResolution);
  //    printer.setFullPage( true );
  //   QPrintPreviewDialog preview(&printer, this);
  //  preview.setWindowFlags ( Qt::Window );
  //    connect(&preview, SIGNAL(paintRequested(QPrinter* )), SLOT(print(QPrinter* )));
  //   preview.exec();

  QString str;
  QTextStream out( & str);

  const int rowCount = ui -> tableViewAuto -> model() -> rowCount();
  const int columnCount = ui -> tableViewAuto -> model() -> columnCount();

  if (rowCount == 0 && columnCount == 0) {
    QMessageBox::warning(0, "Ошибка", "Нет данных для печати");
  } else

  {
    out << "<html>\n" << "<head>\n" << "meta Content=\"Text/html;charset=Windows-1251\">\n" <<

      QString("<h1>%2</h1><title>%1</title>\n").arg("Report") <<
      "</head>\n"
    "<body bgcolor=#ffffff link=#5000A0>\n"
    "<table border= 1 cellspacing=0 cellpadding=2>\n";

    out << QString("<h1>Вывод таблицы : %2</h1>").arg(rTableModel -> tableName());
    out << "<thead><tr bgcolor=#f0f0f0> ";

    for (int column = 0; column < columnCount; column++)

      if (!ui -> tableViewAuto -> isColumnHidden(column))

        out << QString("<th>%1</th>").arg(ui -> tableViewAuto -> model() -> headerData(column, Qt::Horizontal).toString());

    out << "</tr></thead>\n";

    for (int row = 0; row < rowCount; row++) {

      out << "<tr>";

      for (int column = 0; column < columnCount; column++) {

        if (!ui -> tableViewAuto -> isColumnHidden(column)) {

          QString data = ui -> tableViewAuto -> model() -> data(ui -> tableViewAuto -> model() -> index(row, column)).toString().simplified();

          out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));

        }

      }

      out << "</tr>\n";

    }

    out << "</table>\n"
    "</body>\n"
    "</html>";

    QTextDocument * document = new QTextDocument();

    document -> setHtml(str);

    QPrinter printer;

    QPrintDialog * dialog = new QPrintDialog( & printer, 0);

    if (dialog -> exec() == QDialog::Accepted) {

      document -> print( & printer);

    }

    delete document;

  }

}

void TableWindow::on_importButton_clicked() {

  QString fileName;

  QSqlQuery dataload;

  QSqlQuery detailed;

  QSqlQuery dataout;

  fileName = QFileDialog::getOpenFileName(this, "Импорт", "/Users/" + QDir::home().dirName() + "/Desktop/" + rTableModel -> tableName(), "CSV File (*.csv);;XML File (*.xml)");

  QFile file(fileName);

  QFileInfo fileInfo(fileName);\

  if (file.open(QIODevice::ReadOnly)) {

    if (fileInfo.completeSuffix() == "xml") {

      QStringList convert;
      QXmlStreamReader x( & file);
      QStringList toConvert;

      while (!x.atEnd()) {

        QXmlStreamReader::TokenType t = x.readNext();

        if (t == QXmlStreamReader::StartDocument)

          continue;

        if (t == QXmlStreamReader::StartElement) {
          if (x.name() != "line")

            continue;

          else if (x.name() == "line") {
            x.readNext();

            while (!(x.tokenType() == QXmlStreamReader::EndElement && x.name() == "line")) {
              if (x.tokenType() == QXmlStreamReader::StartElement) {
                x.readNext();
                convert << x.text().toString();
              }

              x.readNext();
            }

            toConvert << convert.join(",").replace(",", ";");
            qDebug() << convert;

            detailed.exec(("DESCRIBE `" + rTableModel -> tableName() + "`"));

            QString describe;

            while (detailed.next()) {
              if (detailed.value(3).toString() != "PRI") {
                describe += "`" + detailed.value(0).toString() + "`,";
              }
            }

            describe = describe.remove(describe.length() - 1, 1);

            QString req = "INSERT INTO `" + rTableModel -> tableName() + "`      (" + describe + ") VALUES(";

            for (int i = 0; i < convert.length(); i++) {
              if (rTableModel -> relation(i + 1).tableName() != "") {
                dataout.exec("SELECT `id` FROM `" + rTableModel -> relation(i + 1).tableName() + "` WHERE " + rTableModel -> relation(i + 1).displayColumn() + "= '" + convert.at(i) + "' ");

                dataout.next();

                req.append('"' + (dataout.value(0).toString() + '"'));
              } else {
                req.append('"' + convert.at(i) + '"');
              }

              req.append(",");

            }

            req.chop(1);
            req.append(");");

            if (!(dataload.exec(req))) {
              QMessageBox::information(this, "Error", "Ошибка импорта", QMessageBox::Cancel);

            } else

            {

              if (rTableModel -> tableName() == "auto") {
                showAutoTable();
              } else if (rTableModel -> tableName() == "client") {
                showClientTable();
              } else if (rTableModel -> tableName() == "worker") {
                showWorkerTable();
              } else if (rTableModel -> tableName() == "reg") {
                showRegTable();
              } else if (rTableModel -> tableName() == "pts") {
                showRegTable();
              } else if (rTableModel -> tableName() == "models") {
                showModelTable();
              } else if (rTableModel -> tableName() == "insurer") {
                showInsurerTable();
              } else if (rTableModel -> tableName() == "inspect") {
                showInspectTable();
              } else if (rTableModel -> tableName() == "dtp") {
                showDtpTable();
              } else if (rTableModel -> tableName() == "contract") {
                showContractTable();
              } else if (rTableModel -> tableName() == "brand") {
                showBrandTable();
              }
            }
            convert.clear();
          }
        }
      }
    }

    if (fileInfo.completeSuffix() == "csv") {

      QTextStream ts( & file);

      // Вытаскиваем структуру таблицы
      detailed.exec(("DESCRIBE `" + rTableModel -> tableName() + "`"));
      // Строка в которой будет вся структура
      QString describe;

      while (detailed.next()) {
        if (detailed.value(3).toString() != "PRI") {
          describe += "`" + detailed.value(0).toString() + "`,";
          qDebug() << describe;

        }
      }

      describe = describe.remove(describe.length() - 1, 1);

      while (!ts.atEnd()) {

        QString req = "INSERT INTO `" + rTableModel -> tableName() + "`      (" + describe + ") VALUES(";

        QStringList line = ts.readLine().split(';');

        for (int i = 0; i < line.length(); i++) {
          if (rTableModel -> relation(i + 1).tableName() != "") {
            dataout.exec("SELECT `id` FROM `" + rTableModel -> relation(i + 1).tableName() + "` WHERE " + rTableModel -> relation(i + 1).displayColumn() + "= '" + line.at(i) + "' ");

            dataout.next();

            req.append('"' + (dataout.value(0).toString() + '"'));
          } else {
            req.append('"' + line.at(i) + '"');
          }

          req.append(",");

        }

        req.chop(1);
        req.append(");");

        if (!(dataload.exec(req))) {
          QMessageBox::information(this, "Error", "Ошибка импорта", QMessageBox::Cancel);
        } else

        {

          if (rTableModel -> tableName() == "auto") {
            showAutoTable();
          } else if (rTableModel -> tableName() == "client") {
            showClientTable();
          } else if (rTableModel -> tableName() == "worker") {
            showWorkerTable();
          } else if (rTableModel -> tableName() == "reg") {
            showRegTable();
          } else if (rTableModel -> tableName() == "pts") {
            showRegTable();
          } else if (rTableModel -> tableName() == "models") {
            showModelTable();
          } else if (rTableModel -> tableName() == "insurer") {
            showInsurerTable();
          } else if (rTableModel -> tableName() == "inspect") {
            showInspectTable();
          } else if (rTableModel -> tableName() == "dtp") {
            showDtpTable();
          } else if (rTableModel -> tableName() == "contract") {
            showContractTable();
          } else if (rTableModel -> tableName() == "brand") {
            showBrandTable();
          }
        }
      }

      file.close();
    }
  }
}

void TableWindow::on_searchEdit_textChanged(const QString & arg1) {

  if (ui -> searchEdit -> text() != "") {
    if (ui -> tabWidget -> currentIndex() == 0) {
      rTableModel -> setFilter("`auto_full` LIKE '%" + ui -> searchEdit -> text() + "%'");
    }

    if (ui -> tabWidget -> currentIndex() == 1) {
      rTableModel -> setFilter("`search` LIKE '%" + ui -> searchEdit -> text() + "%'");

    }

    if (ui -> tabWidget -> currentIndex() == 2) {
      rTableModel -> setFilter("`status` LIKE '%" + ui -> searchEdit -> text() + "%'");

    }

    if (ui -> tabWidget -> currentIndex() == 3) {
      rTableModel -> setFilter("`search` LIKE '%" + ui -> searchEdit -> text() + "%'");

    }

    if (ui -> tabWidget -> currentIndex() == 4) {

      rTableModel -> setFilter("`search` LIKE '%" + ui -> searchEdit -> text() + "%'");

    }

    if (ui -> tabWidget -> currentIndex() == 4) {

      rTableModel -> setFilter("`search` LIKE '%" + ui -> searchEdit -> text() + "%'");

    }

    if (ui -> tabWidget -> currentIndex() == 5) {

      rTableModel -> setFilter("`search` LIKE '%" + ui -> searchEdit -> text() + "%'");

    }

    if (ui -> tabWidget -> currentIndex() == 6) {

      rTableModel -> setFilter("`search` LIKE '%" + ui -> searchEdit -> text() + "%'");

    }

    if (ui -> tabWidget -> currentIndex() == 7) {

      rTableModel -> setFilter("`search` LIKE '%" + ui -> searchEdit -> text() + "%'");

    }

    if (ui -> tabWidget -> currentIndex() == 8) {

      rTableModel -> setFilter("`search` LIKE '%" + ui -> searchEdit -> text() + "%'");

    }

    if (ui -> tabWidget -> currentIndex() == 9) {

      rTableModel -> setFilter("`search` LIKE '%" + ui -> searchEdit -> text() + "%'");

    }

    if (ui -> tabWidget -> currentIndex() == 10) {

      rTableModel -> setFilter("`search` LIKE '%" + ui -> searchEdit -> text() + "%'");

    }

  }

}

void TableWindow::showControlTable() {

  // Клиент - Авто - Период

  QSqlQuery query;

  QStringList autoAvialable;

  QStringList Clients;

  ui -> tableViewControl -> setEditTriggers(QAbstractItemView::NoEditTriggers);

  ui -> tableViewControl -> setColumnCount(0);
  ui -> tableViewControl -> setRowCount(0);

  ui -> tableViewControl -> horizontalHeader() -> hide();
  ui -> tableViewControl -> verticalHeader() -> hide();

  query.exec("SELECT `id`,`auto_full` FROM `auto` ORDER BY `auto_full`");

  int i = 1;

  ui -> tableViewControl -> insertRow(0);
  ui -> tableViewControl -> insertColumn(0);

  ui -> tableViewControl -> setItem(0, 0, new QTableWidgetItem("Клиенты/Аренды"));

  while (query.next()) {

    autoAvialable << query.value(0).toString();

    ui -> tableViewControl -> insertColumn(i);
    ui -> tableViewControl -> setItem(0, i, new QTableWidgetItem(query.value(1).toString()));

    i++;
  }

  query.exec("SELECT `id`,`full_name` FROM `client` ORDER BY `full_name`");

  i = 1;

  while (query.next()) {

    Clients << query.value(0).toString();

    ui -> tableViewControl -> insertRow(i);
    ui -> tableViewControl -> setItem(i, 0, new QTableWidgetItem(query.value(1).toString()));

    i++;
  }

  ui -> tableViewControl -> horizontalHeader() -> setSectionResizeMode(QHeaderView::ResizeToContents);
  ui -> tableViewControl -> verticalHeader() -> setSectionResizeMode(QHeaderView::ResizeToContents);

  for (int i = 0; i < autoAvialable.length(); i++) {
    for (int b = 0; b < Clients.length(); b++) {

      query.exec("SELECT `status` FROM `contract` WHERE `id_client`='" + Clients[b] + "' AND `id_auto`= '" + autoAvialable[i] + "' LIMIT 1");

      query.next();

      QString spent;

      if (query.value(0).toString() != "")
        spent = query.value(0).toString();
      else
        spent = "-";
      ui -> tableViewControl -> setItem(b + 1, i + 1, new QTableWidgetItem(spent));
    }
  }

}

void TableWindow::updateAutoTable() {
  QSqlQuery query;

  QStringList brandsKeys;

  QStringList modelsKeys;

  QStringList brandNames;

  QStringList modelNames;

  QStringList idKeys;

  QStringList colorNames;

  QStringList vinList;

  QStringList yearList;

  query.exec("SELECT id from auto");

  while (query.next()) {
    idKeys << brandsKeys << query.value(0).toString();
  }

  query.exec("SELECT id_brand FROM auto ORDER BY id");

  while (query.next()) {

    brandsKeys << query.value(0).toString();

  }

  for (int i = 0; i < brandsKeys.length(); i++) {
    query.exec("SELECT brand_name FROM brand WHERE id = \'" + brandsKeys[i] + "\'");

    query.next();

    brandNames << query.value(0).toString();

  }

  query.exec("SELECT id_model FROM auto ORDER BY id");

  while (query.next()) {

    modelsKeys << query.value(0).toString();

  }

  for (int i = 0; i < modelsKeys.length(); i++) {
    query.exec("SELECT model FROM models WHERE id = \'" + modelsKeys[i] + "\'");

    query.next();

    modelNames << query.value(0).toString();

  }

  for (int i = 0; i < idKeys.length(); i++) {
    query.exec("SELECT color FROM auto WHERE id = \'" + idKeys[i] + "\'");

    query.next();

    colorNames << query.value(0).toString();

  }

  for (int i = 0; i < idKeys.length(); i++) {
    query.exec("SELECT year_start FROM auto WHERE id = \'" + idKeys[i] + "\'");

    query.next();

    yearList << query.value(0).toString();

    qDebug() << yearList;

  }

  for (int i = 0; i < idKeys.length(); i++) {
    query.exec("SELECT VIN FROM auto WHERE id = \'" + idKeys[i] + "\'");

    query.next();

    vinList << query.value(0).toString().remove(0, 13);

    qDebug() << vinList;

  }

  for (int i = 0; i < idKeys.length(); i++) {

    query.exec("UPDATE auto SET auto_full = \'" + brandNames[i] + "\' \'" + " " + "\' \'" + modelNames[i] + "\' \'" + " " + "\' \'(" + yearList[i] + ")\' \'" + " " + "\' \ \'(" + colorNames[i] + ")\' \ \'" + " " + "\' \'VIN: " + vinList[i] + "\' WHERE id = \'" + idKeys[i] + "\'");

    query.next();

  }

}

void TableWindow::on_resetButton_clicked() {
  rTableModel -> setFilter("");
}
