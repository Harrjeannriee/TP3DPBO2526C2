#ifndef ARTWORK_H
#define ARTWORK_H

#include <string>

using namespace std;

class Artwork
{
    private:
        string ArtStyle;
        string CreationDate;
        string Price;

    public:
        // Constructor, kalau mau bikin artwork, kasih ArtStyle, CreationDate, Price 
        Artwork(string ArtStyle, string CreationDate, string Price);

        // Getter
        string getArtStyle();
        string getCreationDate();
        string getPrice();

        // Setter
        void setArtStyle(string ArtStyle);
        void setCreationDate(string CreationDate);
        void setPrice(string Price);
};
#endif