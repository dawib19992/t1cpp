#include "playerdialog.h"
#include "qlabel.h"
#include <QVBoxLayout>

PlayerDialog::PlayerDialog(QWidget *parent)
    : QDialog(parent)
{
    nameLineEdit = new QLineEdit(this);
    ageSpinBox = new QSpinBox(this);
    pointsSpinBox = new QSpinBox(this);
    okButton = new QPushButton("OK", this);
    cancelButton = new QPushButton("Anuluj", this);

    // Ustawienia do kontrolek
    ageSpinBox->setRange(1, 100);
    pointsSpinBox->setRange(0, 1000);

    // Dodanie kontrolek do layoutu
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("Nazwisko:", this));
    layout->addWidget(nameLineEdit);
    layout->addWidget(new QLabel("Wiek:", this));
    layout->addWidget(ageSpinBox);
    layout->addWidget(new QLabel("Liczba punktów:", this));
    layout->addWidget(pointsSpinBox);
    layout->addWidget(okButton);
    layout->addWidget(cancelButton);

    // Podpięcie slotów do przycisków
    connect(okButton, &QPushButton::clicked, this, &PlayerDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &PlayerDialog::reject);
}

QString PlayerDialog::getPlayerName() const
{
    return nameLineEdit->text();
}

int PlayerDialog::getPlayerAge() const
{
    return ageSpinBox->value();
}

int PlayerDialog::getPlayerPoints() const
{
    return pointsSpinBox->value();
}
