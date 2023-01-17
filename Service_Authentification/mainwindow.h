#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <map>
#include <algorithm>
#include <QObject>

#include "placeholder.h"
#include "creer_un_compte.h"



// C'est sur ce fichier que toutes les variables utilisées dans mainwindow.cpp doivent être initialisées

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
signals:
    void sendVariables();



private:
    int counter = 0;
    Ui::MainWindow *ui;
    PlaceHolder *placeholder;
    Creer_un_compte *compte;
    std::map<QString , QString> logins;

};

#endif // MAINWINDOW_H
