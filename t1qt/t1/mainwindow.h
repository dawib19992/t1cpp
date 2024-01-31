#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void showPlayerDialog();
    void showPodium();

private:
    QListWidget *playerList;
    QLabel *clubLogo;
    QPushButton *addPlayerButton;
    QPushButton *podiumButton;

    void sortPlayerList();
};

#endif // MAINWINDOW_H
