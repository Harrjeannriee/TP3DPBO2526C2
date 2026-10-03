from Client import Client
from Commission import Commission
from DigitalArtwork import DigitalArtwork
from TraditionalArtwork import TraditionalArtwork


FILE_NAME = "data.txt"


# READ DATA
def read_data(clients):
    try:
        with open(FILE_NAME, "r") as file:

            for line in file:
                line = line.strip()

                if line == "":
                    continue

                data = line.split("|")

                Id = int(data[0])
                Name = data[1]
                Email = data[2]

                IdReq = int(data[3])
                Request = data[4]
                Deadline = data[5]

                ArtStyle = data[6]
                CreationDate = data[7]
                Price = data[8]

                Type = data[9]

                # Membuat object Client
                client = Client(Id, Name, Email)

                # Membuat object Commission
                commission = Commission(IdReq, Request, Deadline)

                # Membuat object Artwork
                if Type == "Digital":

                    FileFormat = data[10]
                    Resolution = data[11]

                    artwork = DigitalArtwork(
                        ArtStyle,
                        CreationDate,
                        Price,
                        FileFormat,
                        Resolution
                    )

                elif Type == "Traditional":

                    Medium = data[10]
                    Size = data[11]

                    artwork = TraditionalArtwork(
                        ArtStyle,
                        CreationDate,
                        Price,
                        Medium,
                        Size
                    )

                else:
                    continue

                # Composition
                commission.addArtwork(artwork)
                client.addCommission(commission)

                # Masukkan object Client ke list
                clients.append(client)

    except FileNotFoundError:
        print("Data file belum tersedia.")


# SAVE DATA
def save_data(clients):

    with open(FILE_NAME, "w") as file:

        for client in clients:

            commission = client.Commission
            artwork = commission.Artwork

            if isinstance(artwork, DigitalArtwork):

                file.write(
                    f"{client.getId()}|"
                    f"{client.getName()}|"
                    f"{client.getEmail()}|"
                    f"{commission.getIdreq()}|"
                    f"{commission.getRequest()}|"
                    f"{commission.getDeadline()}|"
                    f"{artwork.getArtStyle()}|"
                    f"{artwork.getCreationDate()}|"
                    f"{artwork.getPrice()}|"
                    f"Digital|"
                    f"{artwork.getFileFormat()}|"
                    f"{artwork.getResolution()}\n"
                )

            elif isinstance(artwork, TraditionalArtwork):

                file.write(
                    f"{client.getId()}|"
                    f"{client.getName()}|"
                    f"{client.getEmail()}|"
                    f"{commission.getIdreq()}|"
                    f"{commission.getRequest()}|"
                    f"{commission.getDeadline()}|"
                    f"{artwork.getArtStyle()}|"
                    f"{artwork.getCreationDate()}|"
                    f"{artwork.getPrice()}|"
                    f"Traditional|"
                    f"{artwork.getMedium()}|"
                    f"{artwork.getSize()}\n"
                )


# ADD / INPUT DATA
def add_data(clients):

    print("\n----------------------------------------")
    print("|          TAMBAH PESANAN              |")
    print("----------------------------------------")

    Id = int(input("ID Client       : "))
    Name = input("Nama Client     : ")
    Email = input("Email           : ")

    IdReq = int(input("ID Request      : "))
    Request = input("Request         : ")
    Deadline = input("Deadline        : ")

    ArtStyle = input("Art Style       : ")
    CreationDate = input("Creation Date   : ")
    Price = input("Price           : ")

    print("\nJenis Artwork")
    print("1. Digital")
    print("2. Traditional")

    choice = input("Pilih            : ")

    if choice == "1":

        FileFormat = input("File Format     : ")
        Resolution = input("Resolution      : ")

        artwork = DigitalArtwork(
            ArtStyle,
            CreationDate,
            Price,
            FileFormat,
            Resolution
        )

    elif choice == "2":

        Medium = input("Medium          : ")
        Size = input("Size            : ")

        artwork = TraditionalArtwork(
            ArtStyle,
            CreationDate,
            Price,
            Medium,
            Size
        )

    else:
        print("\nPilihan tidak valid.")
        return

    # Membuat object Client
    client = Client(Id, Name, Email)

    # Membuat object Commission
    commission = Commission(
        IdReq,
        Request,
        Deadline
    )

    # Composition
    commission.addArtwork(artwork)
    client.addCommission(commission)

    # Masukkan object Client ke list
    clients.append(client)

    # Simpan data ke TXT
    save_data(clients)

    print("\nPesanan berhasil ditambahkan!")


# SHOW DATA
def show_data(clients):

    if len(clients) == 0:
        print("\nBelum ada data pesanan.")
        return

    print("\n-----------------------------------------")
    print("|          DATA PESANAN ART STUDIO     |")
    print("-----------------------------------------")

    for client in clients:

        commission = client.Commission
        artwork = commission.Artwork

        print("\n####################################")

        print("CLIENT")
        print("ID       :", client.getId())
        print("Name     :", client.getName())
        print("Email    :", client.getEmail())

        print("\nCOMMISSION")
        print("ID       :", commission.getIdreq())
        print("Request  :", commission.getRequest())
        print("Deadline :", commission.getDeadline())

        print("\nARTWORK")
        print("Art Style     :", artwork.getArtStyle())
        print("Creation Date :", artwork.getCreationDate())
        print("Price         :", artwork.getPrice())

        if isinstance(artwork, DigitalArtwork):

            print("\nDIGITAL ARTWORK")
            print("File Format :", artwork.getFileFormat())
            print("Resolution  :", artwork.getResolution())

        elif isinstance(artwork, TraditionalArtwork):

            print("\nTRADITIONAL ARTWORK")
            print("Medium      :", artwork.getMedium())
            print("Size        :", artwork.getSize())

    print("\n-----------------------------------------")