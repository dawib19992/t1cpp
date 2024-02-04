#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void calculateTotal();
    void addClient();

    void on_dodaj_clicked();

    void on_wylicz_clicked();

private:
    void sortClientsList();
    Ui::MainWindow *ui;
    double porabacie;
};

#endif // MAINWINDOW_H
