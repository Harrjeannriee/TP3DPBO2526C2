#include "Commission.h"
#include "Artwork.h"

// constructor, intinya kalau mau bikin sebuah Commision, harus kasih IdReq, Request, Deadline
Commission::Commission(int IdReq, string Request, string Deadline)
{
    this->IdReq = IdReq;
    this->Request = Request;
    this->Deadline = Deadline;
    this->artwork = nullptr; // saat commission baru dibuat, dia belum punya artwork
}

// Getter
int Commission::getIdreq()
{
    return this->IdReq;
}
string Commission::getRequest()
{
    return this->Request;
}
string Commission::getDeadline()
{
    return this->Deadline;
}

// Setter
void Commission::setIdReq(int IdReq)
{
    this->IdReq = IdReq;
}
void Commission::setRequest(string Request)
{
    this->Request = Request;
}
void Commission::setDeadline(string Deadline)
{
    this->Deadline = Deadline;
}

// Composition. (Bahasa bayi buat saya: Commission, nih ada artwork, simpan artwork ini di gue y)
void Commission::addArtwork(Artwork* Artwork)
{
    this->artwork = Artwork;
}

// Getter Artwork
Artwork* Commission::getArtwork()
{
    return this->artwork;
}