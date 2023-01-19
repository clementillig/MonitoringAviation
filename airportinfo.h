#ifndef AIRPORTINFO_H
#define AIRPORTINFO_H

#include <QWidget>

namespace Ui {
class AirportInfo;
}

class AirportInfo : public QWidget
{
    Q_OBJECT

public:
    explicit AirportInfo(QWidget *parent = nullptr);
    void setFrenchName(const QString& frenchName);
    void setEnglishName(const QString& EnglishName);
    void setGeoPoint(const QString& GeoPoint);
    void setIATACode(const QString& IATACode);
    void setICAOCode(const QString& ICAOcode);
    void setWikidataId(const QString& WikidataId);
    void setOperator(const QString& Operator);
    void setCountry(const QString& Country);
    void setCountryCode(const QString& CountryCode);
    void setAltitude(const QString& Altitude);

signals:

};

#endif // AIRPORTINFO_H
