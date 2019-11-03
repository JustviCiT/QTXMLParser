#include "song.h"

Song::Song()
{

}

void Song::print(){

}

/***
 * SETTERS
 */

void Song::setArtist(QString _artist)
{
    artist = _artist;
}

void Song::setiD(int _id)
{
    id = _id;
}

void Song::setAlbum(QString _album)
{
    album = _album;
}

void Song::setFav(bool _fav)
{
    fav = _fav;
}


/***
 * GETTERS
 */
QString Song::gArtist()
{
    return artist;
}

QString Song::gAlbum()
{
    return album;
}

bool Song::gFav()
{
    return fav;
}

int Song::giD()
{
    return id;
}
