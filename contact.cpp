#include "contact.h"

Contact::Contact()
{

}

Contact::Contact(QString _name,
                 QString _phone_home,
                 QString _phone_work,
                 bool _fav)
{
    this->name = _name;
    this->phone_home = _phone_home;
    this->phone_work = _phone_work;
    this->fav = _fav;
}


void Contact::print(){
    qDebug() << "NAME: "<<  name<< " PHONE HOME "<< phone_home << " PHONE WORK "<< phone_work << "FAV" << fav << " ID "<< id;
}

void Contact::setName(QString _name)
{
    name = _name;
}

void Contact::setPhoneHome(QString _home)
{
    phone_home = _home;
}

void Contact::setPhoneWork(QString _work)
{
    phone_work =_work;
}

void Contact::setFav(bool _fav)
{
    fav = _fav;
}

void Contact::setID(int _id)
{
    id = _id;
}
