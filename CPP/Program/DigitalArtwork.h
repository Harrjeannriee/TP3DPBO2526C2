#ifndef DIGITALARTWORK_H
#define DIGITALARTWORK_H

#include "Artwork.h"

using namespace std;

// DigitalArtwork adalah anak dari Artwork
class DigitalArtwork : public Artwork
{
    // data khusus DigitalArtwork
    private:
        string Resolution;
        string FileFormat;

    public:
        DigitalArtwork(string ArtStyle, string CreationDate, string Price, string Resolution, string FileFormat);

        // Getter
        string getResolution();
        string getFileFormat();

        // Setter
        void setResolution(string Resolution);
        void setFileFormat(string FileFormat);
};
#endif