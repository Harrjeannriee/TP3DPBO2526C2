import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class DataManager
{
    // file yang bakal dibaca namanya data.txt
    private static final String FILE_NAME = "data.txt";

    // BACA DATA DARI FILE DAN MASUKKAN CLIENT KE ARRAYLIST CLIENTS
    public static void readData(ArrayList<Client> clients)
    {
        // Buka file
        File file = new File(FILE_NAME);

        // Kalau file gak bisa dibuka, berarti data belum tersedia
        if (!file.exists())
        {
            System.out.println("Data file belum tersedia.");
            return;
        }

        try
        {
            BufferedReader reader = new BufferedReader(new FileReader(file));
            String line; // tempat buat nyimpan satu baris data

            // Selama masih ada baris di data.txt, baca terus
            while ((line = reader.readLine()) != null)
            {
                // Kalau baris kosong, skip
                if (line.isEmpty())
                {
                    continue;
                }

                // wadah sementara buat nyimpen data yang dipisah pake '|'
                String[] fields = line.split("\\|");

                // ambil data client
                int Id = Integer.parseInt(fields[0]);
                String Name = fields[1];
                String Email = fields[2];

                // ambil data commission
                int IdReq = Integer.parseInt(fields[3]);
                String Request = fields[4];
                String Deadline = fields[5];

                // ambil data artwork
                String ArtStyle = fields[6];
                String CreationDate = fields[7];
                String Price = fields[8];

                // ambil data type artwork
                String Type = fields[9];

                // Membuat object Client
                Client client = new Client(Id, Name, Email);

                // Membuat object Commission
                Commission commission = new Commission(
                    IdReq,
                    Request,
                    Deadline
                );

                // Membuat object Artwork, null karena belum tau tipenya digital atau tradisional
                Artwork artwork = null;

                // jika tipenya digital
                if (Type.equals("Digital"))
                {
                    String FileFormat = fields[10];
                    String Resolution = fields[11];

                    artwork = new DigitalArtwork(
                        ArtStyle,
                        CreationDate,
                        Price,
                        Resolution,
                        FileFormat
                    );
                }

                // jika tipenya tradisional
                else if (Type.equals("Traditional"))
                {
                    String Medium = fields[10];
                    String Size = fields[11];

                    artwork = new TraditionalArtwork(
                        ArtStyle,
                        CreationDate,
                        Price,
                        Medium,
                        Size
                    );
                }

                // kalau selain itu, skip data
                else
                {
                    continue;
                }

                // Composition
                commission.addArtwork(artwork);
                client.addCommission(commission);

                // Masukkan object Client ke ArrayList
                clients.add(client);
            }
            reader.close();
        }
        catch (IOException e)
        {
            System.out.println("Gagal membaca data.");
        }
    }


    // SIMPAN DATA KE FILE
    public static void saveData(ArrayList<Client> clients)
    {
        // Buka file untuk menulis
        try
        {
            PrintWriter file = new PrintWriter(new FileWriter(FILE_NAME));

            // ambil client satu-satu dari daftar clients
            for (Client client : clients)
            {
                // ambil commission dan artwork dari client
                Commission commission = client.getCommission();
                Artwork artwork = commission.getArtwork();

                // Kalau artwork merupakan DigitalArtwork
                if (artwork instanceof DigitalArtwork)
                {
                    DigitalArtwork digital = (DigitalArtwork) artwork;

                    file.println(
                        client.getId() + "|" +
                        client.getName() + "|" +
                        client.getEmail() + "|" +
                        commission.getIdreq() + "|" +
                        commission.getRequest() + "|" +
                        commission.getDeadline() + "|" +
                        artwork.getArtStyle() + "|" +
                        artwork.getCreationDate() + "|" +
                        artwork.getPrice() + "|" +
                        "Digital" + "|" +
                        digital.getFileFormat() + "|" +
                        digital.getResolution()
                    );
                }

                // Kalau artwork merupakan TraditionalArtwork
                else if (artwork instanceof TraditionalArtwork)
                {
                    TraditionalArtwork traditional =
                        (TraditionalArtwork) artwork;

                    file.println(
                        client.getId() + "|" +
                        client.getName() + "|" +
                        client.getEmail() + "|" +
                        commission.getIdreq() + "|" +
                        commission.getRequest() + "|" +
                        commission.getDeadline() + "|" +
                        artwork.getArtStyle() + "|" +
                        artwork.getCreationDate() + "|" +
                        artwork.getPrice() + "|" +
                        "Traditional" + "|" +
                        traditional.getMedium() + "|" +
                        traditional.getSize()
                    );
                }
            }
            file.close();
        }
        catch (IOException e)
        {
            System.out.println("Gagal menyimpan data.");
        }
    }


// MENERIMA DATA DARI USER
public static void addData(ArrayList<Client> clients, Scanner input)
{
    System.out.println("\n----------------------------------------");
    System.out.println("|          TAMBAH PESANAN              |");
    System.out.println("----------------------------------------");

    // wadah untuk data yang akan diinput
    int Id;
    String Name;
    String Email;
    int IdReq;
    String Request;
    String Deadline;
    String ArtStyle;
    String CreationDate;
    String Price;

    // input data dari user
    System.out.print("ID Client       : ");
    Id = Integer.parseInt(input.nextLine());

    System.out.print("Nama Client     : ");
    Name = input.nextLine();

    System.out.print("Email           : ");
    Email = input.nextLine();

    System.out.print("ID Request      : ");
    IdReq = Integer.parseInt(input.nextLine());

    System.out.print("Request         : ");
    Request = input.nextLine();

    System.out.print("Deadline        : ");
    Deadline = input.nextLine();

    System.out.print("Art Style       : ");
    ArtStyle = input.nextLine();

    System.out.print("Creation Date   : ");
    CreationDate = input.nextLine();

    System.out.print("Price           : ");
    Price = input.nextLine();

    System.out.println("\nJenis Artwork");
    System.out.println("1. Digital");
    System.out.println("2. Traditional");

    // pilih jenis artwork
    String choice;

    System.out.print("Pilih            : ");
    choice = input.nextLine();

    // wadah bernama artwork tapi belum menunjuk ke object Artwork manapun
    Artwork artwork = null;

    // jika pilihannya digital, buat object DigitalArtwork
    if (choice.equals("1"))
    {
        String FileFormat;
        String Resolution;

        System.out.print("File Format     : ");
        FileFormat = input.nextLine();

        System.out.print("Resolution      : ");
        Resolution = input.nextLine();

        // buat object DigitalArtwork dan object tersebut disimpan ke variable artwork
        artwork = new DigitalArtwork(
            ArtStyle,
            CreationDate,
            Price,
            Resolution,
            FileFormat
        );
    }

    // jika pilihannya tradisional, buat object TraditionalArtwork
    else if (choice.equals("2"))
    {
        String Medium;
        String Size;

        System.out.print("Medium          : ");
        Medium = input.nextLine();

        System.out.print("Size            : ");
        Size = input.nextLine();

        // buat object TraditionalArtwork dan object tersebut disimpan ke variable artwork
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
        System.out.println("\nPilihan tidak valid.");
        return;
    }

    // Membuat object Client
    Client client = new Client(
        Id,
        Name,
        Email
    );

    // Membuat object Commission
    Commission commission = new Commission(
        IdReq,
        Request,
        Deadline
    );

    // Composition
    commission.addArtwork(artwork);
    client.addCommission(commission);

    // Masukkan object Client ke ArrayList
    clients.add(client);

    // Simpan data ke TXT
    saveData(clients);

    System.out.println("\nPesanan berhasil ditambahkan!");
}


// MENAMPILKAN DATA
public static void showData(ArrayList<Client> clients)
{
    // Cek ada data atau tidak, kalau kosong beri tahu kosong
    if (clients.size() == 0)
    {
        System.out.println("\nBelum ada data pesanan.");
        return;
    }

    // kalau ada data, tampilkan data
    System.out.println("\n-----------------------------------------");
    System.out.println("|          DATA PESANAN ART STUDIO      |");
    System.out.println("-----------------------------------------");

    // ambil client satu-satu dari daftar clients
    for (Client client : clients)
    {
    // ambil commission dan artwork dari client
        Commission commission = client.getCommission();
        Artwork artwork = commission.getArtwork();

        System.out.println("\n####################################");
        System.out.println("CLIENT");
        System.out.println("ID       : " + client.getId());
        System.out.println("Name     : " + client.getName());
        System.out.println("Email    : " + client.getEmail());

        System.out.println("\nCOMMISSION");
        System.out.println("ID       : " + commission.getIdreq());
        System.out.println("Request  : " + commission.getRequest());
        System.out.println("Deadline : " + commission.getDeadline());

        System.out.println("\nARTWORK");
        System.out.println("Art Style     : " + artwork.getArtStyle());
        System.out.println("Creation Date : " + artwork.getCreationDate());
        System.out.println("Price         : " + artwork.getPrice());

        // kalau artwork digital, tampilkan data digital
        if (artwork instanceof DigitalArtwork)
        {
            DigitalArtwork digital = (DigitalArtwork) artwork;
            System.out.println("\nDIGITAL ARTWORK");
            System.out.println("File Format : " + digital.getFileFormat());
            System.out.println("Resolution  : " + digital.getResolution());
        }

        // kalau artwork tradisional, tampilkan data tradisional
        else if (artwork instanceof TraditionalArtwork)
        {
            TraditionalArtwork traditional = (TraditionalArtwork) artwork;

            System.out.println("\nTRADITIONAL ARTWORK");
            System.out.println("Medium      : " + traditional.getMedium());
            System.out.println("Size        : " + traditional.getSize());
        }
    }
    System.out.println("\n-----------------------------------------");
    }
}