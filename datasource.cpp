#include "datasource.h"

DataSource::DataSource(QObject *parent) : QObject(parent)
{
    key_songs = 0;
    key_radios = 0;
    key_contacts = 0;
}

void DataSource::addSong(Song * mysong){
    m_Songs[key_songs] = mysong;
    key_songs ++;
}
void DataSource::addRadio(Radio * myradio){
    m_Radios[key_radios] = myradio;
    key_radios ++;
}
void DataSource::addContact(Contact *mycontact){
    m_Contacts[key_contacts] = mycontact;
    key_contacts ++;
}

void DataSource::clean()
{
    m_Songs.clear();
    m_Radios.clear();
    m_Contacts.clear();

    key_songs = 0;
    key_radios = 0;
    key_contacts = 0;
}

void DataSource::print(){
    QMapIterator<int, Radio* > i(m_Radios);
    QMapIterator<int, Song* > j(m_Songs);
    QMapIterator<int, Contact* > k(m_Contacts);

    while (i.hasNext()) {
        i.next();
        qDebug()<< i.key() << ": ";
        i.value()->print();
    }
    qDebug()<<" ---------------------------------- ";
    while (j.hasNext()) {
        j.next();
        qDebug()<< j.key() << ": ";
        j.value()->print();
    }
    qDebug()<<" ---------------------------------- ";
    while (k.hasNext()) {
        k.next();
        qDebug()<< k.key() << ": ";
        k.value()->print();
    }
}
