#include "mainwindow.h"
#include "ui_mainwindow.h"

//Pour régler le bug de "ui.machin.h not found" il suffit de remplacer le u de ui par U puis de le rechanger par u



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

    if( logins.find(identifiant) != logins.end() && logins[identifiant] == password){
        placeholder = new PlaceHolder(this); // Ces lignes permettent d'ouvrir une nouvelle page de type MainWindow ( différent de la classe MainWindow, c'est un type d'application Qt )
        placeholder->setWindowState(Qt::WindowMaximized);
        placeholder->setWindowTitle("Dashboard");
        placeholder->show();
        hide();
    }
    else if (identifiant == "" || password == "")
    {
        QMessageBox::warning(this,"Erreur","Tous les champs doivent être remplis");
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

void MainWindow::receivebackVariables(std::map<QString , QString> m_logins){
   this->logins = m_logins;
}

void MainWindow::on_pushButton_2_clicked()
{
    compte = new Creer_un_compte(this);
    compte->setWindowTitle("Creer un compte");
    compte->show();

    connect(this, &MainWindow::sendVariables, compte, &Creer_un_compte::receiveVariables); //On connecte mainwindow à compte
    emit sendVariables(logins);

    connect(compte, &Creer_un_compte::sendbackVariables, this, &MainWindow::receivebackVariables); //On connecte compte à mainwindow (la relation de connexion par signals and slots n'est pas une relation d'équivalence)

}


