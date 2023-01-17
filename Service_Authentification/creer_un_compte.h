#ifndef CREER_UN_COMPTE_H
#define CREER_UN_COMPTE_H

#include <QDialog>
#include <QMessageBox>
#include <map>

namespace Ui {
class Creer_un_compte;
}

class Creer_un_compte : public QDialog
{
    Q_OBJECT

public:
    explicit Creer_un_compte(QWidget *parent = 0);
    ~Creer_un_compte();


public slots:
    void receiveVariables();

    void on_buttonBox_accepted();


private:
    Ui::Creer_un_compte *ui;

};

#endif // CREER_UN_COMPTE_H
