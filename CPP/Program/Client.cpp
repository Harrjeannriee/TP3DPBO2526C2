#include "Client.h"
#include "Commission.h"

// Constructor
Client::Client(int Id, string Name, string Email)
{
    this->Id = Id;
    this->Name = Name;
    this->Email = Email;
    this->commission = nullptr; //saat client baru dibuat, dia belum punya commissiom
}

// Getter
int Client::getId()
{
    return this->Id;
}
string Client::getName()
{
    return this->Name;
}
string Client::getEmail()
{
    return this->Email;
}

// Setter
void Client::setId(int Id)
{
    this->Id = Id;
}
void Client::setName(string Name)
{
    this->Name = Name;
}
void Client::setEmail(string Email)
{
    this->Email = Email;
}

// Composition. Commission yang diberi ke fungsi ini jadi commission milik client ini
void Client::addCommission(Commission* Commission)
{
    // commission milik client diisi dengan commissionyang diterima sebagai parameter
    this->commission = Commission;
}

// Getter Commission untuk mengambil commission dari client
Commission* Client::getCommission()
{
    return this->commission;
}