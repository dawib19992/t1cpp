#ifndef SOLDIERDIALOG_H
#define SOLDIERDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QPushButton>

class SoldierDialog : public QDialog
{
    Q_OBJECT

public:
    SoldierDialog(QWidget *parent = nullptr);
    ~SoldierDialog();

    QString getName() const;
    int getAge() const;
    QString getRank() const;

private:
    QLineEdit *nameLineEdit;
    QSpinBox *ageSpinBox;
    QComboBox *rankComboBox;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUI();
};

#endif // SOLDIERDIALOG
