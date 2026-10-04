#include <iostream>
#include <vector>

#include "dataManager.h"

using namespace std;

int main()
{
    // membuat tempat untuk menyimpan kumpulan pointer ke object Client
    vector<Client*> clients;
    read_data(clients); //baca data txt

    // jalankan program terus menerus selama user gak milih berhenti(exit)
    while (true)
    {
        cout << "\n----------------------------------------" << endl;
        cout << "|            ART STUDIO                |" << endl;
        cout << "----------------------------------------" << endl;
        cout << "| 1. Show Data                         |" << endl;
        cout << "| 2. Add Commission                    |" << endl;
        cout << "| 3. Exit                              |" << endl;
        cout << "----------------------------------------" << endl;

        string choice;
        cout << "Pilih menu : ";
        getline(cin, choice);

        if (choice == "1")
        {
            show_data(clients);
        }
        else if (choice == "2")
        {
            add_data(clients);
        }
        else if (choice == "3")
        {
            cout << "\nProgram selesai." << endl;
            break;
        }
        else
        {
            cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}