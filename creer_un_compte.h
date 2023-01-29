#ifndef CREER_UN_COMPTE_H
#define CREER_UN_COMPTE_H

#include <QDialog>
#include <QMessageBox>
#include <map>
#include <QDebug>

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
    void receiveVariables(std::map<QString , QString> m_logins);

    void on_buttonBox_accepted();
signals:
    void sendbackVariables(std::map<QString , QString> m_logins);

private:
    Ui::Creer_un_compte *ui;
    std::map<QString , QString> logins;
};

#endif // CREER_UN_COMPTE_H
