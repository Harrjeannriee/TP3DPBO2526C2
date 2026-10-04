#include "Artwork.h"

Artwork::Artwork(string ArtStyle, string CreationDate, string Price)
{
    this->ArtStyle = ArtStyle;
    this->CreationDate = CreationDate;
    this->Price = Price;
}

// Getter
string Artwork::getArtStyle()
{
    return this->ArtStyle;
}
string Artwork::getCreationDate()
{
    return this->CreationDate;
}
string Artwork::getPrice()
{
    return this->Price;
}

// Setter
void Artwork::setArtStyle(string ArtStyle)
{
    this->ArtStyle = ArtStyle;
}
void Artwork::setCreationDate(string CreationDate)
{
    this->CreationDate = CreationDate;
}
void Artwork::setPrice(string Price)
{
    this->Price = Price;
}