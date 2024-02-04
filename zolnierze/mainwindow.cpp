#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPixmap>
#include <QDir>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*QPixmap logo("C:/Users/student/Desktop/kolt1dk/kolt1b-dawib19992/logo.png");
    ui->logo->setPixmap(logo.scaled(150, 150));*/
    QPixmap logo("C:/Users/student/Desktop/kolt1dk/kolt1b-dawib19992/company_logo.png");
    ui->logo->setPixmap(logo.scaled(150, 150));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addSoldier()
{
    SoldierDialog dialog(this);

    if (dialog.exec() == QDialog::Accepted) {
        QString name = dialog.getName();
        int age = dialog.getAge();
        QString rank = dialog.getRank();

        if (age < 18) {
            QMessageBox::critical(this, "Error", "Żołnierz musi być pełnoletni.");
            return;
        }

        if(name == nullptr)
        {
            QMessageBox::critical(this,"Error", "Wprowadź imie żołnierza.");
            return;
        }

        // Add soldier to the list
        QString soldierInfo = name + ", " + rank + ", " + QString::number(age);
        QListWidgetItem *newSoldier = new QListWidgetItem(soldierInfo);
        ui->lista_zolnierzy->addItem(newSoldier);

        // Sort the list by age (oldest first)
        for (int i = 0; i < ui->lista_zolnierzy->count() - 1; ++i) {
            for (int j = i + 1; j < ui->lista_zolnierzy->count(); ++j) {
                QStringList soldier1 = ui->lista_zolnierzy->item(i)->text().split(", ");
                QStringList soldier2 = ui->lista_zolnierzy->item(j)->text().split(", ");
                if (soldier1[2].toInt() < soldier2[2].toInt()) {
                    ui->lista_zolnierzy->insertItem(i, ui->lista_zolnierzy->takeItem(j));
                }
            }
        }
    }
}

void MainWindow::showOldestByRank()
{
    QString selectedRank = ui->stopien->currentText();
    int index = -1;

    // Find the oldest soldier of the selected rank
    for (int i = 0; i < ui->lista_zolnierzy->count(); ++i) {
        QStringList soldierInfo = ui->lista_zolnierzy->item(i)->text().split(", ");
        if (soldierInfo[1] == selectedRank) {
            if (index == -1 || soldierInfo[2].toInt() > ui->lista_zolnierzy->item(index)->text().split(", ")[2].toInt()) {
                index = i;
            }
        }
    }

    if (index != -1) {
        QMessageBox::information(this, "Najstarszy żołnierz według stopnia", ui->lista_zolnierzy->item(index)->text());
    } else {
        QMessageBox::information(this, "Najstarszy żołnierz według stopnia", "Nieznaleziono żołnierza z danym stopniem.");
    }
}

void MainWindow::on_dodajzolnierza_clicked()
{
    addSoldier();
}


void MainWindow::on_najstarszy_clicked()
{
    showOldestByRank();
}

