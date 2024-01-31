// playerdialog.h
#ifndef PLAYERDIALOG_H
#define PLAYERDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>

class PlayerDialog : public QDialog
{
    Q_OBJECT

public:
    PlayerDialog(QWidget *parent = nullptr);

    QString getPlayerName() const;
    int getPlayerAge() const;
    int getPlayerPoints() const;

private:
    QLineEdit *nameLineEdit;
    QSpinBox *ageSpinBox;
    QSpinBox *pointsSpinBox;
    QPushButton *okButton;
    QPushButton *cancelButton;
};

#endif // PLAYERDIALOG_H
