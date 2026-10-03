from dataManager import read_data, add_data, show_data


def main():

    clients = []

    read_data(clients)

    while True:

        print("\n----------------------------------------")
        print("|            ART STUDIO                |")
        print("----------------------------------------")
        print("| 1. Show Data                         |")
        print("| 2. Add Commission                    |")
        print("| 3. Exit                              |")
        print("----------------------------------------")

        choice = input("Pilih menu : ")

        if choice == "1":
            show_data(clients)

        elif choice == "2":
            add_data(clients)

        elif choice == "3":
            print("\nProgram selesai.")
            break

        else:
            print("\nPilihan tidak valid. Silakan coba lagi.")


if __name__ == "__main__":
    main()