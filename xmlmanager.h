#ifndef IPCMANAGER_H
#define IPCMANAGER_H

#include <QTextStream>
#include <QObject>
#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QDebug>
#include <datasource.h>

//#define XMLNAME_ROOT    "root"
#define XMLNAME_ROOT_SONGS  "songs"
#define XMLNAME_ROOT_SONG   "song"
//#define XMLNAME_ROOT_RADIOS  "stations"
//#define XMLNAME_ROOT_RADIO   "radio"
#define XMLNAME_ROOT_CONTACTS  "contacts"
#define XMLNAME_ROOT_CONTACT   "contact"
#define XMLNAME_ROOT "contacts"
#define XMLNAME_ROOT_RADIOS  "items"
#define XMLNAME_ROOT_RADIO   "contact"


class XMLManager : public QObject
{
    Q_OBJECT
public:

    explicit XMLManager(QIODevice*, DataSource *, QObject *parent = nullptr);

    bool parseXML();
    void writeXML();

private:
    void readFirstLevel();

    void readRadios();
    void readRadio();

    void readContacts();
    void readContact();

//    void changeFavRadio(int ,bool newfav);

private:
    QIODevice* device;
    QString xmlFilename;
    DataSource* ds;
    QXmlStreamReader reader;
    QXmlStreamWriter writer;

signals:

public slots:
};

#endif // IPCMANAGER_H
