#ifndef PLACEHOLDER_H
#define PLACEHOLDER_H

#include <QMainWindow>

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
