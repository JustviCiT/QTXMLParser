#ifndef RADIO_H
#define RADIO_H

#include <QObject>
#include <QDebug>

class Radio
{
public:
    explicit Radio();
    void print();

    void setName(QString _name);
    void setMood(QString _mood);
    void setFav(bool _fav);
    void setID(int _id);

    QString gName() const;
    QString gMood() const;
    bool gFav() const;
    int giD() const;

private:
    QString name;
    QString mood;
    bool fav;
    int id;
};

#endif // RADIO_H
