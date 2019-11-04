#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <QObject>
#include <QMap>
#include <QDebug>

#include <contact.h>
#include <radio.h>
#include <song.h>

class DataSource : public QObject
{
    Q_OBJECT
public:
    explicit DataSource(QObject *parent = nullptr);
    void print();

    void addSong(Song *);
    void addRadio(Radio *);
    void addContact(Contact *);
    void clean();


    QMap<int, Song*> m_Songs;
    QMap<int, Radio*> m_Radios;
    QMap<int, Contact*> m_Contacts;

private:
    int key_songs;
    int key_radios;
    int key_contacts;

signals:
public slots:


};

#endif // DATASOURCE_H
