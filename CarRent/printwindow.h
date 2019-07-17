#ifndef PRINTWINDOW_H
#define PRINTWINDOW_H

#include <QMainWindow>
#include <tablewindow.h>

namespace Ui {
class PrintWindow;
}

class PrintWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PrintWindow(QWidget *parent = 0);
    ~PrintWindow();

private:
    Ui::PrintWindow *ui;
    PrintWindow *print_window;
};

#endif // PRINTWINDOW_H
