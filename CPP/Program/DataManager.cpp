#include "dataManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// file yang bakal dibaca namanya data.txt
const string FILE_NAME = "data.txt";

// BACA DATA DARI FILE DAN MASUKKAN CLIENT KE VECTOR CLIENTS
void read_data(vector<Client*>& clients)
{
    ifstream file(FILE_NAME);   //Buka file
    // Kalau file gak bisa dibuka, berrati data belum tersedia
    if (!file.is_open())
    {
        cout << "Data file belum tersedia." << endl;
        return;
    }

    string line;    //tempat buat nyimpan satu baris data

    // Selama masih ada baris di data.txt, baca terus
    while (getline(file, line))
    {
        // Kalau baris kosong, skip
        if (line.empty())
        {
            continue;
        }

        // wadah sementara buat nyimpen data yang dipisah pake '|'
        stringstream ss(line);
        string data;
        vector<string> fields;

        // setiap ketemu |, pecah data
        while (getline(ss, data, '|'))
        {
            fields.push_back(data);
        }

        // ambil data client
        int Id = stoi(fields[0]);
        string Name = fields[1];
        string Email = fields[2];

        // ambil data commission
        int IdReq = stoi(fields[3]);
        string Request = fields[4];
        string Deadline = fields[5];

        // ambil data artwork
        string ArtStyle = fields[6];
        string CreationDate = fields[7];
        string Price = fields[8];

        // ambil data type artwork
        string Type = fields[9];

        // Membuat object Client
        Client* client = new Client(Id, Name, Email);

        // Membuat object Commission
        Commission* commission = new Commission(
            IdReq,
            Request,
            Deadline
        );

        // Membuat object Artwork. null karena belum tau tipenya digital atau tradisional
        Artwork* artwork = nullptr;

        //  jika tipenya digital
        if (Type == "Digital")
        {
            string FileFormat = fields[10];
            string Resolution = fields[11];

            artwork = new DigitalArtwork(
                ArtStyle,
                CreationDate,
                Price,
                Resolution,
                FileFormat
            );
        }
        // jike tipenya tradisional
        else if (Type == "Traditional")
        {
            string Medium = fields[10];
            string Size = fields[11];

            artwork = new TraditionalArtwork(
                ArtStyle,
                CreationDate,
                Price,
                Medium,
                Size
            );
        }
        // kalau selain itu, hapus data 
        else
        {
            delete commission;
            delete client;
            continue;
        }

        // Composition
        commission->addArtwork(artwork);
        client->addCommission(commission);

        // Masukkan object Client ke vector
        clients.push_back(client);
    }

    file.close();
}


// SIMPAN DATA KE FILE
void save_data(vector<Client*>& clients)
{
    // Buka file untuk menulis
    ofstream file(FILE_NAME);

    // ambil client satu" dari daftar clients
    for (Client* client : clients)
    {
        // ambil commission dan artwork dari client
        Commission* commission = client->getCommission();
        Artwork* artwork = commission->getArtwork();

        // memperlakukan pointer Artwork sebagai DigitalArtwork supaya bisa mengakses fitur khusus DigitalArtwork
        DigitalArtwork* digital =
            static_cast<DigitalArtwork*>(artwork);
        // memperlakukan pointer Artwork sebagai TraditionalArtwork supaya bisa mengakses fitur khusus TraditionalArtwork
        TraditionalArtwork* traditional =
            static_cast<TraditionalArtwork*>(artwork);

        // kalau pointer digital gak kosong, berarti data dianggap DigitalArtwork
        if (digital != nullptr)
        {
            file << client->getId() << "|"
                 << client->getName() << "|"
                 << client->getEmail() << "|"
                 << commission->getIdreq() << "|"
                 << commission->getRequest() << "|"
                 << commission->getDeadline() << "|"
                 << artwork->getArtStyle() << "|"
                 << artwork->getCreationDate() << "|"
                 << artwork->getPrice() << "|"
                 << "Digital" << "|"
                 << digital->getFileFormat() << "|"
                 << digital->getResolution()
                 << endl;
        }
        // kalau pointer traditional gak kosong, berarti data dianggap TraditionalArtwork
        else if (traditional != nullptr)
        {
            file << client->getId() << "|"
                 << client->getName() << "|"
                 << client->getEmail() << "|"
                 << commission->getIdreq() << "|"
                 << commission->getRequest() << "|"
                 << commission->getDeadline() << "|"
                 << artwork->getArtStyle() << "|"
                 << artwork->getCreationDate() << "|"
                 << artwork->getPrice() << "|"
                 << "Traditional" << "|"
                 << traditional->getMedium() << "|"
                 << traditional->getSize()
                 << endl;
        }
    }
    file.close();
}


// MENERIMA DATA DARI USER
void add_data(vector<Client*>& clients) //menerima vector yang isinya kumpulan pointer ke Client
{
    cout << "\n----------------------------------------" << endl;
    cout << "|          TAMBAH PESANAN              |" << endl;
    cout << "----------------------------------------" << endl;

    // wadah untuk data yang akan diinput
    int Id;
    string Name;
    string Email;
    int IdReq;
    string Request;
    string Deadline;
    string ArtStyle;
    string CreationDate;
    string Price;

    // input data dari user
    cout << "ID Client       : ";
    cin >> Id;
    cin.ignore();

    cout << "Nama Client     : ";
    getline(cin, Name); //mengambil seluruh baris input, termasuk spasi

    cout << "Email           : ";
    getline(cin, Email);

    cout << "ID Request      : ";
    cin >> IdReq;
    cin.ignore();

    cout << "Request         : ";
    getline(cin, Request);

    cout << "Deadline        : ";
    getline(cin, Deadline);

    cout << "Art Style       : ";
    getline(cin, ArtStyle);

    cout << "Creation Date   : ";
    getline(cin, CreationDate);

    cout << "Price           : ";
    getline(cin, Price);

    cout << "\nJenis Artwork" << endl;
    cout << "1. Digital" << endl;
    cout << "2. Traditional" << endl;

    // pilih jenis artwork
    string choice;
    cout << "Pilih            : ";
    getline(cin, choice);

    // wadah bernama artwork tapi belum menunjuk ke object Artwork manapun
    Artwork* artwork = nullptr;

    // jika pilihannya digital, buat object DigitalArtwork
    if (choice == "1")
    {
        string FileFormat;
        string Resolution;

        cout << "File Format     : ";
        getline(cin, FileFormat);

        cout << "Resolution      : ";
        getline(cin, Resolution);

        // buat object DigitalArtwork dan alamat object disimpan ke pointer artwork
        artwork = new DigitalArtwork(
            ArtStyle,
            CreationDate,
            Price,
            Resolution,
            FileFormat
        );
    }
    // jika pilihannya tradisional, buat object TraditionalArtwork
    else if (choice == "2")
    {
        string Medium;
        string Size;

        cout << "Medium          : ";
        getline(cin, Medium);

        cout << "Size            : ";
        getline(cin, Size);

        // buat object TraditionalArtwork dan alamat object disimpan ke pointer artwork
        artwork = new TraditionalArtwork(
            ArtStyle,
            CreationDate,
            Price,
            Medium,
            Size
        );
    }
    // selain itu tidak valid
    else
    {
        cout << "\nPilihan tidak valid." << endl;
        return;
    }

    // Membuat object Client
    Client* client = new Client(
        Id,
        Name,
        Email
    );

    // Membuat object Commission
    Commission* commission = new Commission(
        IdReq,
        Request,
        Deadline
    );

    // Composition
    commission->addArtwork(artwork);    //Commission pnya Artwork, simpan Artwork di Commission
    client->addCommission(commission);  //Client pnya Commission, simpan Commission di Client

    // Masukkan object Client ke vector
    clients.push_back(client);

    // Simpan data ke TXT
    save_data(clients);

    cout << "\nPesanan berhasil ditambahkan!" << endl;
}


// MENAMPILKAN DATA
void show_data(vector<Client*>& clients)
{
    // Cek ada data atau tidak, kalau kosong beri tahu kosong
    if (clients.size() == 0)
    {
        cout << "\nBelum ada data pesanan." << endl;
        return;
    }

    // kalau ada data, tampilkan data
    cout << "\n-----------------------------------------" << endl;
    cout << "|          DATA PESANAN ART STUDIO      |" << endl;
    cout << "-----------------------------------------" << endl;

    // ambil client satu" dari daftar clients
    for (Client* client : clients)
    {
        // ambil commission dan artwork dari client
        Commission* commission = client->getCommission();
        Artwork* artwork = commission->getArtwork();

        cout << "\n####################################" << endl;

        cout << "CLIENT" << endl;
        cout << "ID       : " << client->getId() << endl;
        cout << "Name     : " << client->getName() << endl;
        cout << "Email    : " << client->getEmail() << endl;

        cout << "\nCOMMISSION" << endl;
        cout << "ID       : " << commission->getIdreq() << endl;
        cout << "Request  : " << commission->getRequest() << endl;
        cout << "Deadline : " << commission->getDeadline() << endl;

        cout << "\nARTWORK" << endl;
        cout << "Art Style     : " << artwork->getArtStyle() << endl;
        cout << "Creation Date : " << artwork->getCreationDate() << endl;
        cout << "Price         : " << artwork->getPrice() << endl;

        // memperlakukan pointer Artwork sebagai DigitalArtwork supaya bisa mengakses fitur khusus DigitalArtwork
        DigitalArtwork* digital =
            static_cast<DigitalArtwork*>(artwork);
        // memperlakukan pointer Artwork sebagai TraditionalArtwork supaya bisa mengakses fitur khusus TraditionalArtwork
        TraditionalArtwork* traditional =
            static_cast<TraditionalArtwork*>(artwork);

        // kalau artwork digital, tampilkan data digital
        if (digital != nullptr)
        {
            cout << "\nDIGITAL ARTWORK" << endl;
            cout << "File Format : "
                 << digital->getFileFormat() << endl;
            cout << "Resolution  : "
                 << digital->getResolution() << endl;
        }
        // kalau artwork tradisional, tampilkan data tradisional
        else if (traditional != nullptr)
        {
            cout << "\nTRADITIONAL ARTWORK" << endl;
            cout << "Medium      : "
                 << traditional->getMedium() << endl;
            cout << "Size        : "
                 << traditional->getSize() << endl;
        }
    }

    cout << "\n-----------------------------------------" << endl;
}
