#include "mainwindow.h"
#include "secdialog.h" // Klasa do drugiego okna
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    ,ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap logopixmap("C:/Users/dawid/Desktop/kolt0b/logo.png");
    ui->label->setPixmap(logopixmap.scaled(150, 150));
}

void MainWindow::calculateTotal()
{
    double totalOrders = 0.0;

    for (int i = 0; i < ui->listaklientow->count(); i++) {
        QListWidgetItem *item = ui->listaklientow->item(i);
        double orderValue = item->data(Qt::UserRole).toDouble();
        totalOrders += orderValue;
    }
    QMessageBox::information(this, "Wartość Zamówień", "Wartość: "+QString::number(totalOrders));
}

void MainWindow::addClient()
{
    SecDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString name = dialog.getFirstName();
        QString address = dialog.getAdress();
        double discount;
        double wartosc;
        if(dialog.getAmount() < 0)
        {
            wartosc = 0;
        }
        else
        {
           wartosc = dialog.getAmount();
        }
        if(dialog.getDiscount() < 0)
        {
           discount = 0;
        }
        else
        {
           discount = dialog.getDiscount();
        }
        porabacie = wartosc - (wartosc*(discount/100));
        QString customerInfo = QString("%1, %2, %3").arg(address, name, QString::number(porabacie));
        QListWidgetItem *newItem = new QListWidgetItem(customerInfo);
        newItem->setData(Qt::UserRole, QVariant(porabacie));
        ui->listaklientow->addItem(newItem);
        sortClientsList();
    }
}

void MainWindow::sortClientsList()
{
    for(int i = 0; i < ui->listaklientow->count(); i++)
    {
       for (int j = 0; j < ui->listaklientow->count(); j++)
       {
            QStringList klient1 = ui->listaklientow->item(i)->text().split(", ");
            QStringList klient2 = ui->listaklientow->item(j)->text().split(", ");
            if(klient1[2].toDouble() > klient2[2].toDouble())
            {
                ui->listaklientow->insertItem(i, ui->listaklientow->takeItem(j));
            }
       }
    }
}

void MainWindow::on_dodaj_clicked()
{
    addClient();
}


void MainWindow::on_wylicz_clicked()
{
    calculateTotal();
}

