#ifndef CLIENT_H
#define CLIENT_H

#include <string>

using namespace std;

class Commission;
class Client
{
    private:
        int Id;
        string Name;
        string Email;
        Commission* commission;

    public:
        // Constructor
        Client(int Id, string Name, string Email);

        // Getter
        int getId();
        string getName();
        string getEmail();

        // Setter
        void setId(int Id);
        void setName(string Name);
        void setEmail(string Email);

        // Composition (note buat saya, class*, parameter tipe pointer)
        void addCommission(Commission* Commission);

        // Pointer commission yang menunjuk ke object Commission
        Commission* getCommission();
};
#endif