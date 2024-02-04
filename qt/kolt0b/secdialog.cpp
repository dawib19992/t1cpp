#include "secdialog.h"

SecDialog::SecDialog(QWidget *parent)
    : QDialog(parent)
{
    setupUI();
}

void SecDialog::setupUI()
{
    firstNameLineEdit = new QLineEdit(this);
    adressLineEdit = new QLineEdit(this);
    amountLineEdit = new QLineEdit(this);
    discountLineEdit = new QLineEdit(this);
    okButton = new QPushButton("OK", this);
    cancelButton = new QPushButton("Cancel", this);

    QFormLayout *layout = new QFormLayout(this);
    layout->addRow("Imie:", firstNameLineEdit);
    layout->addRow("Adres:", adressLineEdit);
    layout->addRow("Amount:", amountLineEdit);
    layout->addRow("Discount:", discountLineEdit);
    layout->addRow(okButton, cancelButton);

    connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));

    setLayout(layout);
}

QString SecDialog::getFirstName() const
{
    return firstNameLineEdit->text();
}

QString SecDialog::getAdress() const
{
    return adressLineEdit->text();
}

double SecDialog::getAmount() const
{
    return amountLineEdit->text().toDouble();
}

double SecDialog::getDiscount() const
{
    return discountLineEdit->text().toDouble();
}
