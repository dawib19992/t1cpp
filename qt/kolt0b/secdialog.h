// studentdialog.h
#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    SecDialog(QWidget *parent = nullptr);

    QString getFirstName() const;
    QString getAdress() const;
    double getAmount() const;
    double getDiscount() const;

private:
    QLineEdit *firstNameLineEdit;
    QLineEdit *adressLineEdit;
    QLineEdit *amountLineEdit;
    QLineEdit *discountLineEdit;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUI();
};

#endif

