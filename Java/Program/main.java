import java.util.ArrayList;
import java.util.Scanner;

public class main
{
    public static void main(String[] args)
    {
        ArrayList<Client> clients = new ArrayList<>();
        Scanner input = new Scanner(System.in);

        // Baca data dari data.txt
        DataManager.readData(clients);

        while (true)
        {
            System.out.println("\n----------------------------------------");
            System.out.println("|          ART STUDIO MENU             |");
            System.out.println("----------------------------------------");
            System.out.println("| 1. Show Data                         |");
            System.out.println("| 2. Add Commission                    |");
            System.out.println("| 3. Exit                              |");
            System.out.println("----------------------------------------");

            System.out.print("Pilih : ");
            String choice = input.nextLine();

            if (choice.equals("1"))
            {
                DataManager.showData(clients);
            }

            else if (choice.equals("2"))
            {
                DataManager.addData(clients, input);
            }

            else if (choice.equals("3"))
            {
                System.out.println("Program selesai.");
                break;
            }

            else
            {
                System.out.println("Pilihan tidak valid. Silakan coba lagi.");
            }
        }

        input.close();
    }
}
