#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Repository.h"
#include "Controller.h"
#include "FilteringCriteria.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Controller* c) { cont = c; };
    MainWindow(QWidget *parent = nullptr, Controller *c=nullptr);
    ~MainWindow();


private slots:

    void on_print_button_clicked();

    void on_AddButton_clicked();

    void on_Del_last_clicked();

    void on_del_id_clicked();



    void on_filter_crit_button_clicked();

    void on_updat_button_clicked();

    void on_undo_button_clicked();

    void on_pushButton_6_clicked();

private:
    Controller* cont;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
