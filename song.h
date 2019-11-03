#ifndef SONG_H
#define SONG_H

#include <QObject>
#include <QDebug>

class Song
{
public:
    explicit Song();
    void print();

    void setArtist(QString);
    void setiD(int);
    void setAlbum(QString);
    void setFav(bool);
    void setID(int);

    QString gArtist();
    QString gAlbum();
    bool gFav();
    int giD();

private:
    int id;
    QString artist;
    QString album;
    bool fav;
};

#endif // SONG_H
