#include "creer_un_compte.h"
#include "ui_creer_un_compte.h"

Creer_un_compte::Creer_un_compte(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Creer_un_compte)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}

Creer_un_compte::~Creer_un_compte()
{
    delete ui;
}

void Creer_un_compte::receiveVariables(){

}



void Creer_un_compte::on_buttonBox_accepted()
{
    QString identifiant = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    if(identifiant == "" || password == "")
    {
        QMessageBox::warning(this,"Erreur","Tous les champs doivent etre remplis");
    }
 //   else if(logins.find(identifiant) == logins.end()){
 //     logins[identifiant] = password;
 //  }
  // else{
   //    QMessageBox::warning(this,"Erreur","Cet identifiant est deja utilise");
  // }
}




