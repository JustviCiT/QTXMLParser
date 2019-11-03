#include <QCoreApplication>
#include <QSharedMemory>
#include <QDebug>
#include <QFile>
#include <QXmlStreamReader>

#include <xmlmanager.h>
#include <datasource.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString mySharedMem = "SharedMem";
    QFile* myFile = new QFile("example-xml.xml");

    if(!myFile->open(QIODevice::ReadWrite | QFile::Text)){
        qDebug()<<"File Openning Error"<< myFile->errorString();
        exit(-1);
    }

    DataSource *ds = new DataSource();
    XMLManager *ipc = new XMLManager(myFile, ds);

    ipc->parseXML();
    ds->print();

    myFile->close();


//    QSharedMemory *sharedSpace = new QSharedMemory(mySharedMem);
//    bool isAttached = sharedSpace->attach(QSharedMemory::ReadOnly);
//    isAttached ? qDebug()<<"Attached" :
//                 qDebug()<<"NotAttached";

//    return a.exec();
}
