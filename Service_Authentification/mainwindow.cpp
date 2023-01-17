#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password); // Cette ligne permet de cacher le mot de passe lorsqu'il est tapé


}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString identifiant = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    if(identifiant == "test" && password == "test"){
        placeholder = new PlaceHolder(this); // Ces 2 lignes permettent d'ouvrir une nouvelle page MainWindow
        placeholder->show();
        hide();
    }
    else{
        counter += 1;
        QMessageBox::warning(this,"Erreur","L'identifiant ou le mot de passe est incorrect.");
        if(counter == 3)
        {
            ui->stackedWidget->setCurrentIndex(1); // Cela permet de Switcher de page à l'aide du stackedWidget
                                                   // Ici, ça switch vers une page vide, ce qui cache le bouton
                                                   // De connexion et les lignes pour ecrires les logins
        }


}
}


void MainWindow::on_pushButton_2_clicked()
{
    compte = new Creer_un_compte(this);
    compte->setWindowTitle("Creer un compte");
    compte->show();

    connect(this, &MainWindow::sendVariables, compte, &Creer_un_compte::receiveVariables);


}
