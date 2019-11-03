#ifndef CONTACT_H
#define CONTACT_H

#include <QObject>
#include <QDebug>

class Contact
{
public:
    explicit Contact();
    explicit Contact(QString _name,
                     QString _phone_home,
                     QString _phone_work,
                     bool _fav);

    void print();

    void setName(QString);
    void setPhoneHome(QString);
    void setPhoneWork(QString);
    void setFav(bool);
    void setID(int);

    QString gName();
    QString gPhoneHome();
    QString gPhoneWork();
    bool gFav();
    int giD();

private:
    int id;
    QString name;
    QString phone_home;
    QString phone_work;
    bool fav;
};

#endif // CONTACT_H
