#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

/* My Includes */
#include <dynamicbutton.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addButton_clicked();    // SLOT-handler pressing add button
    void on_deleteButton_clicked(); // SLOT-handler pressing the delete button
    void slotGetNumber();           // SLOT for getting number of the dynamic buttons

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
