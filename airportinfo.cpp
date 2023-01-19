#include "airportinfo.h"
#include "ui_mainwindow.h"

AirportInfo::AirportInfo(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void AirportInfo::setFrenchName(const QString& FrenchName) {
    ui->frenchLabelName->setText(FrenchName);
}

void AirportInfo::setEnglishName(const QString& EnglishName) {
    ui->englishLabelName->setText(EnglishName);
}

void AirportInfo::setGeoPoint(const QString& GeoPoint) {
    ui->geoPointLabelName->setText(GeoPoint);
}

void AirportInfo::setIATACode(const QString& IATACode) {
    ui->iataCodeLabelName->setText(IATACode);
}

void AirportInfo::setICAOCode(const QString& ICAOCode) {
    ui->icaoCodeLabelName->setText(ICAOCode);
}

void AirportInfo::setWikidataId(const QString& WikidataId) {
    ui->wikidataIdLabelName->setText(WikidataId);
}

void AirportInfo::setOperator(const QString& Operator) {
    ui->operatorLabelName->setText(Operator);
}

void AirportInfo::setCountry(const QString& Country) {
    ui->countryLabelName->setText(Country);
}

void AirportInfo::setCountryCode(const QString& CountryCode) {
    ui->countryCodeLabelName->setText(CountryCode);
}

void AirportInfo::setAltitude(const QString& Altitude) {
    ui->altitudeLabelName->setText(Altitude);
}
