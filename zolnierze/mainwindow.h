#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "soldierdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addSoldier();
    void showOldestByRank();

    void on_dodajzolnierza_clicked();

    void on_najstarszy_clicked();

private:
    Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
