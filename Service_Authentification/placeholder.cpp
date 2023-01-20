#include "placeholder.h"
#include "ui_placeholder.h"

PlaceHolder::PlaceHolder(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlaceHolder)
{
    ui->setupUi(this);
}

PlaceHolder::~PlaceHolder()
{
    delete ui;
}

void PlaceHolder::on_importButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Import CSV File : Importing", QDir::rootPath(), "CSV Files (*.csv)");

    qDebug()<<filePath<<" is the path of the file we imported";

    QFile mFile(filePath);
    if(!mFile.open(QFile::Text | QFile::ReadOnly))
    {
        return;
    }
    QTextStream inFile(&mFile);

    int cter = 0;
    QString readedLine = inFile.readLine();
    QStringList listValue = readedLine.split(";");
    ui->tableWidget->setColumnCount(listValue.size());
    ui->tableWidget->setHorizontalHeaderLabels(listValue);

    while(!inFile.atEnd())
    {
        QString readedLine = inFile.readLine();
        QStringList listValue = readedLine.split(";");

        cter +=1;
        ui->tableWidget->setRowCount(cter);

        for(int k = 0; k < listValue.size(); k++)
        {
            ui->tableWidget->setItem(cter-1, k, new QTableWidgetItem(listValue[k]));
        }
    }

    mFile.flush();
    mFile.close();
}
