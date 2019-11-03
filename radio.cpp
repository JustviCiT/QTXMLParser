#include "radio.h"

Radio::Radio()
{

}

void Radio::print(){
    qDebug() << "NAME: "<<  name<< " FAV "<< fav << " ID "<< id <<" MOOD "<< mood;
}

/**
 * SETTERS *
 */
void Radio::setName(QString _name)
{
    name = _name;
}

void Radio::setMood(QString _mood)
{
    mood = _mood;
}

void Radio::setFav(bool _fav)
{
   fav = _fav;
}

void Radio::setID(int _id)
{
    id = _id;
}
/**
 * GETTERS *
 */

QString Radio::gName() const
{
    return name;
}

QString Radio::gMood() const
{
    return mood;
}

bool Radio::gFav() const
{
    return fav;
}

int Radio::giD() const
{
    return id;
}
