#include "xmlmanager.h"

XMLManager::XMLManager(QIODevice* _device ,DataSource* ds, QObject *parent) : QObject(parent)
{
    this->ds = ds;
    this->device = _device;
    this->reader.setDevice(_device);
}

bool XMLManager::parseXML()
{
    if (reader.readNextStartElement()) {
//        qDebug()<<reader.name();
        if (reader.name() == XMLNAME_ROOT){
            readFirstLevel();
        }else{
            qCritical()<<"ERROR reading XMLFILE";
            return false;
        }
    }

    return true;
}

void XMLManager::readFirstLevel(){
    while(reader.readNextStartElement()){
        if(reader.name() == XMLNAME_ROOT_RADIOS){
            readRadios();
        }else if (reader.name() == XMLNAME_ROOT_CONTACTS){
            readContacts();
        }else{
            reader.skipCurrentElement();
        }
    }
}

void XMLManager::readRadios()
{
    while(reader.readNextStartElement()){
        if(reader.name() == XMLNAME_ROOT_RADIO)
            readRadio();
        else
            reader.skipCurrentElement();
    }
}

// roba cool
// bool test = true;
// QString s = QString::number(test);

void XMLManager::readRadio()
{
    Q_ASSERT(reader.isStartElement() &&
             reader.name() == XMLNAME_ROOT_RADIO);

    Radio* r = new Radio();

    while (reader.readNextStartElement()) {
        if (reader.name() == "name")
            r->setName(reader.readElementText());
        else if (reader.name() == "fav")
            r->setFav( QVariant( reader.readElementText()).toBool() );
        else if (reader.name() == "id")
            r->setID( QVariant( reader.readElementText()).toInt() );
        else
            reader.skipCurrentElement();
    }
//    r->print();

    ds->addRadio(r);
}


void XMLManager::readContacts()
{
    while(reader.readNextStartElement()){
        if(reader.name() == XMLNAME_ROOT_CONTACT)
            readContact();
        else
            reader.skipCurrentElement();
    }
}

void XMLManager::readContact()
{
    Q_ASSERT(reader.isStartElement() &&
             reader.name() == XMLNAME_ROOT_CONTACT);

    Contact* r = new Contact();

    while (reader.readNextStartElement()) {
        if (reader.name() == "name")
            r->setName(reader.readElementText());
        else if (reader.name() == "phone_home")
            r->setPhoneHome(reader.readElementText());
        else if (reader.name() == "phone_work")
            r->setPhoneWork(reader.readElementText());
        else if (reader.name() == "fav"){
            r->setFav( QVariant( reader.readElementText()).toBool() );
        }else if (reader.name() == "id")
            r->setID( QVariant( reader.readElementText()).toInt() );
        else
            reader.skipCurrentElement();
    }
//    r->print();

    ds->addContact(r);
}
