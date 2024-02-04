#include "soldierdialog.h"
#include "qlabel.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

SoldierDialog::SoldierDialog(QWidget *parent)
    : QDialog(parent)
{
    setupUI();
}

SoldierDialog::~SoldierDialog()
{
}

void SoldierDialog::setupUI()
{
    nameLineEdit = new QLineEdit(this);
    ageSpinBox = new QSpinBox(this);
    rankComboBox = new QComboBox(this);
    okButton = new QPushButton("OK", this);
    cancelButton = new QPushButton("Anuluj", this);

    ageSpinBox->setMinimum(18);
    rankComboBox->addItem("Kapral");
    rankComboBox->addItem("Chorąży");
    rankComboBox->addItem("Porucznik");

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(new QLabel("Imie:", this));
    mainLayout->addWidget(nameLineEdit);
    mainLayout->addWidget(new QLabel("Wiek:", this));
    mainLayout->addWidget(ageSpinBox);
    mainLayout->addWidget(new QLabel("Stopień:", this));
    mainLayout->addWidget(rankComboBox);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    mainLayout->addLayout(buttonLayout);

    connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));

    setLayout(mainLayout);
}

QString SoldierDialog::getName() const
{
    return nameLineEdit->text();
}

int SoldierDialog::getAge() const
{
    return ageSpinBox->value();
}

QString SoldierDialog::getRank() const
{
    return rankComboBox->currentText();
}
