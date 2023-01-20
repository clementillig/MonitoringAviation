#ifndef PLACEHOLDER_H
#define PLACEHOLDER_H

#include <QMainWindow>

#include <QFile>
#include <QTextStream>
#include <QDebug>

#include <QString>
#include <QStringList>
#include <QFileDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class PlaceHolder; }
QT_END_NAMESPACE

class PlaceHolder : public QMainWindow
{
    Q_OBJECT

public:
    PlaceHolder(QWidget *parent = nullptr);
    ~PlaceHolder();



private slots:
    void on_importButton_clicked();

private:
    Ui::PlaceHolder *ui;
};
#endif // PLACEHOLDER_H
