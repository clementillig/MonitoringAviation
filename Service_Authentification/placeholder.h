#ifndef PLACEHOLDER_H
#define PLACEHOLDER_H

#include <QMainWindow>

// Pour permettre d'ouvrir une nouvelle page il faut faire :
// clique droit sur le projet < add New < Qt Designer Form Class < MainWindow

namespace Ui {
class PlaceHolder;
}

class PlaceHolder : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlaceHolder(QWidget *parent = 0);
    ~PlaceHolder();

private:
    Ui::PlaceHolder *ui;
};

#endif // PLACEHOLDER_H
