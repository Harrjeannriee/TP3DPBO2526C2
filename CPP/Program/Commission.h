#ifndef COMMISSION_H
#define COMMISSION_H

#include <string>

using namespace std;

class Artwork;  //buat ngasih tau nanti ada class yang namanya 'Artwork'
class Commission
{
    private:
        int IdReq;
        string Request;
        string Deadline;
        Artwork* artwork;   //Commission punya tempat buat menyimpan/menunjuk ke Artwork

    public:
        // Constructor
        Commission(int IdReq, string Request, string Deadline);

        // Getter
        int getIdreq();
        string getRequest();
        string getDeadline();

        // Setter
        void setIdReq(int IdReq);
        void setRequest(string Request);
        void setDeadline(string Deadline);

        // Composition, Commission menyimpan pointer ke artwork di dalam dirinya sendri
        void addArtwork(Artwork* Artwork);

        // Getter Artwork
        Artwork* getArtwork();
};
#endif