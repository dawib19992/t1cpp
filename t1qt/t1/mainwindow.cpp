#include "mainwindow.h"
#include "playerdialog.h"
#include <QMessageBox>
#include <QVBoxLayout>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    playerList = new QListWidget(this);
    clubLogo = new QLabel(this);
    addPlayerButton = new QPushButton("Dodaj Zawodnika", this);
    podiumButton = new QPushButton("Wyświetl podium", this);

    // Dodanie widżetów do głównego okna
    setCentralWidget(playerList);

    QVBoxLayout* mainLayout = new QVBoxLayout();
    QHBoxLayout* buttonLayout = new QHBoxLayout();

    buttonLayout->addWidget(addPlayerButton);
    buttonLayout->addWidget(podiumButton);

    mainLayout->addWidget(clubLogo);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(playerList);

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    // Podpięcie slotów do przycisków
    connect(addPlayerButton, &QPushButton::clicked, this, &MainWindow::showPlayerDialog);
    connect(podiumButton, &QPushButton::clicked, this, &MainWindow::showPodium);

    // Tu możesz wczytać logo klubu (przykład zakłada, że jest plik o nazwie "club_logo.png" w bieżącym katalogu)
    QPixmap logoPixmap("C:/Users/dawid/Desktop/logo.png");
    clubLogo->setPixmap(logoPixmap.scaled(150, 150)); // Skalowanie logo

    sortPlayerList();
}


MainWindow::~MainWindow()
{
    // Usuń dynamicznie alokowane obiekty
    delete playerList;
    delete clubLogo;
    delete addPlayerButton;
    delete podiumButton;
}

void MainWindow::showPlayerDialog()
{
    PlayerDialog dialog(this);

    if (dialog.exec() == QDialog::Accepted) {
        // Dodaj nowego zawodnika do listy
        QString playerName = dialog.getPlayerName();
        int playerAge = dialog.getPlayerAge();
        int playerPoints = dialog.getPlayerPoints();

        QString playerInfo = QString("%1 %2 %3").arg(playerAge).arg(playerName).arg(playerPoints);
        playerList->addItem(playerInfo);

        sortPlayerList();
    }
}

void MainWindow::showPodium()
{
    if (playerList->count() < 3) {
        QMessageBox::information(this, "Podium", "Potrzebujesz co najmniej 3 zawodników do utworzenia podium.");
        return;
    }

    QDialog podiumDialog(this);
    podiumDialog.setWindowTitle("Podium");

    QVBoxLayout *podiumLayout = new QVBoxLayout(&podiumDialog);

    // Pobierz informacje o trzech najlepszych zawodnikach
    QStringList podiumInfo;
    for (int i = 0; i < 3; ++i) {
        QString playerInfo = playerList->item(i)->text();
        podiumInfo.append(playerInfo);
    }

    // Utwórz etykiety dla miejsc na podium
    for (int i = 1; i <= 3; ++i) {
        QLabel *label = new QLabel(QString("%1. %2").arg(i).arg(podiumInfo[i - 1]), &podiumDialog);
        podiumLayout->addWidget(label);
    }

    podiumDialog.exec();
}

void MainWindow::sortPlayerList()
{
    // Sortowanie listy zawodników według wieku, nazwiska, a następnie liczby punktów
    playerList->sortItems(Qt::AscendingOrder);

    // Odwróć kolejność na liście, aby najpierw wyświetlała się liczba punktów, potem wiek, a na końcu nazwisko
    int itemCount = playerList->count();
    for (int i = 0; i < itemCount / 2; ++i) {
        QListWidgetItem *firstItem = playerList->takeItem(i);
        QListWidgetItem *lastItem = playerList->takeItem(itemCount - i - 1);

        // Zamień miejscami elementy
        playerList->insertItem(i, lastItem);
        playerList->insertItem(itemCount - i - 1, firstItem);
    }
}
