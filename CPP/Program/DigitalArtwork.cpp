#include "DigitalArtwork.h"

// kalau mau bikin DigitalArtwork, kasih 5 data ini
DigitalArtwork::DigitalArtwork(string ArtStyle, string CreationDate, string Price,
                               string Resolution, string FileFormat)
    : Artwork(ArtStyle, CreationDate, Price)    //panggil constructor milik parent (Artwork)
{
    this->Resolution = Resolution;
    this->FileFormat = FileFormat;
}

// Getter
string DigitalArtwork::getResolution()
{
    return this->Resolution;
}
string DigitalArtwork::getFileFormat()
{
    return this->FileFormat;
}

// Setter
void DigitalArtwork::setResolution(string Resolution)
{
    this->Resolution = Resolution;
}
void DigitalArtwork::setFileFormat(string FileFormat)
{
    this->FileFormat = FileFormat;
}