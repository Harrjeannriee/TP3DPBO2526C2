#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <vector>
#include "Client.h"
#include "Commission.h"
#include "Artwork.h"
#include "DigitalArtwork.h"
#include "TraditionalArtwork.h"

using namespace std;

void read_data(vector<Client*>& clients);
void save_data(vector<Client*>& clients);
void add_data(vector<Client*>& clients);
void show_data(vector<Client*>& clients);

#endif