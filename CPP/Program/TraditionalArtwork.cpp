#include "TraditionalArtwork.h"

TraditionalArtwork::TraditionalArtwork(string ArtStyle, string CreationDate, string Price,
                                       string Medium, string Size)
    : Artwork(ArtStyle, CreationDate, Price)
{
    this->Medium = Medium;
    this->Size = Size;
}

// Getter
string TraditionalArtwork::getMedium()
{
    return this->Medium;
}
string TraditionalArtwork::getSize()
{
    return this->Size;
}

// Setter
void TraditionalArtwork::setMedium(string Medium)
{
    this->Medium = Medium;
}
void TraditionalArtwork::setSize(string Size)
{
    this->Size = Size;
}