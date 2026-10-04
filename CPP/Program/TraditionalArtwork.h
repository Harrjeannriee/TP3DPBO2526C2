#ifndef TRADITIONALARTWORK_H
#define TRADITIONALARTWORK_H

#include "Artwork.h"

using namespace std;

// TraditionalArtwork adalah anak dari Artwork
class TraditionalArtwork : public Artwork
{
    private:
        string Medium;
        string Size;

    public:
        TraditionalArtwork(string ArtStyle, string CreationDate, string Price, string Medium, string Size);

        // Getter
        string getMedium();
        string getSize();

        // Setter
        void setMedium(string Medium);
        void setSize(string Size);
};
#endif