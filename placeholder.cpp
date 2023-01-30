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

void PlaceHolder::on_Dashboard_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void PlaceHolder::on_Serveur_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void PlaceHolder::on_AirportsListButton_clicked()
{
        QFile mFile(":/csv_files/AirportsList.csv");
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


void PlaceHolder::on_FlightsButton_clicked()
{
    QFile mFile(":/csv_files/Vol.csv");
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


void PlaceHolder::on_Cartographie_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}




void PlaceHolder::on_CPUButton_clicked()
{
        QProcess process;
            process.start("cmd", QStringList() << "/c" << "wmic cpu get loadpercentage");
            process.waitForFinished();
        QTextStream stream(process.readAllStandardOutput());
            stream.readLine(); // ignore the first line
        int cpuUsage = stream.readLine().toInt();

        QLineSeries *series = new QLineSeries();

        for (int i = 0; i < 100; i++) {
                series->append(i, cpuUsage);
            }

    QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Consommation de CPU en fonction du temps");
        chart->createDefaultAxes();
        chart->axisX()->setTitleText("Temps (en secondes)");
        chart->axisY()->setTitleText("Consommation de CPU (%)");

    QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->setParent(ui->frameCPU);
        chartView->show();
}


void PlaceHolder::on_RAMButton_clicked()
{
    QProcess process;
        process.start("cmd", QStringList() << "/c" << "wmic OS get FreePhysicalMemory");
        process.waitForFinished();
        QByteArray output = process.readAllStandardOutput();
        QBuffer buffer(&output);
        buffer.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream stream(&buffer);
        stream.readLine(); // ignore the first line
        QString line = stream.readLine().simplified();
        QRegularExpression rx("(\\d+)");
        int freeMemory = 0;
        QRegularExpressionMatch match = rx.match(line);
        if (match.hasMatch()) {
            freeMemory = match.captured(1).toInt();
        }
        int totalMemory = 0;
        process.start("cmd", QStringList() << "/c" << "wmic OS get TotalVisibleMemorySize");
        process.waitForFinished();
        output = process.readAllStandardOutput();
        buffer.setData(output);
        buffer.open(QIODevice::ReadOnly | QIODevice::Text);
        stream.setDevice(&buffer);
        stream.readLine(); // ignore the first line
        line = stream.readLine().simplified();
        match = rx.match(line);
        if (match.hasMatch()) {
            totalMemory = match.captured(1).toInt();
        }
        int usedMemory = totalMemory - freeMemory;
        int ramUsage = (usedMemory * 100) / totalMemory;

    // Créer un graphique
    QLineSeries *series = new QLineSeries();

    for (int i = 0; i < 100; i++) {
        series->append(i, ramUsage);
        }

    // Créer un graphique à partir des données
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Consommation de RAM en fonction du temps");
        chart->createDefaultAxes();
        chart->axisX()->setTitleText("Temps (en secondes)");
        chart->axisY()->setTitleText("Consommation de RAM (en Mo)");

        // Afficher le graphique
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->setParent(ui->frameCPU);
        chartView->show();
}

