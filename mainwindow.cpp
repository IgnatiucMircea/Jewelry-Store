#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qstring.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent, Controller* c)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
 this->cont = c;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_print_button_clicked()
{
    ui->list->setText(QString::fromStdString(cont->to_string()));
}


void MainWindow::on_AddButton_clicked()
{
    std::string id=ui->id_1->toPlainText().toStdString();
    std::string type=ui->type_1->toPlainText().toStdString();
    float price=ui->price_1->toPlainText().toFloat();
    double weight=ui->weight_1->toPlainText().toDouble();
    double nr_jewels=ui->nr_jewels_1->toPlainText().toDouble();
    ui->id_1->clear();
    ui->type_1->clear();
    ui->price_1->clear();
    ui->weight_1->clear();
    ui->nr_jewels_1->clear();
    auto bp=Jewelry_Product{ id,type,price,weight,nr_jewels };
    if(!cont->add(bp))
        QMessageBox::information(this,tr("ERROR"),tr("Invalid input"));
}


void MainWindow::on_Del_last_clicked()
{
    bool ok = cont->pop_back();
        if (!ok)
            QMessageBox::information(this,tr("ERROR"),tr("No elements in repository"));

}


void MainWindow::on_del_id_clicked()
{
    std::string id=ui->del_id_txt->toPlainText().toStdString();
    if(!cont->remove(id)) {
        QMessageBox::information(this,tr("ERROR"),tr("Id doesn't exist"));
    }
    ui->del_id_txt->clear();
}




void MainWindow::on_filter_crit_button_clicked()
{
    vector<Jewelry_Product> res;
    if(ui->filter_box->currentText()=="Price")
    {
        float price=ui->filter_crit->toPlainText().toFloat();
        FilteringPrice fp{ price };
        res = this->cont->filter(fp);
    }
    else if(ui->filter_box->currentText()=="Weight")
    {
        double weight=ui->filter_crit->toPlainText().toDouble();
        FilteringWeight fc{ weight };
        res = this->cont->filter(fc);
    }
    else if(ui->filter_box->currentText()=="Nr of Jewels")
    {
        double i=ui->filter_crit->toPlainText().toDouble();
        FilteringNrJewels fs{ i };
        res = this->cont->filter(fs);
    }
    Repository repo{ res };
        if (repo.to_string() == "")
            QMessageBox::information(this,tr("ERROR"),tr("There are no products for the given criteria"));
        else
            ui->list->setText(QString::fromStdString(repo.to_string()));
}


void MainWindow::on_updat_button_clicked()
{
    int index=ui->index_2->toPlainText().toInt();
    std::string id=ui->id_2->toPlainText().toStdString();
    std::string type=ui->type_2->toPlainText().toStdString();
    float price=ui->price_2->toPlainText().toFloat();
    double weight=ui->weight_2->toPlainText().toDouble();
    double nr_jewels=ui->nr_jewels_2->toPlainText().toDouble();
    ui->index_2->clear();
    ui->id_2->clear();
    ui->type_2->clear();
    ui->price_2->clear();
    ui->weight_2->clear();
    ui->nr_jewels_2->clear();
    if (!cont->update(index, id, type, price, weight, nr_jewels))
    {
        if(!cont->index_ctrl(index))
            QMessageBox::information(this,tr("ERROR"),tr("Invalid index"));
        else
            QMessageBox::information(this,tr("ERROR"),tr("Invalid input"));
    }
}


void MainWindow::on_undo_button_clicked()
{
    if(!cont->UNDO())
        QMessageBox::information(this,tr("ERROR"),tr("No tasks to undo"));
    //ui->list->setText(QString::fromStdString(Controller::));

}


void MainWindow::on_pushButton_6_clicked()
{
    if(!cont->REDO())
        QMessageBox::information(this,tr("ERROR"),tr("No tasks to redo"));
}

